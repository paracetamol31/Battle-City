#include "Shoot.h"



Shoot::Shoot(sf::Texture& textureShoot, char direction_, int coord_x_, int coord_y_, std::string classPlayer,int powerShoot_){
	coord_x = coord_x_;
	coord_y = coord_y_;
	classShoot = classPlayer;
	widthS = 32;
	longS = 32;
	direction = direction_;
	speed = 0.2;
	spriteShoot.setTexture(textureShoot);
	spriteShoot.setPosition(coord_x, coord_y);
	currentFrame = 0;
	timeBengShoot = 50;
	powerShoot = powerShoot_;
}

Shoot::Shoot() {
}

int Shoot::getPowerShoot() {
	return powerShoot;
}

Shoot* Shoot::getNextShoot() {
	return nextShoot;
}

void Shoot::setNextShoot(Shoot* tmp) {
	nextShoot = tmp;
}

void Shoot::subtractTimeBengShoot() {
	timeBengShoot -= 1;
}

sf::Sprite Shoot::update(double time, Map map) {
	speed = 0.6 * time; 
	switch (direction) {
	case 'W':
		spriteShoot.setTextureRect(sf::IntRect(1270, 270, widthS, longS));
		spriteShoot.move(0, -speed);
		break;
	case 'A':
		spriteShoot.setTextureRect(sf::IntRect(1303, 270, longS, widthS));
		spriteShoot.move(-speed, 0);
		break;
	case 'S':
		spriteShoot.setTextureRect(sf::IntRect(1335, 270, widthS, longS));
		spriteShoot.move(0, speed);
		break;
	case 'D':
		spriteShoot.setTextureRect(sf::IntRect(1367, 270, longS, widthS));
		spriteShoot.move(speed, 0);
		break;
	default:
		break;
	}
	chackWall(map);
	return spriteShoot;
}

std::string Shoot::getClassShoot(){
	return classShoot;
}

void Shoot::chackWall(Map map) {
	/*int x = spriteShoot.getPosition().x;
	int y = spriteShoot.getPosition().y;*/
	int flag = 0;
	int coord_i;
	int coord_j;
		for (int i = 15; i < widthS; i++) {
			coord_i = ((coord_x + i) - map.getCentralizerMap()) / map.getWidthSprite();
			coord_j = (coord_y + 12) / map.getWidthSprite();
			if ((timeBengShoot < 20 && direction == 'W') || map.getElemArry(coord_j, coord_i) != 0) {
				flag = 1;
				spriteShoot.move(0, speed);
				break;
			}
			coord_i = ((coord_x + widthS-3) - map.getCentralizerMap()) / map.getWidthSprite();
			coord_j = (coord_y + i) / map.getWidthSprite();
			if ((timeBengShoot < 20 && direction == 'D') || map.getElemArry(coord_j, coord_i) != 0) {
				flag = 1;
				spriteShoot.move(-speed, 0);
				break;
			}
			coord_i = ((coord_x + i) - map.getCentralizerMap()) / map.getWidthSprite();
			coord_j = (coord_y + widthS-2) / map.getWidthSprite();
			if ((timeBengShoot < 20 && direction == 'S') || map.getElemArry(coord_j, coord_i) != 0) {
				flag = 1;
				spriteShoot.move(0, -speed);
				break;
			}
			coord_i = (coord_x  - map.getCentralizerMap()) / map.getWidthSprite();
			coord_j = (coord_y + i) / map.getWidthSprite();
			if ((timeBengShoot <20 && direction == 'A') || map.getElemArry(coord_j, coord_i) != 0) {
				flag = 1;
				spriteShoot.move(speed, 0);
				break;
			}
		}
		if (flag == 1) {
			bang(coord_i, coord_j, map);
		}
		coord_x = spriteShoot.getPosition().x;
		coord_y = spriteShoot.getPosition().y;
}
void Shoot::bang(int i, int j, Map map) {
	if (timeBengShoot <= 20) {
		if (map.getElemArry(j, i) == 1 || map.getElemArry(j, i) == 2) {
			if (direction == 'W' || direction == 'S') {
				if (i % 2 == 1) {
					map.setElemMap(j, i - 1, 0);
					map.setElemMap(j, i, 0);
				}
				else if (i != 0) {
					map.setElemMap(j, i, 0);
					map.setElemMap(j, i + 1, 0);
				}
			}
			if (direction == 'A' || direction == 'D') {
				if (j % 2 == 1) {
					map.setElemMap(j - 1, i, 0);
					map.setElemMap(j, i, 0);
				}
				else if (j != 0) {
					map.setElemMap(j, i, 0);
					map.setElemMap(j + 1, i, 0);
				}
			}
		}
	}
	if(timeBengShoot <=0){
			Shoot* tmp = nextShoot;
			*(this) = *nextShoot;
			delete tmp;
	}
		else {
			spriteShoot.setTextureRect(sf::IntRect(1031, 516, 43, 47));
		}
	timeBengShoot--;
}

