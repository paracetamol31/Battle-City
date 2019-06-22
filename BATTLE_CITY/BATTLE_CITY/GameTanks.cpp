#include "GameTanks.h"
#include <ctime> 

Sprite GameTanks::updateMove(int i, double  time, Map map) {
	return	myPlayers[i].update(i, time ,map);
}

int GameTanks::getTimeBengPayers(int i) {
	return myPlayers[i].getTimeBengTank();
}

void GameTanks::checkCollisiansBengandPlayer() {
	for (int i = 0; i<numberPlayers; i++) {
		for (Shoot* tmp = headShoot; tmp->getNextShoot() != nullptr; tmp = tmp->getNextShoot()) {
			if (tmp->getClassShoot() == "Enemy") {
				for (int x = tmp->getCoord_X(); x < tmp->getCoord_X() + tmp->getWidthS(); x++) {
					int y = tmp->getCoord_Y();
					if (x >= myPlayers[i].getCoord_X() && x <= myPlayers[i].getCoord_X() + myPlayers[i].getWidth() && y >= myPlayers[i].getCoord_Y() && y <= myPlayers[i].getCoord_Y() + myPlayers[i].getHeight()) {
							myPlayers[i].subtractLife(tmp->getPowerShoot());
							Shoot* tmp_1 = tmp->getNextShoot();
							*tmp = *(tmp->getNextShoot());
							delete tmp_1;
							break;
					}
				}
					for (int y = tmp->getCoord_Y(); y < tmp->getCoord_Y() + tmp->getLongS(); y++) {
					int x = tmp->getCoord_X();
					if (x >= myPlayers[i].getCoord_X() && x <= myPlayers[i].getCoord_X() + myPlayers[i].getWidth() && y >= myPlayers[i].getCoord_Y() && y <= myPlayers[i].getCoord_Y() + myPlayers[i].getHeight()) {
							myPlayers[i].subtractLife(tmp->getPowerShoot());
							Shoot* tmp_1 = tmp->getNextShoot();
							*tmp = *(tmp->getNextShoot());
							delete tmp_1;
							break;
					}
				}
			}
			if (tmp->getNextShoot() == nullptr) {
				break;
			}
		}
		if ( myPlayers[i].getLife() <= 0) {
			Sprite newSpriteEnemy;
			newSpriteEnemy.setTexture(textureEnemy);
			newSpriteEnemy.setTextureRect(IntRect(1145, 509, 65, 65));
			newSpriteEnemy.setPosition(myPlayers[i].getCoord_X(), myPlayers[i].getCoord_Y());
			myPlayers[i].fillBangInSprite(newSpriteEnemy);
			myPlayers[i].subtractTimeBengTank();
			if (myPlayers[i].getTimeBengTank() == 0) {
				myPlayers[i].deleteInMap();
			}
		}
		/*if (tmpE->getNextEnemy() == nullptr) {
			break;
		}*/
	}
}

