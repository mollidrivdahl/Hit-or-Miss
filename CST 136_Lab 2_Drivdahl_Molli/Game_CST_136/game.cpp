//Molli Drivdahl
//game.cpp

#include <iostream>
#include <exception>
using std::cout;
using std::exception;

#include "game.h"

//Delay value for SDL_Delay before each update to screen
const int DELAY_TIME = 8;
//Delay value for SDL_Delay before closing game
const int DELAY_CLOSE_TIME = 1000;
//Starting yCoordinate for the moving Rectangle
const int MOV_RECT_STARTING_Y = 410;
//Value to increment xCoordinate for the moving Square
const int MOV_SQR_INCREMENT_X = 6;
//Value to decrement yCoordinate for the moving Rectangle
const int MOV_RECT_DECREMENT_Y = 6;
//Value specifying the number of attempts to shoot the moving Rectangle
//at the moving Square
const int MAX_NUM_TRIES = 3;

//Default constructor
Game::Game() : m_gWindow(nullptr), m_gRenderer(nullptr), m_winGame(false)
{
	//Instantiate each element to different objects with these initial values
	m_shapes.push_back(new Square(0, 75));	//MOVING_SQUARE
	m_shapes.push_back(new Rectangle(300, 430, 40, 50));	//STATIONARY_RECT
	m_shapes.push_back(new Rectangle(315, 410, 10, 20));	//MOVING_RECT
}

//Default destructor
Game::~Game()
{
	//Deallocate all elements of m_shapes vector of Shape pointers
	for (vector<Shape *>::iterator iter = m_shapes.begin();
		 iter != m_shapes.end(); iter++)
	{
		delete *iter;
	}

	//Remove all elements from m_shapes vector of Shape pointers
	m_shapes.clear();

	close();
}

//init() implementation is same as given in SDL Tutorial
bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL_Error: %s\n" << SDL_GetError();
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			cout << "Warning: Linear texture filtering not enabled!";
		}

		//Create window
		m_gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
									  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
									  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		//If window not created successfully
		if (m_gWindow == nullptr)
		{
			cout << "Window could not be created! SDL_Error: %s\n"
				 << SDL_GetError();
			success = false;
		}
		//Else window is created successfully
		else
		{
			//Get window surface
			m_screenSurface.setSurface(SDL_GetWindowSurface(m_gWindow));

			//Create renderer for window
			//Value -1 given from SDL Tutorial
			m_gRenderer = SDL_CreateRenderer(m_gWindow, -1,
											 SDL_RENDERER_ACCELERATED);
			//If renderer not created successfully
			if (m_gRenderer == nullptr)
			{
				cout << "Renderer could not be created! SDL Error: %s\n"
					 << SDL_GetError();
				success = false;
			}
			//Else renderer is created successfully
			else
			{
				//Initialize renderer color
				//Uses RGBA values for a white draw color
				SDL_SetRenderDrawColor(m_gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}
		}
	}

	//Return sucess flag
	return success;
}

//Load all media for textures
bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load background texture
	if (!m_textures[GAME_TEXTURE].loadTexture(m_gRenderer,
											  BACKGROUND_TEXTURE_PIC))
	{
		success = false;
	}
	//Load button sprite sheet texture
	if (!m_textures[BUTTON_SPRITE_TEXTURE].loadTexture(m_gRenderer,
										   BUTTON_SPRITE_SHEET_TEXTURE_PIC))
	{
		success = false;
	}
	//Load game winning texture
	if (!m_textures[WIN_GAME_TEXTURE].loadTexture(m_gRenderer,
												  GAME_WON_TEXTURE_PIC))
	{
		success = false;
	}
	//Load game losing texture
	if (!m_textures[LOSE_GAME_TEXTURE].loadTexture(m_gRenderer,
		GAME_LOST_TEXTURE_PIC))
	{
		success = false;
	}

	//Return success flag
	return success;
}

//Deallocate members at end of game
void Game::close()
{
	//Deallocate surfaces
	m_screenSurface.freeSurface();

	//Free textures
	for (int i = 0; i < TOTAL_NUM_TEXTURES; i++)
	{
		m_textures[i].freeTexture();
	}

	//Reset to default values
	m_winGame = false;

	//Destroy window
	SDL_DestroyRenderer(m_gRenderer);
	SDL_DestroyWindow(m_gWindow);
	m_gRenderer = nullptr;
	m_gWindow = nullptr;

	//Quit SDL subsystems
	SDL_Quit();
}

