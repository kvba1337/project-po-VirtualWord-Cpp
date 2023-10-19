#include "Entities.h"
#include "Organism.h"

Entities::Entities(int maxAmountOfEntities) 
    : maxAmountOfEntities(maxAmountOfEntities) {
    head = new EntitiesList;

    head->entity = NULL;
    head->next = NULL;
};

int Entities::getMaxAmountOfEntities() {
    return maxAmountOfEntities;
};

int Entities::getCurrentAmountOfEntities() {
    return currentAmountOfEntities;
};

void Entities::addEntity(Organism* entity) {
    // Check if there is free space in the number of organisms
    if (currentAmountOfEntities >= maxAmountOfEntities) {
        printf("Entity list is full!\n");
        return;
    }

    // Add new node
    EntitiesList* newEntity = new EntitiesList;
    newEntity->entity = entity;
    newEntity->next = NULL;

    EntitiesList* current = head;

    // Finding a place for a new organism
    while (current->next != NULL) {
        // Check if the initiative of the new organism is greater than the next organism
        if (entity->getInitiative() > current->next->entity->getInitiative()) {
            break;
        }
        // Check if initiatives are equal
        else if (entity->getInitiative() == current->next->entity->getInitiative()) {
            // Check if age is greater than or equal than the next organism
            if (entity->getAge() >= current->next->entity->getAge()) {
                break;
            }
        }
        current = current->next;
    }
    // Queue a new organism
    newEntity->next = current->next;
    current->next = newEntity;

    currentAmountOfEntities++;
};

void Entities::removeEntity(Organism* entity) {
    EntitiesList* current = head;

    // Find the given entity
    for (int i = 0; i < currentAmountOfEntities; i++) {
        if (current->next->entity == entity) {
            break;
        }

        if (i == currentAmountOfEntities - 1) {
            printf("Entity is not present in the world!\n");
            return;
        }
        current = current->next;
    }

    // Remove organism
    current->next = current->next->next;
    delete entity;
    currentAmountOfEntities--;
};

Entities::~Entities() {
    EntitiesList* current = head;
    while (current != NULL) {
        EntitiesList* temp = current;
        current = current->next;
        delete temp->entity;
        delete temp;
    }
};