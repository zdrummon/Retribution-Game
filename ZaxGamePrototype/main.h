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

//Debug log vars
int logCount;
clock_t startTicker;
clock_t totalTicks;
double ticksInSeconds;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image
SDL_Surface* loadSurface (std::string path);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
    
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces [KEY_PRESS_SURFACE_TOTAL];

//Current displayed image
SDL_Surface* gStretchedSurface = NULL;


	
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
		
		success = false;
		
		//{---LOG---SDL could not initialize	
		logEvents();
		printf ("SDL could not initialize! SDL_Error: %s", SDL_GetError()); //}
		
    } else {
        
		//Create window
        gWindow = SDL_CreateWindow ("SOFTWARE I WROTE WHILE POOPING", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		
		if (gWindow == NULL) {

			success = false;
		
			//{---LOG---window could not be created	
			logEvents();
			printf ("window could not be created! SDL_Error: %s", SDL_GetError()); //}
			
		} else {

            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init (imgFlags) & imgFlags)) {
				
				//{---LOG---SDL_image could not initialize	
				logEvents();
                printf( "SDL_image could not initialize! SDL_image Error: %s", IMG_GetError() );

                success = false;

			} else {
				
                //Get window surface
                gScreenSurface = SDL_GetWindowSurface( gWindow );
            
			}
        }
    }
	
	return success;
}

//Loads media
bool loadMedia() {
	
	//Media flag
    bool success = true;
	
    //Load default surface
    gKeyPressSurfaces [KEY_PRESS_SURFACE_DEFAULT] = loadSurface ("default.bmp");
    
	if (gKeyPressSurfaces [KEY_PRESS_SURFACE_DEFAULT] == NULL) {
    
		//{---LOG---failed to load default image
		logEvents();
		printf ("Failed to load default image!"); //}
		
        success = false;
    }

    //Load up surface
    gKeyPressSurfaces [KEY_PRESS_SURFACE_UP] = loadSurface ("up.bmp");

    if (gKeyPressSurfaces [KEY_PRESS_SURFACE_UP] == NULL) {
    
		//{---LOG---failed to load up image
		logEvents();
		printf ("Failed to load up image!"); //}
		
        success = false;
    }

    //Load down surface
    gKeyPressSurfaces [KEY_PRESS_SURFACE_DOWN] = loadSurface ("down.bmp");
    
	if (gKeyPressSurfaces [KEY_PRESS_SURFACE_DOWN] == NULL) {
    
		//{---LOG---failed to load down image
		logEvents();
		printf ("Failed to load down image!"); //}
		
        success = false;
    }

    //Load left surface
    gKeyPressSurfaces [KEY_PRESS_SURFACE_LEFT] = loadSurface ("left.bmp");

    if (gKeyPressSurfaces [KEY_PRESS_SURFACE_LEFT] == NULL) {
    
		//{---LOG---failed to load left image
		logEvents();
		printf ("Failed to load left image!"); //}
		
        success = false;
    }

    //Load right surface
    gKeyPressSurfaces [KEY_PRESS_SURFACE_RIGHT] = loadSurface ("right.bmp");

    if (gKeyPressSurfaces [KEY_PRESS_SURFACE_RIGHT] == NULL) {
    
		//{---LOG---failed to load right image
		logEvents();
		printf ("Failed to load right image!"); //}
		
        success = false;
    }
	
	return success;
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
		optimizedSurface = SDL_ConvertSurface (loadedSurface, gScreenSurface->format, NULL);
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

//Frees media and shuts down SDL
void closeSDL() {
	
	//Deallocate surface
	for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i) {
		SDL_FreeSurface (gKeyPressSurfaces [i]);
		gKeyPressSurfaces[i] = NULL;
	}	
	
	//Destroy window
	SDL_DestroyWindow (gWindow);
	gWindow = NULL;
	
	//Quit SDL subsystems
	SDL_Quit();
}

