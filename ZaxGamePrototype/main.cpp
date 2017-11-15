//libraries
#include <SDL.h>
#include <SDL_image.h>
#include <ctime>
#include <stdio.h>
#include <string>
//headers
#include "main.h"
#include "StartGame.h"
#include "RunGame.h"
#include "Exitgame.h"
//namespaces
using namespace std;

//main class body
int main (int argc, char* args[]) {
	
	//{---LOG---start debug log
	startTicker = clock();
	logCount = 0;
	printf ("\n START DEBUG LOG\n =============================="); //}
	
	//Starts up SDL and creates window 
	if (!initSDL()) {
		
		//{---LOG---failed to initialize SDL	
		logEvents();
		printf ("failed to initialize SDL!"); //}
	
	} else {
		
		//Loads media
		if (!loadMedia()) {
			
			//{---LOG---failed to load media	
			logEvents();
			printf ("failed to load media!"); //}
			
		} else {
			
			//Main loop flag
            bool quit = false;
            
			//Event handler
            SDL_Event e;
			
			//Set default current surface
            gCurrentSurface = gKeyPressSurfaces [KEY_PRESS_SURFACE_DEFAULT];
						
			//While application is running
            while (!quit) {
				
				//Handle events on queue
                while (SDL_PollEvent (&e) != 0) {
					
                    //User requests quit
                    if (e.type == SDL_QUIT) {
						
						quit = true;	
						
						//{---LOG---quit flag has been set
						logEvents();
						printf ("quit flag has been set"); //}
                    }
					
					//User presses a key
                    if (e.type == SDL_KEYDOWN) {
						
						//Select surfaces based on key press
                        switch (e.key.keysym.sym) {
                            
							case SDLK_UP:
							//{---LOG---up key pressed
							logEvents();
							printf ("up key pressed"); //}
                            gCurrentSurface = gKeyPressSurfaces [KEY_PRESS_SURFACE_UP];
                            break;

                            case SDLK_DOWN:
							//{---LOG---down key pressed
							logEvents();
							printf ("down key pressed"); //}							
                            gCurrentSurface = gKeyPressSurfaces [KEY_PRESS_SURFACE_DOWN];
                            break;

                            case SDLK_LEFT:
							//{---LOG---left key pressed
							logEvents();
							printf ("left key pressed"); //}							
                            gCurrentSurface = gKeyPressSurfaces [KEY_PRESS_SURFACE_LEFT];
                            break;

                            case SDLK_RIGHT:
							//{---LOG---right key pressed
							logEvents();
							printf ("right key pressed"); //}							
                            gCurrentSurface = gKeyPressSurfaces [KEY_PRESS_SURFACE_RIGHT];
                            break;

                            default:						
                            gCurrentSurface = gKeyPressSurfaces [KEY_PRESS_SURFACE_DEFAULT];
                            break;
                        }
                    }
                }
				
				//Apply the image stretched
				SDL_Rect stretchRect;
				stretchRect.x = 0;
				stretchRect.y = 0;
				stretchRect.w = SCREEN_WIDTH;
				stretchRect.h = SCREEN_HEIGHT;
				SDL_BlitScaled (gStretchedSurface, NULL, gScreenSurface, &stretchRect);
			
				//Update the surface
				SDL_UpdateWindowSurface (gWindow);
			
			}
		}
	}
		
//{ OLD PROGRAM
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
//}
	
	//Frees media and shuts down SDL
	void closeSDL();
	
	//{---LOG---program has ended
	logEvents();
	printf ("program has ended\n ==============================\n END DEBUG LOG\n"); //}

	return 0;	
}