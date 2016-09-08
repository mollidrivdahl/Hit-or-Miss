//Molli Drivdahl
//rectangle.h

/*******************************************************************************
* Class: Rectangle
* 
* Description:
* 	This class is derived from the Quadrilateral ABC. It provides implementation
* 	for the virtual methods that draw and fill a Shape so that a rectangle is
* 	drawn.
* 
* Constructors:
* 	Rectangle()
* 		Acts as defaulut constructor; initializes inherited data members to
* 		zero.
* 	
* 	Rectangle(int x, int y, int w, int h)
* 		Acts as overloaded constructor; initializes inherited data members to
* 		parameter values.
* 
* 	Rectangle(const Rectangle & rect)
* 		Acts as the copy constructor; copies the member values of an existing
* 		Rectangle to a newly created Rectangle by means of the Quadrilateral
* 		copy constructor.
* 
* Destructors:
* 	virtual ~Rectangle()
* 		Acts as default virtual destructor.
* 
* Mutators:
* 	Rectangle & operator=(const Rectangle & rect)
* 		Acts as the assignment operator; assigns the member values of an
* 		existing Rectangle to another Rectangle.
* 
* Methods:
* 	virtual void fillShape(SDL_Renderer * gRenderer)
* 		Draws and fills a rectangle shape based on values of data members.
* 
* 	virtual void outlineShape(SDL_Renderer * gRenderer)
* 		Draws outline of a rectangle shape based on values of data members.
*******************************************************************************/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "quadrilateral.h"

class Rectangle : public Quadrilateral
{
	public:
		/***********************************************************************
		* Rectangle()
		* 	Purpose :
		* 		To initialize the inherited data members to zero (DEFAULT
		* 		CONSTRUCTOR).
		* 	Entry :
		* 		No entry value.
		* 	Exit :
		* 		Inherited data members are initialized to zero.
		***********************************************************************/
		Rectangle();
		
		/***********************************************************************
		* Rectangle(int x, int y, int w, int h)
		* 	Purpose :
		* 		To initialize the inherited data members to the parameter
		* 		values (OVERLOADED CONSTRUCTOR).
		* 	Entry :
		* 		Four integers representing an x and y displacement and a width
		* 		and height.
		* 	Exit :
		* 		Inherited data members are initialized to the parameter values.
		***********************************************************************/
		Rectangle(int x, int y, int w, int h);

		/***********************************************************************
		* Rectangle(const Rectangle & rect)
		* 	Purpose :
		* 		To copy the member values of an existing Rectangle to a newly
		* 		created Rectangle by means of the Quadrilateral copy constructor
		* 		(COPY CONSTRUCTOR).
		* 	Entry :
		* 		A Rectangle object passed by const ref.
		* 	Exit :
		* 		Members of the Rectangle parameter are copied to the created
		* 		Rectangle.
		***********************************************************************/
		Rectangle(const Rectangle & rect);

		/***********************************************************************
		* virtual ~Rectangle();
		* 	Purpose:
		* 		To deallocate memory, but no memory was allocated in this class
		* 		(DEFAULT DESTRUCTOR).
		* 	Entry:
		* 		No entry value.
		* 	Exit:
		* 		No exit value.
		***********************************************************************/
		virtual ~Rectangle();

		/***********************************************************************
		* Rectangle & operator=(const Rectangle & rect)
		* 	Purpose :
		* 		To assign the member values of an existing Rectangle to another
		* 		Rectangle (ASSIGNMENT OPERATOR).
		* 	Entry :
		* 		A Rectangle object passed by const ref.
		* 	Exit :
		* 		Members of the Rectangle parameter are assign to the other
		* 		Rectangle.
		***********************************************************************/
		Rectangle & operator=(const Rectangle & rect);

		/***********************************************************************
		* virtual void fillShape(SDL_Renderer * gRenderer)
		* 	Purpose :
		* 		To use polymophism to draw and fill a shape.
		* 	Entry :
		* 		The renderer for the window.
		* 	Exit :
		* 		A rectangle is drawn and filled b/c this class's implementation
		* 		of this method is used with Rectangle objects.
		***********************************************************************/
		virtual void fillShape(SDL_Renderer * gRenderer);

		/***********************************************************************
		* virtual void fillShape(SDL_Renderer * gRenderer)
		* 	Purpose :
		* 		To use polymophism to draw the outline of a shape.
		* 	Entry :
		* 		The renderer for the window.
		* 	Exit :
		* 		An outline of a rectangle is drawn b/c this class's
		* 		implementation of this method is used with Rectangle objects.
		***********************************************************************/
		virtual void outlineShape(SDL_Renderer * gRenderer);

	protected:
		//Inherits all data members of Quadrilateral class
};

#endif //RECTANGLE_H