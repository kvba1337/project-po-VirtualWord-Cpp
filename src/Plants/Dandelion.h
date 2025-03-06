#pragma once
#include "../Core/Plant.h"

class Dandelion : public Plant {
public:
	Dandelion(int posX, int posY, int age, World* currentWorld, bool isNew);

	std::string getName() override;
	void action() override;
	void draw() override;
	Organism* clone(int posX, int posY) override;

	~Dandelion();
};