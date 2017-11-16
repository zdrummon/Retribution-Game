#pragma once

//{---CONSTANTS
const int SCREEN_WIDTH = 320;
const int SCREEN_HEIGHT = 320;

const int MAP_WIDTH = 10;
const int MAP_HEIGHT = 10;

enum KeyPress {
    KEY_PRESS_DEFAULT,
    KEY_PRESS_UP,
    KEY_PRESS_DOWN,
    KEY_PRESS_LEFT,
    KEY_PRESS_RIGHT,
    KEY_PRESS_TOTAL
};

enum MapTile {
    MAP_TILE_DEFAULT,
    MAP_TILE_WALL,
    MAP_TILE_FLOOR,
    MAP_TILE_TOTAL
}; //}

//{---Variables
int logCount;
clock_t startTicker;
clock_t totalTicks;
double ticksInSeconds; 
int mapData[MAP_WIDTH][MAP_HEIGHT]; //}

//{---Pointers and objects
//Loads individual image
SDL_Surface* loadSurface (std::string path);

//The window we'll be rendering to
SDL_Window* windowHandler = NULL;
    
//The surface contained by the window
SDL_Surface* windowSurface = NULL;

//The images that correspond to a keypress
SDL_Surface* mapSurfaces [MAP_TILE_TOTAL];

//Current displayed image
SDL_Surface* currentSurface = NULL; 

//}

//{---Function prototypes
void logEvents();
bool initSDLHandler();
bool mediaHandler();
void closeSDLHandler();
void runGame();
void mapPopulator();
void mapGraphicsPopulator();
void mapGraphicsPrinter(); //}

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
    mapSurfaces [MAP_TILE_DEFAULT] = loadSurface ("empty_space.bmp");
    
	if (mapSurfaces [MAP_TILE_DEFAULT] == NULL) {
    
		//{---LOG---failed to load default image
		logEvents();
		printf ("Failed to load default image!"); //}
		
        initSuccess = false;
    }

    //Load wall surface
    mapSurfaces [MAP_TILE_WALL] = loadSurface ("stone_space.bmp");

    if (mapSurfaces [MAP_TILE_WALL] == NULL) {
    
		//{---LOG---failed to load wall image
		logEvents();
		printf ("Failed to load wall image!"); //}
		
        initSuccess = false;
    }

    //Load floor surface
    mapSurfaces [MAP_TILE_FLOOR] = loadSurface ("dirt_space.bmp");
    
	if (mapSurfaces [MAP_TILE_FLOOR] == NULL) {
    
		//{---LOG---failed to load floor image
		logEvents();
		printf ("Failed to load floor image!"); //}
		
        initSuccess = false;
    }
	
	return initSuccess;
}

void closeSDLHandler() {
	
	//Deallocate surface
	for (int i = 0; i < MAP_TILE_TOTAL; ++i) {
		SDL_FreeSurface (mapSurfaces [i]);
		mapSurfaces[i] = NULL;
	}	
	
	SDL_DestroyWindow (windowHandler);
	windowHandler = NULL;
	
	SDL_Quit();
}

void runGame() {
	
    bool quitFlag = false;
	
	mapPopulator();
	
	SDL_Event eventHandler;

    while (!quitFlag) {
		
		//Handle events on queue
        while (SDL_PollEvent (&eventHandler) != 0) {
			//User requests quit
			if (eventHandler.type == SDL_QUIT) {
				
				quitFlag = true;	
				
				//{---LOG---quit flag has been set
				logEvents();
				printf ("quit flag has been set"); //}
			}
			
			//User presses a key
			if (eventHandler.type == SDL_KEYDOWN) {
				
				//Select surfaces based on key press
				switch (eventHandler.key.keysym.sym) {
					
					case SDLK_UP:
						//{---LOG---up key pressed
						logEvents();
						printf ("up key pressed"); //}
					break;
		
					case SDLK_DOWN:
						//{---LOG---down key pressed
						logEvents();
						printf ("down key pressed"); //}	
					break;
		
					case SDLK_LEFT:
						//{---LOG---left key pressed
						logEvents();
						printf ("left key pressed"); //}	
					break;
		
					case SDLK_RIGHT:
						//{---LOG---right key pressed
						logEvents();
						printf ("right key pressed"); //}	
					break;
		
					default:	
						//empty
					break;
				}
			}	
		}
		
		mapGraphicsPrinter();	
	}
}

//BROKEN due to visibility
//void eventOrganizer() { }

void mapPopulator() {
	
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGHT; j++) {
			
			if ( (i == 0 || i == MAP_WIDTH - 1) ||
				 (j == 0 || j == MAP_HEIGHT - 1) ) {
					 
				mapData[i][j] = MAP_TILE_WALL;
		
			} else {
			
				mapData[i][j] = MAP_TILE_FLOOR;
			}
		}
	}
}

void mapGraphicsPrinter() {

	SDL_Rect imageTransform;
	
	//Apply the map array stretched
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGHT; j++) {
			
			if (mapData[i][j] == MAP_TILE_DEFAULT) {
				
				currentSurface = mapSurfaces [MAP_TILE_DEFAULT];
				
			} else if (mapData[i][j] == MAP_TILE_WALL) {
				
				currentSurface = mapSurfaces [MAP_TILE_WALL]; 	
				
			} else if (mapData[i][j] == MAP_TILE_FLOOR) {
				
				currentSurface = mapSurfaces [MAP_TILE_FLOOR];
				
			} else {
				
				//{---LOG---failed to load default image
				logEvents();
				printf ("Map data missing at %i, %i", i, j); //}
			}
			
			//Current image positioner
			imageTransform.x = i * 32;
			imageTransform.y = j * 32;
			imageTransform.w = 32;
			imageTransform.h = 32;
			SDL_BlitScaled (currentSurface, NULL, windowSurface, &imageTransform);
			SDL_UpdateWindowSurface (windowHandler);
		}
	}
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