//libraries
#include <windows.h> 
#include <iostream>
#include <time.h>
//headers
#include "StartGame.h"
//namespaces
using namespace std;
//class body
StartGame::StartGame() {}

//TODO
StartGame::graphicsHandler() {}

//TODO
StartGame::uiHandler() {}

//opening splash screen
StartGame::startScreen(int versionRelease, 
					   int versionInternal,
					   int versionAsset, 
					   int versionScript) {
	system("CLS");
	cout << "                                                          Trevor Haggerty & Zachary Drummond's    " << endl;
	cout << "   #############################################################################################  " << endl;
	cout << "        -             -                   -             -                       -                 " << endl;
	cout << "   ##  ##     ##  -  ####     ##   ########  ######        ####  ##  ##  ######   ####     ####   " << endl;
	cout << "   ## ##   - ## ##   ##  ##  ## ##    ##     ##          ##      ##  ##  ##      ##  ##   ##  ##  " << endl;
	cout << "   ####   -  #####   ####    #####    ##     ####   -   ##       ######  ####     ##       ##     " << endl;
	cout << "   ##  ##   ##   ##  ##  ## ##   ##   ##     ##         ##       ##  ##  ##         ##       ##   " << endl;
	cout << "   ##  ##   ##   ##  ##  ## ##   ##   ##     ##          ##      ##  ##  ##      ##  ##   ##  ##  " << endl;
	cout << "   ##  ## - ##   ##  ##  ## ##   ##   ##     ######        ####  ##  ##  ######   ####     ####   " << endl;
	cout << "       -                    -                      -            -                                 " << endl;
 	cout << "   #############################################################################################  " << endl;
	cout << "   version " << versionRelease << "." 
						  << versionInternal << "." 
						  << versionAsset << "." 
						  << versionScript << "\n\n\n";
	return 0;
}

//TODO
StartGame::inputHandler() {}

//game start menu
StartGame::startMenu() {
	
	//ask the player if they would like to play and read the results for a y,Y,n,or N
	while ((startMenuInput != 'y') && (startMenuInput != 'Y') && (startMenuInput != 'n') && (startMenuInput != 'N')) {
		cout << " Would you like to play (y/n) "<< endl;
		cin >> startMenuInput;
	}
	  
	//return value based on menu interaction
	system("CLS");
	if ((startMenuInput == 'y')||(startMenuInput == 'Y')) {
		return 1;
	} else {
		return 0; 
	}
}

//TODO
StartGame::outputHandler() {}






