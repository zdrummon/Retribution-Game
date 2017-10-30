//libraries
#include <windows.h> 
#include <iostream>
#include <time.h>
//headers
#include "StartGame.h"
//namespaces
using namespace std;

StartGame::StartGame() {}

//opening splash screen on program run
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

StartGame::startMenu() {
	
	//ask the player if they would like to play and read the results for a y,Y,n,or N
	while ((startMenuInput != 'y') && (startMenuInput != 'Y') && (startMenuInput != 'n') && (startMenuInput != 'N')) {
		cout << " Would you like to play (y/n) "<< endl;
		cin >> startMenuInput;
	}
	  
	//if the player said yes set the bool to yes telling the game to start
	system("CLS");
	if ((startMenuInput == 'y')||(startMenuInput == 'Y')) {
		return 1;
	} else {
		return 0; 
	}
}