void GameTanks::checkCollisiansBengandEnemy() {
	for (Enemy* tmpE = headMyEnemy; tmpE->getNextEnemy() != nullptr; tmpE = tmpE->getNextEnemy()) {
		for (Shoot* tmp = headShoot; tmp->getNextShoot() != nullptr; tmp = tmp->getNextShoot()) {
			if (tmp->getClassShoot() == "Player") {
				for (int x = tmp->getCoord_X(); x < tmp->getCoord_X() + tmp->getWidthS(); x++) {
					int y = tmp->getCoord_Y() ;
					if (x >= tmpE->getCoord_X() && x <= tmpE->getCoord_X() + tmpE->getWidth() && y >= tmpE->getCoord_Y() && y <= tmpE->getCoord_Y() + tmpE->getHeight()) {
							tmpE->subtractLife(tmp->getPowerShoot());
							tmp->subtractTimeBengShoot();
							Shoot* tmp_1 = tmp->getNextShoot();
							*tmp = *(tmp->getNextShoot());
							delete tmp_1;
							break;
					}
				}
				for (int y = tmp->getCoord_Y(); y < tmp->getCoord_Y() + tmp->getLongS(); y++) {
					int x = tmp->getCoord_X();
					if (x >= tmpE->getCoord_X() && x <= tmpE->getCoord_X() + tmpE->getWidth() && y >= tmpE->getCoord_Y() && y <= tmpE->getCoord_Y() + tmpE->getHeight()) {
							tmpE->subtractLife(tmp->getPowerShoot());
							Shoot* tmp_1 = tmp->getNextShoot();
							*tmp = *(tmp->getNextShoot());
							delete tmp_1;
							break;
					}
				}
		}
			/*else {
				Shoot* tmp_1 = tmp->getNextShoot();
				*tmp = *(tmp->getNextShoot());
				delete tmp_1;
			}*/
			if (tmp->getNextShoot() == nullptr) {
				break;
			}
		}
		if (/*tmpE->getTimeBengTank() < 50*/ tmpE->getLife() <= 0) {
			Sprite newSpriteEnemy;
			newSpriteEnemy.setTexture(textureEnemy);
			newSpriteEnemy.setTextureRect(IntRect(1145, 509, 65, 65));
			newSpriteEnemy.setPosition(tmpE->getCoord_X(), tmpE->getCoord_Y());
			tmpE->fillBangInSprite(newSpriteEnemy);
			tmpE->subtractTimeBengTank();
			if (tmpE->getTimeBengTank() == 0) {
				Enemy* tmpE_1 = tmpE->getNextEnemy();
				*tmpE = *(tmpE->getNextEnemy());
				delete tmpE_1;
				numberEnemyOnMap--;
				commonNumderEnemy--;
			}
		}
		if (tmpE->getNextEnemy() == nullptr) {
			break;
		}
	}
}

GameTanks::GameTanks(int numberPlayers_) {
	lifeEagle = true;
	timeBangEagle = 200;
	imageGameOver.loadFromFile("images//gameOver.png");
	imageGameOver.createMaskFromColor(Color(255, 255, 255));
	textureGameOver.loadFromImage(imageGameOver);
	spriteGameOver.setTexture(textureGameOver);
	spriteGameOver.setTextureRect(IntRect(400, 250, 500, 300));
	spriteGameOver.setPosition(1700, 300);

	imageEnemy.loadFromFile("images//tanks.png");
	imageEnemy.createMaskFromColor(Color(0, 0, 1));
	imageEnemy.createMaskFromColor(Color(0, 0, 0));
	imageEnemy.createMaskFromColor(Color(0, 14, 5));
	textureEnemy.loadFromImage(imageEnemy);
	spriteEnemy.setTexture(textureEnemy);
	spriteEnemy.setTexture(textureEnemy);
	myEnemy = new Enemy;
	headMyEnemy = myEnemy;
	numberEnemy = 6;
	numberPlayers = numberPlayers_;
	timeSpawnEnemy = 0;
	numberEnemyOnMap = 0;
	commonNumderEnemy = 20;
	std::string name;
	headShoot = new Shoot;
	myPlayers = new TankPlayer[numberPlayers];
	for (int i = 0; i < numberPlayers; i++) {
		if (i == 0) {
			myPlayers[i] = player_1;
		}
		else {
			myPlayers[i] = player_2;
		}
	}
}

void GameTanks::generateShootPlayers(int i) {
	Shoot* newHeadShoot = myPlayers[i].generateShootPlayers(i);
	if (newHeadShoot != nullptr) {
		newHeadShoot->setNextShoot(headShoot);
		headShoot = newHeadShoot;
		myPlayers[i].zeroizeTimeShoot();
	}
}

