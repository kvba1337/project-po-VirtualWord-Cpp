#pragma once
#include "../Core/Animal.h"

class Turtle : public Animal {
public:
	Turtle(int posX, int posY, int age, World* currentWorld, bool isNew);

	std::string getName() override;
	void action() override;
	void draw() override;
	Organism* clone(int posX, int posY) override;
	bool isAttackReflected(Organism* entity) override;

	~Turtle();
};