#pragma once
#include"Tank.h"
#include<string>
#include "SFML/Graphics.hpp"
#include"map.h"
#include"Shoot.h"
using namespace sf;
class TankPlayer :public Tank {
	//void chackWall(Map);
	char getDirection(int);

	void virtual chackWall(Map);
public:
	void deleteInMap();
	Shoot* generateShootPlayers(int);
	void zeroizeTimeShoot();
	/*double getTimeShoot();
	char getDirection();
	int getCoord_X();
	int getCoord_Y();*/
	void setSpeed(double);
	void setTimeShoot(double);
	//TankPlayer(const TankPlayer &);
	Sprite virtual  moveTank(int, Map) ;
	Sprite virtual update(int, double, Map);
	//Sprite virtual shotTank(int, int, Map) ;
	//TankPlayer(std::string);
	TankPlayer();
};
