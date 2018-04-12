#pragma once
#include<map>
class Scene;
class GameController
{
public:
	static GameController* GetInstance();
	void GameRun();
	bool isGameRun = true;
	int curSceneID = 0;
	std::map<int, Scene*> m_scenes;
private:
	static GameController* instance;
	GameController();
	~GameController();
	GameController(const GameController&);
	GameController& operator=(const GameController&) {};
};