//Control flow of game
void Game::startGame()
{
	//Start up SDL and create window
	if (!init())
	{
		cout << "Failed to initialize!\n";
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			cout << "Failed to load media!\n";
		}
		else
		{
			//Run actual game functionality
			gameLoop();
		}
	}

	//Free resources and close SDL
	close();
}

//Run actual game functionality
void Game::gameLoop()
{
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	//Set default current texture, & render to screen with specified source &
	//destination values
	m_textures[GAME_TEXTURE].renderTexture(m_gRenderer, 0, 0, SCREEN_WIDTH,
										   SCREEN_HEIGHT, 0, 0, SCREEN_WIDTH,
										   SCREEN_HEIGHT);
	//Update screen
	SDL_RenderPresent(m_gRenderer);

	//While application is running (start actual game loop)
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			//Handle mouse events for button
			m_startButton.handleEvent(&e);
		}
		//If the game has been won
		if (m_winGame == true)
		{
			//Display texture that announces the win
			displayWinTexture();
			//Pause for specified time to continue showing texture
			SDL_Delay(DELAY_CLOSE_TIME);
			//Leave the actual game loop
			quit = true;
		}
		//Else if game has been lost
		else if (m_loseGame == true)
		{
			//Display texture that announces the win
			displayLoseTexture();
			//Pause for specified time to continue showing texture
			SDL_Delay(DELAY_CLOSE_TIME);
			//Leave the actual game loop
			quit = true;
		}
		//Else if the button has been clicked already
		else if (m_startButton.getButtonReleaseStatus() == true)
		{
			//Run events that occur after button is clicked
			buttonReleaseBeginGame(&e);
		}
		//Else the button has not been clicked; the mouse either hovered over
		//the button, or the mouse is still outside of the button
		else
		{
			//Clear screen
			SDL_SetRenderDrawColor(m_gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(m_gRenderer);

			//Render background texture with specified source & destination
			//values
			m_textures[GAME_TEXTURE].renderTexture(m_gRenderer, 0, 0,
												   SCREEN_WIDTH, SCREEN_HEIGHT,
												   0, 0, SCREEN_WIDTH,
												   SCREEN_HEIGHT);
			//Render button
			m_startButton.render(m_gRenderer,
								 &m_textures[BUTTON_SPRITE_TEXTURE]);

			//Update screen
			SDL_RenderPresent(m_gRenderer);
		}
	}
}

//Run events that occur after button is clicked
void Game::buttonReleaseBeginGame(SDL_Event * e)
{
	//Define and initialize each variable only first time method is called
	//Count number times method is called
	static int numCalls = 0;

	//Square and Rectangle to cast Shapes too
	static Square * movingSquare = nullptr;
	static Rectangle * movingRect = nullptr;

	//Initialize values for x and y coordinates of the moving Square and
	//Rectangle
	static int xCoordinateMovingSquare = 0;
	static int yCoordinateMovingSquare = 0;
	static int xCoordinateMovingRect = 0;
	static int yCoordinateMovingRect = 0;

	//Increment each time method is called
	numCalls++;

	//If first time method is called
	if (numCalls == 1)
	{
		//Downcast elements of vector of Shape pointers to Square and Rectangle
		//only once - the first time this method is called
		downCastShapes(movingSquare, movingRect, xCoordinateMovingSquare,
					   yCoordinateMovingSquare, xCoordinateMovingRect,
					   yCoordinateMovingRect);
	}
	//If key is pressed
	if (e->type == SDL_KEYDOWN)
	{
		//Determine whether to move Rectangle and Square if specific key is
		//pressed
		keyDownEvent(e, movingSquare, movingRect, xCoordinateMovingSquare,
					 yCoordinateMovingRect);
	}
	//Else key is not pressed
	else
	{
		//Keep square moving even when rectangle is not moving
		continueMovingSquare(movingSquare, movingRect, xCoordinateMovingSquare,
							 yCoordinateMovingRect);
	}
}

