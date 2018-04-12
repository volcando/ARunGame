#include "LoginScene.h"
#include<Windows.h>
#include<conio.h>

int LoginScene::sceneID = 0;
LoginScene::LoginScene()
{
	m_buttons["New Game"] = { 10,5 };
	m_buttons["Exit"] = { 10,7 };
	m_buttons["->"] = { 7,5 };
}


LoginScene::~LoginScene()
{
}

void LoginScene::SceneRun() {
	if (isSceneRun) {
		cout << "    按 w s 键移动光标，按 空格键 确认选择";
		ShowUI();
		playerFollow();
	}
	char input = NULL;
	while (isSceneRun)
	{
		if (_kbhit()) {
			input = _getch();
			if (input == 'w') {
				changeChoice(true);
				if (m_buttons["->"].Y == m_buttons["New Game"].Y)
					m_buttons["->"].Y = m_buttons["Exit"].Y;
				else
					m_buttons["->"].Y -= 2;
				changeChoice(false);
				playerFollow();
			}
			else if (input == 's') {
				changeChoice(true);
				if (m_buttons["->"].Y == m_buttons["Exit"].Y)
					m_buttons["->"].Y = m_buttons["New Game"].Y;
				else
					m_buttons["->"].Y += 2;
				changeChoice(false);
				playerFollow();
			}
			else if (input == ' ') {
				isSceneRun = false;
				system("cls");
				if (m_buttons["->"].Y == m_buttons["Exit"].Y) {
					exit(0);
				}
			}
		}
			/*if (GetAsyncKeyState(VK_UP) & 0x8000) {
				changeChoice(true);
				if (m_buttons["->"].Y == m_buttons["New Game"].Y)
					m_buttons["->"].Y = m_buttons["Exit"].Y;
				else
					m_buttons["->"].Y -= 2;
				changeChoice(false);
				playerFollow();
			}
			else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
				changeChoice(true);
				if (m_buttons["->"].Y == m_buttons["Exit"].Y)
					m_buttons["->"].Y = m_buttons["New Game"].Y;
				else
					m_buttons["->"].Y += 2;
				changeChoice(false);
				playerFollow();
			}
			else if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
				isSceneRun = false;
				system("cls");
				if (m_buttons["->"].Y == m_buttons["Exit"].Y) {
					exit(0);
				}
			}*/
	}
}

void LoginScene::changeChoice(bool clear) {
	if (clear) {
		Pos(m_buttons["->"].X, m_buttons["->"].Y);
		cout << "  ";
	}
	else {
		Pos(m_buttons["->"].X, m_buttons["->"].Y);
		cout << "->";
	}
}

void LoginScene::playerFollow() {
	clearPlayer();
	player->leg->posX = m_buttons["->"].X - 2;
	player->leg->posY = m_buttons["->"].Y + 1;
	for (PlayerNode* temp = player->leg; temp != player->head; temp = temp->_pref)
	{
		if (temp->_pref) {
			temp->_pref->posX = temp->posX;
			temp->_pref->posY = temp->posY - 1;
		}
	}
	showPlayer();
}
