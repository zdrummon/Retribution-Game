//libraries
#include <SDL.h>
#include <SDL_image.h>
#include <ctime>
#include <stdio.h>
#include <string>
//headers
#include "main.h"
//namespaces
using namespace std;
//main class body
int main (int argc, char* args[]) {
	
	srand(time(NULL));

	//{---LOG---start debug log
	startTicker = clock();
	logCount = 0;
	printf ("\n DEBUG LOG\n =============================="); //}
	
	if (!initSDLHandler()) {
		
		//{---LOG---failed to initialize SDL
		logEvents();
		printf ("failed to initialize SDL!"); //}
	
	} else {
		
		if (!mediaHandler()) {
			
			//{---LOG---failed to load media
			logEvents();
			printf ("failed to load media!"); //}
			
		} else {
			
			runGame();
		}
	}

	void closeSDLHandler();
	
	//{---LOG---program has ended
	logEvents();
	printf ("program has ended\n ==============================\n"); //}

	return 0;			
}