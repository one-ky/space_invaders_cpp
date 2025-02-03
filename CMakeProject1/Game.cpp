#include "Game.hpp"
#include <iostream>
#include <conio.h>
#include <Windows.h>

// initialize the game state when a game object is created
Game::Game() {
	initializeEnemies();
}

// position the enemies in a grid to start the game
void Game::initializeEnemies() {
	for (int row = 0; row < ENEMY_ROWS; row++) { 
		for (int col = 0; col < ENEMY_COLS; col++) { // loop through 2d array and set each enemies x and y location
			enemies[row][col].x = 5 + col * 4;
			enemies[row][col].y = 2 + row * 2;
		}
	}
}

// MAIN GAME LOOP
void Game::run() {
	// hide console cursor
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = 0; 
	SetConsoleCursorInfo(hConsole, &cursorInfo);
	// game loop
	while (true) {
		handleInput(); // check player input
		update(); // update gae state (bullets, enemies)
		render(hConsole); // draw everything
		Sleep(1); // slow down the loop
	}
}

// handle input
void Game::handleInput() {
	if (_kbhit()) { // if a key is pressed
		char key = _getch(); // read the key value
		switch (key) {
		case 75: player.moveLeft(); break; // left arrow
		case 77: player.moveRight(); break; // right arrow
		case 32: // space bar -- fires a bullet
			if (!bullet.isActive) {
				bullet.x = player.x;
				bullet.y = player.y - 1;
				bullet.isActive = true;
			}
			break;
		}
	}
}

// update game state 
void Game::update() {
	bullet.update(); // move bullet upward if active
	updateEnemies(); // move enemies and check edge collisions
	checkCollisions(); // detect if bullet hit enemy
}

// move enemies and handle edge detection
void Game::updateEnemies() {
	enemyMoveCounter++; // increment counter to track # frames passed since last enemy movement
	if (enemyMoveCounter >= enemySpeed) { // checks if its time to move enemies
		enemyMoveCounter = 0; // resets counter after enemies have been moved

		bool shouldMoveDown = false; // flag to track if enemies should move down (if enemies hit edge of screen)
		for (int row = 0; row < ENEMY_ROWS; row++) { // iterate over enemy grid
			for (int col = 0; col < ENEMY_COLS; col++) {
				if (enemies[row][col].isAlive) { // skip dead enemies
					int newX = enemies[row][col].x + enemyDir; // calculate enemies next position
					if (newX < 0 || newX >= SCREEN_WIDTH - 3) { // check if next position is outside the screen
						shouldMoveDown = true;
						break; 
					}
				}
			}
			if (shouldMoveDown) break; // if enemies hit edge, exit loop early
		}
		if (shouldMoveDown) { // if enemy hit the edge, reverse directionn
			enemyDir *= -1;
			for (int row = 0; row < ENEMY_ROWS; row++) {
				for (int col = 0; col < ENEMY_COLS; col++) {
					if (enemies[row][col].isAlive) { // move the enemies down one row
						enemies[row][col].y += 1;
						if (enemies[row][col].y >= SCREEN_HEIGHT - 2) { // game over if enemies reach player
							system("cls");
							std::cout << "GAME OVER! Score: " << score << "\n";
							exit(0);
						}
					}
				}	
			}
		}
		else { // horizontal movement if the enemy does not hit the edge
			for (int row = 0; row < ENEMY_ROWS; row++) {
				for (int col = 0; col < ENEMY_COLS; col++) {
					if (enemies[row][col].isAlive) {
						enemies[row][col].x += enemyDir;
					}
				}
			}
		}
	}
}
void Game::checkCollisions() {
	if (!bullet.isActive) return;

	for (int row = 0; row < ENEMY_ROWS; row++) {
		for (int col = 0; col < ENEMY_COLS; col++) {
			if (enemies[row][col].isAlive &&
				bullet.x >= enemies[row][col].x &&
				bullet.x <= enemies[row][col].x + 2 &&
				bullet.y == enemies[row][col].y)
			{
				enemies[row][col].isAlive = false;
				bullet.isActive = false;
				score += 10;
				return;
			}
		}
	}
}

void Game::render(HANDLE hConsole) {
	system("cls");

	// Draw player
	COORD playerCoord = { player.x, player.y };
	SetConsoleCursorPosition(hConsole, playerCoord);
	std::cout << "A";

	// Draw bullet
	if (bullet.isActive) {
		COORD bulletCoord = { bullet.x, bullet.y };
		SetConsoleCursorPosition(hConsole, bulletCoord);
		std::cout << "|";
	}

	//Draw Enemies
	for (int row = 0; row < ENEMY_ROWS; row++) {
		for (int col = 0; col < ENEMY_COLS; col++) {
			if (enemies[row][col].isAlive) {
				COORD enemyCoord = { enemies[row][col].x, enemies[row][col].y };
				SetConsoleCursorPosition(hConsole, enemyCoord);
				std::cout << "X X";
			}
		}
	}

	// Draw Score
	COORD scoreCoord = { 0, SCREEN_HEIGHT };
	SetConsoleCursorPosition(hConsole, scoreCoord);
	std::cout << "Score:" << score;

}

 