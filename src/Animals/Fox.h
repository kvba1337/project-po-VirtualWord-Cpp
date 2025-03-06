#pragma once
#include "../Core/Animal.h"

class Fox : public Animal {
public:
	Fox(int posX, int posY, int age, World* currentWorld, bool isNew);

	std::string getName() override;
	void action() override;
	void draw() override;
	Organism* clone(int posX, int posY) override;

	~Fox();
};