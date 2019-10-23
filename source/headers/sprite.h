#ifndef sprite_h
#define sprite_h

#include <string>
#include <SDL2/SDL.h>

class Graphics;

/*
 * Sprite class
 * Holds all structs/functions for individual sprites
 */

class Sprite {
public:
	Sprite();
	Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
	virtual ~Sprite();
	virtual void update();
	void draw(Graphics &graphics, int x, int y);
private:
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;
	
	float _x,_y;
};

#endif /* sprite_h */
