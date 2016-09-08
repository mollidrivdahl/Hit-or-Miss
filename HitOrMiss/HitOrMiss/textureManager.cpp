//Molli Drivdahl
//textureManager.cpp

#include <iostream>
using std::cout;

#include "textureManager.h"

//Default constructor
TextureManager::TextureManager() : m_texture(nullptr)
{}

//Overloaded constructor
TextureManager::TextureManager(SDL_Renderer * gRenderer,
							   SurfaceManager * surface)
{
	//The final texture
	SDL_Texture * newTexture = nullptr;

	//Create texture from surface pixels
	newTexture = SDL_CreateTextureFromSurface(gRenderer, surface->getSurface());

	//Assign texture to texture data member
	m_texture = newTexture;
}

//Default destructor
TextureManager::~TextureManager()
{
	freeTexture();
}

//Loads a bitmap to the texture
bool TextureManager::loadTexture(SDL_Renderer * gRenderer, string path)
{
	//Get rid of preexisting texture
	freeTexture();

	//The final texture
	SDL_Texture * newTexture = nullptr;

	//Load image at specified path
	SDL_Surface * loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == nullptr)
	{
		cout << "Unable to load image %s! SDL Error: %s\n" << path.c_str()
			 << SDL_GetError();
	}
	else
	{
		//Color key image to RGB values for Cyan
		SDL_SetColorKey(loadedSurface, SDL_TRUE,
						SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == nullptr)
		{
			cout << "Unable to create texture from %s! SDL Error: %s\n"
				 << path.c_str() << SDL_GetError();
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Assign local newTexture to actual texture data member
	m_texture = newTexture;

	bool success = (m_texture != nullptr);

	//Return success
	return success;
}

//Render texture to screen with specified source and destination values
void TextureManager::renderTexture(SDL_Renderer * gRenderer, int xSrc, int ySrc,
								   int wSrc, int hSrc, int xDest, int yDest,
								   int wDest, int hDest)
{
	//Create rectangles with specified source & destination values
	SDL_Rect src = { xSrc, ySrc, wSrc, hSrc };
	SDL_Rect dest = { xDest, yDest, wDest, hDest };
	
	//Render to screen
	SDL_RenderCopy(gRenderer, m_texture, &src, &dest);
}

//Deallocate texture
void TextureManager::freeTexture()
{
	//Free texture if it exists
	if (m_texture != nullptr)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
	}
}

//Getter for texture
SDL_Texture * TextureManager::getTexture()
{
	return m_texture;
}