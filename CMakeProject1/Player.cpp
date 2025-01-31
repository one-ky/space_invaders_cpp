#include "Player.hpp"
#include "Constants.hpp"

Player::Player() {
	x = SCREEN_WIDTH / 2; // initialize x to the middle of the screen
	y = SCREEN_HEIGHT - 2; // initialize y near the bottom
}

void Player::moveLeft() {
	if (x > 0) // decrease x (move left) id not at the left edge
		x--;
}

void Player::moveRight() {
	if (x < 79) // increase x (move right) if not at the right edge
		x++; 
}