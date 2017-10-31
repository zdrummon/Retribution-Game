//libraries
#include <windows.h> 
#include <iostream>
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