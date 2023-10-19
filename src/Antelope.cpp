#include "Antelope.h"

Antelope::Antelope(int posX, int posY, int age, World* currentWorld, bool isNew)
	: Animal(4, 4, posX, posY, age, currentWorld, isNew) {};

std::string Antelope::getName() {
    return("Antelope");
};

void Antelope::draw() {
    SetConsoleTextAttribute(color, RED);
    printf("A");
    SetConsoleTextAttribute(color, WHITE);
};

int* Antelope::findNewField() {
    int* newPos = new int[2];
    newPos[0] = position[0];
    newPos[1] = position[1];

    int randomField;

    // Random field to move
    while (true) {
        randomField = rand() % 8;

        switch (randomField) {
        case 0: // Up
            // Check if field is not out of board
            if (newPos[1] == 0) continue;
            else newPos[1]--;
            break;
        case 1: // Right
            if (newPos[0] == currentWorld->getN() - 1) continue;
            else newPos[0]++;
            break;
        case 2: // Down
            if (newPos[1] == currentWorld->getM() - 1) continue;
            else newPos[1]++;
            break;
        case 3: // Left
            if (newPos[0] == 0) continue;
            else newPos[0]--;
            break;
        case 4: // Up + 2
            if (newPos[1] <= 1) continue;
            else newPos[1] -= 2;
            break;
        case 5: // Right + 2
            if (newPos[0] >= currentWorld->getN() - 2) continue;
            else newPos[0] += 2;
            break;
        case 6: // Down + 2
            if (newPos[1] >= currentWorld->getM() - 2) continue;
            else newPos[1] += 2;
            break;
        case 7: // Left + 2
            if (newPos[0] <= 1) continue;
            else newPos[0] -= 2;
            break;
        }

        break;
    }

    return newPos;
};

void Antelope::collision(Organism* collidingEntity) {
    // 50% chance of escape
    if (rand() % 2 && !doAnimalsMatch(*collidingEntity) && collidingEntity->getStrength() > strength) {
        // Escape
        std::cout << "Collision [ESCAPE] " << getName() << " (" << position[0] << "," << position[1] << "), and";
        std::cout << collidingEntity->getName() << " (" << collidingEntity->getPosX() << "," << collidingEntity->getPosY() << ")." << std::endl;

        // Find a new empty field to move to
        int* newPos = findNewEmptyField();
        if (newPos[0] != POS_UNDEFINED && newPos[1] != POS_UNDEFINED) {
            currentWorld->entitySpace[newPos[0]][newPos[1]] = this;
            currentWorld->entitySpace[position[0]][position[1]] = NULL;
            position[0] = newPos[0];
            position[1] = newPos[1];
        }
    }
    else {
        Animal::collision(collidingEntity);
    }
};

Organism* Antelope::clone(int posX, int posY) {
    return new Antelope(posX, posY, 1, currentWorld, true);
};

Antelope::~Antelope() {};