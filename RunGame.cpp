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