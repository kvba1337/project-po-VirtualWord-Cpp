#include "Plant.h"

Plant::Plant(int strength, int posX, int posY, int age, World* currentWorld, bool isNew)
: Organism(strength, 0, posX, posY, age, currentWorld, isNew) {
};

void Plant::action() {
    if (this->getName() != "Dandelion") {
        age++;
    }

    // Attempt to spawn each plant, chance is 15%
    if (rand() % 100 + 1 > 85) {
        std::cout << "Sewing " << this->getName() << " (" << position[0] << "," << position[1] << ")." << std::endl;
        int* newPos = findNewEmptyField();
        if (newPos[0] == POS_UNDEFINED && newPos[1] == POS_UNDEFINED) {
            std::cout << "Sewing failed (no free field)!" << std::endl;
            delete newPos;
            return;
        }
        else {
            clone(newPos[0], newPos[1]);
        }
    }
};

Plant::~Plant() {};