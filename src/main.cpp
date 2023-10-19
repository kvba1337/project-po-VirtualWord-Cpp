#include "World.h"

using namespace std;

int main() {
    srand(time(NULL));
    SetConsoleTitle(TEXT("Jakub Falk 193252"));
    system("cls");
    printf("                    |   Jakub Falk 193252   |\n");
    printf("                    | - - - - - - - - - - - |\n");
    printf("                    |  1 - Start new game   |\n");
    printf("                    |  2 - Load saved game  |\n");
    printf("                    |  3 - Exit             |\n");
    printf("                    | - - - - - - - - - - - |\n");
    printf("                         Choose option : ");

    int boardSizeN, boardSizeM, option=0;
    cin >> option;

    if (option == 1) {
        printf("                         New world size : ");
        cin >> boardSizeN >> boardSizeM;

        // World's constructor
        World newWorld(boardSizeN, boardSizeM);

        // Game in progress
        while (newWorld.getGameState()) {
            system("cls");
            newWorld.printWorld();
            newWorld.makeNextRound();
        }

        // End of game
        system("cls");
        newWorld.printWorld();
    }
    else if (option == 2) {
        string fileName;
        ifstream file;

        while (true) {
            printf("Enter the name of the file to load ('exit' ends program): ");
            cin >> fileName;

            if (fileName == "exit") exit(0);

            file.open(fileName.c_str(), ios::in);

            if (!file) printf("Invalid file name, try again.\n");
            else break;
        }

        file >> boardSizeN >> boardSizeM;

        // Saved World's constructor
        World savedWorld(boardSizeN, boardSizeM, file);

        // Game in progress
        while (savedWorld.getGameState()) {
            system("cls");
            savedWorld.printWorld();
            savedWorld.makeNextRound();
        }

        // End of game
        system("cls");
        savedWorld.printWorld();
    }
    else {
        exit(0);
    }

    printf("GAME OVER");
	return 0;
}