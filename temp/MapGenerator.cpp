//libraries
//headers
#include "MapGenerator.h"
//namespaces
using namespace std;




cellularAutomata(int scanLayer,
							 int writeLayer,
							 int scanTileTypeOne,
							 int scanTileTypeTwo,
							 int writeTileType
							 int mode){
	
	
	
	
	
	for (int i = 1; i < axisx - 1; i++) {
		for (int j = 1; j < axisy - 1; j++) {			
			
			if ((terrainmap [i - 1][j - 1][  0  ] +
				 terrainmap [  i  ][j - 1][  0  ] +
				 terrainmap [i + 1][j - 1][  0  ] +
				 terrainmap [i - 1][  j  ][  0  ] +
				 terrainmap [i + 1][  j  ][  0  ] +
				 terrainmap [i - 1][j + 1][  0  ] +
				 terrainmap [  i  ][j + 1][  0  ] +
				 terrainmap [i + 1][j + 1][  0  ]) > 4) {
			                                   
				 terrainmap [  i  ][  j  ][  0  ] = 1;
			}
		}
	}
	
}