void GameTanks::generateShootEnemy(int time) {
	for (Enemy* tmp = headMyEnemy; tmp->getNextEnemy() != nullptr; tmp = tmp->getNextEnemy()) {
		Shoot * newHeadShoot = tmp->shootEnemy(time, textureEnemy);
		if (newHeadShoot != nullptr) {
			newHeadShoot->setNextShoot(headShoot);
			headShoot = newHeadShoot;
		}
	}
}

Shoot* GameTanks::getHeadShoot() {
	return  headShoot;
}

bool GameTanks::getkLifeEagle() {
	return lifeEagle;
}

void GameTanks::setLifeEagle(bool life) {
	lifeEagle = life;
}

void GameTanks::subtracTimeBangEagle() {
	timeBangEagle--;
}

int GameTanks::getTimeBangEagle() {
	return timeBangEagle;
}

Sprite GameTanks::fillListEnemy(int time) {
	if (timeSpawnEnemy > 2000 && numberEnemyOnMap != numberEnemy && commonNumderEnemy>numberEnemyOnMap) {
		Enemy * newEnemy = randClassEnemy();
		newEnemy->setSprite(spriteEnemy);
		newEnemy->setTexture();
		newEnemy->location();
		newEnemy->setNextEnemy(headMyEnemy);
		headMyEnemy = newEnemy;
		numberEnemyOnMap++;
		timeSpawnEnemy = 0;
		/*for(Enemy* tmp = headMyEnemy; headMyEnemy->getNextEnemy() != nullptr; tmp = tmp->getNextEnemy ){

	}*/
	}
	timeSpawnEnemy += time;
	return headMyEnemy->getSprite();
}

Sprite GameTanks::moveEnemy(int time, Map map, Enemy* thisEnemy) {
	return thisEnemy->update(time, map);
}

Enemy* GameTanks::getHeadEnemy() {
	return headMyEnemy;
}

Enemy* GameTanks::getNextEnemy() {
	return headMyEnemy->getNextEnemy();
}

Enemy* GameTanks::randClassEnemy() {
	srand(time(0));
	int flag = rand() % 4;
	if (flag == 0) {
		Enemy * newEnemy = new EnemyClass_1;
		return newEnemy;
	}
	else if (flag == 1) {
		Enemy * newEnemy = new EnemyClass_2;
		return newEnemy;
	}
	else if (flag == 2) {
		Enemy * newEnemy = new EnemyClass_3;
		return newEnemy;
	}
	else {
		Enemy * newEnemy = new EnemyClass_4;
		return newEnemy;
	}
}

void GameTanks::checkCollisionsEnemyAndPlaeyr() {
	for (Enemy* tmp = headMyEnemy; tmp->getNextEnemy() != nullptr; tmp = tmp->getNextEnemy()) {
		for (int i = 0; i < numberPlayers; i++) {
			for (int x = myPlayers[i].getCoord_X(); x < myPlayers[i].getCoord_X() + myPlayers[i].getWidth(); x++) {
				int y = myPlayers[i].getCoord_Y()-1;
				if ((x >= tmp->getCoord_X() && x <= tmp->getCoord_X() + tmp->getWidth()) && y >= tmp->getCoord_Y() && y <= tmp->getCoord_Y() + tmp->getHeight()) {
					tmp->setDirecion('S');
					tmp->stop('S');
					myPlayers[i].stop('W');
					break;
				}
				y = myPlayers[i].getMirrorCoord_Y()+1;
				if ((x >= tmp->getCoord_X() && x <= tmp->getCoord_X() + tmp->getWidth()) && y >= tmp->getCoord_Y() && y <= tmp->getCoord_Y() + tmp->getHeight()) {
					tmp->setDirecion('W');
					tmp->stop('W');
					myPlayers[i].stop('S');
					break;
				}
			}
			for (int y = myPlayers[i].getCoord_Y();y < myPlayers[i].getCoord_Y() + myPlayers[i].getHeight(); y++) {
				int x = myPlayers[i].getCoord_X() - 1;
				if ((y >= tmp->getCoord_Y() && y <= tmp->getCoord_Y() + tmp->getHeight()) && x >= tmp->getCoord_X() && x <= tmp->getCoord_X() + tmp->getWidth()) {
					tmp->setDirecion('D');
					tmp->stop('D');
					myPlayers[i].stop('A');
					break;
				}
				x = myPlayers[i].getMirrorCoord_X() + 3;
				if ((y >= tmp->getCoord_Y() && y <= tmp->getCoord_Y() + tmp->getHeight()) && x >= tmp->getCoord_X() && x <= tmp->getCoord_X() + tmp->getWidth()) {
					tmp->setDirecion('A');
					tmp->stop('A');
					myPlayers[i].stop('D');
					break;
				}
			}
		}
	}
}

