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
	
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    } else {
        //Create window
        window = SDL_CreateWindow("Pig Benis", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			printf ("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		} else {
            //Get window surface
            screenSurface = SDL_GetWindowSurface(window);

            //Fill the surface white
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
            
            //Update the surface
            SDL_UpdateWindowSurface(window);

            //Wait two seconds
            SDL_Delay(2000);
        }
    }
	
/*	//start the game
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
*/
	
	//Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();	

	return 0;	
}