#ifndef graphics_h
#define graphics_h

/*  Graphics Library
 - Holds all data/structs/functions dealing with graphics generation for the game
*/

#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class Graphics {
public:
	Graphics();
	~Graphics();
	
	/*
	 * SDL_Surface* loadImage
	 * Loads image into _spriteSheets map if it doesn't already exist
	 * As a result, each image will only be loaded once.
	 * Returns the image from the map regardless of whether or not it was just loaded
	 */
	SDL_Surface* loadImage(const std::string &filePath);
	
	/*
	 * void blitSurface
	 * Draws a texture to a certain part of the screen
	 * sourceRectangle: what to draw to the screen
	 * destinationRectangle: where to draw the sourceRectangle on the screen
	 */
	void blitSurface(SDL_Texture* source,
					 SDL_Rect* sourceRectangle,
					 SDL_Rect* destinationRectangle);
	
	/* void flip
	 * Renders everything on the screen
	 */
	void flip();
	
	/* void clear
	 * Clears everything from the screen
	 */
	void clear();
	
	/* SDL_Renderer* getRenderer()
	 * Returns the renderer
	 */
	SDL_Renderer* getRenderer() const;
	
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	
	std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif /* graphics_h */
