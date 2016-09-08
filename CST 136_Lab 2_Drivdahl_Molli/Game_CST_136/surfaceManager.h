//Molli Drivdahl
//surfaceManager.h

/*******************************************************************************
* Class: SurfaceManager
* 
* Description:
* 	This class handles the methods that should be associated with an
* 	SDL_Surface. The actual surface is the private data member, and a major
* 	purpose to this class is to load a bitmap to the surface data member.
* 
* Constructors:
* 	SurfaceManager()
* 		Acts as the default constructor; initializes private data member to
* 		nullptr.
* 
* Destructors:
* 	~SurfaceManager()
* 		Acts as the default destructor.
* 
* Mutators:
* 	void setSurface(SDL_Surface * setter)
* 		Sets value of m_surface private data member to the value of the
* 		parameter.
* 
* 	bool loadSurface(string path, SDL_Surface * screenSurface))
* 		Loads a bitmap image given as the parameter to an optimized local
* 		surface, assigns that surface to the surface data member, and then
* 		returns whether the loading was successful.
* 
* 	void freeSurface()
* 		Deallocates surface and resets surface to nullptr.
* 
* Methods:
* 	SDL_Rect softStretch()
* 		Determines the size for bitmaps to be stretched in a surface, and
* 		returns that rectangle size.
* 
* 	SDL_Surface * getScreenSurface()
* 		Returns value of m_surface private data member.
*******************************************************************************/

#ifndef SURFACE_MANAGER_H
#define SURFACE_MANAGER_H

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <string>
using std::string;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class SurfaceManager
{
	public:
		/***********************************************************************
		* SurfaceManager()
		* 	Purpose :
		* 		To initialize the private data member to a known value
		* 		(DEFAULT CONSTRUCTOR).
		* 	Entry :
		* 		No entry value.
		* 	Exit :
		* 		The private data member is assigned to nullptr.
		***********************************************************************/
		SurfaceManager();

		/***********************************************************************
		* ~SurfaceManager()
		* 	Purpose :
		* 		To deallocate memory, but just makes call to the freeSurface()
		* 		method to do this (DEFAULT DESTRUCTOR).
		* 	Entry :
		* 		No entry value.
		* 	Exit :
		* 		The surface data member is deallocated.
		***********************************************************************/
		~SurfaceManager();

		/***********************************************************************
		* bool loadSurface(string path, SDL_Surface * screenSurface)
		* 	Purpose :
		* 		To load a bitmap image given as the parameter to an optimized
		* 		local surface, assign that surface to the surface data member,
		* 		and then return whether the loading was successful.
		* 	Entry :
		* 		A string with the path to a bitmap, and the screen surface.
		* 	Exit :
		* 		The surface data member is assigned a value, and the success
		* 		flag is returned.
		***********************************************************************/
		bool loadSurface(string path, SDL_Surface * screenSurface);

		/***********************************************************************
		* SDL_Rect softStretch()
		* 	Purpose :
		* 		To determine the size for bitmaps to be stretched in a surface,
		* 		and then return that rectangle size.
		* 	Entry :
		* 		No entry value.
		* 	Exit :
		* 		The SDL_Rect variable with the surface size dimensions is
		* 		returned.
		***********************************************************************/
		SDL_Rect softStretch();

		/***********************************************************************
		* void setSurface(SDL_Surface * setter)
		* 	Purpose :
		* 		To set the value of the parameter to the private data member
		* 		representing the surface
		* 	Entry :
		* 		An SDL_Surface pointer.
		* 	Exit :
		* 		The parameter value is assigned to the private data member.
		***********************************************************************/
		void setSurface(SDL_Surface * setter);

		/***********************************************************************
		* SDL_Surface * getSurface()
		* 	Purpose :
		* 		To return the value of the private data member representing the
		* 		surface.
		* 	Entry :
		* 		No entry value.
		* 	Exit :
		* 		The private data member representing the surface is returned.
		***********************************************************************/
		SDL_Surface * getSurface();
		
		/***********************************************************************
		* void freeSurface()
		* 	Purpose :
		* 		To deallocate the surface and reset to nullptr, if necessary to
		* 		do so before the destructor is called.
		* 	Entry :
		* 		No entry value.
		* 	Exit :
		* 		Surface is deallocated and reset to nullptr.
		***********************************************************************/
		void freeSurface();

	private:
		//The actual surface
		SDL_Surface * m_surface;
};

#endif //SURFACE_MANAGER_H