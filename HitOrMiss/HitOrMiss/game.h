//Molli Drivdahl
//game.h

/*******************************************************************************
* Class: Game
* 
* Description:
* 	This class contains all the basic methods that control the flow of the game.
* 
* Constructors:
* 	Game()
* 		Acts as the default constructor; initializes private data members to
* 		nullptr, and the objects of the m_shapes vector of Shape pointers is
* 		instantiated.
* 
* Destructors:
* 	~Game()
* 		Acts as the default destructor; deallocates memory of the vector of
* 		Shape pointers.
* 
* Mutators:
* 	bool init()
* 		Create the window surface and the renderer for the window.	
* 
* 	void close()
* 		Deallocates the textures and destroys the window.
* 
* 	void drawAllShapes(Square *& movingSquare, Rectangle *& movingRect,
* 					int & xCoordinateMovingSquare, int & yCoordinateMovingRect)
* 		Draws the moving and stationary Shapes to the screen once the moving
* 		Rectangle and moving Square objects have been upcasted back to their
* 		corresponding vector of Shape pointers elemets.
* 
* 	bool detectCollision(Square *& movingSquare, Rectangle *& movingRect)
* 		Detects whether or not the moving Rectangle has collided into the
* 		moving Square. If there is a collision, m_winGame is set to true and
* 		the flag is returned as true.
* 
* Methods:
* 	bool loadMedia()
* 		Loads bitmap media to the textures.
* 
* 	void startGame()
* 		Runs other methods that control the flow of the game. 
* 		
* 	void gameLoop()
* 		Handles events that run the game.
* 
* 	void buttonReleaseBeginGame(SDL_Event * e)
* 		Runs the events that occur after button is clicked.
* 
* 	void downCastShapes(Square *& movingSquare, Rectangle *& movingRect,
* 					int xCoordinateMovingSquare, int yCoordinateMovingSquare,
* 					int xCoordinateMovingRect, int yCoordinateMovingRect)
* 		Downcasts specified elements of vector of Shape pointers to actual
* 		Square or Rectangle objects, and sets initial values for those two
* 		objects.
* 
* 	void keyDownEvent(SDL_Event * e, Square *& movingSquare,
* 						Rectangle *& movingRect, int & xCoordinateMovingSquare,
* 						int & yCoordinateMovingRect)
* 		Determines if the up arrow key is pressed; if so, call methods to move
* 		the moving Rectagle and moving Square.
* 
* 	void upPressShootRect(Square *& movingSquare, Rectangle *& movingRect,
* 					int & xCoordinateMovingSquare, int & yCoordinateMovingRect)
* 		Shoots the moving Rectangle upwards, and lets the moving Square keep
* 		moving to the right.
* 
* 	void continueMovingSquare(Square *& movingSquare,
* 						Rectangle *& movingRect, int & xCoordinateMovingSquare,
* 						int & yCoordinateMovingRect);
* 		Keeps the moving Square moving to the right even when the moving
* 		Rectangle is not moving (when the up arrow key to shoot the Rectangle
* 		upwards has not been pressed).
* 
* 	void displayWinTexture()
* 		Renders a texture congratulating the player of his or her win which
* 		occurs from hitting the moving Square with the moving Rectangle.
*
*	void displayLoseTexture()
*		Renders a texture informing the player of his or her loss which occurs
*		from attempting to shoot the moving Rectangle more than 3 times.
*******************************************************************************/

#ifndef GAME_H
#define GAME_H

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <vector>
using std::vector;

#include "surfaceManager.h"
#include "textureManager.h"
#include "square.h"
#include "button.h"

//Assign bitmaps to string constants
const string BACKGROUND_TEXTURE_PIC = "gameScreen.bmp";
const string BUTTON_SPRITE_SHEET_TEXTURE_PIC = "buttonSpriteSheet.bmp";
const string GAME_WON_TEXTURE_PIC = "winGame.bmp";
const string GAME_LOST_TEXTURE_PIC = "loseGame.bmp";

class Game
{
	public:
		/***********************************************************************
		* Game()
		* 	Purpose:
		* 		To initialize the private data members to a known value
		* 		(DEFAULT CONSTRUCTOR).
		* 	Entry:
		* 		No entry value.
		* 	Exit:
		* 		Private data members are set to nullptr, all the objects of the
		* 		m_shapes vector of Shape pointers and instantiated, and the
		* 		m_winGame bool is set to false.
		***********************************************************************/
		Game();

