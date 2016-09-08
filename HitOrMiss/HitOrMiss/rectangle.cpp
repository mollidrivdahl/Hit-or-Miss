//Molli Drivdahl
//rectangle.cpp

#include "rectangle.h"

//Default constructor
Rectangle::Rectangle() : Quadrilateral()
{}

//Overloaded constructor
Rectangle::Rectangle(int x, int y, int w, int h) 
					: Quadrilateral(x, y, w, h)
{}

//Copy constructor
//Invoke Quadrilateral's copy constructor passing the Rectangle
//as the parameter
Rectangle::Rectangle(const Rectangle & rect) : Quadrilateral(rect)
{}

//Default destructor
Rectangle::~Rectangle()
{
	m_xCoordinate = 0;
	m_yCoordinate = 0;
	m_width = 0;
	m_height = 0;
}

//Assignment operator
Rectangle & Rectangle::operator=(const Rectangle & rect)
{
	//Check if object is being assigned to itself
	if (this != &rect)
	{
		//Invoke Quadrilateral's assignment operator
		Quadrilateral::operator=(rect);
	}
		return *this;
}

//Draw and fill a rectangle shape
void Rectangle::fillShape(SDL_Renderer * gRenderer)
{
	SDL_Rect fillRect = { m_xCoordinate, m_yCoordinate, m_width, m_height };
	//Uses RGBA values for a purple fill color
	SDL_SetRenderDrawColor(gRenderer, 0x77, 0x00, 0x77, 0xFF);
	SDL_RenderFillRect(gRenderer, &fillRect);
}

//Draw outline of a rectangle shape
void Rectangle::outlineShape(SDL_Renderer * gRenderer)
{
	SDL_Rect outlineRect = { m_xCoordinate, m_yCoordinate, m_width, m_height };
	//Uses RGBA values for a black outline color
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderDrawRect(gRenderer, &outlineRect);
}