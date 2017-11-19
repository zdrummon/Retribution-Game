//libraries 
#include <iostream>
#include <windows.h> 
//headers
#include "RunGame.h"
#include "GameHandler.h"
//namespaces
using namespace std;
//class body
RunGame::RunGame() {}

<<<<<<< HEAD:temp/RunGame.cpp
//run the game
RunGame::RunGame() {}

//build the map
RunGame::mapHandler() {
	MapHandler MapHandlerObject;
	
	return 0;
}

//play the game
RunGame::playGame() {
	quitGame = false;
=======
//play the game
RunGame::playGame() {
	quitGame = false;
	
	//temporary map data
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << "  " << 9 - i << " ";
		for (int j = 0; j < 10; j++) {
			mapArray[i][j] = 0;
			cout << mapArray[i][j] << " ";
		}
		cout << endl;
	}
>>>>>>> master:RunGame.cpp
	
	//create game handlers
	GameHandler GameHandlerObject;
	GameHandlerObject.mapHandler();
	GameHandlerObject.mobHandler();
	GameHandlerObject.itemHandler();
	GameHandlerObject.playerHandler();
	GameHandlerObject.effectHandler();
	
	//TODO primary game logic
	int i = 0;
	cout << "    ";
	while (quitGame == false) {
		cout << i++ << " ";
		if (i > 9) {
			quitGame = true;
		}
	}
	cout << endl << endl;

	system("pause");	
	return 0;
}