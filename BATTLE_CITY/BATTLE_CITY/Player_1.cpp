#include "Player_1.h"



Player_1::Player_1(){
		coord_x = 650;
		powerShoot = 1;
		coord_y = 827;
		coordSprite_x = 0;
		coordSprite_y = 0;
		name = "firstPlayer";
	spritePlayer.setTextureRect(IntRect(coordSprite_x, coordSprite_y, width, height));
	spritePlayer.setPosition(coord_x, coord_y);
}

Player_1::~Player_1()
{
}
