#pragma once
#include "Tank.h"
#include<ctime>
class Enemy:public Tank{
	Enemy* nextEnemy;
	int timeMove;

	void virtual chackWall(Map);
public:
	void randDirection();
	void updateSpeed(int);
	void updateSpeedMove(int);
	void updateTimeShoot(int);
	Sprite update(int, Map);
	Sprite moveEnemy(Map);
	Shoot* shootEnemy(int, Texture&);
	Sprite getSprite();
	void location();
	void setTexture();
	void setSprite(Sprite);
	//Enemy(const Enemy&);
	void setCoord(int, int);
	Enemy* getNextEnemy();
	void setNextEnemy(Enemy*);
	Sprite virtual  moveTank(int, Map) {return spritePlayer;
	};
	Sprite virtual update(int, double, Map) {return  spritePlayer; };
	Enemy();
	~Enemy();
};

