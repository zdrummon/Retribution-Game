//libraries
//headers
#include "MapGenerator.h"
#include "Map.h"
//namespaces
using namespace std;

MapGenerator::MapGenerator(){	
}

MapGenerator::cellularAutomata(int scanLayer,
				 int writeLayer,
				 int neighborCount,
				 int writeTileType,
				 int mode){
					 
Map CurrentMap;
	
	switch (mode)
	{
	case 0:
	for (int i = 1; i < CurrentMap.mapXDimension - 1; i++) {
		for (int j = 1; j < CurrentMap.mapYDimension - 1; j++) {			
			
			if ((CurrentMap.terrainmap [i - 1][j - 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i    ][j - 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i + 1][j - 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i - 1][j    ][  scanLayer  ] +
				 CurrentMap.terrainmap [i + 1][j    ][  scanLayer  ] +
				 CurrentMap.terrainmap [i - 1][j + 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i    ][j + 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i + 1][j + 1][  scanLayer  ]) < neighborCount) {
			                                   
				 CurrentMap.terrainmap [i    ][j    ][  writeLayer  ] = writeTileType;
			}
		}
	}
	break;
	case 1:
	for (int i = 1; i < CurrentMap.mapXDimension - 1; i++) {
		for (int j = 1; j < CurrentMap.mapYDimension - 1; j++) {			
			
			if ((CurrentMap.terrainmap [i - 1][j - 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i    ][j - 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i + 1][j - 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i - 1][j    ][  scanLayer  ] +
				 CurrentMap.terrainmap [i + 1][j    ][  scanLayer  ] +
				 CurrentMap.terrainmap [i - 1][j + 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i    ][j + 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i + 1][j + 1][  scanLayer  ]) <= neighborCount) {
			                                              
				 CurrentMap.terrainmap [i    ][j    ][  writeLayer  ] = 1;
			}
		}
	}
	break;
	case 2:
	for (int i = 1; i < CurrentMap.mapXDimension - 1; i++) {
		for (int j = 1; j < CurrentMap.mapYDimension - 1; j++) {			
			
			if ((CurrentMap.terrainmap [i - 1][j - 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i    ][j - 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i + 1][j - 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i - 1][j    ][  scanLayer  ] +
				 CurrentMap.terrainmap [i + 1][j    ][  scanLayer  ] +
				 CurrentMap.terrainmap [i - 1][j + 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i    ][j + 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i + 1][j + 1][  scanLayer  ]) == neighborCount) {
			                                              
				 CurrentMap.terrainmap [i    ][j    ][  writeLayer  ] = 1;
			}
		}
	}
	break;
	case 3:
	for (int i = 1; i < CurrentMap.mapXDimension - 1; i++) {
		for (int j = 1; j < CurrentMap.mapYDimension - 1; j++) {			
			
			if ((CurrentMap.terrainmap [i - 1][j - 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i    ][j - 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i + 1][j - 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i - 1][j    ][  scanLayer  ] +
				 CurrentMap.terrainmap [i + 1][j    ][  scanLayer  ] +
				 CurrentMap.terrainmap [i - 1][j + 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i    ][j + 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i + 1][j + 1][  scanLayer  ]) >= neighborCount) {
			                                              
				 CurrentMap.terrainmap [i    ][j    ][  writeLayer  ] = 1;
			}
		}
	}
	break;
	case 4:
	for (int i = 1; i < CurrentMap.mapXDimension - 1; i++) {
		for (int j = 1; j < CurrentMap.mapYDimension - 1; j++) {			
			
			if ((CurrentMap.terrainmap [i - 1][j - 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i    ][j - 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i + 1][j - 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i - 1][j    ][  scanLayer  ] +
				 CurrentMap.terrainmap [i + 1][j    ][  scanLayer  ] +
				 CurrentMap.terrainmap [i - 1][j + 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i    ][j + 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i + 1][j + 1][  scanLayer  ]) > neighborCount) {
			                                              
				 CurrentMap.terrainmap [i    ][j    ][  writeLayer  ] = 1;
			}
		}
	}
	break;
	case 5:
	for (int i = 1; i < CurrentMap.mapXDimension - 1; i++) {
		for (int j = 1; j < CurrentMap.mapYDimension - 1; j++) {			
			
			if ((CurrentMap.terrainmap [i - 1][j - 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i    ][j - 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i + 1][j - 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i - 1][j    ][  scanLayer  ] +
				 CurrentMap.terrainmap [i + 1][j    ][  scanLayer  ] +
				 CurrentMap.terrainmap [i - 1][j + 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i    ][j + 1][  scanLayer  ] +
				 CurrentMap.terrainmap [i + 1][j + 1][  scanLayer  ]) != writeTileType) {
			                                              
				 CurrentMap.terrainmap [i    ][j    ][  writeLayer  ] = 1;
			}
		}
	}
	break;
	
				 }
				 }