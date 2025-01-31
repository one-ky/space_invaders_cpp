#pragma once
#include "Constants.hpp"

class Bullet {

public:
	int x; // x coordiante of bullet
	int y; // y coordiante of bullet
	bool isActive; // is the bullet currently moving

	Bullet(); // constructor
	void update(); // moves the bullet upward from the player
};