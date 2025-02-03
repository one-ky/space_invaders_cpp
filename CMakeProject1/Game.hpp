#pragma once
#include "Player.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Constants.hpp"
#include <Windows.h>

class Game {
public:
	Player player;
	Bullet bullet;
	Enemy enemies[ENEMY_ROWS][ENEMY_COLS];
	int score = 0;
	int enemyDir = 1;
	int enemySpeed = 15;
	int enemyMoveCounter = 0;

	Game();
	void run();

private:
	void initializeEnemies();
	void handleInput();
	void update();
	void updateEnemies();
	void checkCollisions();
	void render(HANDLE hConsole);
};