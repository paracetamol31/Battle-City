#pragma once
#include<fstream>
#include<iostream>
#include "SFML/Graphics.hpp"
class Map{
private:
	int centralizerMap;
	int widthSprite;
	int  width;
	int height;
	int ** myMap;
public:
	void setElemMap(int, int, int);
	int getCentralizerMap();
	int getWidthSprite();
	int getElemArry(int, int);
	int getWidth();
	int getHeight();
	Map();
	~Map();
};

