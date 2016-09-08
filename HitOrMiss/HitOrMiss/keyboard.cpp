//Molli Drivdahl
//keyboard.cpp

#include "keyboard.h"
#include <iostream>
using std::cout;

//Default constructor
Keyboard::Keyboard()
{}

//Default destructor
Keyboard::~Keyboard()
{}

//Load media from keyboard input
bool Keyboard::loadKeyboardSurfaceMedia(SurfaceManager & surface, string path,
										SDL_Surface * screenSurface)
{
	bool success = true;

	//Load default surface
	if (!surface.loadSurface(path, screenSurface))
	{
		cout << "Failed to load default image!\n";
		success = false;
	}

	return success;
}