void GameTanks::checkCollisionsEnemyAndEnemy() {
	for (Enemy* tmp = headMyEnemy; tmp->getNextEnemy() != nullptr; tmp = tmp->getNextEnemy()) {
		for (Enemy* tmp_1 = headMyEnemy; tmp_1->getNextEnemy() != nullptr; tmp_1 = tmp_1->getNextEnemy()) {
			if (tmp != tmp_1) {
				for (int x = tmp->getCoord_X(); x < tmp->getCoord_X() + tmp->getWidth(); x++) {
					int y = tmp->getCoord_Y() - 1;
					if ((x >= tmp_1->getCoord_X() && x <= tmp_1->getCoord_X() + tmp_1->getWidth()) && y >= tmp_1->getCoord_Y() && y <= tmp_1->getCoord_Y() + tmp_1->getHeight()) {
						tmp_1->setDirecion('W');
						tmp_1->stop('S');
						tmp->setDirecion('S');
						tmp->stop('W');
						break;
					}
					y = tmp->getMirrorCoord_Y() + 1;
					if ((x >= tmp_1->getCoord_X() && x <= tmp_1->getCoord_X() + tmp_1->getWidth()) && y >= tmp_1->getCoord_Y() && y <= tmp_1->getCoord_Y() + tmp_1->getHeight()) {
						tmp_1->setDirecion('S');
						tmp_1->stop('W');
						tmp->setDirecion('W');
						tmp->stop('S');
						break;
					}
				}
				for (int y = tmp->getCoord_Y(); y < tmp->getCoord_Y() + tmp->getHeight(); y++) {
					int x = tmp->getCoord_X() - 1;
					if ((y >= tmp_1->getCoord_Y() && y <= tmp_1->getCoord_Y() + tmp_1->getHeight()) && x >= tmp_1->getCoord_X() && x <= tmp_1->getCoord_X() + tmp_1->getWidth()) {
						tmp_1->setDirecion('A');
						tmp_1->stop('D');
						tmp->setDirecion('D');
						tmp->stop('A');
						break;
					}
					x = tmp->getMirrorCoord_X() + 3;
					if ((y >= tmp_1->getCoord_Y() && y <= tmp_1->getCoord_Y() + tmp_1->getHeight()) && x >= tmp_1->getCoord_X() && x <= tmp_1->getCoord_X() + tmp_1->getWidth()) {
						tmp_1->setDirecion('D');
						tmp_1->stop('A');
						tmp->setDirecion('A');
						tmp->stop('D');
						break;
					}
				}

			}
		}
	}
}

void GameTanks::checkBorder() {
	for (Enemy* tmp = headMyEnemy; tmp->getNextEnemy() != nullptr; tmp = tmp->getNextEnemy()) {
		if (tmp->getCoord_X() <= 300 || tmp->getCoord_X() >= 1260 || tmp->getCoord_Y() <= 1 || tmp->getCoord_Y() >= 930) {
			Enemy* tmpE_1 = tmp->getNextEnemy();
			*tmp = *(tmp->getNextEnemy());
			delete tmpE_1;
			numberEnemyOnMap--;
			commonNumderEnemy++;
		}
		if (tmp->getNextEnemy() == nullptr) {
			break;
		}
	}
}

