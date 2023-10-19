#pragma once
#include "Animal.h"

class Antelope : public Animal {
public:
	Antelope(int posX, int posY, int age, World* currentWorld, bool isNew);

	std::string getName() override;
	void draw() override;

	int* findNewField() override;
	void collision(Organism* collidingEntitiy) override;
	Organism* clone(int posX, int posY) override;

	~Antelope();
};