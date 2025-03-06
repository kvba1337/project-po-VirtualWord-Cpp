#pragma once
#include "../Core/Plant.h"

class Belladonna : public Plant {
public:
	Belladonna(int posX, int posY, int age, World* currentWorld, bool isNew);

	std::string getName() override;
	void draw() override;
	Organism* clone(int posX, int posY) override;

	~Belladonna();
};