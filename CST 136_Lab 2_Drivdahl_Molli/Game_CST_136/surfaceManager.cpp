//Molli Drivdahl
//surfaceManager.cpp

#include <iostream>
using std::cout;

#include "surfaceManager.h"

//Default constructor
SurfaceManager::SurfaceManager() : m_surface(nullptr)
{}

//Default destructor
SurfaceManager::~SurfaceManager()
{
	freeSurface();
}

//Loads a bitmap to the surface
bool SurfaceManager::loadSurface(string path, SDL_Surface * screenSurface)
{
	//The final optimized image
	SDL_Surface * optimizedSurface = nullptr;

	//Load image at specified path
	SDL_Surface * loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == nullptr)
	{
		cout << "Unable to load image %s! SDL Error: %s\n" << path.c_str()
			 << SDL_GetError();
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface,
											 screenSurface->format, '\0');
		if (optimizedSurface == nullptr)
		{
			cout << "Unable to optimize image %s! SDL Error: %s\n"
				 << path.c_str() << SDL_GetError();
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Assign optimized surface to actual surface data member
	m_surface = optimizedSurface;

	bool success = (m_surface != nullptr);

	//Return success
	return success;
}

//Sets the size for bitmaps to be stretched in a surface
SDL_Rect SurfaceManager::softStretch()
{
	SDL_Rect stretchRect;
	stretchRect.x = 0;
	stretchRect.y = 0;
	stretchRect.w = SCREEN_WIDTH;
	stretchRect.h = SCREEN_HEIGHT;

	return stretchRect;
}

//Setter for surface
void SurfaceManager::setSurface(SDL_Surface * setter)
{
	m_surface = setter;
}

//Getter for surface
SDL_Surface * SurfaceManager::getSurface()
{
	return m_surface;
}

//Deallocate surface and reset to nullptr
void SurfaceManager::freeSurface()
{
	//Free surface if it exists
	if (m_surface != nullptr)
	{
		SDL_FreeSurface(m_surface);
		m_surface = nullptr;
	}
}