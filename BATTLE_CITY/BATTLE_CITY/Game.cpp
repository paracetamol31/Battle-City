#include"Game.h"


Game::Game() {
	window.create(VideoMode(1600, 900), "BATTLE_CITY"/*, Style::Fullscreen*/);
	/*view.reset(FloatRect(0, 0, 2000, 2000));*/
	numberPlayers = 0;
	positionPointerMenu_Y = 490;
	mapTexture.loadFromFile("images//tanks.png");
	mapSprite.setTexture(mapTexture);
	shootTexture.loadFromFile("images//tanks.png");
	//mapSprite.setTexture(shootTexturee);
}

void Game::start() {
	Clock clock; double timeMap = 0;
	while (window.isOpen()) {
		numberPlayers = 0;
		int time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		menu();
		if (numberPlayers < 0) {
			break;
		}
		if (numberPlayers != 0) {
			/*Shoot* headShoot = new Shoot;*/
			GameTanks gameTanks(numberPlayers);
			Map map;
			while (window.isOpen()) {
				//timeMap = timeMap + clock.getElapsedTime().asSeconds();
				time = clock.getElapsedTime().asMicroseconds();
				clock.restart();
				time = time / 800;
				while (window.pollEvent(event)) {
					if (event.type == Event::Closed) {
						window.close();
					}
				}
				window.clear();
				gameTanks.fillListEnemy(time);
				for (Enemy* tmp = gameTanks.getHeadEnemy(); tmp->getNextEnemy() != nullptr; tmp = tmp->getNextEnemy()) {
					window.draw(gameTanks.moveEnemy(time, map, tmp));
				}
				for (Shoot* tmp = gameTanks.getHeadShoot(); tmp->getNextShoot() != nullptr; tmp = tmp->getNextShoot()) {
					window.draw(tmp->update(time, map));
					if (gameTanks.getkLifeEagle() == true) {
						gameTanks.setLifeEagle(tmp->checkColisionWichEagle(map));
					}
					if (tmp->getNextShoot() == nullptr) {

						break;
					}
				}
				gameTanks.generateShootEnemy(time);
				for (int i = 0; i < numberPlayers; i++) {
					if (gameTanks.getTimeBengPayers(i) > 0) {
						window.draw(gameTanks.updateMove(i, time, map));
						gameTanks.generateShootPlayers(i);
					}

				}
				gameTanks.checkCollisionsEnemyAndPlaeyr();
				gameTanks.checkCollisionsEnemyAndEnemy();
				gameTanks.checkCollisiansBengandEnemy();
				gameTanks.checkCollisiansBengandPlayer();
				gameTanks.checkBorder();
				fillMap(map);
				if (gameTanks.getkLifeEagle() == false) {
					gameTanks.bangEagle(map, window);
				}
				//timeMap = 0;
				if (gameTanks.gameOver(window, time) == false) {
					break;
				}
				window.display();
			}
		}
	}
}

void Game::fillMap(Map map) {
	for (int i = 0; i < map.getWidth(); i++) {
		for (int j = 0; j < map.getHeight(); j++) {
			int flag = map.getElemArry(i,j);
			switch (flag){
			case 1:
				mapSprite.setTextureRect(IntRect(1018, 0, map.getWidthSprite(), map.getWidthSprite()));
				break;
			case 2:
				mapSprite.setTextureRect(IntRect(1050, 0, map.getWidthSprite(), map.getWidthSprite()));
				break;
			case 3:
				mapSprite.setTextureRect(IntRect(1018, 64, map.getWidthSprite(), map.getWidthSprite()));
				break;
			case 4:
				mapSprite.setTextureRect(IntRect(1050, 64, map.getWidthSprite(), map.getWidthSprite()));
				break;
			case 9:
				mapSprite.setTextureRect(IntRect(1478, 0, map.getWidthSprite(), map.getWidthSprite()));
				break;
			case 96:
				mapSprite.setTextureRect(IntRect(1213, 130, map.getWidthSprite(), map.getWidthSprite()));
				break;
			case 97:
				mapSprite.setTextureRect(IntRect(1244, 130, map.getWidthSprite(), map.getWidthSprite()));
				break;
			case 98:
				mapSprite.setTextureRect(IntRect(1213, 162, map.getWidthSprite(), map.getWidthSprite()));
				break;
			case 99:
				mapSprite.setTextureRect(IntRect(1244, 162, map.getWidthSprite(), map.getWidthSprite()));
				break;
			case 92:
				mapSprite.setTextureRect(IntRect(1278, 134, map.getWidthSprite(), map.getWidthSprite()));
				break;
			case 93:
				mapSprite.setTextureRect(IntRect(1310, 134, map.getWidthSprite(), map.getWidthSprite()));
				break;
			case 94:
				mapSprite.setTextureRect(IntRect(1278, 166, map.getWidthSprite(), map.getWidthSprite()));
				break;
			case 95:
				mapSprite.setTextureRect(IntRect(1310, 166, map.getWidthSprite(), map.getWidthSprite()));
				break;
			default:
				flag = 0;
				break;
			}
			if (flag != 0) {
				mapSprite.setPosition(map.getCentralizerMap()+j* map.getWidthSprite(), i*map.getWidthSprite());
				window.draw(mapSprite);
			}
		}
	}
}

void Game::update() {

}

void Game::menu() {
	Texture textureMenu;
	textureMenu.loadFromFile("images//menu.jpg");
	Sprite spriteMenu;
	spriteMenu.setTexture(textureMenu);
	spriteMenu.setTextureRect(IntRect(5, 0, 750, 550));
	spriteMenu.setPosition(400, 100);
	Sprite pointer;
	pointer.setTexture(textureMenu);
	pointer.setTextureRect(IntRect(646,640,42,40));
	pointer.setPosition(550, positionPointerMenu_Y);
		if ((Keyboard::isKeyPressed(Keyboard::W))) {
			positionPointerMenu_Y -= 40;
		}
		if ((Keyboard::isKeyPressed(Keyboard::S))) {
			positionPointerMenu_Y += 40;
		}
		if (positionPointerMenu_Y < 490) {
		 positionPointerMenu_Y = 490;
		}
		if (positionPointerMenu_Y > 530) {
			positionPointerMenu_Y = 530;
		}
		pointer.setPosition(550, positionPointerMenu_Y);
		window.clear();
		window.draw(spriteMenu);
		window.draw(pointer);
		window.display();
		if ((Keyboard::isKeyPressed(Keyboard::Enter))) {
			switch (positionPointerMenu_Y){
		case 490:
			numberPlayers = 1;
			break;
		case 530:
			numberPlayers = 2;
			break;
		default:
			numberPlayers = 1;
			break;
		}
		}
		if ((Keyboard::isKeyPressed(Keyboard::Escape))) {
			numberPlayers = -1;
		}
	}


