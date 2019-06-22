#pragma once
#include <iostream>
//#include"windows.h"
#include"GameTanks.h"
#include "SFML/Graphics.hpp"
#include"map.h";
using namespace sf;
 
class Game {
private:
	//View view;
	int positionPointerMenu_Y ;
	sf::RenderWindow window;
	int numberPlayers;
	void fillMap(Map);
	//Shoot shoot;
	Texture mapTexture;
	Sprite mapSprite;
	Texture shootTexture;
//	Sprite shottSprite;

    void  menu();
public:
	Game();
	void start();
	/*int startMenu();
	void startGame();*/
	void update();

};