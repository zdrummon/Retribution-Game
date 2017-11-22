#pragma once
SDL_Surface* loadSurface (std::string path);
enum MapTile {
			MAP_TILE_DEFAULT,
			MAP_TILE_WALL,
			MAP_TILE_FLOOR,
			MAP_TILE_PLAYER,
			MAP_TILE_ENEMY,
			MAP_TILE_TOTAL
		};
		
class GraphicsHandler {
	
	public:
		GraphicsHandler();
		
		const int getMAP_WIDTH() const;
		const int getMAP_HEIGHT() const;
		const int getTILE_WIDTH() const;
		const int getTILE_HEIGHT() const;
		const int getSCREEN_WIDTH() const;
		const int getSCREEN_HEIGHT() const;
		int getMapTile();
		
		bool initializeSDLHandler();
		bool mediaLoader();
		
		void closeSDLHandler();
		void mapGraphicsPrinter(int mapData[20][20][2]);

		
		
	protected:	
	
	private:
		const int MAP_WIDTH = 10;
		const int MAP_HEIGHT = 10;
		const int TILE_WIDTH = 32;
		const int TILE_HEIGHT = 32;
		const int SCREEN_WIDTH = TILE_WIDTH * MAP_WIDTH;
		const int SCREEN_HEIGHT = TILE_HEIGHT * MAP_HEIGHT;
		
		
		
		//Loads individual image
		//SDL_Surface* loadSurface (std::string path);
		
		//The window we'll be rendering to
		SDL_Window* windowHandler = NULL;
			
		//The surface contained by the window
		SDL_Surface* windowSurface = NULL;
		
		//The images that correspond to a keypress
		SDL_Surface* mapSurfaces [MAP_TILE_TOTAL];
		
		//Current displayed image
		SDL_Surface* currentSurface = NULL;
};