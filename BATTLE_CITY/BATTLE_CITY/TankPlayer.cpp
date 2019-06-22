#include "TankPlayer.h"

TankPlayer::TankPlayer() {
	width = 64;
	height = 62;
	speedByDefault = 0.1;
	classPlayr = "Player";
	imagePlayer.loadFromFile(road);
	imagePlayer.createMaskFromColor(Color(0, 0, 1));
	imagePlayer.createMaskFromColor(Color(0, 0, 0));
	imagePlayer.createMaskFromColor(Color(0, 14, 5));
	texturePlayer.loadFromImage(imagePlayer);
	spritePlayer.setTexture(texturePlayer);
	texturePlayer.loadFromImage(imagePlayer);
	spritePlayer.setTexture(texturePlayer);
};



//TankPlayer::TankPlayer(const TankPlayer & newPlayer) {
//	currentFrame = newPlayer.currentFrame;
//	width = newPlayer.width;
//	height = newPlayer.height;
//	speed = newPlayer.speed;
//	forceShot = newPlayer.forceShot;
//	life = newPlayer.life;
//	name = newPlayer.name;
//	road = newPlayer.road;
//	imagePlayer = newPlayer.imagePlayer;
//	texturePlayer = newPlayer.texturePlayer;
//	spritePlayer = newPlayer.spritePlayer;
//	bonus = newPlayer.bonus;
//	coord_x = newPlayer.coord_x;
//	coord_y = newPlayer.coord_y;
//	coordSprite_x = newPlayer.coordSprite_x;
//	coordSprite_y = newPlayer.coordSprite_y;
//}


Sprite TankPlayer::update(int i, double time, Map map) {
	setSpeed(time);
	setTimeShoot(time);
	coord_x = spritePlayer.getPosition().x;
	coord_y = spritePlayer.getPosition().y;
	return moveTank(i, map);
}

Shoot* TankPlayer::generateShootPlayers(int i) {
	if (life > 0 && i== 0 && Keyboard::isKeyPressed(Keyboard::Space) && timeShoot > 500000) {
      		return new Shoot(texturePlayer, direction, coord_x +4, coord_y+11, classPlayr, powerShoot);
	}
	else if (life > 0 && i == 1 && Keyboard::isKeyPressed(Keyboard::Numpad0) && timeShoot > 500000) {
		return new Shoot(texturePlayer, direction, coord_x + 4, coord_y + 11, classPlayr, powerShoot);

	}
	else return nullptr;
}

void TankPlayer::deleteInMap() {
	coord_x = 1;
	coord_y = 1;
}

Sprite TankPlayer::moveTank(int flag,Map map){
	if (life > 0) {
		int Position = 0;
		if (flag == 0) {
			if ((Keyboard::isKeyPressed(Keyboard::W))) {
				Position = 0;
				spritePlayer.move(0, -speed);
				direction = getDirection(Position);
			}
			else if ((Keyboard::isKeyPressed(Keyboard::A))) {
				Position = 126;
				spritePlayer.move(-speed, 0);
				direction = getDirection(Position);
			}
			else if ((Keyboard::isKeyPressed(Keyboard::D))) {
				Position = 382;
				spritePlayer.move(speed, 0);
				direction = getDirection(Position);
			}
			else if ((Keyboard::isKeyPressed(Keyboard::S))) {
				Position = 254;
				spritePlayer.move(0, speed);
				direction = getDirection(Position);
			}
			else {
				speed = 0;
			}
			/*if (Keyboard::isKeyPressed(Keyboard::Space)) {
				 tmp(getDirection(Position), spritePlayer.getPosition().x + (width / 2), spritePlayer.getPosition().y + (height / 2));
				Shoot *tmp_1 = &shoot;
				while (tmp_1->getNextShoot() != nullptr) {
					tmp_1 = tmp_1->getNextShoot();
				}
				tmp_1->setNextShoot(&tmp);
			}*/
		}
		else {
			if ((Keyboard::isKeyPressed(Keyboard::Up))) {
				Position = 0;
				spritePlayer.move(0, -speed);
				direction = getDirection(Position);
			}
			else if ((Keyboard::isKeyPressed(Keyboard::Left))) {
				Position = 126;
				spritePlayer.move(-speed, 0);
				direction = getDirection(Position);
			}
			else if ((Keyboard::isKeyPressed(Keyboard::Right))) {
				Position = 382;
				spritePlayer.move(speed, 0);
				direction = getDirection(Position);
			}
			else if ((Keyboard::isKeyPressed(Keyboard::Down))) {
				Position = 254;
				spritePlayer.move(0, speed);
				direction = getDirection(Position);
			}
			else {
				speed = 0;
			}
			/*if (Keyboard::isKeyPressed(Keyboard::RShift)) {
				 tmp(getDirection(Position), spritePlayer.getPosition().x + (width / 2), spritePlayer.getPosition().y + (height / 2));
				Shoot *tmp_1 = &shoot;
				while (tmp_1 != nullptr) {
					tmp_1 = tmp_1->getNextShoot();
				}
				tmp_1->setNextShoot(&tmp);
			}*/
		}

		currentFrame += speed;
		if (currentFrame >= 2) {
			currentFrame = 0;
		}
		if (speed != 0) {
			spritePlayer.setTextureRect(IntRect(Position + width * int(currentFrame), coordSprite_y, width, height));
		}
		chackWall(map);
	}
	return spritePlayer;
}

void TankPlayer::chackWall(Map map) {
	int x = spritePlayer.getPosition().x + 4;
	int y = spritePlayer.getPosition().y + 4;
	int coord_i;
	int coord_j;
	for (int i = 3; i < width - 8; i++) {
		coord_i = ((x + i) - map.getCentralizerMap()) / map.getWidthSprite();
		coord_j = (y +2)/ map.getWidthSprite();
		if (map.getElemArry(coord_j, coord_i) != 0) {
			spritePlayer.move(0, speed);
			break;
		}
		coord_i = ((x + width-7) - map.getCentralizerMap()) / map.getWidthSprite();
		coord_j = (y + i+1) / map.getWidthSprite();
		if (map.getElemArry(coord_j, coord_i) != 0) {
			spritePlayer.move(-speed, 0);
			break;
		}
		coord_i = ((x + i) - map.getCentralizerMap()) / map.getWidthSprite();
		coord_j = (y + width-8) / map.getWidthSprite();
		if (map.getElemArry(coord_j, coord_i) != 0) {
			spritePlayer.move(0, -speed);
			break;
		}
		coord_i = (x - map.getCentralizerMap()) / map.getWidthSprite();
		coord_j = (y + i) / map.getWidthSprite();
		if (map.getElemArry(coord_j, coord_i) != 0) {
			spritePlayer.move(speed, 0);
			break;
		}
	}
}

void TankPlayer::setSpeed(double time) {
	speed = speedByDefault * time;
}

char TankPlayer::getDirection(int Position) {
	switch (Position){
	case 0:
		return 'W';
	case 126:
		return 'A';
	case 254:
		return 'S';
	case 382:
		return 'D';
	default:
		return 'W';
	}
}

//char TankPlayer::getDirection() {
//	return direction;
//}
//
//int TankPlayer::getCoord_X(){
//	return coord_x + width/2 - 27;
//}
//
//int TankPlayer::getCoord_Y() {
//	return coord_y + height / 2 -22;
//}

void TankPlayer::setTimeShoot(double time) {
	timeShoot += time*800;
}

//double TankPlayer::getTimeShoot() {
//	return timeShoot;
//}

void TankPlayer::zeroizeTimeShoot() {
	timeShoot = 0;
}