void Shoot::stop() {
	switch (direction) {
	case 'W':
		spriteShoot.move(0, speed);
		break;
	case 'S':
		spriteShoot.move(0, -speed);
		break;
	case 'A':
		spriteShoot.move(speed, 0);
		break;
	case 'D':
		spriteShoot.move(-speed, 0);
		break;
	default:
		break;
	}
}

bool Shoot::checkColisionWichEagle(Map map) {
	int coord_i;
	int coord_j;
	bool flag = false;
	for (int i = 15; i < widthS; i++) {
		coord_i = ((coord_x + i) - map.getCentralizerMap()) / map.getWidthSprite();
		coord_j = (coord_y + 12) / map.getWidthSprite();
		if (map.getElemArry(coord_j, coord_i) == 96 || map.getElemArry(coord_j, coord_i) == 97 || map.getElemArry(coord_j, coord_i) == 98 || map.getElemArry(coord_j, coord_i) == 99 ) {
			flag = true;
			spriteShoot.move(0, speed);
			break;
		}
		coord_i = ((coord_x + widthS - 3) - map.getCentralizerMap()) / map.getWidthSprite();
		coord_j = (coord_y + i) / map.getWidthSprite();
		if (map.getElemArry(coord_j, coord_i) == 96 || map.getElemArry(coord_j, coord_i) == 97 || map.getElemArry(coord_j, coord_i) == 98 || map.getElemArry(coord_j, coord_i) == 99) {
			flag = true;
			spriteShoot.move(-speed, 0);
			break;
		}
		coord_i = ((coord_x + i) - map.getCentralizerMap()) / map.getWidthSprite();
		coord_j = (coord_y + widthS - 2) / map.getWidthSprite();
		if (map.getElemArry(coord_j, coord_i) == 96 || map.getElemArry(coord_j, coord_i) == 97 || map.getElemArry(coord_j, coord_i) == 98 || map.getElemArry(coord_j, coord_i) == 99) {
			flag = true;
			spriteShoot.move(0, -speed);
			break;
		}
		coord_i = (coord_x - map.getCentralizerMap()) / map.getWidthSprite();
		coord_j = (coord_y + i) / map.getWidthSprite();
		if (map.getElemArry(coord_j, coord_i) == 96 || map.getElemArry(coord_j, coord_i) == 97 || map.getElemArry(coord_j, coord_i) == 98 || map.getElemArry(coord_j, coord_i) == 99) {
			flag = true;
			spriteShoot.move(speed, 0);
			break;
		}
	}
	if (flag == true) {
		Shoot* tmp = nextShoot;
		*(this) = *nextShoot;
		delete tmp;
		return false;
	}
	else return true;

}

void Shoot::fillBangInSprite(sf::Sprite newSprite) {
	spriteShoot = newSprite;
}

void Shoot::setLifeShoot(int time) {
	timeBengShoot = time;
}

int Shoot::getTimeBengShoot() {
	return timeBengShoot;
}

void Shoot::deleteNextShoot() {
	delete nextShoot;
}

int Shoot::getCoord_X() {
	return coord_x;
}

int Shoot::getCoord_Y() {
	return coord_y;
}

int Shoot::getWidthS() {
	return widthS;
}

int Shoot::getLongS() {
	return longS;
}

Shoot::~Shoot()
{
}
