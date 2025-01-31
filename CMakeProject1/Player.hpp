#pragma once // ensures the header is included only once during compilation
#include "Constants.hpp"

class Player { // declare a class named player

public: // constructor to initialize position
	Player(); // declaration of the constructor. this is used to initialize the object so for this just the x and y positon
	// of the player. the functions are independent of the constructor
	// the constructor ensures the player object created starts with valid values
	int x; // member variable for position x
	int y; // member variable for position y

	void moveLeft(); // declaration of a method to move left
	void moveRight(); // declaration of a method to move right
};

