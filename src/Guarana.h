#pragma once
#include "Plant.h"

class Guarana : public Plant {
public:
	Guarana(int posX, int posY, int age, World* currentWorld, bool isNew);

	std::string getName() override;
	void draw() override;
	Organism* clone(int posX, int posY) override;

	~Guarana();
};