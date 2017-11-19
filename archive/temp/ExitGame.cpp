//libraries
#include <windows.h> 
#include <iostream>
<<<<<<< HEAD:temp/ExitGame.cpp
//#include <time.h> <---line12
=======
>>>>>>> master:ExitGame.cpp
//headers
#include "ExitGame.h"
//namespaces
using namespace std;
//class body
ExitGame::ExitGame() {}

//this works fine stop looking here
ExitGame::exitScreen() {
	system("CLS");
	cout << "   #############################################################################################" << endl;
	cout << "                                                                                                " << endl;
	cout << "               ####       ####         ####     ####       ######   ##  ##   ######             " << endl;
	cout << "             ##         ##    ##     ##    ##   ##  ##     ## ##    ##  ##   ##                 " << endl;
	cout << "            ##         ##      ##   ##      ##  ##   ##    ####     ######   ####               " << endl;
	cout << "            ##  ####   ##      ##   ##      ##  ##   ##    ##  ##     ##     ##                 " << endl;
	cout << "             ##   ##    ##    ##     ##    ##   ##  ##     ##  ##     ##     ##                 " << endl;
	cout << "               ####       ####         ####     ####       ######     ##     ######             " << endl;
	cout << "                                                                                                " << endl;
	cout << "   #############################################################################################" << endl;
	
	return 0;
}