//Downcast elements of vector of Shape pointers to Square and Rectangle
void Game::downCastShapes(Square *& movingSquare, Rectangle *& movingRect,
					int xCoordinateMovingSquare, int yCoordinateMovingSquare,
					int xCoordinateMovingRect, int yCoordinateMovingRect)
{
	//Downcast specified element of vector of Shape pointers to an actual Square
	movingSquare = dynamic_cast<Square *>(m_shapes[MOVING_SQUARE]);

	//Check if legal cast
	if (movingSquare == nullptr)
	{
		throw exception("Illegal downcast to from a Shape to a Square.");
	}

	//Re-randomize color for moving Square
	movingSquare->randomizeColor();

	//Assign x & y coordinate values of the moving Square to static
	//variables holding the coordinate values of the moving Square
	xCoordinateMovingSquare = movingSquare->getXCoordinate();
	yCoordinateMovingSquare = movingSquare->getYCoordinate();

	//Downcast specified element of vector of Shape pointers to an actual
	//Rectangle
	movingRect = dynamic_cast<Rectangle *>(m_shapes[MOVING_RECT]);

	//Check if legal cast
	if (movingRect == nullptr)
	{
		throw exception("Illegal downcast to from a Shape to a Rectangle.");
	}

	//Assign x & y coordinate values of the moving Rectangle to static
	//variables holding the coordinate values of the moving Rectangle
	xCoordinateMovingRect = movingRect->getXCoordinate();
	yCoordinateMovingRect = movingRect->getYCoordinate();
}

//Determine whether to move Rectangle and Square if specific key is pressed
void Game::keyDownEvent(SDL_Event * e, Square *& movingSquare,
						Rectangle *& movingRect, int & xCoordinateMovingSquare,
						int & yCoordinateMovingRect)
{
	//Count number of times the user attempts to shoot the moving Rectangle
	static int countRects = 0;
	
	//Select actions based on key press
	switch (e->key.keysym.sym)
	{
		case SDLK_UP:		//Up press
		{
			//Shoot moving Rectangle upwards, and let moving Square keep moving
			upPressShootRect(movingSquare, movingRect, xCoordinateMovingSquare,
							 yCoordinateMovingRect);
			//Increment number of times the moving Rectangle is shot upwards
			countRects++;
			break;
		}
	}

	//If the user attempted to shoot the moving Rectangle at the moving Square
	//too many times without success
	if (countRects == MAX_NUM_TRIES)
	{
		//User loses the game
		m_loseGame = true;
	}
}

