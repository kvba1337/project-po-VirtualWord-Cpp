#pragma once
#include "../Core/Plant.h"

class Hogweed : public Plant {
public:
	Hogweed(int posX, int posY, int age, World* currentWorld, bool isNew);

	std::string getName() override;
	void action() override;
	void draw() override;
	Organism* clone(int posX, int posY) override;

	void checkAndKillAnimal(int x, int y);

	~Hogweed();
};