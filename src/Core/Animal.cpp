#include "Animal.h"
#include "../Plants/Hogweed.h"
#include "../Plants/Guarana.h"
#include "Human.h"

Animal::Animal(int strength, int initiative, int posX, int posY, int age, World* currentWorld, bool isNew)
: Organism(strength, initiative, posX, posY, age, currentWorld, isNew) {
};

void Animal::action() {
    if (this->getName() != "Turtle") {
        age++;
    }

    int* newPos = findNewField();

    // If field is empty - move
    if (currentWorld->entitySpace[newPos[0]][newPos[1]] == NULL) {
        currentWorld->entitySpace[newPos[0]][newPos[1]] = this;
        currentWorld->entitySpace[position[0]][position[1]] = NULL;
        position[0] = newPos[0];
        position[1] = newPos[1];
    }
    else {
        collision(currentWorld->entitySpace[newPos[0]][newPos[1]]);
    }
    delete newPos;
};

void Animal::collision(Organism* collidingEntity) {
    if (doAnimalsMatch(*collidingEntity)) {
        // Check if entity is human
        if (typeid(*collidingEntity) == typeid(Human)) {
            return;
        }

        // Collision with the same organism
        std::cout << "Collision [MATCH] " << this->getName() << " (" << position[0] << "," << position[1] << "), and ";
        std::cout << collidingEntity->getName() << " (" << collidingEntity->getPosX() << "," << collidingEntity->getPosY() << ")." << std::endl;

        checkIfCloningIsPossible();
        return;
    }
    else {
        // Checking if the turtle reflect the collision
        if (collidingEntity->isAttackReflected(this)) {
            std::cout << "Colliding [REFLECT] " << this->getName() << " (" << position[0] << "," << position[1] << "), and ";
            std::cout << collidingEntity->getName() << " (" << collidingEntity->getPosX() << "," << collidingEntity->getPosY() << ")." << std::endl;
            return;
        }

        // The fight of two organisms
        std::cout << "Colliding [FIGHT] " << this->getName() << " (" << position[0] << "," << position[1] << "), and ";
        std::cout << collidingEntity->getName() << " (" << collidingEntity->getPosX() << "," << collidingEntity->getPosY() << ")." << std::endl;

        // If the strength of one animal is higher than the strength of the other and if the second organism is not HogWeed
        if (strength >= collidingEntity->getStrength() && typeid(*collidingEntity) != typeid(Hogweed)) {
            // Win
            std::cout << this->getName() << " WINS" << std::endl;

            // If it was guarana, we increase the strength of this organism
            if (typeid(*collidingEntity) == typeid(Guarana)) {
                std::cout << "Increasing strength for: " << this->getName() << " (" << position[0] << "," << position[1] << ")" << std::endl;
                strength += 3;
            }

            // Remove the organism from the board
            currentWorld->entitySpace[position[0]][position[1]] = NULL;
            position[0] = collidingEntity->getPosX();
            position[1] = collidingEntity->getPosY();
            currentWorld->entitySpace[position[0]][position[1]] = this;

            currentWorld->entityFind->removeEntity(collidingEntity);
        }
        else {
            // Defeat
            std::cout << this->getName() << " DEFEAT" << std::endl;
            currentWorld->entitySpace[position[0]][position[1]] = NULL;
            currentWorld->entityFind->removeEntity(this);
        }
    }
};

bool Animal::doAnimalsMatch(Organism& entity) {
    return (this->getName() == entity.getName());
};

void Animal::checkIfCloningIsPossible() {
    int* newPos = findNewEmptyField();

    // If there is no place for the organism to appear
    if (newPos[0] == POS_UNDEFINED && newPos[1] == POS_UNDEFINED) {
        std::cout << "[" << this->getName() << "] Cloning failed. No empty place for cloning!" << std::endl;
        return;
    }

    // If there is a free place
    clone(newPos[0], newPos[1]);
    delete newPos;
};

Animal::~Animal() {};