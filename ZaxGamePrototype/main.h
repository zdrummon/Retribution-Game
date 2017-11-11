#pragma once

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Key press surfaces constants
enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

//Declare debug log containers
int logCount;
clock_t startTicker;
clock_t totalTicks;
double ticksInSeconds;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
    
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;
	
//Print logged event time
void logEvents() {
	
	++logCount;
	totalTicks = clock() - startTicker;
	ticksInSeconds = totalTicks / (double) CLOCKS_PER_SEC;
	printf ("\n [Event %.6i - %.3f seconds]: ", logCount, ticksInSeconds);
}

//Starts up SDL and creates window
bool initSDL() {
	
	//Initialization flag
    bool success = true;
	
    //Initialize SDL
    if (SDL_Init (SDL_INIT_VIDEO) < 0) {
		
		//---LOG	
		logEvents();
		printf ("SDL could not initialize! SDL_Error: %s", SDL_GetError());
		success = false;
		
    } else {
        
		//Create window
        gWindow = SDL_CreateWindow ("SOFTWARE I WROTE WHILE POOPING", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		
		if (gWindow == NULL) {
			
			//---LOG	
			logEvents();
			printf ("Window could not be created! SDL_Error: %s", SDL_GetError());
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
	
	//Media flag
    bool success = true;
	
	//Load splash image
    gHelloWorld = SDL_LoadBMP ("oh_no.bmp");
    
	if (gHelloWorld == NULL) {
		
		//---LOG	
		logEvents();
		printf ("\n Unable to load image %s! SDL Error: %s", "oh_no.bmp", SDL_GetError());
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