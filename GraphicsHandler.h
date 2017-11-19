#pragma once

namespace GraphicsHandler {
	
	extern int MAP_WIDTH_SET;
	extern int MAP_HEIGHT_SET;
	extern int TILE_WIDTH;
	extern int TILE_HEIGHT;
	extern int SCREEN_WIDTH;
	extern int SCREEN_HEIGHT;
		
	bool initSDLHandler();
	bool mediaHandler();
	void closeSDLHandler();
	//SDL_Surface* loadSurface();
	void mapGraphicsPrinter();

}

