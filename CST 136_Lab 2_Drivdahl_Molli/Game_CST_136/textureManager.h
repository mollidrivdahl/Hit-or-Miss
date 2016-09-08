//Molli Drivdahl
//textureManager.h

/*******************************************************************************
* Class: TextureManager
* 
* Description:
* 	This class handles the methods that should be associated with an
* 	SDL_Texture. The actual texture is the private data member, and the major
* 	purposes to this class is to load a bitmap to the texture data member and
* 	render this texture to the screen.
* 
* Constructors:
* 	TextureManager()
* 		Acts as the default constructor; initializes private data member to
* 		nullptr.
* 
* 	TextureManager(SDL_Renderer * gRenderer, SurfaceManager * surface)
* 		Acts as a conversion constructor; assigns the value of the surface
* 		parameter to the private texture data member via conversion.
* 
* Destructors:
* 	~TextureManager()
* 		Acts as the default destructor.
* 
* Mutators:
* 	bool loadTexture(SDL_Renderer * gRenderer, string path)
* 		Loads a bitmap image given as the parameter and assigns it to the
* 		private texture data member.
* 	
* 	void freeTexture()
* 		Deallocates texture and resets texture to nullptr.
* 
* Methods:
* 	void renderTexture(SDL_Renderer * gRenderer, int xSrc, int ySrc, int wSrc,
* 					   int hSrc, int xDest, int yDest, int wDest, int hDest)
* 		Renders the texture to the screen based on specified source and
* 		destination values from the parameters.
* 	
* 	SDL_Texture * getTexture();
* 		Returns value of m_surface private data member.
*******************************************************************************/


#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

#include "surfaceManager.h"

//Element specifiers for Textures
enum Textures
{
	GAME_TEXTURE,
	BUTTON_SPRITE_TEXTURE,
	WIN_GAME_TEXTURE,
	LOSE_GAME_TEXTURE,
	TOTAL_NUM_TEXTURES
};

class TextureManager
{
	public:
		/***********************************************************************
		* TextureManager()
		* 	Purpose :
		* 		To initialize the private data member to a known value
		* 		(DEFAULT CONSTRUCTOR).
		* 	Entry :
		* 		No entry value.
		* 	Exit :
		* 		The private data member is assigned to nullptr.
		***********************************************************************/
		TextureManager();

		/***********************************************************************
		* TextureManager(SDL_Renderer * gRenderer, SurfaceManager * surface)
		* 	Purpose :
		* 		To assign the value of the surface parameter to the private
		* 		texture data member via conversion (CONVERSION CONSTRUCTOR).
		* 	Entry :
		* 		The renderer for the window and a SurfaceManager object.
		* 	Exit :
		* 		The surface value is assigned to the texture.
		***********************************************************************/
		TextureManager(SDL_Renderer * gRenderer, SurfaceManager * surface);

		/***********************************************************************
		* ~TextureManager()
		* 	Purpose :
		* 		To deallocate memory, but just makes call to the freeTexture()
		* 		method to do this (DEFAULT DESTRUCTOR).
		* 	Entry :
		* 		No entry value.
		* 	Exit :
		* 		The texture data member is deallocated.
		***********************************************************************/
		~TextureManager();

		/***********************************************************************
		* bool loadTexture(SDL_Renderer * gRenderer, string path)
		* 	Purpose :
		* 		To load a bitmap image given as the parameter and assign it to
		* 		the private texture data member.
		* 	Entry :
		* 		The renderer for the window and a string with the path to a
		* 		bitmap.
		* 	Exit :
		* 		The texture data member is assigned a value, and the success
		* 		flag is returned.
		***********************************************************************/
		bool loadTexture(SDL_Renderer * gRenderer, string path);

		/***********************************************************************
		* void renderTexture(SDL_Renderer * gRenderer, int xSrc, int ySrc,
		* 				   int wSrc, int hSrc, int xDest, int yDest, int wDest,
		* 				   int hDest)
		* 	Purpose :
		* 		To render the texture to the screen based on specified source
		* 		and destination values from the parameters.
		* 	Entry :
		* 		The renderer for the window, four integers representing an x
		* 		and y displacement and a width and height for the source
		* 		rectangle, and four integers representing an x and y
		* 		displacement and a width and height for the destination
		* 		rectangle.
		* 	Exit :
		* 		The texture is rendered to the screen.
		***********************************************************************/
		void renderTexture(SDL_Renderer * gRenderer, int xSrc, int ySrc,
						   int wSrc, int hSrc, int xDest, int yDest, int wDest,
						   int hDest);

		/***********************************************************************
		* void freeTexture()
		* 	Purpose :
		* 		To deallocate the texture and reset to nullptr, if necessary to
		* 		do so before the destructor is called.
		* 	Entry :
		* 		No entry value.
		* 	Exit :
		* 		Texture is deallocated and reset to nullptr.
		***********************************************************************/
		void freeTexture();

		/***********************************************************************
		* SDL_Texture * getTexture()
		* 	Purpose :
		* 		To return the value of the private data member representing the
		* 		texture.
		* 	Entry :
		* 		No entry value.
		* 	Exit :
		* 		The private data member representing the texture is returned.
		***********************************************************************/
		SDL_Texture * getTexture();

	private:
		//The actual texture
		SDL_Texture * m_texture;
};

#endif //TEXTURE_MANAGER_H