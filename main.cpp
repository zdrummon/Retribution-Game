// main.cpp for execution of the eventual code



#include <iostream>
#include <stdio.h>    
#include <stdlib.h>   
#include <time.h>  
#include <limits>
#include "titleScreen.h"
#include "mapHandler.h"


using namespace std;

bool gameActive = true;
int playTicks = 0;
int maxGameTicks = 10;

int gameStartTime;

int main(){
//declare map values
	srand (time(NULL));
	int axisx = 0;
	int axisy = 0;
	int mapSeed = 0;
	int roomCenterX = 0;
	int roomCenterY = 0;
	int roomWidth = 0;
	int roomHeight = 0;




	
	gameActive = displayTitleScreen(0,0,0,2); // display the title screen with version numbers
	gameStartTime = clock();
	
	
	
	if (gameActive == true){
	
	
		//TODO: make initial map
		while((axisx <= 19)||(axisx >= 41)){
			
		cout << "choose a map width \n 20-40\n please no fucking letters"<<endl;

		cin >> axisx;
		
		}
		while((axisy <= 19)||(axisy >= 41)){
		cout << "choose a map height \n 20-40\n please no fucking letters"<<endl;

		cin >> axisy;
		}
		
		cout << "choose a map seed\n please no fucking letters\n 0 for random"<<endl;

		cin >> mapSeed;
		 if (mapSeed == 0){
			 mapSeed = rand();	 
		 }
		srand (mapSeed);
		
		cout << mapSeed<<endl;
		int terrainmap[axisx][axisy][3];
	
	
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







