void GameTanks::bangEagle(Map map, RenderWindow& window) {
	if (timeBangEagle > 0) {
		Sprite bang;
		bang.setTexture(textureEnemy);
		if (timeBangEagle > 100) {
			bang.setTextureRect(IntRect(1212, 512, 116, 118));
			bang.setPosition(720, 790);
		}
		else{
			bang.setTextureRect(IntRect(1337, 507, 128, 128));
			bang.setPosition(716, 786);
		}
		//map.setElemMap()
		window.draw(bang);
		timeBangEagle--;
		if (timeBangEagle <= 0) {
			map.setElemMap(27, 13, 0);
			map.setElemMap(26, 13, 0);
			
			map.setElemMap(27, 16, 0);
			map.setElemMap(26, 16, 0);
		
			map.setElemMap(25, 14, 0);
			map.setElemMap(25, 15, 0);

			map.setElemMap(26, 14, 92);
			map.setElemMap(26, 15, 93);
			map.setElemMap(27, 14, 94);
			map.setElemMap(27, 15, 95);
		}
	}

}

bool GameTanks::gameOver(RenderWindow& window, int time) {
	bool flag = false;
	for (int i = 0; i < numberPlayers; i++) {
		if (myPlayers[i].getLife() >0 ){
			flag = true;
		}
	}
	if (flag == false || lifeEagle == false) {
		spriteGameOver.move(-0.1*time, 0);
		window.draw(spriteGameOver);

		if (spriteGameOver.getPosition().x < 600) {
			return false;
		}
	}
	if (commonNumderEnemy <= 0) {
		spriteGameOver.move(-0.1*time, 0);
		if (spriteGameOver.getPosition().x < 600) {
			return false;
		}
	}
	return true;
}
//void GameTanks::stop(int x, int y, Enemy*tmp) {
//	if(tmp->getCoord_X()+tmp->getWidth() - x > 0)
//}

//void GameTanks::location(Enemy* thisEnemy) {
//	srand(time(0));
//	int flag = rand() / 4;
//	switch (flag) {
//	case 0:
//		thisEnemy.
//		spriteEnmey.setTextureRect(IntRect(coordSprite_x + width * int(currentFrame), coordSprite_y, width, height));
//		spritePlayer.move(0, speed);
//		return;
//	case 1:
//		thisEnemy->setCoord(550, 500);
//		return;
//	case 2:
//		thisEnemy->setCoord(600, 500);
//		return;
//	case 3:
//		thisEnemy->setCoord(650, 500);
//		return;
//	default:
//		return;
//	}
//
//}

//char GameTanks::getDirection(int i) {
//	return myPlayers[i].getDirection();
//}
//
//int GameTanks::getCoord_X(int i) {
//	return myPlayers[i].getCoord_X();
//}
//
//int GameTanks::getCoord_Y(int i) {
//	return myPlayers[i].getCoord_Y();
//}

//double GameTanks::getTimeShoot(int i) {
//	return myPlayers[i].getTimeShoot();
//}

//void GameTanks::zeroizeTimeShoot(int i) {
//	myPlayers[i].zeroizeTimeShoot();
//}

GameTanks::~GameTanks() {
	Enemy* tmpE = headMyEnemy;
	while (tmpE->getNextEnemy() != nullptr){
		Enemy* tmpE_1 = tmpE;
		tmpE = tmpE->getNextEnemy();
		delete tmpE_1;
	}
	delete tmpE;

	Shoot* tmpS = headShoot;
	while (tmpS->getNextShoot() != nullptr) {
		Shoot* tmpS_1 = tmpS;
		tmpS = tmpS->getNextShoot();
		delete tmpS_1;
	}
	delete tmpS;
	delete[] myPlayers;
}