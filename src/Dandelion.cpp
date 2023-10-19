#include "Dandelion.h"

Dandelion::Dandelion(int posX, int posY, int age, World* currentWorld, bool isNew)
	: Plant(0, posX, posY, age, currentWorld, isNew) {};

std::string Dandelion::getName() {
    return("Dandelion");
};

void Dandelion::action() {
    age++;

    for (int i = 0; i < 3; i++) {
        Plant::action();
    }
};

void Dandelion::draw() {
    SetConsoleTextAttribute(color, GREEN);
    printf("d");
    SetConsoleTextAttribute(color, WHITE);
};

Organism* Dandelion::clone(int posX, int posY) {
    return new Dandelion(posX, posY, 1, currentWorld, true);
};

Dandelion::~Dandelion() {};