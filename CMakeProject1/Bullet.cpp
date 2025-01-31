#include "Constants.hpp"
#include "Bullet.hpp"

//Constructor: Initialize bullet as inactive
Bullet::Bullet() {
	isActive = false;
}

void Bullet::update() {
	if (isActive) { // if the bullet is active, so is active is true
		y--; // move up

		// deactivate bullet if it goes off screen
		if (y < 0) {
			isActive = false;
		}
	}
}