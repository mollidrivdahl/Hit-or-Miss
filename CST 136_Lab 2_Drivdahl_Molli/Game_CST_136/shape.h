//Molli Drivdahl
//shape.h

/*******************************************************************************
* Class: Shape
* 
* Description:
* 	This class is a Pure Virtual Base Class that does not implement methods.
* 
* Constructors
* 	<NONE>
* 
* Destructors
* 	<NONE>
* 
* Mutators:
* 	<NONE>
* 
* Methods:
* 	virtual void fillShape(SDL_Renderer * gRenderer) = 0;
* 		No implementation in PVBC.
* 
* 	virtual void outlineShape(SDL_Renderer * gRenderer) = 0;
* 		No implementation in PVBC.
*******************************************************************************/

#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
	public:
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
};

#endif //SHAPE_H