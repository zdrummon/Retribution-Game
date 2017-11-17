#pragma once

//{---CONSTANTS
const int MAP_WIDTH = 10;
const int MAP_HEIGHT = 10;
const int TILE_WIDTH = 32;
const int TILE_HEIGHT = 32;
const int SCREEN_WIDTH = TILE_WIDTH * MAP_WIDTH;
const int SCREEN_HEIGHT = TILE_HEIGHT * MAP_HEIGHT;

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
	MAP_TILE_PLAYER,
	MAP_TILE_ENEMY,
    MAP_TILE_TOTAL
}; //}

//{---Variables
int logCount;
clock_t startTicker;
clock_t totalTicks;
double ticksInSeconds; 
int mapData[MAP_WIDTH][MAP_HEIGHT][2];
int playerPositionX;
int playerPositionY;
int enemyPositionX;
int enemyPositionY; //}

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
SDL_Surface* currentSurface = NULL; //}

//{---Function prototypes
void logEvents();
bool initSDLHandler();
bool mediaHandler();
void closeSDLHandler();
void runGame();
void mapMove(int moveX, int moveY);
void enemyMove();
void mapPopulator();
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
        windowHandler = SDL_CreateWindow ("Karate Chess 0.0.0.5", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		
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
	
	//Load floor surface
    mapSurfaces [MAP_TILE_PLAYER] = loadSurface ("player_character.bmp");    
	if (mapSurfaces [MAP_TILE_PLAYER] == NULL) {
    
		//{---LOG---failed to load player image
		logEvents();
		printf ("Failed to load player image!"); //}
        initSuccess = false;
    }
	
	//Load floor surface
    mapSurfaces [MAP_TILE_ENEMY] = loadSurface ("enemy_character.bmp");    
	if (mapSurfaces [MAP_TILE_ENEMY] == NULL) {
    
		//{---LOG---failed to load enemy image
		logEvents();
		printf ("Failed to load enemy image!"); //}
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
						mapMove (0,-1);
						enemyMove();
					break;
		
					case SDLK_DOWN:
						//{---LOG---down key pressed
						logEvents();
						printf ("down key pressed"); //}
						mapMove (0,1);
						enemyMove();
					break;
		
					case SDLK_LEFT:
						//{---LOG---left key pressed
						logEvents();
						printf ("left key pressed"); //}	
						mapMove (-1,0);
						enemyMove();
					break;
		
					case SDLK_RIGHT:
						//{---LOG---right key pressed
						logEvents();
						printf ("right key pressed"); //}	
						mapMove (1,0);
						enemyMove();
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

void mapMove (int moveX, int moveY) {

	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGHT; j++) {
			
			
			
			if ((mapData[i][j][1] == MAP_TILE_PLAYER) && 
				(mapData[i + moveX][j + moveY][0] != MAP_TILE_WALL) &&
				(mapData[i + moveX][j + moveY][1] != MAP_TILE_ENEMY)) {
				
				mapData[i][j][1] = NULL;
				mapData[i + moveX][j + moveY][1] = MAP_TILE_PLAYER;
				playerPositionX = i + moveX;
				playerPositionY = j + moveY;
				i = MAP_WIDTH;
				j = MAP_HEIGHT;
			
			} 
			if ((mapData[i][j][1] == MAP_TILE_PLAYER) && (mapData[i + moveX][j + moveY][1] == MAP_TILE_ENEMY)) {
				
				mapData[i + moveX][j + moveY][1] = NULL;
				i = MAP_WIDTH;
				j = MAP_HEIGHT;
			}	
		}
	}
}

