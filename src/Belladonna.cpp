#include "Belladonna.h"

Belladonna::Belladonna(int posX, int posY, int age, World* currentWorld, bool isNew)
	: Plant(99, posX, posY, age, currentWorld, isNew) {};

std::string Belladonna::getName() {
	return("Belladonna");
};

void Belladonna::draw() {
	SetConsoleTextAttribute(color, GREEN);
	printf("b");
	SetConsoleTextAttribute(color, WHITE);
};

Organism* Belladonna::clone(int posX, int posY) {
    return new Belladonna(posX, posY, 1, currentWorld, true);
};

Belladonna::~Belladonna() {};