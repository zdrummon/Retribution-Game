cd documents/cplusplus_practice/zaxgameprototype
g++ main.cpp StartGame.cpp RunGame.cpp MapTerrain.cpp ExitGame.cpp -IC:/mingw_dev_lib/include/SDL2 -LC:/mingw_dev_lib/lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o KarateChess
./karateChess
