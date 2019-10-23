#ifndef animatedsprite_h
#define animatedsprite_h

#include <map>
#include <string>
#include <vector>

#include "globals.h"
#include "sprite.h"

class Graphics;

/* Graphics class
 * Holds information for animating sprites
 */

class AnimatedSprite : public Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(Graphics &graphics,
				   const std::string &filePath,
				   int sourceX, int sourceY,
				   int width,
				   int height,
				   float posX,
				   float posY,
				   float timeToUpdate);
	
	/*
	 * void playAnimation
	 * Plays animation provided if it's not already playing
	 */
	void playAnimation(std::string animation,
					   bool once = false);
	
	/*
	 * void update
	 * Updates animation sprite timer
	 */
	void update(float elapsedTime);
	
	/*
	 * void draw
	 * Draws sprite on screen
	 */
	void draw(Graphics &graphics,
			  int x,
			  int y);
	
	
protected:
	double _timeToUpdate;
	bool _currentAnimationOnce;
	std::string _currentAnimation;
	
	/*
	 * void addAnimation
	 * Adds an animation to the map of animations for the sprite
	 */
	void addAnimation(int frames,
					  int x,
					  int y,
					  std::string name,
					  int width,
					  int height,
					  Vector2 offset);
	
	/*
	 * void resetAnimations
	 * Resets all animations associated with the sprite
	 */
	void resetAnimations();
	
	/*
	 * void stopAnimation
	 * Stops current animations
	 */
	void stopAnimation();
	
	/*
	 * void setVisible
	 * Sets visibbility of the animated sprite
	 */
	void setVisible(bool visible);
	
	/*
	 * void animationDone
	 * Logic that happens when an animation ends
	 */
	void virtual animationDone(std::string currentAnimation) = 0;
	
	/*
	 * void setupAnimations
	 * A required function that sets up all animations for the sprite
	 */
	virtual void setupAnimations() = 0;
	
	
private:
	std::map<std::string, std::vector<SDL_Rect> > _animations;
	std::map<std::string, Vector2> _offsets;

	int _frameIndex;
	double _timeElapsed;
	bool _visible;
};

#endif /* animatedsprite_h */
