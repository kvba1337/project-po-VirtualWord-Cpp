#pragma once
#include "Organism.h"

class Plant : public Organism {
public:
	Plant(int strength, int posX, int posY, int age, World* currentWorld, bool isNew);

	void action() override;

	~Plant();
};