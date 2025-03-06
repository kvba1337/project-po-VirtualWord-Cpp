#pragma once
#include "Entities.h"
#include "../constans.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <time.h>
#include <windows.h>
HANDLE static color = GetStdHandle(STD_OUTPUT_HANDLE);

class Organism;

class World {
private:
	int N, M;
	int round = 1;
	bool gameState;
	int cooldown;
	int playerInput;

public:
	World(int N, int M); // World's constructor
	World(int N, int M, std::ifstream& loadFile); // World's constructor from the saved file

	int getPlayerInput();
	int getN();
	int getM();
	int getRound();
	void setRound(int round);
	bool getGameState();
	void setGameState();
	int getCooldown();
	void setCooldown(int counter);

	void makeNextRound();
	void printWorld();

	void putInRandomPlace(Organism* entity);
	void putInSpecificPlace(Organism* entity, int horizontalN, int verticalM);

	void saveWorld();
	void drawBoard();
	void drawBorder();

	Entities* entityFind;
	Organism*** entitySpace;

	~World();
};