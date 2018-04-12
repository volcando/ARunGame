#pragma once
class PlayerNode
{
public:
	PlayerNode();
	PlayerNode(int x, int y);
	~PlayerNode();
	PlayerNode* SetPref();
	PlayerNode* _pref = nullptr;
	PlayerNode* _next = nullptr;
	int posX = 0;
	int posY = 0;
};

