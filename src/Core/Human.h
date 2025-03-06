#pragma once
#include "Animal.h"

class Human : public Animal {
public:
	Human(int posX, int posY, int age, World* currentWorld);

	std::string getName() override;
	void action() override;
	void draw() override;
	Organism* clone(int posX, int posY) override;

	void specialAbility();

	~Human();
};