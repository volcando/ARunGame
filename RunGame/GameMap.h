#pragma once
#define MAPSIZEX 500
#define MAPSIZEY 14
#define WINDOWSIZEX 50
#define WINDOWSIZEY 14
#define STAR 2
#define GROUND 1
#define SPACE 0
class GameMap
{
public:
	int** map2D;
	void deleteFirstCol();
	int arrayLen;
	int GetMapType(int x, int y);
	GameMap();
	~GameMap();
private:
	char* gameMap1D;
	int* map1D;
	
};

