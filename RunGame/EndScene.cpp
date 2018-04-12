#include "EndScene.h"
#include<conio.h>

int EndScene::sceneID = 2;
EndScene::EndScene()
{
	m_buttons["Restart"] = { 10,7 };
	m_buttons["Exit"] = { 10,9 };
	m_buttons["->"] = { 7,7 };
}


EndScene::~EndScene()
{
}

void EndScene::SceneRun() {
	if (isSceneRun) {
		system("cls");
		cout << "    按 w s 键移动光标，按 空格键 确认选择";
		ShowUI();
	}
	char input = NULL;
	while (isSceneRun)
	{
		if (_kbhit()) {
			input = _getch();
			if (input == 'w') {
				changeChoice(true);
				if (m_buttons["->"].Y == m_buttons["Restart"].Y)
					m_buttons["->"].Y = m_buttons["Exit"].Y;
				else
					m_buttons["->"].Y -= 2;
				changeChoice(false);
			}
			else if (input == 's') {
				changeChoice(true);
				if (m_buttons["->"].Y == m_buttons["Exit"].Y)
					m_buttons["->"].Y = m_buttons["Restart"].Y;
				else
					m_buttons["->"].Y += 2;
				changeChoice(false);
			}
			else if (input == ' ') {
				isSceneRun = false;
				system("cls");
				if (m_buttons["->"].Y == m_buttons["Exit"].Y) {
					exit(0);
				}
			}
		}
	}
}


void EndScene::changeChoice(bool clear) {
	if (clear) {
		Pos(m_buttons["->"].X, m_buttons["->"].Y);
		cout << "  ";
	}
	else {
		Pos(m_buttons["->"].X, m_buttons["->"].Y);
		cout << "->";
	}
}