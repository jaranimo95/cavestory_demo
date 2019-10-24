#ifndef player_h
#define player_h

#include "globals.h"
#include "animatedsprite.h"

class Graphics;

class Player : public AnimatedSprite {
public:
	Player();
	Player(Graphics &graphics, float x, float y);
	void draw(Graphics &graphics);
	void update(float elapsedTime);
	
	/*
	 * void moveLeft
	 * Moves player left by -(_dx)
	 */
	void moveLeft();
	
	/*
	 * void moveRight
	 * Moves player right by +(_dx)
	 */
	void moveRight();
	
	/*
	 * void stopMoving
	 * Stops player and plays idle animation in last direction facing
	 */
	void stopMoving();
	
	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();
	
	void handleTileCollisions(std::vector<Rectangle> &others);
	
	const float getX() const;
	const float getY() const;
	
private:
	float _dx, _dy;
	
	Direction _facing;
	
	bool _grounded;
};

#endif /* player_h */
