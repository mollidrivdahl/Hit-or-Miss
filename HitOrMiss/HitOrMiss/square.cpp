//Molli Drivdahl
//square.cpp

#include <cstdlib>
#include <ctime>
#include <exception>
using std::srand;
using std::time;
using std::exception;

#include "square.h"

//Default constructor
Square::Square() : Rectangle()
{
	srand((unsigned int)time(nullptr));	//Placed here b/c needs only run once

	randomizeColor();
}

//Overloaded constructor
//Always want squares to have width and height of 100
Square::Square(int x, int y) : Rectangle(x, y, 10, 10)
{
	srand((unsigned int)time(nullptr));	//Placed here b/c needs only run once

	randomizeColor();
}

//Copy constructor
//Invoke Rectangles's copy constructor passing the Square
//as the parameter
Square::Square(const Square & sqr) : Rectangle(sqr)
{
	for (int i = 0; i < TOTAL_NUM_SPECIFIERS; i++)
	{
		m_color[i] = sqr.m_color[i];
	}
}

//Default destructor
Square::~Square()
{
	m_xCoordinate = 0;
	m_yCoordinate = 0;
	m_width = 0;
	m_height = 0;
	
	for (int i = 0; i < TOTAL_NUM_SPECIFIERS; i++)
	{
		m_color[i] = 0;
	}
}

Square & Square::operator=(const Square & sqr)
{
	//Check if object is being assigned to itself
	if (this != &sqr)
	{
		//Invoke Quadrilateral's assignment operator
		Quadrilateral::operator=(sqr);

		//Assign data member values of sqr to the data
		//members of the this pointer
		for (int i = 0; i < TOTAL_NUM_SPECIFIERS; i++)
		{
			m_color[i] = sqr.m_color[i];
		}
	}
		return *this;
}

//Draw and fill a square shape with randomly generated colors
void Square::fillShape(SDL_Renderer * gRenderer)
{	
	SDL_Rect fillSquare = {m_xCoordinate, m_yCoordinate, m_width, m_height};
	SDL_SetRenderDrawColor(gRenderer, m_color[RED], m_color[GREEN],
						   m_color[BLUE], m_color[ALPHA]);
	SDL_RenderFillRect(gRenderer, &fillSquare);
}

//Draw outline of square shape
void Square::outlineShape(SDL_Renderer * gRenderer)
{
	SDL_Rect outlineSquare = {m_xCoordinate, m_yCoordinate, m_width, m_height};
	//Uses RGBA values for a black outline color
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderDrawRect(gRenderer, &outlineSquare);
}

void Square::randomizeColor()
{
	//Randomly give any color to each RGBA value
	m_color[RED] = rand() % 0xFF;
	m_color[GREEN] = rand() % 0xFF;
	m_color[BLUE] = rand() % 0xFF;
	m_color[ALPHA] = rand() % 0xFF;
}