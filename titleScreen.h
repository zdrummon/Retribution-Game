//header file for splash screens at the begining and ending of play
#pragma once
using namespace std;


// display the splash screen and prompt player on wether they wanna be here and such
// returns a boolean result true being
bool displayTitleScreen(int vNRelease,int vNInternal,int vNAsset,int vNScript) // the four inputs are the versions
{
	
	char playerTitleDecision;
	bool playerTitleResult = false;
	
	
	
	cout << "                                                          Trevor Haggerty & Zachary Drummond's    "<< endl;
	cout << "   #############################################################################################  "<< endl;
	cout << "        -             -                   -             -                       -                 "<< endl;
	cout << "   ##  ##     ##  -  ####     ##   ########  ######        ####  ##  ##  ######   ####     ####   "<< endl;
	cout << "   ## ##   - ## ##   ##  ##  ## ##    ##     ##          ##      ##  ##  ##      ##  ##   ##  ##  "<< endl;
	cout << "   ####   -  #####   ####    #####    ##     ####   -   ##       ######  ####     ##       ##     "<< endl;
	cout << "   ##  ##   ##   ##  ##  ## ##   ##   ##     ##         ##       ##  ##  ##         ##       ##   "<< endl;
	cout << "   ##  ##   ##   ##  ##  ## ##   ##   ##     ##          ##      ##  ##  ##      ##  ##   ##  ##  "<< endl;
	cout << "   ##  ## - ##   ##  ##  ## ##   ##   ##     ######        ####  ##  ##  ######   ####     ####   "<< endl;
	cout << "       -                    -                      -            -                                 "<< endl;
 	cout << "   #############################################################################################  "<< endl;
	cout << "   version "<< vNRelease <<"."<< vNInternal <<"."<< vNAsset<<"."<< vNScript <<"\n\n\n"<< endl;
	 
	 
	 //ask the player if they would like to play and read the results for a y,Y,n,or N
	 while ((playerTitleDecision != 'y')&&(playerTitleDecision != 'Y')&&(playerTitleDecision != 'n')&&(playerTitleDecision != 'N')){
		cout << " Would you like to play (y/n) "<<endl;
		cin >> playerTitleDecision;
	 }
	 
	 
	 //if the player said yes set the bool to yes telling the game to start
	 if ((playerTitleDecision == 'y')||(playerTitleDecision == 'Y')){
		 playerTitleResult = true;
	 } else{
	 //if the player is lame and doesnt want to play our game they can leave
		  playerTitleResult = false; 
	 }
	 
	 //return if the player is wanting to play the game and thus cool or not
	return playerTitleResult;
	 
	 
	 
}


	 //display the exiting splash screen
int displayEndScreen(int playTime)
{
	 cout << "   #############################################################################################"<< endl;
	 cout << "                                                                                                "<< endl;
	 cout << "               ####       ####         ####     ####       ######   ##  ##   ######             "<< endl;
	 cout << "             ##         ##    ##     ##    ##   ##  ##     ## ##    ##  ##   ##                 "<< endl;
	 cout << "            ##         ##      ##   ##      ##  ##   ##    ####     ######   ####               "<< endl;
	 cout << "            ##  ####   ##      ##   ##      ##  ##   ##    ##  ##     ##     ##                 "<< endl;
	 cout << "             ##   ##    ##    ##     ##    ##   ##  ##     ##  ##     ##     ##                 "<< endl;
	 cout << "               ####       ####         ####     ####       ######     ##     ######             "<< endl;
	 cout << "                                                                                                "<< endl;
	 cout << "   #############################################################################################"<< endl;
	 cout << "   you played "<< playTime<<" 'seconds'"<< endl;
	return 0;
}
