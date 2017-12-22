#OBJS specifies which files to compile as part of the project
OBJS = source/main.cpp source/LogHandler.cpp source/GraphicsHandler.cpp

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = KarateChess

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -ID:/Development/External_Libraries/mingw_dev_lib/include/SDL2

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -LD:/Development/External_Libraries/mingw_dev_lib/lib

#COMPILER_FLAGS specifies the additional compilation options we're using
# -Wl,-subsystem,windows gets rid of the console window
# -w suppresses all warnings
# -Wall enables almost all warnings
# -Wextra enables extra warnings
COMPILER_FLAGS = -Wl,-subsystem,windows -Wall -Wextra

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 
#TODO -lSDL2_image for later lib inclusion

#This is the target that compiles our executable
all : $(OBJS)
	g++ $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)