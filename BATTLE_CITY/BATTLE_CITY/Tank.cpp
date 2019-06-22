#include"Tank.h"
Tank::Tank() {
	road = "images//tanks.png";
	currentFrame = 0;
	speed = 0.2;
	powerShoot = 1;
	timeShoot = 0;
	direction = 'W';
	life = 1;
	timeBengTank = 50;
}

void Tank::subtractLife(int xp) {
	life -= xp;
}

int Tank::getLife() {
	return life;
}

//void Tank::chackWall(Map map) {
//	int x = spritePlayer.getPosition().x + 4;
//	int y = spritePlayer.getPosition().y + 4;
//	int coord_i;
//	int coord_j;
//	for (int i = 3; i < width - 8; i++) {
//		coord_i = ((x + i) - map.getCentralizerMap()) / map.getWidthSprite();
//		coord_j = (y + 2) / map.getWidthSprite();
//		if (map.getElemArry(coord_j, coord_i) != 0) {
//			spritePlayer.move(0, speed);
//			break;
//		}
//		coord_i = ((x + width - 8) - map.getCentralizerMap()) / map.getWidthSprite();
//		coord_j = (y + i) / map.getWidthSprite();
//		if (map.getElemArry(coord_j, coord_i) != 0) {
//			spritePlayer.move(-speed, 0);
//			break;
//		}
//		coord_i = ((x + i) - map.getCentralizerMap()) / map.getWidthSprite();
//		coord_j = (y + width - 8) / map.getWidthSprite();
//		if (map.getElemArry(coord_j, coord_i) != 0) {
//			spritePlayer.move(0, -speed);
//			break;
//		}
//		coord_i = (x - map.getCentralizerMap()) / map.getWidthSprite();
//		coord_j = (y + i) / map.getWidthSprite();
//		if (map.getElemArry(coord_j, coord_i) != 0) {
//			spritePlayer.move(speed, 0);
//			break;
//		}
//	}
//}

Tank::~Tank() {
}

int Tank::getHeight() {
	return height;
}

int Tank::getWidth() {
	return width;
}

int Tank::getCoord_X() {
	return coord_x;
}

int Tank::getCoord_Y() {
	return coord_y;
}

int Tank::getMirrorCoord_X() {
	return coord_x + width;
}

int Tank::getMirrorCoord_Y() {
	return coord_y+ height;
}

void Tank::setDirecion(char dir) {
	direction = dir;
}

void Tank::fillBangInSprite(Sprite SpriteTank) {
	spritePlayer = SpriteTank;
}

int Tank::getTimeBengTank() {
	return timeBengTank;
}

void Tank::stop(char direction_) {
	switch (direction_){
	case 'W':
		spritePlayer.move(0, speed);
		break;
	case 'S':
		spritePlayer.move(0, -speed);
		break;
	case 'A':
		spritePlayer.move(speed, 0);
		break;
	case 'D':
		spritePlayer.move(-speed, 0);
		break;
	default:
		break;
	}
}

void Tank::subtractTimeBengTank() {
	timeBengTank -= 1;
}