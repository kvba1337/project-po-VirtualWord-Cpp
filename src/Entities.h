#pragma once

class Organism;

struct EntitiesList {
	Organism* entity;
	EntitiesList* next;
};

class Entities {
private:
	int maxAmountOfEntities;
	int currentAmountOfEntities;

public:
	Entities(int maxAmountOfEntities);

	int getMaxAmountOfEntities();
	int getCurrentAmountOfEntities();
	void addEntity(Organism* entity);
	void removeEntity(Organism* entity);

	EntitiesList* head;

	~Entities();
};