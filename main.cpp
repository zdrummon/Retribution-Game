//libraries
//headers
#include "StartGame.h"
#include "RunGame.h"
#include "Exitgame.h"
//namespaces
using namespace std;

int main() {
	//start the game
	StartGame StartGameObject;
	StartGameObject.startScreen(0,0,0,3);
	StartGameObject.startMenu();
	
	if (StartGameObject.startMenu() == 1) {	
		//handle the map
	//	MapHandler MapHandlerObject;
		
		//run the game
		RunGame RunGameObject;
		RunGameObject.mapHandler();
		RunGameObject.playGame();
	}
	
	//exit the game
	ExitGame ExitGameObject;
	ExitGameObject.exitScreen();
	return 0;	
}