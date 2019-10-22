#include "graphics.h"
#include "SDL2/SDL.h"

/*  Graphics Library
	- Holds all data/structs/functions dealing with graphics generation for the game

 			Created by Christian Jarani on 10/22/19.
 			Copyright © 2019 majula. All rights reserved.
*/

Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_render);
	SDL_SetWindowTitle(this->_window,"cavestory");
}

Graphics::~Graphics() {
	SDL_DestroyWindow(this->_window);
}


