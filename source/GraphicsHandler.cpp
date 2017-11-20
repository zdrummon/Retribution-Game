//libraries
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
//headers
#include "LogHandler.h"

GraphicsHandler::GraphicsHandler() {}	
	
bool initSDLHandler() {
	
    bool initSuccess = true;
	
    //Initialize SDL
    if (SDL_Init (SDL_INIT_VIDEO) < 0) {
		
		initSuccess = false;
		
		//{---LOG---SDL could not initialize	
		LogHandler::logEvents();
		printf ("SDL could not initialize! SDL_Error: %s", SDL_GetError()); //}
		
    } else {
        
		//Create window
        windowHandler = SDL_CreateWindow ("Karate Chess 0.0.0.5", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		
		if (windowHandler == NULL) {

			initSuccess = false;
		
			//{---LOG---window could not be created	
			LogHandler::logEvents();
			printf ("window could not be created! SDL_Error: %s", SDL_GetError()); //}
			
		} else {

//            //Initialize PNG loading
//            int imgFlags = IMG_INIT_PNG;
//            if (!(IMG_Init (imgFlags) & imgFlags)) {
//				
//				//{---LOG---SDL_image could not initialize	
//				LogHandler::logEvents();
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
		LogHandler::logEvents();
		printf ("Failed to load default image!"); //}
        initSuccess = false;
    }

    //Load wall surface
    mapSurfaces [MAP_TILE_WALL] = loadSurface ("stone_space.bmp");
    if (mapSurfaces [MAP_TILE_WALL] == NULL) {
    
		//{---LOG---failed to load wall image
		LogHandler::logEvents();
		printf ("Failed to load wall image!"); //}
        initSuccess = false;
    }

    //Load floor surface
    mapSurfaces [MAP_TILE_FLOOR] = loadSurface ("dirt_space.bmp");    
	if (mapSurfaces [MAP_TILE_FLOOR] == NULL) {
    
		//{---LOG---failed to load floor image
		LogHandler::logEvents();
		printf ("Failed to load floor image!"); //}
        initSuccess = false;
    }
	
	//Load floor surface
    mapSurfaces [MAP_TILE_PLAYER] = loadSurface ("player_character.bmp");    
	if (mapSurfaces [MAP_TILE_PLAYER] == NULL) {
    
		//{---LOG---failed to load player image
		LogHandler::logEvents();
		printf ("Failed to load player image!"); //}
        initSuccess = false;
    }
	
	//Load floor surface
    mapSurfaces [MAP_TILE_ENEMY] = loadSurface ("enemy_character.bmp");    
	if (mapSurfaces [MAP_TILE_ENEMY] == NULL) {
    
		//{---LOG---failed to load enemy image
		LogHandler::logEvents();
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

void mapGraphicsPrinter() {

	SDL_Rect imageTransform;
	
	//Apply the map array stretched
	for (int i = 0; i < MAP_WIDTH_SET; i++) {
		for (int j = 0; j < MAP_HEIGHT_SET; j++) {
			
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
				LogHandler::logEvents();
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
		LogHandler::logEvents();
		printf ("Unable to load image %s! SDL Error: %s", path.c_str(), SDL_GetError()); //}
	
	} else {
		
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface (loadedSurface, windowSurface->format, NULL);
		if (optimizedSurface == NULL) {
			
			//{---LOG---unable to optimize image
			LogHandler::logEvents();
			printf ("Unable to optimize image %s! SDL Error: %s", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface (loadedSurface);
	}

	return optimizedSurface;
}