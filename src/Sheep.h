#pragma once
#include "Animal.h"

class Sheep : public Animal {
public:
	Sheep(int posX, int posY, int age, World* currentWorld, bool isNew);

	std::string getName() override;
	void draw() override;
	Organism* clone(int posX, int posY) override;

	~Sheep();
};