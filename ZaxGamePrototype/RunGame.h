#pragma once

class RunGame {
	public:
		RunGame();
		
		//temporary map data
		int mapArray[10][10];
	
		//quit game flag
		bool quitGame;
		
		//play the game
		int playGame();
		
	protected:
	private:
};