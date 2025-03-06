#include "World.h"
#include "../AllClasses.h"

World::World(int N, int M) : N(N), M(M) {
    printf("World created. Size(%d, %d)\n", N, M);

    // Allocate space for organisms
    entitySpace = new Organism **[N];
    for (int i = 0; i < N; i++) {
        entitySpace[i] = new Organism * [M];
    }

    // Set an empty field for each position
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            entitySpace[i][j] = NULL;
        }
    }

    // Allocate space for finding an entity
    entityFind = new Entities(N * M);

    // Set game parameters
    gameState = true;
    cooldown = -5;

    // Create and put organisms in random place
    putInRandomPlace(new Human(POS_UNDEFINED, POS_UNDEFINED, rand() % 20 + 1, this));

    putInRandomPlace(new Antelope(POS_UNDEFINED, POS_UNDEFINED, rand() % 20 + 1, this, false));
    putInRandomPlace(new Antelope(POS_UNDEFINED, POS_UNDEFINED, rand() % 20 + 1, this, false));

    putInRandomPlace(new Belladonna(POS_UNDEFINED, POS_UNDEFINED, rand() % 20 + 1, this, false));
    putInRandomPlace(new Belladonna(POS_UNDEFINED, POS_UNDEFINED, rand() % 20 + 1, this, false));

    putInRandomPlace(new Dandelion(POS_UNDEFINED, POS_UNDEFINED, rand() % 20 + 1, this, false));

    putInRandomPlace(new Fox(POS_UNDEFINED, POS_UNDEFINED, rand() % 20 + 1, this, false));
    putInRandomPlace(new Fox( POS_UNDEFINED, POS_UNDEFINED, rand() % 20 + 1, this, false));

    putInRandomPlace(new Grass(POS_UNDEFINED, POS_UNDEFINED, rand() % 20 + 1, this, false));

    putInRandomPlace(new Guarana(POS_UNDEFINED, POS_UNDEFINED, rand() % 20 + 1, this, false));
    putInRandomPlace(new Guarana(POS_UNDEFINED, POS_UNDEFINED, rand() % 20 + 1, this, false));

    putInRandomPlace(new Hogweed(POS_UNDEFINED, POS_UNDEFINED, rand() % 20 + 1, this, false));

    putInRandomPlace(new Sheep(POS_UNDEFINED, POS_UNDEFINED, rand() % 20 + 1, this, false));
    putInRandomPlace(new Sheep(POS_UNDEFINED, POS_UNDEFINED, rand() % 20 + 1, this, false));

    putInRandomPlace(new Turtle(POS_UNDEFINED, POS_UNDEFINED, rand() % 20 + 1, this, false));
    putInRandomPlace(new Turtle(POS_UNDEFINED, POS_UNDEFINED, rand() % 20 + 1, this, false));

    putInRandomPlace(new Wolf(POS_UNDEFINED, POS_UNDEFINED, rand() % 20 + 1, this, false));
    putInRandomPlace(new Wolf(POS_UNDEFINED, POS_UNDEFINED, rand() % 20 + 1, this, false));
}

World::World(int N, int M, std::ifstream& loadFile) : N(N), M(M) {
    printf("Saved World created. Size(%d, %d)\n", N, M);

    // Allocate space for organisms
    entitySpace = new Organism * *[N];
    for (int i = 0; i < N; i++) {
        entitySpace[i] = new Organism * [M];
    }

    // Set an empty field for each position
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            entitySpace[i][j] = NULL;
        }
    }

    // Allocate space for finding an entity
    entityFind = new Entities(N * M);

    std::string word;
    int savedN, savedM, savedAge, savedIsNew, savedRound, savedCooldown;
    loadFile >> savedRound >> savedCooldown;

    // Set game parameters
    gameState = true;
    setRound(savedRound);
    setCooldown(savedCooldown);

    while (loadFile >> word) {
        loadFile >> savedN >> savedM >> savedAge >> savedIsNew;
        if (word == "Human") {
            putInSpecificPlace(new Human(POS_UNDEFINED, POS_UNDEFINED, savedAge, this), savedN, savedM);
        }
        else if (word == "Antelope") {
            putInSpecificPlace(new Antelope(POS_UNDEFINED, POS_UNDEFINED, savedAge, this, savedAge), savedN, savedM);
        }
        else if (word == "Belladonna") {
            putInSpecificPlace(new Belladonna(POS_UNDEFINED, POS_UNDEFINED, savedAge, this, savedAge), savedN, savedM);
        }
        else if (word == "Fox") {
            putInSpecificPlace(new Fox(POS_UNDEFINED, POS_UNDEFINED, savedAge, this, savedAge), savedN, savedM);
        }
        else if (word == "Dandelion") {
            putInSpecificPlace(new Dandelion(POS_UNDEFINED, POS_UNDEFINED, savedAge, this, savedAge), savedN, savedM);
        }
        else if (word == "Grass") {
            putInSpecificPlace(new Grass(POS_UNDEFINED, POS_UNDEFINED, savedAge, this, savedAge), savedN, savedM);
        }
        else if (word == "Hogweed") {
            putInSpecificPlace(new Hogweed(POS_UNDEFINED, POS_UNDEFINED, savedAge, this, savedAge), savedN, savedM);
        }
        else if (word == "Guarana") {
            putInSpecificPlace(new Guarana(POS_UNDEFINED, POS_UNDEFINED, savedAge, this, savedAge), savedN, savedM);
        }
        else if (word == "Sheep") {
            putInSpecificPlace(new Sheep(POS_UNDEFINED, POS_UNDEFINED, savedAge, this, savedAge), savedN, savedM);
        }
        else if (word == "Wolf") {
            putInSpecificPlace(new Wolf(POS_UNDEFINED, POS_UNDEFINED, savedAge, this, savedAge), savedN, savedM);
        }
        else if (word == "Turtle") {
            putInSpecificPlace(new Turtle(POS_UNDEFINED, POS_UNDEFINED, savedAge, this, savedAge), savedN, savedM);
        }
    }
}

