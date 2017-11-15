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
			
            bool quitFlag = false;
            
            SDL_Event eventHandler;	

			currentSurface = keySurfaces [KEY_PRESS_DEFAULT];			
	
            while (!quitFlag) {
				
				//Handle events on queue
                while (SDL_PollEvent (&eventHandler) != 0) {
					
                    //User requests quit
                    if (eventHandler.type == SDL_QUIT) {
						
						quitFlag = true;	
						
						//{---LOG---quit flag has been set
						logEvents();
						printf ("quit flag has been set"); //}
                    }
					
					//User presses a key
                    if (eventHandler.type == SDL_KEYDOWN) {
						
						//Select surfaces based on key press
                        switch (eventHandler.key.keysym.sym) {
                            
							case SDLK_UP:
							//{---LOG---up key pressed
							logEvents();
							printf ("up key pressed"); //}
							
                            currentSurface = keySurfaces [KEY_PRESS_UP];
                            break;

                            case SDLK_DOWN:
							//{---LOG---down key pressed
							logEvents();
							printf ("down key pressed"); //}	
							
                            currentSurface = keySurfaces [KEY_PRESS_DOWN];
                            break;

                            case SDLK_LEFT:
							//{---LOG---left key pressed
							logEvents();
							printf ("left key pressed"); //}	
							
                            currentSurface = keySurfaces [KEY_PRESS_LEFT];
                            break;

                            case SDLK_RIGHT:
							//{---LOG---right key pressed
							logEvents();
							printf ("right key pressed"); //}	
							
                            currentSurface = keySurfaces [KEY_PRESS_RIGHT];
                            break;

                            default:						
                            currentSurface = keySurfaces [KEY_PRESS_DEFAULT];
                            break;
                        }
                    }
                }
				
				//Apply the image stretched
				SDL_Rect stretchRect;
				stretchRect.x = 0;
				stretchRect.y = 0;
				stretchRect.w = SCREEN_WIDTH;
				stretchRect.h = SCREEN_HEIGHT;
				SDL_BlitScaled (currentSurface, NULL, windowSurface, &stretchRect);
				SDL_UpdateWindowSurface (windowHandler);			
			}
		}
	}

	void closeSDLHandler();
	
	//{---LOG---program has ended
	logEvents();
	printf ("program has ended\n ==============================\n"); //}

	return 0;			
}