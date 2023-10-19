#pragma once
#include "Animal.h"

class Wolf : public Animal {
public:
	Wolf(int posX, int posY, int age, World* currentWorld, bool isNew);

	std::string getName() override;
	void draw() override;
	Organism* clone(int posX, int posY) override;

	~Wolf();
};