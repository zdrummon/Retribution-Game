//libraries
#include <SDL.h>
#include <SDL_image.h>
#include <ctime>
#include <stdio.h>
#include <string>
//headers
#include "main.h"
#include "LogHandler.h"
#include "GraphicsHandler.h"
//namespaces
using namespace std;
//main class body
int main (int argc, char* args[]) {
	
	srand(time(NULL));
	LogHandler Log;
	Log.logStart();
	Log.logEvents();
	
	if (!GraphicsHandler::initSDLHandler()) {
		
		//{---LOG---failed to initialize SDL
		Log.logEvents();
		printf ("failed to initialize SDL!"); //}
	
	} else {
		
		if (!GraphicsHandler::mediaHandler()) {
			
			//{---LOG---failed to load media
			Log.logEvents();
			printf ("failed to load media!"); //}
			
		} else {
			
			//runGame();
		}
	}

	GraphicsHandler::closeSDLHandler();	\
	
	Log.logEnd();
	return 0;			
}