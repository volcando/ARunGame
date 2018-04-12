#pragma once
#include "Scene.h"
class GameMap;
class GameScene :
	public Scene
{
public:
	static int sceneID;
	GameScene();
	~GameScene();
	virtual void SceneRun();
	
private:
	GameMap* mymap;
	bool change = false;	
	int playerHP = 1;
	void playerCollide();
	void playerDead();
	void playerMove(char input);
};

