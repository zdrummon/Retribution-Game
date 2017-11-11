//libraries
#include <SDL.h>
#include <ctime>
#include <string>
#include <stdio.h>
//headers
#include "main.h"
#include "StartGame.h"
#include "RunGame.h"
#include "Exitgame.h"
//namespaces
using namespace std;

//main class body
int main (int argc, char* args[]) {
	
	//Start debug log
	startTicker = clock();
	logCount = 0;
	printf ("\n START DEBUG LOG\n ==============================");
	
	//Starts up SDL and creates window
	if (!initSDL()) {
		
		//---LOG	
		logEvents();
		printf ("Failed to initialize!");
	
	} else {
		
		//Loads media
		if (!loadMedia()) {
			
			//---LOG	
			logEvents();
			printf ("Failed to load media!");
			
		} else {
			
			//Main loop flag
            bool quit = false;
            
			//Event handler
            SDL_Event e;
						
			//While application is running
            while (!quit) {
				
				//Handle events on queue
                while (SDL_PollEvent (&e) != 0) {
					
                    //User requests quit
                    if (e.type == SDL_QUIT) {
						
						quit = true;	
						
						//---LOG
						logEvents();
						printf ("You quit the program");
                    }
					
					//User presses a key
                    if (e.type == SDL_KEYDOWN) {

						//---LOG
						logEvents();
						printf ("You pressed a key");
                    }
                }
				
				//Apply the image
				SDL_BlitSurface (gHelloWorld, NULL, gScreenSurface, NULL);
			
				//Update the surface
				SDL_UpdateWindowSurface (gWindow);
			
			}
		}
	}
		
//	//start the game
//	StartGame StartGameObject;
//	StartGameObject.startScreen(0,0,0,1);
//	StartGameObject.startMenu();
//	
//	//run the game
//	if (StartGameObject.startMenu() == 1) {	
//		RunGame RunGameObject;
//		RunGameObject.playGame();
//	}
//	
//	//exit the game
//	ExitGame ExitGameObject;
//	ExitGameObject.exitScreen();
	
	//Frees media and shuts down SDL
	void closeSDL();
	
	//---LOG
	logEvents();
	printf ("The program has ended\n ==============================\n END DEBUG LOG\n");

	return 0;	
}