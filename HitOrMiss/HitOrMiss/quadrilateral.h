//Molli Drivdahl
//quadrilateral.h

/*******************************************************************************
* Class: Quadrilateral
* 
* Description:
* 	This class is an Abstract Base Class that is derived directed from the Shape
* 	PVBC. This class does not implement either of the virtual methods from the
* 	Shape PVBC, but it provides implementation for other methods.
* 
* Constructors:
* 	Quadrilateral()
* 		Acts as the default constructor; initializes the protected data members
* 		to zero.
* 
* 	Quadrilateral(int x, int y, int w, int h)
* 		Acts as an overloaded constructor; initializes the protected data
* 		members to the parameter values.
* 
* 	Quadrilateral(const Quadrilateral & quad)
* 		Acts as the copy constructor; copies the member values of an existing
* 		"Quadrilateral" to a newly created "Quadrilateral", but the "quad"
* 		parameter will actually be either a Rectangle or Square object since no
* 		Quadrilateral objects can be created.
* 
* Destructors:
* 	virtual ~Quadrilateral()
* 		Acts as the default destructor.
* 
* Mutators:
* 	virtual Quadrilateral & operator=(const Quadrilateral & quad)
* 		Acts as the assignment operator; assigns the member values of an
* 		existing "Quadrilateral" to another "Quadrilateral", but the "quad"
* 		parameter will actually be either a Rectangle or Square object since no
* 		Quadrilateral objects can be created.
* 
* 	void setXCoordinate(int xCoordinate)
* 		Sets the m_xCoordinate data member to the parameter value.
* 
* 	void setYCoordinate(int yCoordinate)
* 		Sets the m_yCoordinate data member to the parameter value.
* 
* Methods:
* 	virtual void fillShape(SDL_Renderer * gRenderer) = 0;
* 		No implementation in this ABC.
* 
* 	virtual void outlineShape(SDL_Renderer * gRenderer) = 0;
* 		No implementation in this ABC.
* 
* 	int getXCoordinate()
* 		Returns the value of m_xCoordinate.
* 
* 	int getYCoordinate()
* 		Returns the value of m_yCoordinate.
* 
* 	int getWidth()
* 		Returns the value of m_width.
* 
* 	int getHeight()
* 		Returns the value of m_height.
*******************************************************************************/

#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include <SDL.h>

#include "shape.h"

//Element specifiers for Shapes
enum Shapes
{
	MOVING_SQUARE,
	STATIONARY_RECT,
	MOVING_RECT,
	TOTAL_NUM_SHAPES
};

class Quadrilateral : public Shape
{
	public:
		/***********************************************************************
		* Quadrilateral()
		* 	Purpose :
		* 		To initialize the protected data members to zero (DEFAULT
		* 		CONSTRUCTOR).
		* 	Entry :
		* 		No entry value.
		* 	Exit :
		* 		Protected data members are initialized to zero.
		***********************************************************************/
		Quadrilateral();

		/***********************************************************************
		* Quadrilateral(int x, int y, int w, int h)
		* 	Purpose :
		* 		To initialize the protected data members to the parameter
		* 		values (OVERLOADED CONSTRUCTOR).
		* 	Entry :
		* 		Four integers representing an x and y displacement and a width
		* 		and height.
		* 	Exit :
		* 		Protected data members are initialized to the parameter values.
		***********************************************************************/
		Quadrilateral(int x, int y, int w, int h);

		/***********************************************************************
		* Quadrilateral(const Quadrilateral & quad)
		* 	Purpose :
		* 		To copy the member values of an existing "Quadrilateral" to a
		* 		newly created "Quadrilateral", but the "quad" parameter will
		* 		actually be either a Rectangle or Square object since no
		* 		Quadrilateral objects can be created (COPY CONSTRUCTOR).
		* 	Entry :
		* 		A Quadrilateral object passed by const ref that was originally
		* 		either a Rectangle or a Square object.
		* 	Exit :
		* 		Members of the Quadrilateral parameter are copied to the created
		* 		Quadrilateral.
		***********************************************************************/
		Quadrilateral(const Quadrilateral & quad);

