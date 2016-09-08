//Molli Drivdahl
//quadrilateral.cpp

#include "quadrilateral.h"

//Default constructor
Quadrilateral::Quadrilateral()
	: m_xCoordinate(0), m_yCoordinate(0), m_width(0), m_height(0)
{}

//Overloaded constructor
Quadrilateral::Quadrilateral(int x, int y, int w, int h)
	: m_xCoordinate(x), m_yCoordinate(y), m_width(w), m_height(h)
{}

//Copy constructor
Quadrilateral::Quadrilateral(const Quadrilateral & quad)
{
	m_xCoordinate = quad.m_xCoordinate;
	m_yCoordinate = quad.m_yCoordinate;
	m_width = quad.m_width;
	m_height = quad.m_height;
}

//Default destructor
Quadrilateral::~Quadrilateral()
{
	m_xCoordinate = 0;
	m_yCoordinate = 0;
	m_width = 0;
	m_height = 0;
}

//Assignment operator
Quadrilateral & Quadrilateral::operator=(const Quadrilateral & quad)
{
	//Check if object is being assigned to itself
	if (this != &quad)
	{
		m_xCoordinate = quad.m_xCoordinate;
		m_yCoordinate = quad.m_yCoordinate;
		m_width = quad.m_width;
		m_height = quad.m_height;
	}
		return *this;
}

//Setter for m_xCoordinate data member
void Quadrilateral::setXCoordinate(int xCoordinate)
{
	m_xCoordinate = xCoordinate;
}

//Setter for m_yCoordinate data member
void Quadrilateral::setYCoordinate(int yCoordinate)
{
	m_yCoordinate = yCoordinate;
}

//Getter for m_xCoordinate data member
int Quadrilateral::getXCoordinate()
{
	return m_xCoordinate;
}

//Getter for m_yCoordinate data member
int Quadrilateral::getYCoordinate()
{
	return m_yCoordinate;
}

//Getter for m_width data member
int Quadrilateral::getWidth()
{
	return m_width;
}

//Getter for m_height data member
int Quadrilateral::getHeight()
{
	return m_height;
}