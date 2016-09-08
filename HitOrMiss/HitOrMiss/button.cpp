//Molli Drivdahl
//button.cpp

#include "button.h"

//Default constructor
Button::Button() : m_currentButtonSprite(BUTTON_SPRITE_MOUSE_OUT),
				   m_buttonRelease(false)
{
	//Button may only ever be in this location
	m_position.x = BUTTON_X_COORDINATE;
	m_position.y = BUTTON_Y_COORDINATE;
}

//Default destructor
Button::~Button()
{
	//Reset members to default values
	m_position.x = BUTTON_X_COORDINATE;
	m_position.y = BUTTON_Y_COORDINATE;
	m_currentButtonSprite = BUTTON_SPRITE_MOUSE_OUT;
	m_buttonRelease= false;
}

//Handles mouse event
void Button::handleEvent(SDL_Event * e)
{
	//If mouse event happened
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN
		|| e->type == SDL_MOUSEBUTTONUP)
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if (x < m_position.x)
		{
			inside = false;
		}
		//Mouse is right of the button
		else if (x > m_position.x + BUTTON_WIDTH)
		{
			inside = false;
		}
		//Mouse above the button
		else if (y < m_position.y)
		{
			inside = false;
		}
		//Mouse below the button
		else if (y > m_position.y + BUTTON_HEIGHT)
		{
			inside = false;
		}

		//Mouse is outside button
		if (!inside)
		{
			m_currentButtonSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch (e->type)
			{
			case SDL_MOUSEMOTION:
				m_currentButtonSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;

			case SDL_MOUSEBUTTONDOWN:
				m_currentButtonSprite = BUTTON_SPRITE_MOUSE_DOWN;
				break;

			case SDL_MOUSEBUTTONUP:
				//Set flag to signal a mouse click
				m_buttonRelease = true;
				break;
			}
		}
	}
}

//Renders button to screen with specified texture
void Button::render(SDL_Renderer * gRenderer,
					TextureManager * buttonSpriteTexture)
{
	//Initialize sprite texture source coordinates
	int xSrc = 0;
	int ySrc = 0;
	int wSrc = BUTTON_WIDTH;
	int hSrc = BUTTON_HEIGHT;

	//Set source coordinates for piece of sprite texture to render
	if (m_currentButtonSprite == BUTTON_SPRITE_MOUSE_OUT)
	{
		xSrc = 0;
		ySrc = 0;
	}

	//Set source coordinates for piece of sprite texture to render
	else if (m_currentButtonSprite == BUTTON_SPRITE_MOUSE_OVER_MOTION)
	{
		xSrc = 100;
		ySrc = 0;
	}

	//Set source coordinates for piece of sprite texture to render
	else if (m_currentButtonSprite == BUTTON_SPRITE_MOUSE_DOWN)
	{
		xSrc = 200;
		ySrc = 0;
	}

	//Render peice of sprite texture
	buttonSpriteTexture->renderTexture(gRenderer, xSrc, ySrc, wSrc, hSrc,
									  m_position.x, m_position.y,
									  BUTTON_WIDTH, BUTTON_HEIGHT);
}

//Getter for the button release flag
bool Button::getButtonReleaseStatus()
{
	return m_buttonRelease;
}