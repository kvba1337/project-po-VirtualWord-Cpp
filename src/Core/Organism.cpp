#include "Organism.h"

Organism::Organism(int strength, int initiative, int posX, int posY, int age, World* currentWorld, bool isNew)
    : strength(strength), initiative(initiative), age(age), currentWorld(currentWorld), isNew(isNew) {
    this->position[0] = posX;
    this->position[1] = posY;

    if (posX == POS_UNDEFINED && posY == POS_UNDEFINED) return;

    currentWorld->entitySpace[posX][posY] = this;
    currentWorld->entityFind->addEntity(this);
};

int Organism::getStrength() {
    return strength;
};

int Organism::getInitiative() {
    return initiative;
};

int Organism::getPosX() {
    return position[0];
};

void Organism::setPosX(int x) {
    position[0] = x;
};

int Organism::getPosY() {
    return position[1];
};

void Organism::setPosY(int y) {
    position[1] = y;
};

int Organism::getAge() {
    return age;
};

bool Organism::getIsNew() {
    return isNew;
};

void Organism::setIsNew() {
    isNew = isNew ? 0 : 1;
};

bool Organism::isAttackReflected(Organism* entity) {
    return false;
};

int* Organism::findNewField() {
    int* newPos = new int[2];
    newPos[0] = position[0];
    newPos[1] = position[1];

    bool isValidMove = false;
    while (!isValidMove) {
        int randomField = rand() % 4;

        switch (randomField) {
        case 0:  // Up
            if (newPos[1] > 0) {
                newPos[1]--;
                isValidMove = true;
            }
            break;
        case 1:  // Right
            if (newPos[0] < currentWorld->getN() - 1) {
                newPos[0]++;
                isValidMove = true;
            }
            break;
        case 2:  // Down
            if (newPos[1] < currentWorld->getM() - 1) {
                newPos[1]++;
                isValidMove = true;
            }
            break;
        case 3:  // Left
            if (newPos[0] > 0) {
                newPos[0]--;
                isValidMove = true;
            }
            break;
        }
    }
    return newPos;
};

int* Organism::findNewEmptyField() {
    int* newPos = new int[2];
    newPos[0] = position[0];
    newPos[1] = position[1];

    // Up
    if ((newPos[1] != 0) && (currentWorld->entitySpace[newPos[0]][newPos[1] - 1] == NULL)) {
        newPos[1]--;
    }
    // Right
    else if ((newPos[0] != currentWorld->getN() - 1) && (currentWorld->entitySpace[newPos[0] + 1][newPos[1]] == NULL)) {
        newPos[0]++;
    }
    // Down
    else if ((newPos[1] != currentWorld->getM() - 1) && (currentWorld->entitySpace[newPos[0]][newPos[1] + 1] == NULL)) {
        newPos[1]++;
    }
    // Left
    else if ((newPos[0] != 0) && (currentWorld->entitySpace[newPos[0] - 1][newPos[1]] == NULL)) {
        newPos[0]--;
    }
    else {
        newPos[0] = POS_UNDEFINED;
        newPos[1] = POS_UNDEFINED;
    }

    return newPos;
};

Organism::~Organism() {};