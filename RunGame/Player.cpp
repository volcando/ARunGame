#include "Player.h"
#include"GameMap.h"
#include<ctime>
#include<conio.h>
Player* Player::instance = nullptr;
Player* Player::GetInstance() {
	if (instance == nullptr)
		instance = new Player();
	return instance;
}
Player::Player()
{
	leg = new PlayerNode(6, 18);
	PlayerNode* temp = leg->SetPref();
	head = temp->SetPref();
	head->_next = temp;
	temp->_next = leg;
}


Player::~Player()
{
}
