#pragma once
#include "Organism.h"

class Animal : public Organism {
public:
	Animal(int strength, int initiative, int posX, int posY, int age, World* currentWorld, bool isNew);

	std::string getName() override = 0;
	void action() override;
	void draw() override = 0;

	virtual void collision(Organism* collidingEntity);
	bool doAnimalsMatch(Organism& entity);
	void checkIfCloningIsPossible();

	~Animal();
};