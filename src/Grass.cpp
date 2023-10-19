#include "Grass.h"

Grass::Grass(int posX, int posY, int age, World* currentWorld, bool isNew)
	: Plant(0, posX, posY, age, currentWorld, isNew) {};

std::string Grass::getName() {
    return("Grass");
};

void Grass::draw() {
    SetConsoleTextAttribute(color, GREEN);
    printf("#");
    SetConsoleTextAttribute(color, WHITE);
};

Organism* Grass::clone(int posX, int posY) {
    return new Grass(posX, posY, 1, currentWorld, true);
};

Grass::~Grass() {};