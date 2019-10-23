#ifndef game_h
#define game_h

/*  Game Class
 - Holds all logic for our main game loop
 */

#include "animatedsprite.h"

class Graphics;

class Game {
public:
	Game();
	~Game();
private:
	
	/*
	 * void gameLoop
	 * Called upon game start, contains all game logic inc. event processing, frame limiting, etc.
	 */
	void gameLoop();
	
	/*
	 * void draw
	 * Called upon each frame, renders current game state on screen
	 */
	void draw(Graphics &graphics);
	
	/*
	 * void update
	 * Called at end of each frame
	 */
	void update(float elapsedTime);
	
	AnimatedSprite _player;
};

#endif /* game_h */
