#pragma once
#include "Plant.h"

class Grass : public Plant {
public:
	Grass(int posX, int posY, int age, World* currentWorld, bool isNew);

	std::string getName() override;
	void draw() override;
	Organism* clone(int posX, int posY) override;

	~Grass();
};