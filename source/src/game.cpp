#include "game.h"
#include "graphics.h"
#include "input.h"

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game() {
	
}

void Game::gameLoop() {
	Graphics graphics;
	Input input;
	SDL_Event event;
	
	this->_player = AnimatedSprite(graphics, "./content/sprites/MyChar.png", 0, 0, 16, 16, 100, 100, 100);
	this->_player.setupAnimations();
	this->_player.playAnimation("RunLeft");
	
	int LAST_UPDATE_TIME = SDL_GetTicks();
	//Start Game Loop
	while(true) {
		input.beginNewFrame();
		
		if(SDL_PollEvent(&event)) {
			if(event.type==SDL_KEYDOWN) {
				if(event.key.repeat==0){
					input.keyDownEvent(event);
				}
			}
			else if(event.type==SDL_KEYUP) {
				input.keyUpEvent(event);
			}
			else if(event.type==SDL_QUIT) {
				return;
			}
		}
		if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) {
			return;
		}
		
		const int CURR_TIME_MS = SDL_GetTicks();
		int ELAP_TIME_MS = CURR_TIME_MS - LAST_UPDATE_TIME;
		this->update(std::min(ELAP_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURR_TIME_MS;
		
		this->draw(graphics);
	}
}

void Game::draw(Graphics &graphics) {
	graphics.clear();
	
	this->_player.draw(graphics, 100, 100);
	
	graphics.flip();
}

void Game::update(float elapsedTime) {
	this->_player.update(elapsedTime);
}

