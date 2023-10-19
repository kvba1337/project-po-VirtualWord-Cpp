#include "Turtle.h"

Turtle::Turtle(int posX, int posY, int age, World* currentWorld, bool isNew)
	: Animal(2, 1, posX, posY, age, currentWorld, isNew) {};

std::string Turtle::getName() {
	return("Turtle");
}

void Turtle::action() {
	// 25% chance
	if (rand() % 4 == 0) {
		Animal::action();
	}
	age++;
}

void Turtle::draw() {
	SetConsoleTextAttribute(color, RED);
	printf("T");
	SetConsoleTextAttribute(color, WHITE);
}

Organism* Turtle::clone(int posX, int posY) {
	return new Turtle(posX, posY, 1, currentWorld, true);
}

bool Turtle::isAttackReflected(Organism* entity) {
	if (entity->getStrength() < 5) return true;
	else return false;
}

Turtle::~Turtle() {}