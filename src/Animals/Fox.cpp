#include "Fox.h"

Fox::Fox(int posX, int posY, int age, World* currentWorld, bool isNew)
	: Animal(3, 7, posX, posY, age, currentWorld, isNew) {};

std::string Fox::getName() {
    return("Fox");
};

void Fox::action() {
    age++;
    int* newPos = findNewField();

    // If place is empty - move
    if (currentWorld->entitySpace[newPos[0]][newPos[1]] == NULL) {
        currentWorld->entitySpace[newPos[0]][newPos[1]] = this;
        currentWorld->entitySpace[position[0]][position[1]] = NULL;
        position[0] = newPos[0];
        position[1] = newPos[1];
    }
    else {
        // Only move if you are able to defeat the organism that is in that field
        if (currentWorld->entitySpace[newPos[0]][newPos[1]]->getStrength() <= getStrength()) {
            collision(currentWorld->entitySpace[newPos[0]][newPos[1]]);
        }
        else {
            // Escape
            std::cout << "Collision [REFUSE] " << this->getName() << " (" << position[0] << "," << position[1] << "), and ";
            std::cout << currentWorld->entitySpace[newPos[0]][newPos[1]]->getName() << "(" << currentWorld->entitySpace[newPos[0]][newPos[1]]->getPosX() << "," << currentWorld->entitySpace[newPos[0]][newPos[1]]->getPosY() << ")." << std::endl;
        }
    }
    delete newPos;
};

void Fox::draw() {
    SetConsoleTextAttribute(color, RED);
    printf("F");
    SetConsoleTextAttribute(color, WHITE);
};

Organism* Fox::clone(int posX, int posY) {
    return new Fox(posX, posY, 1, currentWorld, true);
};

Fox::~Fox() {};