#include "Scene.h"


Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::Pos(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
void Scene::ShowUI() {
	map<char*, COORD>::iterator tempIt = m_buttons.begin();
	for (tempIt; tempIt != m_buttons.end(); tempIt++)
	{
		Pos(tempIt->second.X, tempIt->second.Y);
		cout << tempIt->first;
	}
}
//����player��������
void Scene::UpdatePlayerPos() {
	for (PlayerNode* temp = player->leg; temp != player->head; temp = temp->_pref)
	{
		if (temp->_pref) {
			temp->_pref->posX = temp->posX;
			temp->_pref->posY = temp->posY - 1;
		}
	}
	showPlayer();
}
//player��Ծ1��
void Scene::playerJump() {
		clearPlayer();
		player->leg->posY -= 1;
		player->leg->posX += 1;
		UpdatePlayerPos();
		++jumpable;
}
//���player�ڿ���̨�ϵ�λ��
void Scene::clearPlayer() {
	for (PlayerNode* temp = player->head; temp != player->leg; temp = temp->_next)
	{
		Pos(temp->posX, temp->posY);
		cout << "  ";
	}
}
//����player�ڿ���̨�ϵ�λ��
void Scene::showPlayer() {
	for (PlayerNode* temp = player->head; temp != player->leg; temp = temp->_next) {
		Pos(temp->posX, temp->posY);
		if (temp == player->head)
			cout << "��";
		else
			cout << "��";
	}
}



