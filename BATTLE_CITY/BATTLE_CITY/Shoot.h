#pragma once
#include "SFML/Graphics.hpp"
#include"map.h"
#include<string>
class Shoot{
private:
	std::string classShoot;
	int coord_x;
	int coord_y;
	int timeBengShoot;
	int widthS;
	int powerShoot;
	int longS;
	char direction;
	double speed;
	int currentFrame;
	sf::Image imageShoot;
	sf::Texture textureShoot;
	sf::Sprite spriteShoot;
	Shoot* nextShoot;
	Shoot* preShoot;

	void bang(int, int, Map);
public:
	bool checkColisionWichEagle(Map);
	void  subtractTimeBengShoot();
	void fillBangInSprite(sf::Sprite);
	void  stop();
	int getTimeBengShoot();
	int getPowerShoot();
	void deleteNextShoot();
	void setLifeShoot(int);
	int getCoord_X();
	int getCoord_Y();
	int getWidthS();
	int getLongS();
	std::string getClassShoot();
	void setNextShoot(Shoot*);
	Shoot* getNextShoot();
	Shoot(sf::Texture& , char, int, int, std::string, int);
	sf::Sprite update(double, Map);
	Shoot();
	void chackWall(Map map);
	~Shoot();
};