//Shoot moving Rectangle upwards, and let moving Square keep moving
void Game::upPressShootRect(Square *& movingSquare, Rectangle *& movingRect,
					int & xCoordinateMovingSquare, int & yCoordinateMovingRect)
{
	//Move Rectangle upwards while not at top of screen and while game has not
	//been won
	while (yCoordinateMovingRect >= 0 && m_winGame == false)
	{
		//Uses RGBA values for a white draw color
		SDL_SetRenderDrawColor(m_gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(m_gRenderer);

		//Render background texture with specified source & destination values
		m_textures[GAME_TEXTURE].renderTexture(m_gRenderer, 0, 0, SCREEN_WIDTH,
			SCREEN_HEIGHT, 0, 0, SCREEN_WIDTH,
			SCREEN_HEIGHT);

		//Decrement the y coordinate of the moving rectangle
		yCoordinateMovingRect -= MOV_RECT_DECREMENT_Y;
		//Increment the x coordinate of the moving square
		xCoordinateMovingSquare += MOV_SQR_INCREMENT_X;

		//Draw moving Rectangle up 1 frame; draw moving Square right 1 frame;
		//draw stationary Rectangle
		drawAllShapes(movingSquare, movingRect, xCoordinateMovingSquare,
					  yCoordinateMovingRect);

		//Pause for specified time
		SDL_Delay(DELAY_TIME);

		//Update screen
		SDL_RenderPresent(m_gRenderer);

		//Check for collision between moving Square and moving Rectangle
		if (detectCollision(movingSquare, movingRect) == true)
		{
			//Display texture that announces the win
			displayWinTexture();
		}
	}
}

//Keep square moving even when rectangle is not moving
void Game::continueMovingSquare(Square *& movingSquare, Rectangle *& movingRect,
					int & xCoordinateMovingSquare, int & yCoordinateMovingRect)
{
	//Clear screen
	//Uses RGBA values for a white draw color
	SDL_SetRenderDrawColor(m_gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(m_gRenderer);

	//Render background texture with specified source & destination values
	m_textures[GAME_TEXTURE].renderTexture(m_gRenderer, 0, 0, SCREEN_WIDTH,
										   SCREEN_HEIGHT, 0, 0, SCREEN_WIDTH,
										   SCREEN_HEIGHT);

	//Reset y coordinate for moving rect to place it back at bottom
	yCoordinateMovingRect = MOV_RECT_STARTING_Y;
	//Increment the x coordinate of the moving square
	xCoordinateMovingSquare += MOV_SQR_INCREMENT_X;

	//Draw moving Rectangle in default location at bottom of screen; draw
	//moving Square right 1 frame; draw stationary Rectangle
	drawAllShapes(movingSquare, movingRect, xCoordinateMovingSquare,
				  yCoordinateMovingRect);

	//Pause for specified time
	SDL_Delay(DELAY_TIME);

	//Update screen
	SDL_RenderPresent(m_gRenderer);
}

//Draw moving Rectangle, moving Square, and stationary Rectangle
void Game::drawAllShapes(Square *& movingSquare, Rectangle *& movingRect,
					int & xCoordinateMovingSquare, int & yCoordinateMovingRect)
{
	//If moving Square has reached right edge of screen
	if (xCoordinateMovingSquare >= SCREEN_WIDTH)
	{
		//Reset x coordinate for moving Square
		xCoordinateMovingSquare = 0;
		//Re-randomize color for moving Square to look like it's a new Square
		movingSquare->randomizeColor();
	}

	//Set the new x coordinate of the moving Square
	movingSquare->setXCoordinate(xCoordinateMovingSquare);
	//Set the new y coordinate of the moving rectangle
	movingRect->setYCoordinate(yCoordinateMovingRect);

	//Upcast the moving Square back to specified element of vector of Shape
	//pointers
	m_shapes[MOVING_SQUARE] = static_cast<Shape *>(movingSquare);
	//Upcast the moving Rectangle back to specified element of vector of Shape
	//pointers
	m_shapes[MOVING_RECT] = static_cast<Shape *>(movingRect);
	
	//Draw moving Square, stationary Rectangle, and moving Rectangle from the
	//specified vector of Shape pointers elements
	for (int i = 0; i < TOTAL_NUM_SHAPES; i++)
	{
		m_shapes[i]->fillShape(m_gRenderer);
		m_shapes[i]->outlineShape(m_gRenderer);
	}
}

//Check for collision between moving Square and moving Rectangle
bool Game::detectCollision(Square *& movingSquare, Rectangle *& movingRect)
{
	//Create and initialize the sides of the shapes
	int leftSquare = 0, leftRect = 0;
	int rightSquare = 0, rightRect = 0;
	int topSquare = 0, topRect = 0;
	int bottomSquare = 0, bottomRect = 0;

	//Calculate the location of the side of the moving Square
	leftSquare = movingSquare->getXCoordinate();
	rightSquare = movingSquare->getXCoordinate() + movingSquare->getWidth();
	topSquare = movingSquare->getYCoordinate();
	bottomSquare = movingSquare->getYCoordinate() + movingSquare->getHeight();

	//Calculate the location of the side of the moving Rectangle
	leftRect = movingRect->getXCoordinate();
	rightRect = movingRect->getXCoordinate() + movingRect->getWidth();
	topRect = movingRect->getYCoordinate();
	bottomRect = movingRect->getYCoordinate() + movingRect->getHeight();

	//If any sides from moving Square are outside of moving Rectangle
	if (bottomSquare <= topRect || topSquare >= bottomRect
		|| rightSquare <= leftRect || leftSquare >= rightRect)
	{
		//No collision
		m_winGame = false;
	}

	//Else no sides from moving Square are outside of moving Rectangle, then
	//there is overlap which means there is a collision
	else
	{
		m_winGame = true;
	}

	return m_winGame;
}

//Display texture that announces the win
void Game::displayWinTexture()
{
	//Clear screen
	//Uses RGBA values for a white draw color
	SDL_SetRenderDrawColor(m_gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(m_gRenderer);

	//Render game winning texture with specified source & destination values
	m_textures[WIN_GAME_TEXTURE].renderTexture(m_gRenderer, 0, 0, SCREEN_WIDTH,
										   SCREEN_HEIGHT, 0, 0, SCREEN_WIDTH,
										   SCREEN_HEIGHT);

	//Update screen
	SDL_RenderPresent(m_gRenderer);
}

//Display texture that announces the loss
void Game::displayLoseTexture()
{
	//Clear screen
	//Uses RGBA values for a white draw color
	SDL_SetRenderDrawColor(m_gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(m_gRenderer);

	//Render game winning texture with specified source & destination values
	m_textures[LOSE_GAME_TEXTURE].renderTexture(m_gRenderer, 0, 0, SCREEN_WIDTH,
		SCREEN_HEIGHT, 0, 0, SCREEN_WIDTH,
		SCREEN_HEIGHT);

	//Update screen
	SDL_RenderPresent(m_gRenderer);
}