// main.cpp for execution of the eventual code



#include <iostream>
#include <stdio.h>   
#include <windows.h> 

#include <stdlib.h>   
#include <time.h>  
#include <limits>  
#include <sstream>
//gui headers
#include "titleScreen.h"
//logic headers
#include "mapHandler.h"


using namespace std;

bool gameActive = true;
int playTicks = 0;
int maxGameTicks = 10;
int gameStartTime;







int main(){
	
	
	gameActive = displayTitleScreen(0,0,0,3); // display the title screen with version numbers
	
	gameStartTime = clock();
	srand (time(NULL));
	
	
	if (gameActive == true){
	
	
		//TODO: make initial map
		getUserMapData();
		
			
		Map firstMap;
		firstMap.fillMap(0,0);
		firstMap.fillMap(1,0);
		firstMap.printMap(0);
		firstMap.fillMapNoise(0,1);
		firstMap.printMap(0);
		firstMap.smoothMap(0,1,4);
		firstMap.printMap(1);
		firstMap.killLoners(1,1,3);
		firstMap.printMap(0);
		firstMap.smoothMap(0,1,4);
		firstMap.printMap(1);
		firstMap.smoothMap(0,1,3);
		firstMap.printMap(1);
		firstMap.killLoners(1,1,3);
		firstMap.printMap(1);
		firstMap.smoothMap(1,1,6);
		firstMap.printMap(1);
		
			system("pause");
		system("CLS");
		//--------BEGIN GAME----------------------------
		while (gameActive == true){
			firstMap.printMapFancy(1);
			/*
			---------------------code block for time monitoring and testing------------
			
			playTicks++;
			cout << "gameTicks = " <<playTicks<< "    gameTime = " <<clock()<< endl;
			if (playTicks >= maxGameTicks){
				gameActive = false;
			}
			cout << gameStartTime<< endl;
			cout << clock()<< endl;
			----------------------------------------------------------------------------
			*/
			gameActive = false;
		}
	}
	
	
	
	system("pause");
	displayEndScreen((clock()-gameStartTime )/1000); // display the title screen with version numbers
	return 0;
}







































