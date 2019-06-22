#include "Player_2.h"



Player_2::Player_2(){
	coord_x = 850;
	coord_y = 827;
	coordSprite_x = 0;
	powerShoot=1;
	coordSprite_y = 508;
	name = "secondPlayer";
	spritePlayer.setTextureRect(IntRect(coordSprite_x, coordSprite_y, width, height));
	spritePlayer.setPosition(coord_x, coord_y);
}


Player_2::~Player_2()
{
}
