#pragma once
#include <set>;
#include <string>;
#include "SFML/Graphics.hpp"
#include"map.h"
#include "Shoot.h"
using namespace sf;

class Tank {
protected:
	int timeBengTank;
	std::string classPlayr;
	double timeShoot;
	char direction;
	Shoot shoot;
	std::string name;
	double currentFrame;
	std::string road;
	Image imagePlayer;
	Texture texturePlayer;
	Sprite spritePlayer;
	std::set<std::string> bonus;
	int coord_x;
	int coord_y;
	int coordSprite_x;
	int coordSprite_y;
	int height;
	int width;
	double speedByDefault;
	double speed;
	int powerShoot;
	int life;

	void virtual chackWall(Map) = 0;
public:
	void subtractLife(int);
	int getLife();
	int getTimeBengTank();
	void fillBangInSprite(Sprite);
	void subtractTimeBengTank();
	void stop(char);
	void setDirecion(char);
	int getWidth();
	int getHeight();
	int getCoord_X();
	int getCoord_Y();
	int getMirrorCoord_X();
	int getMirrorCoord_Y();
	Tank();
	Sprite virtual update(int, double, Map) = 0;
	Sprite virtual  moveTank(int, Map) =0 ;
//	Sprite virtual shotTank(int, int , Map) = 0;
	~Tank();
};