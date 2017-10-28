// main.cpp for execution of the eventual code



#include <iostream>
#include <stdio.h>    
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
	

	gameActive = displayTitleScreen(0,0,0,2); // display the title screen with version numbers
	gameStartTime = clock();
	srand (time(NULL));
	
	
	if (gameActive == true){
	
	
		//TODO: make initial map
		getUserMapData();
		
			
		Map firstMap;
		//firstMap.fillMap(1,0); not working Q!Q!Q!Q!
	
		//--------BEGIN GAME----------------------------
		while (gameActive == true){
	
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
	
	
	
	
	displayEndScreen((clock()-gameStartTime )/1000); // display the title screen with version numbers
	return 0;
}







































