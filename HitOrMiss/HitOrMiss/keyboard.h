//Molli Drivdahl
//keyboard.h

/*
Class: Keyboard

Constructors:
	Keyboard()
		Acts as the default constructor.

Destructors:
	~Keyboard()
		Acts as the default destructor.

Mutators:
	<NONE>

Methods:
	bool loadKeyboardMedia(SurfaceManager & surface, bool success)
		Assigns a surface containing a bitmap to a surface corresponding to a
		particular key press.

*/

#ifndef KEYBOARD_H
#define KEYBOARD_H

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

#include "surfaceManager.h"

class Keyboard
{
	public:
		/*
		Keyboard()
			Purpose :
				To initialize the private data member to a known values, but
				there are no private data members to be initialized
				(DEFAULT CONSTRUCTOR).
			Entry :
				No entry value.
			Exit :
				No exit value.
		*/
		Keyboard();

		/*
		~Keyboard()
			Purpose :
				To deallocate memory, but no memory was allocated inside this
				class (DESTRUCTOR).
			Entry :
				No entry value.
			Exit :
				No exit value.
		*/
		~Keyboard();

		/*
		bool loadKeyboardSurfaceMedia(SurfaceManager & surface, string path,
									  SDL_Surface * screenSurface)
			Purpose :
				To assign surfaces containing bitmaps to surfaces corresponding
				to particular key presses.
			Entry :
				A SurfaceManager object passed by reference, a path to the
				bitmap, and the screen surface object.
			Exit :
				The surfaces corresponding to particular key presses are
				assigned a surface containing a bitmap. The flag indicating if
				the function ran successfully is returned.
		*/
		bool loadKeyboardSurfaceMedia(SurfaceManager & surface, string path,
									  SDL_Surface * screenSurface);
};

#endif //KEYBOARD_H