#pragma once

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
    
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

//Starts up SDL and creates window
bool initSDL() {
	
	//Initialization flag
    bool success = true;
	
    //Initialize SDL
    if (SDL_Init (SDL_INIT_VIDEO) < 0) {
		
		printf ("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
		
    } else {
        
		//Create window
        gWindow = SDL_CreateWindow ("makefile compile test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		
		if (gWindow == NULL) {
			
			printf ("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
			
		} else {
			
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface (gWindow);
        }
    }
	
	return success;
}

//Loads media
bool loadMedia() {
	
	//media flag
    bool success = true;
	
	//Load splash image
    gHelloWorld = SDL_LoadBMP ("oh_no.bmp");
    
	if (gHelloWorld == NULL) {
		
		printf ("Unable to load image %s! SDL Error: %s\n", "oh_no.bmp", SDL_GetError());
		success = false;
    }
	
	return success;
}

//Frees media and shuts down SDL
void closeSDL() {
	
	//Deallocate surface
	SDL_FreeSurface (gHelloWorld);
	gHelloWorld = NULL;
	
	//Destroy window
	SDL_DestroyWindow (gWindow);
	gWindow = NULL;
	
	//Quit SDL subsystems
	SDL_Quit();
}