		/***********************************************************************
		* ~Game()
		* 	Purpose:
		* 		To deallocate the memory alloacted for the vector of Shape
		* 		pointers (DEFAULT DESTRUCTOR).
		* 	Entry:
		* 		No entry value.
		* 	Exit:
		* 		The vector of Shape pointers are dealloacted.
		***********************************************************************/
		~Game();

		/***********************************************************************
		* bool init()
		* 	Purpose:
		* 		To create the window surface and the renderer for the window. 
		* 	Entry:
		* 		No entry value.
		* 	Exit:
		* 		Returns a flag to signal if the function ran succesfully.
		***********************************************************************/
		bool init();

		/***********************************************************************
		* bool loadMedia()
		* 	Purpose:
		* 		To load bitmap media to the textures.
		* 	Entry:
		* 		No entry value.
		* 	Exit:
		* 		Returns a flag to signal if the function ran succesfully.
		***********************************************************************/
		bool loadMedia();

		/***********************************************************************
		* void close()
		* 	Purpose:
		* 		To deallocate the textures and destroy the window.
		* 	Entry:
		* 		No entry value.
		* 	Exit:
		* 		The textures are deallocated and the window is destroyed and
		* 		closed.
		***********************************************************************/
		void close();

		/***********************************************************************
		* void startGame()
		* 	Purpose:
		* 		To run other methods that control the flow of the game.
		* 	Entry:
		* 		No entry value. 
		* 	Exit:
		* 		No exit value.
		***********************************************************************/
		void startGame();

		/***********************************************************************
		* void gameLoop()
		* 	Purpose:
		* 		To handle events that run the game.
		* 	Entry:
		* 		No entry value.
		* 	Exit:
		* 		Events are handled and game begins to function accordingly.		
		***********************************************************************/
		void gameLoop();

		/***********************************************************************
		* void buttonReleaseBeginGame(SDL_Event * e)
		* 	Purpose:
		* 		To run the events that occur after button is clicked.
		* 	Entry:
		* 		An event handler.
		* 	Exit:
		* 		Events from the keyboard are checked and corresponding methods
		* 		are ran accordingly.
		***********************************************************************/
		void buttonReleaseBeginGame(SDL_Event * e);

		/***********************************************************************
		* void downCastShapes(Square *& movingSquare, Rectangle *& movingRect,
		* 			int xCoordinateMovingSquare, int yCoordinateMovingSquare,
		* 			int xCoordinateMovingRect, int yCoordinateMovingRect)
		* 	Purpose:
		* 		To downcast specified elements of vector of Shape pointers to
		* 		actual Square or Rectangle objects, and set initial values for
		* 		those two objects.
		* 	Entry:
		* 		A Square object, a Rectangle object, and four integers that
		* 		specify the x & y coordinates of both the moving Square and the
		* 		moving Rectangle.
		* 	Exit:
		* 		The vector of Shape pointers is casted and the values of the two
		* 		new objects are reset.
		***********************************************************************/
		void downCastShapes(Square *& movingSquare, Rectangle *& movingRect,
					int xCoordinateMovingSquare, int yCoordinateMovingSquare,
					int xCoordinateMovingRect, int yCoordinateMovingRect);

		/***********************************************************************
		* void keyDownEvent(SDL_Event * e, Square *& movingSquare,
		* 				Rectangle *& movingRect, int & xCoordinateMovingSquare,
		* 				int & yCoordinateMovingRect)
		* 	Purpose:
		* 		To determine if the up arrow key is pressed; if so, call
		* 		method to move the moving Rectagle and moving Square.
		* 	Entry:
		* 		An event handler, a Square object, a Rectangle object, and two
		* 		integers that specify the x coordinate of the moving Square and
		* 		the y coordinate of the moving Rectangle.
		* 	Exit:
		* 		If the up arrow key is pressed, the method to move the moving
		* 		Rectangle and moving Square method is called.
		***********************************************************************/
		void keyDownEvent(SDL_Event * e, Square *& movingSquare,
						Rectangle *& movingRect, int & xCoordinateMovingSquare,
						int & yCoordinateMovingRect);

