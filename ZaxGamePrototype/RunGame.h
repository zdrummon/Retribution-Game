#pragma once

class RunGame {
	public:
		RunGame();
		
		//static map size
		static int const MAPSIZE = 10;
		
		//temporary map data
		int mapArray[MAPSIZE][MAPSIZE];
	
		//quit game flag
		bool quitGame;
		
		//play the game
		int playGame();
		
	protected:
	private:
};