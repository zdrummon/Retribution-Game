#pragma once

#include "LogHandler.h"
//#include "GraphicsHandler.h"

//{---CONSTANTS
enum KeyPress {
    KEY_PRESS_DEFAULT,
    KEY_PRESS_UP,
    KEY_PRESS_DOWN,
    KEY_PRESS_LEFT,
    KEY_PRESS_RIGHT,
    KEY_PRESS_TOTAL
};

//enum MapTile {
//  MAP_TILE_DEFAULT,
//  MAP_TILE_WALL,
//	MAP_TILE_FLOOR,
//	MAP_TILE_PLAYER,
//	MAP_TILE_ENEMY,
//  MAP_TILE_TOTAL
//}; //}

const int MAP_WIDTH=10;
const int MAP_HEIGHT=10;

//{---Variables


int mapData[MAP_WIDTH][MAP_HEIGHT][2];
int playerPositionX;
int playerPositionY;
int enemyPositionX;
int enemyPositionY; //}



//{---Function prototypes

bool initSDLHandler();
bool mediaHandler();
void closeSDLHandler();
void runGame();
void mapMove(int moveX, int moveY);
void enemyMove();
void mapPopulator();
void mapGraphicsPrinter(); //}

//{---Functions

/*
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
				LogHandler::logEvents();
				printf ("quit flag has been set"); //}
			}
			
			//User presses a key
			if (eventHandler.type == SDL_KEYDOWN) {
				
				//Select surfaces based on key press
				switch (eventHandler.key.keysym.sym) {
					
					case SDLK_UP:
						//{---LOG---up key pressed
						LogHandler::logEvents();
						printf ("up key pressed"); //}
						mapMove (0,-1);
						enemyMove();
					break;
		
					case SDLK_DOWN:
						//{---LOG---down key pressed
						LogHandler::logEvents();
						printf ("down key pressed"); //}
						mapMove (0,1);
						enemyMove();
					break;
		
					case SDLK_LEFT:
						//{---LOG---left key pressed
						LogHandler::logEvents();
						printf ("left key pressed"); //}	
						mapMove (-1,0);
						enemyMove();
					break;
		
					case SDLK_RIGHT:
						//{---LOG---right key pressed
						LogHandler::logEvents();
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

	for (int i = 0; i < GraphicsHandler::MAP_WIDTH; i++) {
		for (int j = 0; j < GraphicsHandler::MAP_HEIGHT; j++) {
			
			
			
			if ((mapData[i][j][1] == MAP_TILE_PLAYER) && 
				(mapData[i + moveX][j + moveY][0] != MAP_TILE_WALL) &&
				(mapData[i + moveX][j + moveY][1] != MAP_TILE_ENEMY)) {
				
				mapData[i][j][1] = NULL;
				mapData[i + moveX][j + moveY][1] = MAP_TILE_PLAYER;
				playerPositionX = i + moveX;
				playerPositionY = j + moveY;
				i = GraphicsHandler::MAP_WIDTH;
				j = GraphicsHandler::MAP_HEIGHT;
			
			} 
			if ((mapData[i][j][1] == MAP_TILE_PLAYER) && (mapData[i + moveX][j + moveY][1] == MAP_TILE_ENEMY)) {
				
				mapData[i + moveX][j + moveY][1] = NULL;
				i = GraphicsHandler::MAP_WIDTH;
				j = GraphicsHandler::MAP_HEIGHT;
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
		
		for (int i = 0; i < GraphicsHandler::MAP_WIDTH; i++) {
			for (int j = 0; j < GraphicsHandler::MAP_HEIGHT; j++) {
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
	
	for (int i = 0; i < GraphicsHandler::MAP_WIDTH; i++) {
		for (int j = 0; j < GraphicsHandler::MAP_HEIGHT; j++) {
			if ((mapData[i][j][1] == MAP_TILE_ENEMY) && 
				(mapData[i + moveX][j + moveY][0] != MAP_TILE_WALL) &&
				(mapData[i + moveX][j + moveY][1] != MAP_TILE_PLAYER)) {
					
				mapData[i][j][1] = NULL;
				mapData[i + moveX][j + moveY][1] = MAP_TILE_ENEMY;
				i = GraphicsHandler::MAP_WIDTH;
				j = GraphicsHandler::MAP_HEIGHT;
				
			} else if ((mapData[i][j][1] == MAP_TILE_ENEMY) && 
					   (mapData[i + moveX][j + moveY][1] == MAP_TILE_PLAYER)) {
				
				mapData[i + moveX][j + moveY][1] = NULL;
				i = GraphicsHandler::MAP_WIDTH;
				j = GraphicsHandler::MAP_HEIGHT;
			}
		}
	}
}

//BROKEN due to visibility
//void eventOrganizer() { }

void mapPopulator() {
	
	for (int i = 0; i < GraphicsHandler::MAP_WIDTH; i++) {
		for (int j = 0; j < GraphicsHandler::MAP_HEIGHT; j++) {
			
			if ( (i == 0 || i == GraphicsHandler::MAP_WIDTH - 1) ||
				 (j == 0 || j == GraphicsHandler::MAP_HEIGHT - 1) ) {
					 
				mapData[i][j][0] = MAP_TILE_WALL;
		
			} else {
			
				mapData[i][j][0] = MAP_TILE_FLOOR;
			}
		}
	}
	
	mapData[GraphicsHandler::MAP_WIDTH / 2][GraphicsHandler::MAP_HEIGHT / 2][1] = MAP_TILE_PLAYER;
	mapData[GraphicsHandler::MAP_WIDTH / 4][GraphicsHandler::MAP_HEIGHT / 4][1] = MAP_TILE_ENEMY;
}
*/
