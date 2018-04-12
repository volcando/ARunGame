#pragma once
#include<Windows.h>
#include<iostream>
#include<map>
#include"Player.h"
using namespace std;
class Scene
{
public:
	Scene();
	virtual ~Scene();
	virtual void SceneRun() = 0;
	void ShowUI();
	bool isSceneRun = true;
	void Pos(int x, int y);
	int havelearned = 0;
protected:
	Player* player = Player::GetInstance();
	map<char*, COORD> m_buttons;
	void showPlayer();
	void clearPlayer();
	void playerJump();
	void UpdatePlayerPos();
	int jumpable = 0;
private:
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
};

