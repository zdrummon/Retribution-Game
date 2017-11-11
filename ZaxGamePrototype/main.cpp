//libraries
#include <SDL.h>
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
	
	//Starts up SDL and creates window
	if (!initSDL()) {
		
		printf ("Failed to initialize!\n");
	
	} else {
		
		//Loads media
		if (!loadMedia()) {
			
			printf ("Failed to load media!\n");
			
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

	return 0;	
}