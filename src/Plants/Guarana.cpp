#include "Guarana.h"

Guarana::Guarana(int posX, int posY, int age, World* currentWorld, bool isNew)
	: Plant(0, posX, posY, age, currentWorld, isNew) {};

std::string Guarana::getName() {
    return("Guarana");
};

void Guarana::draw() {
    SetConsoleTextAttribute(color, GREEN);
    printf("g");
    SetConsoleTextAttribute(color, WHITE);
}

Organism* Guarana::clone(int posX, int posY) {
    return new Guarana(posX, posY, 1, currentWorld, true);
};

Guarana::~Guarana() {};