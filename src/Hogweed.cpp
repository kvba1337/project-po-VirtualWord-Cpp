#include "Hogweed.h"
#include "Animal.h"

Hogweed::Hogweed(int posX, int posY, int age, World* currentWorld, bool isNew)
	: Plant(10, posX, posY, age, currentWorld, isNew) {};

std::string Hogweed::getName() {
	return("Hogweed");
}

void Hogweed::checkAndKillAnimal(int x, int y) {
    if (currentWorld->entitySpace[x][y] != NULL) {
        // Check if entity is an animal
        if (dynamic_cast<Animal*>(currentWorld->entitySpace[x][y])) {
            // Kill the animal
            std::cout << "[KILL] : " << this->getName() << " (" << position[0] << "," << position[1] << "), and " << currentWorld->entitySpace[x][y]->getName();
            std::cout << " (" << currentWorld->entitySpace[x][y]->getPosX() << "," << currentWorld->entitySpace[x][y]->getPosY() << ")." << std::endl;

            currentWorld->entityFind->removeEntity(currentWorld->entitySpace[x][y]);
            currentWorld->entitySpace[x][y] = NULL;
        }
    }
}

void Hogweed::action() {
    age++;
    int currentPos[2];
    currentPos[0] = position[0];
    currentPos[1] = position[1];

    // Up
    if (currentPos[1] != 0) {
        checkAndKillAnimal(currentPos[0], currentPos[1] - 1);
    }
    // Right
    if (currentPos[0] != currentWorld->getN() - 1) {
        checkAndKillAnimal(currentPos[0] + 1, currentPos[1]);
    }
    // Down
    if (currentPos[1] != currentWorld->getM() - 1) {
        checkAndKillAnimal(currentPos[0], currentPos[1] + 1);
    }
    // Left
    if (currentPos[0] != 0) {
        checkAndKillAnimal(currentPos[0] - 1, currentPos[1]);
    }

    // 85% chance of sewing
    if (rand() % 100 + 1 > 85) {
        std::cout << "Sewing " << this->getName() << " (" << position[0] << "," << position[1] << ")." << std::endl;
        int* newPos = findNewEmptyField();

        // If there is no empty field
        if (newPos[0] == POS_UNDEFINED && newPos[1] == POS_UNDEFINED) {
            std::cout << "Sewing failed - no unoccupied field!" << std::endl;
            delete newPos;
            return;
        }
        else {
            clone(newPos[0], newPos[1]);
        }
    }
};

void Hogweed::draw() {
    SetConsoleTextAttribute(color, GREEN);
    printf("h");
    SetConsoleTextAttribute(color, WHITE);
}

Organism* Hogweed::clone(int posX, int posY) {
    return new Hogweed(posX, posY, 1, currentWorld, true);
};

Hogweed::~Hogweed() {};