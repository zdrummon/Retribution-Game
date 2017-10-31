#pragma once

class StartGame {
	public:
		StartGame();
		
		//TODO set startMenuInput to private
		char startMenuInput; 
		
		//TODO
		int graphicsHandler();
		
		//TODO
		int uiHandler();
		
		//opening splash screen
		int startScreen(int versionRelease, 
						 int versionInternal,
						 int versionAsset, 
						 int versionScript);
		
		//TODO
		int inputHandler();
		
		//game start menu
		int startMenu();
		
		//TODO
		int outputHandler();
		
	protected:
	private:
};