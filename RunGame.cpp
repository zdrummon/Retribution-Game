//libraries 
#include <iostream>
#include <windows.h> 
//headers
#include "RunGame.h"
//namespaces
using namespace std;

//run the game
RunGame::RunGame() {
	
	//TODO map handler
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << "  " << 9 - i << " ";
		for (int j = 0; j < 10; j++) {
			mapArray[i][j] = 0;
			cout << mapArray[i][j] << " ";
		}
		cout << endl;
	}
}

//build the map
RunGame::mapHandler() {
	return 0;
}

//play the game
RunGame::playGame() {
	quitGame = false;
	
	//TODO input handler
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