		/***********************************************************************
		* virtual ~Quadrilateral();
		* 	Purpose:
		* 		To deallocate memory, but no memory was allocated in this class
		* 		(DEFAULT DESTRUCTOR).
		* 	Entry:
		* 		No entry value.
		* 	Exit:
		* 		No exit value.
		***********************************************************************/
		virtual ~Quadrilateral();

		/***********************************************************************
		* Quadrilateral & operator=(const Quadrilateral & quad)
		* 	Purpose :
		* 		To assign the member values of an existing "Quadrilateral" to
		* 		another "Quadrilateral", but the "quad" parameter will
		* 		actually be either a Rectangle or Square object since no
		* 		Quadrilateral objects can be created (ASSIGNMENT OPERATOR).
		* 	Entry :
		* 		A Quadrilateral object passed by const ref that was originally
		* 		either a Rectangle or a Square object.
		* 	Exit :
		* 		Members of the Quadrilateral parameter are assigned to the
		* 		other Quadrilateral.
		***********************************************************************/
		Quadrilateral & operator=(const Quadrilateral & quad);

		/***********************************************************************
		* virtual void fillShape(SDL_Renderer * gRenderer) = 0;
		* 	Purpose :
		* 		To use polymophism to draw and fill a shape.
		* 	Entry :
		* 		The renderer for the window.
		* 	Exit :
		* 		A shape is drawn and filled based on which class implementation
		* 		of this method is used.
		***********************************************************************/
		virtual void fillShape(SDL_Renderer * gRenderer) = 0;

		/***********************************************************************
		* virtual void fillShape(SDL_Renderer * gRenderer) = 0;
		* 	Purpose :
		* 		To use polymophism to draw the outline of a shape.
		* 	Entry :
		* 		The renderer for the window.
		* 	Exit :
		* 		An outline of a shape is drawn based on which class
		* 		implementation of this method is used.
		***********************************************************************/
		virtual void outlineShape(SDL_Renderer * gRenderer) = 0;

		/***********************************************************************
		* void setXCoordinate(int xCoordinate)
		* 	Purpose :
		* 		To set the m_xCoordinate data member to the parameter value.
		* 	Entry :
		* 		An integer specifying the x coordinate value.
		* 	Exit :
		* 		The private data member is set to the value of the parameter.
		***********************************************************************/
		void setXCoordinate(int xCoordinate);

		/***********************************************************************
		* void setYCoordinate(int yCoordinate)
		* 	Purpose :
		* 		To set the m_yCoordinate data member to the parameter value.
		* 	Entry :
		* 		An integer specifying the y coordinate value.
		* 	Exit :
		* 		The private data member is set to the value of the parameter.
		***********************************************************************/
		void setYCoordinate(int yCoordinate);

		/***********************************************************************
		* int getXCoordinate()
		* 	Purpose :
		* 		To return the value of m_xCoordinate.
		* 	Entry :
		* 		No entry value.
		* 	Exit :
		* 		The value of m_xCoordinate is returned.
		***********************************************************************/
		int getXCoordinate();

		/***********************************************************************
		* int getXYCoordinate()
		* 	Purpose :
		* 		To return the value of m_yCoordinate.
		* 	Entry :
		* 		No entry value.
		* 	Exit :
		* 		The value of m_yCoordinate is returned.
		***********************************************************************/
		int getYCoordinate();

		/***********************************************************************
		* int getWidth()
		* 	Purpose :
		* 		To return the value of m_width.
		* 	Entry :
		* 		No entry value.
		* 	Exit :
		* 		The value of m_width is returned.
		***********************************************************************/
		int getWidth();

		/***********************************************************************
		* int getHeight()
		* 	Purpose :
		* 		To return the value of m_height.
		* 	Entry :
		* 		No entry value.
		* 	Exit :
		* 		The value of m_height is returned.
		***********************************************************************/
		int getHeight();

	protected:
		//Holds x coordinate value for location of shape
		int m_xCoordinate;

		//Holds y coordinate value for location of shape
		int m_yCoordinate;

		//Holds value for width of shape
		int m_width;

		//Holds value for height of shape
		int m_height;
};

#endif //QUADRILATERAL_H