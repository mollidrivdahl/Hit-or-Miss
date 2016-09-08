//Molli Drivdahl
//square.h

/*******************************************************************************
* Class: Square (inherits from Rectangle class)
* 
* Description:
* 	This class inherits from the Rectangle class, which is derived from the
* 	Quadrilateral ABC. It provides implementation for the virtual methods that
* 	draw and fill a Shape so that a square is drawn. Squares are drawn with a
* 	random fill color.
* 
* Constructors:
* 	Square()
* 		Acts as the default constructor; initializes the inherited and protected
* 		data members to zero. 
* 	
* 	Square(int x, int y)
* 		Acts as overloaded constructor; initializes inherited m_xCoordinate and
* 		m_yCoordinate data members to parameter values, initializes inherited
* 		m_width and m_height to zero, and initializes the elements of m_color
* 		array to zero.
* 
* 	Square(const Square & sqr)
* 		Acts as the copy constructor; copies the member values of an existing
* 		Square to a newly created Square by means of the Rectangle copy
* 		constructor.
* 
* Destructors:
* 	virtual ~Square()
* 		Acts as default virtual destructor.
* 
* Mutators:
* 	Square & operator=(const Square & sqr)
* 		Acts as the assignment operator; assigns the member values of an
* 		existing Square to another Square.
* 
* 	void randomizeColor()
* 		Sets random color values to the elements of the m_color array to
* 		randomize the fill color of the Square.
* 
* Methods:
* 	virtual void fillShape(SDL_Renderer * gRenderer)
* 		Draws and fills a square shape based on values of data members.
* 
* 	virtual void outlineShape(SDL_Renderer * gRenderer)
* 		Draws outline of a square shape based on values of data members.
*******************************************************************************/

#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"
#include "textureManager.h"

//Used with m_color array to specify the RGBA fields
enum RGBA
{
	RED,
	GREEN,
	BLUE,
	ALPHA,
	TOTAL_NUM_SPECIFIERS
};

class Square : public Rectangle
{
	public:
		/***********************************************************************
		* Square()
		* 	Purpose :
		* 		To initialize the inherited and protected data members to zero
		* 		(DEFALUT CONSTRUCTOR).
		* 	Entry :
		* 		No entry value.
		* 	Exit :
		* 		Inherited and protected data members are initialized to zero.
		***********************************************************************/
		Square();
		
		/***********************************************************************
		* Square(int x, int y)
		* 	Purpose :
		* 		To initialize the inherited m_xCoordinate and m_yCoordinate data
		* 		members to parameter values, the inherited m_width and m_height
		* 		to zero, and the elements of m_color array to zero (OVERLOADED
		* 		CONSTRUCTOR).
		* 	Entry :
		* 		Two integers representing an x and y displacement.
		* 	Exit :
		* 		Inherited and protected data members are initialized to known
		* 		values.
		***********************************************************************/
		Square(int x, int y);

		/***********************************************************************
		* Square(const Square & sqr)
		* 	Purpose :
		* 		To copy the member values of an existing Square to a newly
		* 		created Square by means of the Rectangle copy constructor (COPY
		* 		CONSTRUCTOR).
		* 	Entry :
		* 		A Square object passed by const ref.
		* 	Exit :
		* 		Members of Square parameter are copied to the created Square.
		***********************************************************************/
		Square(const Square & sqr);

		/***********************************************************************
		* virtual ~Square()
		* 	Purpose:
		* 		To deallocate memory, but no memory was allocated in this class
		* 		(DESTRUCTOR).
		* 	Entry:
		* 		No entry value.
		* 	Exit:
		* 		No exit value.
		***********************************************************************/
		virtual ~Square();

		/***********************************************************************
		* Square & operator=(const Square & sqr)
		* 	Purpose :
		* 		To assign the member values of an existing Square to another
		* 		Square (ASSIGNMENT OPERATOR).
		* 	Entry :
		* 		A Square object passed by const ref.
		* 	Exit :
		* 		Members of the Square parameter are assign to the other Square.
		***********************************************************************/
		Square & operator=(const Square & sqr);

		/***********************************************************************
		* virtual void fillShape(SDL_Renderer * gRenderer)
		* 	Purpose :
		* 		To use polymophism to draw and fill a shape.
		* 	Entry :
		* 		The renderer for the window.
		* 	Exit :
		* 		A square is drawn and filled b/c this class's implementation of
		* 		this method is used with Square objects.
		***********************************************************************/
		virtual void fillShape(SDL_Renderer * gRenderer);

		/***********************************************************************
		* virtual void outlineShape(SDL_Renderer * gRenderer)
		* 	Purpose :
		* 		To use polymophism to draw the outline of a shape.
		* 	Entry :
		* 		The renderer for the window.
		* 	Exit :
		* 		An outline of a square is drawn b/c this class's implementation
		* 		of this method is used with Square objects.
		***********************************************************************/
		virtual void outlineShape(SDL_Renderer * gRenderer);

		/***********************************************************************
		* void randomizeColor()
		* 	Purpose :
		* 		To set random color values to the elements of the m_color array
		* 		to randomize the fill color of the Square.
		* 	Entry :
		* 		No entry value.
		* 	Exit :
		* 		Random color values are assigned to each element of the m_color
		* 		array.
		***********************************************************************/
		void randomizeColor();

	protected:
		//Inherits all data members of Rectangle class from Quadrilateral class

		//Array of integers to hold color values for each RGBA field
		int m_color[TOTAL_NUM_SPECIFIERS];
};

#endif SQUARE_H