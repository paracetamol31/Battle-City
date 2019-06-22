#pragma once
#include <iostream>
#include "TankPlayer.h"
#include "SFML/Graphics.hpp"
#include "Player_1.h"
#include "Player_2.h"
#include"map.h"
#include"EnemyClass_1.h"
#include"EnemyClass_2.h"
#include"EnemyClass_3.h"
#include"EnemyClass_4.h"
#include"Enemy.h"
#include<ctime>
using namespace sf;


class GameTanks{
private:
	int timeBangEagle;
	bool lifeEagle;
	int numberPlayers;
	int numberEnemy;
	int timeSpawnEnemy;
	int commonNumderEnemy;
	int numberEnemyOnMap;
	TankPlayer* myPlayers;
	Enemy* myEnemy;
	Image imageEnemy;
	Texture textureEnemy;
	Sprite spriteEnemy;
	EnemyClass_1 enemyClass_1;
	EnemyClass_2 enemyClass_2;
	EnemyClass_3 enemyClass_3;
	EnemyClass_4 enemyClass_4;
	Player_1 player_1;
	Player_2 player_2;
	Shoot* headShoot;
	Enemy* headMyEnemy;

	Image imageGameOver;
	Texture textureGameOver;
	Sprite spriteGameOver;
	//void location(Enemy*);
	/*Maps maps;
	Enemys enemys;*/
public:
	bool gameOver(RenderWindow&, int);
	void bangEagle(Map, RenderWindow&);
	void subtracTimeBangEagle();
	int getTimeBangEagle();
	void setLifeEagle(bool);
	bool getkLifeEagle();
	void checkBorder();
	int getTimeBengPayers(int);
	void checkCollisiansBengandPlayer();
	void checkCollisiansBengandEnemy();
	void checkCollisionsEnemyAndEnemy(); 
	void checkCollisionsEnemyAndPlaeyr();
	void generateShootEnemy(int);
	Sprite moveEnemy(int, Map, Enemy*);
	Enemy* getNextEnemy();
	Enemy* getHeadEnemy();
	Enemy* randClassEnemy();
	Sprite fillListEnemy(int);
	Shoot* getHeadShoot();
	/*void zeroizeTimeShoot(int);
	double getTimeShoot(int);
	char getDirection(int);
	int getCoord_X(int);
	int getCoord_Y(int);*/
	Sprite updateMove(int, double, Map);
	void generateShootPlayers(int );
	/*Sprite updateShoot(int, int, Map);*/
	GameTanks(int);
	GameTanks() {};
	~GameTanks();
	
};

