#include "map.h"



Map::Map() {
	widthSprite = 32;
	centralizerMap = 300;
	width = 30;
	height = 30;
	myMap = new int*[width];
	for (int i = 0; i < width; i++) {
		myMap[i] = new int[height];
	}
	std::ifstream out("maps//map_1.txt");
	if (!out.is_open()) {
		std::cout << "Error:File absent!";
	}
	else {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				out >> myMap[i][j];
			/*	std::cout << myMap[i][j];*/
			}
		/*	std::cout << std::endl;*/
		}
		out.close();
	}
}

int Map::getElemArry(int i, int j) {
	return myMap[i][j];
}

int Map::getHeight() {
	return height;
}

int Map::getWidth() {
	return width;
}

int Map::getWidthSprite() {
	return widthSprite;
}

int Map::getCentralizerMap() {
	return centralizerMap;
}

Map::~Map()
{
}

void Map::setElemMap(int i, int j, int elem) {
	myMap[i][j] = elem;
}
