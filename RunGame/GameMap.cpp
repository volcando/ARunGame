#include "GameMap.h"
#include<fstream>
using namespace std;

GameMap::GameMap()
{
#pragma region Read Map From .csv
	ifstream in("GameMap.csv");
	if (!in) {
		printf("»±…Ÿ≈‰÷√Œƒº˛GameMap.csv\n");
		system("pause");
		exit(0);
	}
	in.seekg(0, ios::end);   // go to the end
	int length = in.tellg(); // report location (this is the length)
	in.seekg(0, ios::beg);   // go back to the beginning
	gameMap1D = new char[length];
	in.read(gameMap1D, length);
	in.close();
#pragma endregion
	arrayLen = MAPSIZEX;
	map1D = new int[MAPSIZEX*MAPSIZEY] {};
	map2D = new int*[MAPSIZEX] {};
	for (size_t i = 0; i < MAPSIZEX*MAPSIZEY; i++)
	{
		map1D[i] = *(gameMap1D + 2 * i) - '0';
	}
	for (size_t i = 0; i < MAPSIZEY; ++i)
	{
		map2D[i] = map1D + i*MAPSIZEX;
	}
}

void GameMap::deleteFirstCol() {
	for (size_t i = 0; i < MAPSIZEY; i++)
	{
		for (size_t j = 0; j < arrayLen-1; j++)
		{
			map2D[i][j] = map2D[i][j + 1];
		}
	}
	--arrayLen;
}

int GameMap::GetMapType(int x, int y) {
	return map2D[y - 6][x / 2];
}

GameMap::~GameMap()
{
	delete[] gameMap1D;
	delete[] map1D;
	for (size_t i = 0; i < MAPSIZEY; i++)
	{
		delete[] map2D[i];
	}
}