int World::getPlayerInput() {
    return playerInput;
}

int World::getN() {
    return N;
}

int World::getM() {
    return M;
}

int World::getRound() {
    return round;
}

void World::setRound(int round) {
    this->round = round;
}

bool World::getGameState() {
    return gameState;
}

void World::setGameState() {
    gameState = gameState ? 0 : 1;
}

int World::getCooldown() {
    return cooldown;
}

void World::setCooldown(int counter) {
    cooldown = counter;
}

void World::makeNextRound() {
    printf("ROUND %d\n", getRound());
    printf("Press one of the keys: ");

    playerInput = _getch();

	SetConsoleTextAttribute(color, RED);
	printf("\nActions that happened after the move: \n");
	SetConsoleTextAttribute(color, WHITE);

    if (playerInput == KEY_ARROWS) {
        playerInput = _getch();
    }
    else if (playerInput == KEY_S) {
        saveWorld();
        SetConsoleTextAttribute(color, GREEN);
        printf("Press ENTER to continue");
        SetConsoleTextAttribute(color, WHITE);
        getchar();

        printf("Press one of the keys: ");

        playerInput = _getch();
        if (playerInput == KEY_ARROWS) {
            playerInput = _getch();
        }
    }
    else if (playerInput == KEY_ESC) {
        setGameState();
    }

    cooldown--;

    EntitiesList* head = entityFind->head->next;

    // Loop through all entities in the list
    while (head != NULL) {
        if (head->entity->getIsNew()) {
            head->entity->setIsNew();
        }
        else {
            head->entity->action();
        }
        head = head->next;
    }

    if (getRound() == 1) getchar();

    setRound(getRound()+1);
    SetConsoleTextAttribute(color, GREEN);
    printf("Press ENTER to continue");
    SetConsoleTextAttribute(color, WHITE);
    getchar();
}

void World::printWorld() {
    for (int i = 0; i < M + 2; i++) {
        printf("%c", VERTICAL_LINE);
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == M + 1) {
                printf("%c", HORIZONTAL_LINE);
            }
            else {
                if (entitySpace[j][i - 1] != NULL) {
                    entitySpace[j][i - 1]->draw();
                }
                else {
                    printf(" ");
                }
            }
        }
        printf("%c\n", VERTICAL_LINE);
    }

    printf("arrows - move human | r - special ability | s - save game | ESC - finish game \n");
    SetConsoleTextAttribute(color, YELLOW);
    printf("[H - Human]\n");
    SetConsoleTextAttribute(color, RED);
    printf("Animals: [A - Antelope][F - Fox][S - Sheep][T - Turtle][W - Wolf]\n");
    SetConsoleTextAttribute(color, GREEN);
    printf("Plants: [b - Belladonna][# - Grass][g - Guarana][h - Hogweed][d - Dandelion]\n");
    SetConsoleTextAttribute(color, WHITE);
}

void World::putInRandomPlace(Organism* entity) {
    int newPos[2];
    newPos[0] = rand() % getN();
    newPos[1] = rand() % getM();

    // If there is emtpy place
    if (entitySpace[newPos[0]][newPos[1]] == NULL) {
        entity->setPosX(newPos[0]);
        entity->setPosY(newPos[1]);
        entitySpace[newPos[0]][newPos[1]] = entity;
        entityFind->addEntity(entity);
    }
    else {
        delete entity;
    }
}

void World::putInSpecificPlace(Organism* entity, int horizontalN, int verticalM) {
    entity->setPosX(horizontalN);
    entity->setPosY(verticalM);
    entitySpace[horizontalN][verticalM] = entity;
    entityFind->addEntity(entity);
}

void World::saveWorld() {
    std::ofstream file;
    std::string filename = "save.txt";
    int counter = 0;

    // Setting unique name of file
    while (true) {
        std::ifstream ifile(filename.c_str());
        if (ifile) {
            counter++;
            filename = "save" + std::to_string(counter) + ".txt";
        }
        else break;
    }

    file.open(filename, std::ios::out);

    if (!file) {
        printf("Couldn't save the world.\n");
        return;
    }
    else {
        file << N << " " << M << "\n";
        file << round << " " << cooldown << "\n";
        EntitiesList* current = entityFind->head->next;

        while (current != NULL) {
            file << current->entity->getName() << " " << current->entity->getPosX() << " " << current->entity->getPosY() << " " << current->entity->getAge() << " " << current->entity->getIsNew() << "\n";
            current = current->next;
        }

        file.close();
        SetConsoleTextAttribute(color, BLUE);
        printf("\nWorld saved.\n");
        SetConsoleTextAttribute(color, WHITE);
    }
}

World::~World() {}