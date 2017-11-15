#pragma once

//{---CONSTANTS
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
enum KeyPressSurfaces
{
    KEY_PRESS_DEFAULT,
    KEY_PRESS_UP,
    KEY_PRESS_DOWN,
    KEY_PRESS_LEFT,
    KEY_PRESS_RIGHT,
    KEY_PRESS_TOTAL
}; //}

//{---Variables
int logCount;
clock_t startTicker;
clock_t totalTicks;
double ticksInSeconds; //}

//{---Handler pointers
//Loads individual image
SDL_Surface* loadSurface (std::string path);

//The window we'll be rendering to
SDL_Window* windowHandler = NULL;
    
//The surface contained by the window
SDL_Surface* windowSurface = NULL;

//The images that correspond to a keypress
SDL_Surface* keySurfaces [KEY_PRESS_TOTAL];

//Current displayed image
SDL_Surface* currentSurface = NULL; //}

//{---Function prototypes
bool initSDLHandler();
bool mediaHandler();
void closeSDLHandler(); //}

//{---Functions
void logEvents() {
	
	++logCount;
	totalTicks = clock() - startTicker;
	ticksInSeconds = totalTicks / (double) CLOCKS_PER_SEC;
	printf ("\n [Event %.6i - %.3f seconds]: ", logCount, ticksInSeconds);
}

bool initSDLHandler() {
	
    bool initSuccess = true;
	
    //Initialize SDL
    if (SDL_Init (SDL_INIT_VIDEO) < 0) {
		
		initSuccess = false;
		
		//{---LOG---SDL could not initialize	
		logEvents();
		printf ("SDL could not initialize! SDL_Error: %s", SDL_GetError()); //}
		
    } else {
        
		//Create window
        windowHandler = SDL_CreateWindow ("SOFTWARE I WROTE WHILE POOPING", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		
		if (windowHandler == NULL) {

			initSuccess = false;
		
			//{---LOG---window could not be created	
			logEvents();
			printf ("window could not be created! SDL_Error: %s", SDL_GetError()); //}
			
		} else {

//            //Initialize PNG loading
//            int imgFlags = IMG_INIT_PNG;
//            if (!(IMG_Init (imgFlags) & imgFlags)) {
//				
//				//{---LOG---SDL_image could not initialize	
//				logEvents();
//                printf( "SDL_image could not initialize! SDL_image Error: %s", IMG_GetError() ); //}
//
//                initSuccess = false;
//
//			} else {
//				
                //Get window surface
                windowSurface = SDL_GetWindowSurface (windowHandler);
            
//			}
        }
    }
	
	return initSuccess;
}

bool mediaHandler() {
	
    bool initSuccess = true;
	
    //Load default surface
    keySurfaces [KEY_PRESS_DEFAULT] = loadSurface ("default.bmp");
    
	if (keySurfaces [KEY_PRESS_DEFAULT] == NULL) {
    
		//{---LOG---failed to load default image
		logEvents();
		printf ("Failed to load default image!"); //}
		
        initSuccess = false;
    }

    //Load up surface
    keySurfaces [KEY_PRESS_UP] = loadSurface ("up.bmp");

    if (keySurfaces [KEY_PRESS_UP] == NULL) {
    
		//{---LOG---failed to load up image
		logEvents();
		printf ("Failed to load up image!"); //}
		
        initSuccess = false;
    }

    //Load down surface
    keySurfaces [KEY_PRESS_DOWN] = loadSurface ("down.bmp");
    
	if (keySurfaces [KEY_PRESS_DOWN] == NULL) {
    
		//{---LOG---failed to load down image
		logEvents();
		printf ("Failed to load down image!"); //}
		
        initSuccess = false;
    }

    //Load left surface
    keySurfaces [KEY_PRESS_LEFT] = loadSurface ("left.bmp");

    if (keySurfaces [KEY_PRESS_LEFT] == NULL) {
    
		//{---LOG---failed to load left image
		logEvents();
		printf ("Failed to load left image!"); //}
		
        initSuccess = false;
    }

    //Load right surface
    keySurfaces [KEY_PRESS_RIGHT] = loadSurface ("right.bmp");

    if (keySurfaces [KEY_PRESS_RIGHT] == NULL) {
    
		//{---LOG---failed to load right image
		logEvents();
		printf ("Failed to load right image!"); //}
		
        initSuccess = false;
    }
	
	return initSuccess;
}

//Loads individual image
SDL_Surface* loadSurface (std::string path) {
	
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;
    
	//Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP (path.c_str());
    
	if (loadedSurface == NULL) {
        
		//{---LOG---unable to load image
		logEvents();
		printf ("Unable to load image %s! SDL Error: %s", path.c_str(), SDL_GetError()); //}
    
	} else {
		
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface (loadedSurface, windowSurface->format, NULL);
		if (optimizedSurface == NULL) {
			
			//{---LOG---unable to optimize image
			logEvents();
			printf ("Unable to optimize image %s! SDL Error: %s", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface (loadedSurface);
	}

	return optimizedSurface;
}

void closeSDLHandler() {
	
	//Deallocate surface
	for (int i = 0; i < KEY_PRESS_TOTAL; ++i) {
		SDL_FreeSurface (keySurfaces [i]);
		keySurfaces[i] = NULL;
	}	
	
	SDL_DestroyWindow (windowHandler);
	windowHandler = NULL;
	
	SDL_Quit();
} //}