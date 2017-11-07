//libraries 
#include <iostream>
#include <windows.h> 
//headers
#include "RunGame.h"
#include "MapTerrain.h"
//namespaces
using namespace std;
//class body
RunGame::RunGame() {}

//play the game
RunGame::playGame() {
	quitGame = false;
	
	//map object definitions
	MapTerrain MapTerrainObject;
	InteractiveTerrain InteractiveTerrainObject;
	Mob MobObject;
	Item ItemObject;
	NPC NPCObject;
	PC PCObject;
	
	//fill the map
	for (int i = 0; i < MAPSIZE; i++) {
		for (int j = 0; j < MAPSIZE; j++) {
			if (i == 0 || i == 9) {
				mapArray[i][j] = 1;
			} else if (j == 0 || j == 9) {
				mapArray[i][j] = 1;
			} else {
				mapArray[i][j] = 0;
			}
		}
	}
	mapArray[5][5] = 5;
	
	//TODO primary game logic
	char playerInput;
	while (quitGame == false) {
		
		//print map data
		system("CLS");
		cout << endl << "    0 1 2 3 4 5 6 7 8 9" << endl;

		for (int i = 0; i < MAPSIZE; i++) {
			cout << "  " << i << " ";
			for (int j = 0; j < MAPSIZE; j++) {
				cout << mapArray[i][j] << " ";
			}
			cout << endl;
		}	
		cout << endl;
		
		//allow player input
		cout << "Type a command and press enter." << endl;
		cin >> playerInput;

		if (playerInput == 'q' || playerInput == 'Q') {
			quitGame = true;
		} else if (playerInput == 'w' || playerInput == 'W') {
			for (int i = 0; i < MAPSIZE; i++) {
				for (int j = 0; j < MAPSIZE; j++) {
					if (mapArray[i][j] == 5) {
						mapArray[i-1][j] = 5;
						mapArray[i][j] = 0;
						i = MAPSIZE;
						j = MAPSIZE;
					}	
				}
			} 
		} else if (playerInput == 'a' || playerInput == 'A') {
			for (int i = 0; i < MAPSIZE; i++) {
				for (int j = 0; j < MAPSIZE; j++) {
					if (mapArray[i][j] == 5) {
						mapArray[i][j-1] = 5;
						mapArray[i][j] = 0;
						i = MAPSIZE;
						j = MAPSIZE;
					}	
				}
			} 
		} else if (playerInput == 's' || playerInput == 'S') {
			for (int i = 0; i < MAPSIZE; i++) {
				for (int j = 0; j < MAPSIZE; j++) {
					if (mapArray[i][j] == 5) {
						mapArray[i+1][j] = 5;
						mapArray[i][j] = 0;
						i = MAPSIZE;
						j = MAPSIZE;
					}	
				}
			} 
		} else if (playerInput == 'd' || playerInput == 'D') {
			for (int i = 0; i < MAPSIZE; i++) {
				for (int j = 0; j < MAPSIZE; j++) {
					if (mapArray[i][j] == 5) {
						mapArray[i][j+1] = 5;
						mapArray[i][j] = 0;
						i = MAPSIZE;
						j = MAPSIZE;
					}	
				}
			} 
		} else {
			cout << endl << "Please input a correct command." << endl
						 << "W, A, S, or D to move.\nQ to quit." << endl;
		system("pause");
		}
	}
	cout << endl << endl;

	return 0;
}