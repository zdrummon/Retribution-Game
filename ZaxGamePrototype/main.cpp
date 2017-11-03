//libraries
//headers
#include "StartGame.h"
#include "RunGame.h"
#include "Exitgame.h"
//namespaces
using namespace std;
//class body
int main() {
	
	//start the game
	StartGame StartGameObject;
	StartGameObject.startScreen(0,0,0,1);
	StartGameObject.startMenu();
	
	//run the game
	if (StartGameObject.startMenu() == 1) {	
		RunGame RunGameObject;
		RunGameObject.playGame();
	}
	
	//exit the game
	ExitGame ExitGameObject;
	ExitGameObject.exitScreen();
	return 0;	
}