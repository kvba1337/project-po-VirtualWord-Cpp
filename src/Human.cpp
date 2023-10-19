#include "Human.h"

Human::Human(int posX, int posY, int age, World* currentWorld)
	: Animal(5, 4, posX, posY, age, currentWorld, false) {};

std::string Human::getName() {
    return("Human");
};

void Human::action() {
    age++;
    
    int newPos[2];
    newPos[0] = position[0];
    newPos[1] = position[1];

    // Chances for a double move (special ability) - 
    // 100% - cooldown >= 3
    // 50% - cooldown = (1-2)
    // 0% - cooldown <= 0
    switch (currentWorld->getPlayerInput()) {
    case KEY_LEFT_ARROW:
        if (currentWorld->getCooldown() >= 3) newPos[0] -= 2;
        else if (currentWorld->getCooldown() > 0 && currentWorld->getCooldown() < 3) {
            // 50% chance
            if (rand() % 2) newPos[0] -= 2;
            else newPos[0]--;
        }
        else newPos[0]--;
        break;
    case KEY_RIGHT_ARROW:
        if (currentWorld->getCooldown() >= 3) newPos[0] += 2;
        else if (currentWorld->getCooldown() > 0 && currentWorld->getCooldown() < 3) {
            // 50% chance
            if (rand() % 2) newPos[0] += 2;
            else newPos[0]++;
        }
        else newPos[0]++;
        break;
    case KEY_UP_ARROW: 
        if (currentWorld->getCooldown() >= 3) newPos[1] -= 2;
        else if (currentWorld->getCooldown() > 0 && currentWorld->getCooldown() < 3) {
            // 50% chance
            if (rand() % 2) newPos[1] -= 2;
            else newPos[1]--;
        }
        else newPos[1]--;
        break;
    case KEY_DOWN_ARROW: 
        if (currentWorld->getCooldown() >= 3) newPos[1] += 2;
        else if (currentWorld->getCooldown() > 0 && currentWorld->getCooldown() < 3) {
            // 50% chance
            if (rand() % 2) newPos[1] += 2;
            else newPos[1]++;
        }
        else newPos[1]++;
        break;
    case KEY_R: 
        specialAbility();
        break;
    default:
        break;
    }

    // Check if move is possible (board limit)
    if ((newPos[0] < 0 || newPos[1] < 0) || (newPos[0] >= currentWorld->getN()) || (newPos[1] >= currentWorld->getM())) {
        printf("[PLAYER] Impossible move!\n");
        return;
    }

    // Process move
    if (currentWorld->entitySpace[newPos[0]][newPos[1]] == NULL) {
        currentWorld->entitySpace[newPos[0]][newPos[1]] = this;
        currentWorld->entitySpace[position[0]][position[1]] = NULL;
        position[0] = newPos[0];
        position[1] = newPos[1];
    }
    else {
        collision(currentWorld->entitySpace[newPos[0]][newPos[1]]);
    }
};

void Human::draw() {
    SetConsoleTextAttribute(color, YELLOW);
    printf("H");
    SetConsoleTextAttribute(color, WHITE);
};

Organism* Human::clone(int posX, int posY) {
    return new Human(posX, posY, 1, currentWorld);
};

void Human::specialAbility() {
    if (currentWorld->getCooldown() <= -5) {
        // The player's special ability allows him to jump over two squares instead of one
        printf("[PLAYER] Special ability activated. (Antelope's speed)\n");
        currentWorld->setCooldown(6);
    }
    else if(currentWorld->getCooldown() > 0) printf("[PLAYER] Ability is already in use.\n");
    else if (currentWorld->getCooldown() > -5 && currentWorld->getCooldown() <= 0) printf("[PLAYER] Ability is on cooldown\n");
};

Human::~Human() {
    currentWorld->setGameState();
};