		/***********************************************************************
		* void upPressShootRect(Square *& movingSquare, Rectangle *& movingRect,
		* 			int & xCoordinateMovingSquare, int & yCoordinateMovingRect)
		* 	Purpose:
		* 		To shoot the moving Rectangle upwards, and let the moving Square
		* 		keep moving to the right.
		* 	Entry:
		* 		A Square object, a Rectangle object, and two integers that
		* 		specify the x coordinate of the moving Square and the y
		* 		coordinate of the moving Rectangle.
		* 	Exit:
		* 		The moving Rectangle is drawn 1 frame up and the moving Square
		* 		is drawn 1 frame to the right for each iteration through the
		* 		loop until the Rectangle reaches the top of the screen.
		***********************************************************************/
		void upPressShootRect(Square *& movingSquare, Rectangle *& movingRect,
					int & xCoordinateMovingSquare, int & yCoordinateMovingRect);

		/***********************************************************************
		* void continueMovingSquare(Square *& movingSquare,
		* 				Rectangle *& movingRect, int & xCoordinateMovingSquare,
		* 				int & yCoordinateMovingRect)
		* 	Purpose:
		* 		To keep the moving Square moving to the right even when
		* 		the moving Rectangle is not moving (when the up arrow key to
		* 		shoot the Rectangle upwards has not been pressed).
		* 	Entry:
		* 		A Square object, a Rectangle object, and two integers that
		* 		specify the x coordinate of the moving Square and the y
		* 		coordinate of the moving Rectangle.
		* 	Exit:
		* 		The moving Square is drawn 1 frame to the right, and the moving
		* 		Rectangle is drawn at its resting location at the bottom of the
		* 		screen, on top of the stationary Rectangle.
		***********************************************************************/
		void continueMovingSquare(Square *& movingSquare,
						Rectangle *& movingRect, int & xCoordinateMovingSquare,
						int & yCoordinateMovingRect);

		/***********************************************************************
		* void drawAllShapes(Square *& movingSquare, Rectangle *& movingRect,
		* 			int & xCoordinateMovingSquare, int & yCoordinateMovingRect)
		* 	Purpose:
		* 		To draw the moving and stationary Shapes to the screen once the
		* 		moving Rectangle and moving Square objects have been upcasted
		* 		back to their corresponding vector of Shape pointers elemets.
		* 	Entry:
		* 		A Square object, a Rectangle object, and two integers that
		* 		specify the x coordinate of the moving Square and the y
		* 		coordinate of the moving Rectangle.
		* 	Exit:
		* 		The Shapes are drawn to the screen in their specified locations.
		***********************************************************************/
		void drawAllShapes(Square *& movingSquare, Rectangle *& movingRect,
					int & xCoordinateMovingSquare, int & yCoordinateMovingRect);

		/***********************************************************************
		* bool detectCollision(Square *& movingSquare, Rectangle *& movingRect)
		* 	Purpose:
		* 		To detect whether or not the moving Rectangle has collided into
		* 		the moving Square.
		* 	Entry:
		* 		A Square object and a Rectangle object.
		* 	Exit:
		* 		A flag signaling whether or not the moving Rectangle hit the
		* 		moving Square. If there is a collision, m_winGame is set to
		* 		true and the flag is returned as true.
		***********************************************************************/
		bool detectCollision(Square *& movingSquare, Rectangle *& movingRect);

		/***********************************************************************
		* void displayWinTexture()
		* 	Purpose:
		* 		To render a texture congratulating the player of his or her win
		* 		which occurs from hitting the moving Square with the moving
		* 		Rectangle.
		* 	Entry:
		* 		No entry value.
		* 	Exit:
		* 		The texture celebrating the win is displayed to the screen.
		***********************************************************************/
		void displayWinTexture();

		/***********************************************************************
		* void displayLoseTexture()
		* 	Purpose:
		* 		To render a texture informing the player of his or her loss
		* 		which occurs from attempting to shoot the moving Rectangle more
		*		than 3 times.
		* 	Entry:
		* 		No entry value.
		* 	Exit:
		* 		The texture announging the loss is displayed to the screen.
		***********************************************************************/
		void displayLoseTexture();

	private:
		//The window we'll be rendering to
		SDL_Window * m_gWindow;

		//Renderer for the window
		SDL_Renderer * m_gRenderer;

		//Surface contained by the window
		SurfaceManager m_screenSurface;

		//Array of TextureManager objects
		TextureManager m_textures[TOTAL_NUM_TEXTURES];

		//Vector to hold Shape PVBC pointers
		vector<Shape *> m_shapes;

		//Button to click to start the game
		Button m_startButton;

		//Flag to exit loop once game is won
		bool m_winGame;

		//Flag to exit loop one game is lost
		bool m_loseGame;
};

#endif //GAME_H