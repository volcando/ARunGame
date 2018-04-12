#pragma once
#include"PlayerNode.h"
class Player
{
public:
	static Player* GetInstance();
	PlayerNode* head = nullptr;
	PlayerNode* leg = nullptr;
	bool isJump = false;
private:
	static Player* instance;
	Player();
	Player(const Player&);
	Player& operator=(const Player&) {};
	~Player();
};

