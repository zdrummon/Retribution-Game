#pragma once

class StartGame {
	public:
		StartGame();
		
		//TODO set startMenuInput to private
		char startMenuInput; 
		
		//opening splash screen
		int startScreen(int versionRelease, 
						int versionInternal,
						int versionAsset, 
						int versionScript);
		
		//game start menu
		int startMenu();
		
	protected:
	private:
};