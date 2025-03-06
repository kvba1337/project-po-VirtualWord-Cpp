#include "Wolf.h"

Wolf::Wolf(int posX, int posY, int age, World* currentWorld, bool isNew)
	: Animal(9, 5, posX, posY, age, currentWorld, isNew) {};

std::string Wolf::getName() {
	return("Wolf");
}

void Wolf::draw() {
	SetConsoleTextAttribute(color, RED);
	printf("W");
	SetConsoleTextAttribute(color, WHITE);
}

Organism* Wolf::clone(int posX, int posY) {
	return new Wolf(posX, posY, 1, currentWorld, true);
}

Wolf::~Wolf() {}