void enemyMove() {
	
	int moveX = 0;
	int moveY = 0;
	
	int moveToPlayer = rand() % 2;
	int moveRandomDirection = rand() % 5;
	
	if (moveToPlayer == 0) {
		if (moveRandomDirection == 0) {
			
			moveX = 0;
			moveY = -1;
			
		} else if (moveRandomDirection == 1) {
		
			moveX = 1;
			moveY = 0;
		
		} else if (moveRandomDirection == 2) {
		
			moveX = 0;
			moveY = 1;		
		
		} else if (moveRandomDirection == 3) {

			moveX = -1;
			moveY = 0;

		} else if (moveRandomDirection == 4) {
		
			moveX = 0;
			moveY = 0;
		}
	
	} else {
		
		for (int i = 0; i < MAP_WIDTH; i++) {
			for (int j = 0; j < MAP_HEIGHT; j++) {
				if (mapData[i][j][1] == MAP_TILE_ENEMY) {
					enemyPositionX = i;
					enemyPositionY = j;
				}
			}
		}
		
		if (playerPositionX > enemyPositionX) {
			
			moveX = 1;
			moveY = 0;
			
		} else if (playerPositionX < enemyPositionX) {
		
			moveX = -1;
			moveY = 0;
		
		} else if (playerPositionY > enemyPositionY) {
		
			moveX = 0;
			moveY = 1;		
		
		} else if (playerPositionY < enemyPositionY) {

			moveX = 0;
			moveY = -1;

		}
	}
	
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGHT; j++) {
			if ((mapData[i][j][1] == MAP_TILE_ENEMY) && 
				(mapData[i + moveX][j + moveY][0] != MAP_TILE_WALL) &&
				(mapData[i + moveX][j + moveY][1] != MAP_TILE_PLAYER)) {
					
				mapData[i][j][1] = NULL;
				mapData[i + moveX][j + moveY][1] = MAP_TILE_ENEMY;
				i = MAP_WIDTH;
				j = MAP_HEIGHT;
				
			} else if ((mapData[i][j][1] == MAP_TILE_ENEMY) && 
					   (mapData[i + moveX][j + moveY][1] == MAP_TILE_PLAYER)) {
				
				mapData[i + moveX][j + moveY][1] = NULL;
				i = MAP_WIDTH;
				j = MAP_HEIGHT;
			}
		}
	}
}

//BROKEN due to visibility
//void eventOrganizer() { }

void mapPopulator() {
	
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGHT; j++) {
			
			if ( (i == 0 || i == MAP_WIDTH - 1) ||
				 (j == 0 || j == MAP_HEIGHT - 1) ) {
					 
				mapData[i][j][0] = MAP_TILE_WALL;
		
			} else {
			
				mapData[i][j][0] = MAP_TILE_FLOOR;
			}
		}
	}
	
	mapData[MAP_WIDTH / 2][MAP_HEIGHT / 2][1] = MAP_TILE_PLAYER;
	mapData[MAP_WIDTH / 4][MAP_HEIGHT / 4][1] = MAP_TILE_ENEMY;
}

void mapGraphicsPrinter() {

	SDL_Rect imageTransform;
	
	//Apply the map array stretched
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGHT; j++) {
			
			if (mapData[i][j][1] == MAP_TILE_PLAYER) {
				
				currentSurface = mapSurfaces [MAP_TILE_PLAYER];
				
			} else if (mapData[i][j][1] == MAP_TILE_ENEMY) {
				
				currentSurface = mapSurfaces [MAP_TILE_ENEMY];
				
			} else if (mapData[i][j][0] == MAP_TILE_WALL) {
				
				currentSurface = mapSurfaces [MAP_TILE_WALL]; 	
				
			} else if (mapData[i][j][0] == MAP_TILE_FLOOR) {
				
				currentSurface = mapSurfaces [MAP_TILE_FLOOR];
				
			} else {
				
				//{---LOG---failed to load default image
				logEvents();
				printf ("Map data missing at %i, %i", i, j); //}
			}
			
			//Current image positioner
			imageTransform.x = i * TILE_WIDTH;
			imageTransform.y = j * TILE_HEIGHT;
			imageTransform.w = TILE_WIDTH;
			imageTransform.h = TILE_HEIGHT;
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

