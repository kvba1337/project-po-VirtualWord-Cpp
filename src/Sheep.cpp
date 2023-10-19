#include "Sheep.h"

Sheep::Sheep(int posX, int posY, int age, World* currentWorld, bool isNew)
	: Animal(4, 4, posX, posY, age, currentWorld, isNew) {};

std::string Sheep::getName() {
	return("Sheep");
}

void Sheep::draw() {
	SetConsoleTextAttribute(color, RED);
	printf("S");
	SetConsoleTextAttribute(color, WHITE);
}

Organism* Sheep::clone(int posX, int posY) {
	return new Sheep(posX, posY, 1, currentWorld, true);
}

Sheep::~Sheep() {}