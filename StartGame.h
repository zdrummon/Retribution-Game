#pragma once

class StartGame {
	public:
		StartGame();
		int startScreen(int versionRelease, 
						 int versionInternal,
						 int versionAsset, 
						 int versionScript);
		//TODO set startMenuInput to private
		char startMenuInput; 
		int startMenu();
		
	protected:
	private:
};