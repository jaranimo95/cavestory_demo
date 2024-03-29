#ifndef sprite_h
#define sprite_h

#include <string>
#include <SDL2/SDL.h>

#include "rectangle.h"
#include "globals.h"

class Graphics;

/*
 * Sprite class
 * Holds all structs/functions for individual sprites
 */

class Sprite {
public:
	Sprite();
	Sprite(Graphics &graphics,
		   const std::string &filePath,
		   int sourceX, int sourceY,
		   int width, int height,
		   float posX, float
		   posY);

	virtual ~Sprite();
	virtual void update();
	
	void draw(Graphics &graphics,
			  int x,
			  int y);
	
	const Rectangle getBoundingBox() const;
	const sides::Side getCollisionSide(Rectangle &other) const;
	
protected:
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;
	
	Rectangle _boundingBox;
	
	float _x,_y;

};

#endif /* sprite_h */
