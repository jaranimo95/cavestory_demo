#include "graphics.h"
#include "player.h"

namespace player_constants {
	const float WALK_SPEED = 0.2f;
	const char* CHAR_IMG = "./content/sprites/MyChar.png";
	const float GRAVITY = 0.002f;
	const float GRAVITY_CAP = 0.8f;
}

Player::Player() {}

Player::Player(Graphics &graphics, float x, float y) :
	AnimatedSprite(graphics, player_constants::CHAR_IMG, 0, 0, 16, 16, x, y, 100),
	_dx(0),
	_dy(0),
	_facing(RIGHT),
	_grounded(false)
{
	graphics.loadImage(player_constants::CHAR_IMG);
	this->setupAnimations();
	this->playAnimation("RunRight");
}

void Player::setupAnimations() {
	this->addAnimation(1, 0, 0, "IdleLeft", 16, 16, Vector2(0,0));
	this->addAnimation(1, 0, 16, "IdleRight", 16, 16, Vector2(0,0));
	this->addAnimation(3, 0, 0, "RunLeft", 16, 16, Vector2(0,0));
	this->addAnimation(3, 0, 16, "RunRight", 16, 16, Vector2(0,0));
}

void Player::animationDone(std::string currentAnimation) {}

const float Player::getX() const {
	return this->_x;
}

const float Player::getY() const {
	return this->_y;
}

void Player::moveLeft() {
	this->_dx = -player_constants::WALK_SPEED;
	this->playAnimation("RunLeft");
	this->_facing = LEFT;
}

void Player::moveRight() {
	this->_dx = player_constants::WALK_SPEED;
	this->playAnimation("RunRight");
	this->_facing = RIGHT;
}

void Player::stopMoving() {
	this->_dx = 0.0f;
	this->playAnimation(this->_facing == RIGHT ? "IdleRight" : "IdleLeft");
}

/* void handleTileCollisions
 * Handle all player collisions with tiles
 */
void Player::handleTileCollisions(std::vector<Rectangle> &others) {
	//Figure out what side the collisions is happening on
	for(int i = 0; i < others.size(); i++) {
		sides::Side collisionSide = Sprite::getCollisionSide(others.at(i));
		if(collisionSide != sides::NONE) {
			switch(collisionSide) {
				case sides::TOP:
					this->_y = others.at(i).getBottom();
					this->_dy = 0;
					break;
					
				case sides::BOTTOM:
					this->_y = others.at(i).getTop() - this->_boundingBox.getHeight() - 1;
					this->_dy = 0;
					this->_grounded = true;
					break;
				
				case sides::LEFT:
					this->_x = others.at(i).getRight() + 1;
					break;
				
				case sides::RIGHT:
					this->_x = others.at(i).getLeft() - this->_boundingBox.getWidth() - 1;
					break;
			}
		}
	}
}

void Player::update(float elapsedTime) {
	//Apply gravity
	if(this->_dy <= player_constants::GRAVITY_CAP) {
		this->_dy += player_constants::GRAVITY * elapsedTime;
	}
	
	//Move by dx
	this->_x += this->_dx * elapsedTime; // Move bby a certain amount based off your frame rate
	//Move by dy
	this->_y += this->_dy *elapsedTime;
	
	AnimatedSprite::update(elapsedTime);
}

void Player::draw(Graphics &graphics) {
	AnimatedSprite::draw(graphics, this->_x, this->_y);
}


