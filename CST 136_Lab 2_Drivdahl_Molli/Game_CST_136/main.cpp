//Molli Drivdahl
//main.cpp

/*******************************************************************************
*  Author:						Molli Drivdahl
*  Date Created:				9/29/15
*  Last Modification Date:		11/24/15
*  Lab Number:					CST 136 - 02L
*  Filename:					main.cpp
* 
*  Overview:
		This program allows a mouse click on a button to start the game, and
		allows the up arrow key to shoot a rectangle upward while a square
		moves horizontally across the screen. If the rectangle hits the square,
		then the player wins the game. If the rectangle is shot 3 times and the
		square still isn't hit by the rectangle, then the player loses the game.
 
*  Input:
*		The input comes from the mouse and the keybaord. Input also comes from
*		bitmap files.
* 
*  Output:
* 		The output will be different textures or shapes loaded to the screen.
*******************************************************************************/

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include <iostream>
#include <exception>
using std::cout;
using std::exception;

#include "game.h"

int main( int argc, char* argv[] )
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//instatiate object of Game class
	Game runGame;

	try
	{
		//object runs startGame() method of Game class to control flow of game
		runGame.startGame();
	}
	catch (exception ex)
	{
		//Display exception error message
		cout << ex.what() << "\n\n";
	}

	return 0;
}