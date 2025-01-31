#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Player.hpp"
#include "Constants.hpp"
#include "Bullet.hpp"


// visualize the game loop
// check for key press -> if pressed handle input
// update bullet position
// clean screen
// draw player
// draw bullet (if active)
// wait 50ms

// entry point of the program
int main() {
	Player player;
	Bullet bullet; // create bullet object

	if (_kbhit()) { // check if a key is pressed
		char key = _getch(); // function that reads a single character directly from the keyboard
		switch (key) { // _getchar returns true if a key is pressed
			case 75: // left arrow key code
				player.moveLeft();
				break;
			case 77: // right arrow
				player.moveRight();
				break;
			case 32: // spacebar
				if (!bullet.isActive) {
					bullet.x = player.x;
					bullet.y = player.y - 1; // the position of the bullet will be right above the player
					bullet.isActive = true;
				}
				break;

		}
	}

}
