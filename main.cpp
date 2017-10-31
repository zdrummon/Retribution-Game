//libraries
//headers
#include "StartGame.h"
#include "MapGenerator.h"
#include "RunGame.h"
#include "Exitgame.h"
//namespaces
using namespace std;
//class body
int main() {
	
	//start the game
	StartGame StartGameObject;
	StartGameObject.graphicsHandler();
	StartGameObject.uiHandler();
	StartGameObject.startScreen(0,0,0,3);
	StartGameObject.startMenu();
	StartGameObject.inputHandler();
	StartGameObject.outputHandler();
	
	if (StartGameObject.startMenu() == 1) {	
		
		//generate the map
		MapGenerator MapGeneratorObject;
		//MapGeneratorObject.mapGeneration();
		
		//run the game
		RunGame RunGameObject;
		RunGameObject.playGame();
	
	}
	
	//exit the game
	ExitGame ExitGameObject;
	ExitGameObject.exitScreen();
	return 0;	
}