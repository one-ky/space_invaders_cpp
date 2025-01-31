#pragma once
#include "Constants.hpp"

class Enemy {
public:
	int x; // x coordinates
	int y; // y coordinates
	bool isAlive; // is the ememy alive?

	Enemy(); // constructor (sets is alive to true in cpp file. when we create an enemy we 
	//want them to start with the condition of being alive
};