#pragma once
#include "World.h"

class Organism {
protected:
	int strength;
	int initiative;
	int position[2];
	int age;
	bool isNew;
	World* currentWorld;

public:
	Organism(int strength, int initiative, int posX, int posY, int age, World* currentWorld, bool isNew);

	int getStrength();
	int getInitiative();
	int getPosX();
	void setPosX(int x);
	int getPosY();
	void setPosY(int y);
	int getAge();
	bool getIsNew();
	void setIsNew();

	virtual std::string getName() = 0;
	virtual void action() = 0;
	virtual void draw() = 0;
	virtual bool isAttackReflected(Organism* entity);

	virtual int* findNewField();
	int* findNewEmptyField();

	virtual Organism* clone(int posX, int posY) = 0;

	virtual ~Organism();
};