#pragma once

class LogHandler {
	
	public:
		GraphicsHandler();
		
		bool initializeSDLHandler();
		bool mediaLoader();
		SDL_Surface* loadSurface (std::string path);
		void closeSDLHandler();
		void mapGraphicsPrinter();

		int getMAP_WIDTH();
		int getMAP_HEIGHT();
		int getTILE_WIDTH();
		int getTILE_HEIGHT();
		int getSCREEN_WIDTH();
		int getSCREEN_HEIGHT();
		int getMapTile();
		
	protected:	
	
	private:
		const int MAP_WIDTH = 10;
		const int MAP_HEIGHT = 10;
		const int TILE_WIDTH = 32;
		const int TILE_HEIGHT = 32;
		const int SCREEN_WIDTH = TILE_WIDTH * MAP_WIDTH;
		const int SCREEN_HEIGHT = TILE_HEIGHT * MAP_HEIGHT;
		
		enum MapTile {
			MAP_TILE_DEFAULT,
			MAP_TILE_WALL,
			MAP_TILE_FLOOR,
			MAP_TILE_PLAYER,
			MAP_TILE_ENEMY,
			MAP_TILE_TOTAL
		};
		
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
};