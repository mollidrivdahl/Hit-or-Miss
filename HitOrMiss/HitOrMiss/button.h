//Molli Drivdahl
//button.h

/*******************************************************************************
* Class: Button
* 
* Description:
* 	This class encapsulates data members and methods that model the behavior
* 	of a button. It handles different mouse events and how the button behaves
* 	according to each mouse event.
* 
* Constructors
* 	Button()
* 		Acts as the default constructor; initializes the data members.
* 
* Destructors
* 	~Button()
* 		Acts as the default destructor.
* 
* Mutators:
* 	void handleEvent(SDL_Event * e)
* 		Sets the current sprite depending on how the mouse behaves, or sets a
* 		flag signaling that the button was clicked by the mouse.
* 
* Methods:
* 	void render(SDL_Renderer * gRenderer, TextureManager * buttonSpriteTexture)
* 		Renders the button to screen with the specified texture.
* 
* 	bool getButtonReleaseStatus()
* 		Returns the value of the m_buttonRelease data member.
*******************************************************************************/

#ifndef BUTTON_H
#define BUTTON_H

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

#include "textureManager.h"

//Location of button
const int BUTTON_X_COORDINATE = 270;
const int BUTTON_Y_COORDINATE = 190;
const int BUTTON_WIDTH = 100;
const int BUTTON_HEIGHT = 100;

//Used with m_currentButtonSprite to specify which sprite is active
enum ButtonSprites
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_TOTAL = 3
};

class Button
{
	public:
		/***********************************************************************
		* Button()
		* 	Purpose :
		* 		To initialize the data members (DEFALUT CONSTRUCTOR).
		* 	Entry :
		* 		No entry value.
		* 	Exit :
		* 		Data members are initialized.
		***********************************************************************/
		Button();
	
		/***********************************************************************
		* ~Button()
		* 	Purpose:
		* 		To deallocate memory, but no memory was allocated in this class
		* 		(DESTRUCTOR).
		* 	Entry:
		* 		No entry value.
		* 	Exit:
		* 		No exit value.
		***********************************************************************/
		~Button();
	
		/***********************************************************************
		* void handleEvent(SDL_Event * e)
		* 	Purpose:
		* 		To set the current sprite depending on how the mouse behaves, or
		* 		set a flag signaling that the button was clicked by the mouse.
		* 	Entry:
		* 		An event handler.
		* 	Exit:
		* 		The mouse events are handled.
		***********************************************************************/
		void handleEvent(SDL_Event * e);
	
		/***********************************************************************
		* void render(SDL_Renderer * gRenderer,
		* 			TextureManager * buttonSpriteTexture)
		* 	Purpose:
		* 		To render the button to screen with the specified texture.
		* 	Entry:
		* 		The renderer for the window, and the TextureManager object that
		* 		specifies which texture to render on the button.
		* 	Exit:
		* 		The button is renderer with the specified texture.
		***********************************************************************/
		void render(SDL_Renderer * gRenderer,
					TextureManager * buttonSpriteTexture);
	
		/***********************************************************************
		* bool getButtonReleaseStatus()
		* 	Purpose :
		* 		To return the value of the m_buttonRelease data member.
		* 	Entry :
		* 		No entry value.
		* 	Exit :
		* 		A bool value signaling whether the data member was set to true
		* 		or false.
		***********************************************************************/
		bool getButtonReleaseStatus();
	
	private:
		//Top left position
		SDL_Point m_position;
		//Specifies which sprite is active
		ButtonSprites m_currentButtonSprite;
		//Flag for button release
		bool m_buttonRelease;
};

#endif //BUTTON_H