#include "Enemy.h"


Enemy::Enemy() {
	width = 64;
	height = 62;
	classPlayr = "Enemy";
	nextEnemy = nullptr;
	timeMove = 0;
	direction = 'S';
}

//Enemy::Enemy(const Enemy & newEnemy) {
//	classPlayr = newEnemy.classPlayr;
//	timeShoot = newEnemy.timeShoot;
//	direction = newEnemy.direction;
//	shoot = newEnemy.shoot;
//	name = newEnemy.name;
//	currentFrame = newEnemy.currentFrame;
//	road = newEnemy.road;
//	imagePlayer = newEnemy.imagePlayer;
//	texturePlayer = newEnemy.texturePlayer;
//	spritePlayer = newEnemy.spritePlayer;
//	bonus = newEnemy.bonus;
//	coord_x = newEnemy.coord_x;
//	coord_y = newEnemy.coord_y;
//	coordSprite_x = newEnemy.coordSprite_x;
//	coordSprite_y = newEnemy.coordSprite_y;
//	height = newEnemy.height;
//	width = newEnemy.width;
//	speedByDefault = newEnemy.speedByDefault;
//	speed = newEnemy.speed;
//	forceShot = newEnemy.forceShot;
//	life = newEnemy.life;
//}

Sprite Enemy::update(int time, Map map) {
	updateSpeed(time);
	updateSpeedMove(time);
	return moveEnemy(map);
	timeBengTank = 50;
}

Sprite Enemy::moveEnemy(Map map) {
	if (life>0) {
	if (timeMove > 6000) {
		randDirection();
		timeMove = 0;
	}
		int Position;
		if (direction == 'W') {
			spritePlayer.move(0, -speed);
			Position = 509;
		}
		else if (direction == 'A') {
			spritePlayer.move(-speed, 0);
			Position = 636;
		}
		else if (direction == 'S') {
			spritePlayer.move(0, speed);
			Position = 764;
		}
		else {
			spritePlayer.move(speed, 0);
			Position = 893;
		}
		currentFrame += speed;
		if (currentFrame >= 2) {
			currentFrame = 0;
		}
		if (speed != 0) {
			spritePlayer.setTextureRect(IntRect(Position + width * int(currentFrame), coordSprite_y, width, height));
		}
		chackWall(map);
		coord_x = spritePlayer.getPosition().x;
		coord_y = spritePlayer.getPosition().y;
	}
	return spritePlayer;
}

void Enemy::chackWall(Map map) {
	int x = spritePlayer.getPosition().x + 4;
	int y = spritePlayer.getPosition().y + 4;
	int coord_i;
	int coord_j;
	for (int i = 3; i < width - 8; i++) {
		coord_i = ((x + i) - map.getCentralizerMap()) / map.getWidthSprite();
		coord_j = (y + 2) / map.getWidthSprite();
		if (map.getElemArry(coord_j, coord_i) != 0) {
			spritePlayer.move(0, speed);
			randDirection();
			break;
		}
		coord_i = ((x + width - 8) - map.getCentralizerMap()) / map.getWidthSprite();
		coord_j = (y + i+1) / map.getWidthSprite();
		if (map.getElemArry(coord_j, coord_i) != 0) {
			spritePlayer.move(-speed, 0);
			randDirection();
			break;
		}
		coord_i = ((x + i) - map.getCentralizerMap()) / map.getWidthSprite();
		coord_j = (y + width - 8) / map.getWidthSprite();
		if (map.getElemArry(coord_j, coord_i) != 0) {
			spritePlayer.move(0, -speed);
			randDirection();
			break;
		}
		coord_i = (x - map.getCentralizerMap()) / map.getWidthSprite();
		coord_j = (y + i) / map.getWidthSprite();
		if (map.getElemArry(coord_j, coord_i) != 0) {
			spritePlayer.move(speed, 0);
			randDirection();
			break;
		}
	}
}

Shoot* Enemy::shootEnemy(int time, Texture& textureEnemy) {
	updateTimeShoot(time);
	if (timeShoot > 2000) {
		timeShoot = 0;
		return new Shoot(textureEnemy, direction, coord_x+4, coord_y+11, classPlayr,powerShoot);
	}
	else {
		return nullptr;
	}
}

void Enemy::location() {
	srand(time(0));
		int flag = rand() % 4;
		switch (flag) {
		case 0:
			coord_x = 366;
			coord_y = 61;
			break;
		case 1:
			coord_x = 626;
			coord_y = 61;
			break;
		case 2:
			coord_x = 881;
			coord_y = 61;
			break;
		case 3:
			coord_x = 1136;
			coord_y = 61;
			break;
		default:
			break;
		}
		spritePlayer.setPosition(coord_x, coord_y);
}

Sprite Enemy::getSprite() {
	return spritePlayer;
}

void Enemy::setTexture() {
	spritePlayer.setTextureRect(IntRect( coordSprite_x, coordSprite_y, width, height));
}

void Enemy::setSprite(Sprite thisSprite) {
	spritePlayer = thisSprite;
}

Enemy* Enemy::getNextEnemy() {
	return nextEnemy;
}

void Enemy::setNextEnemy(Enemy* thisEnemy) {
	nextEnemy = thisEnemy;
}

void Enemy::setCoord(int x, int y) {
	coord_x = x;
	coord_y = y;
}

void Enemy::updateSpeed(int time) {
	speed = speedByDefault * time;
}

void Enemy::updateSpeedMove(int time) {
	timeMove += time;
}

void Enemy::updateTimeShoot(int time) {
	timeShoot += time;
}

void Enemy::randDirection() {
	srand(time(0));
	int flag = (timeMove * rand())%9;
		switch (flag){
		case 0:
			direction = 'A';
			break;
		case 1:
			direction = 'W';
			break;
		case 2:
			direction = 'A';
			break;
		case 3:
			direction = 'S';
			break;
		case 4:
			direction = 'S';
			break;
		case 5:
			direction = 'D';
			break;
		case 6:
			direction = 'D';
			break;
		default:
			direction = 'S';
			break;
		}
}


Enemy::~Enemy()
{
}

