#include "GameScene.h"
#include"GameMap.h"
#include<conio.h>
#include<ctime>
int GameScene::sceneID = 1;
GameScene::GameScene()
{
	mymap = new GameMap();
	m_buttons["☆--"] = { 6,0 };
}

GameScene::~GameScene()
{
}

void GameScene::SceneRun() {
	ShowUI();
#pragma region 初始化地图
	for (size_t i = 0; i < WINDOWSIZEY; i++)
	{
		for (size_t j = 0; j < WINDOWSIZEX; j++)
		{
			if (mymap->map2D[i][j] == GROUND)
			{
				Pos(j * 2, i + 6);
				cout << "■";
			}
			else if (mymap->map2D[i][j] == STAR) {
				Pos(j * 2, i + 6);
				cout << "☆";
			}
		}
	}
#pragma endregion
#pragma region 初始化Player
	player->leg->posX = 6;
	player->leg->posY = 18;
	UpdatePlayerPos();
#pragma endregion
	Pos(10, 0);
	cout << playerHP;
	char input = NULL;

	while (isSceneRun)
	{
		Sleep(100);
		playerCollide();
		UpdatePlayerPos();
#pragma region 操作教程
		if (havelearned < 3) {
			switch (havelearned)
			{
			case 0:
				Pos(10, 5);
				cout << "按 a 键向左移动";
				if (_getch() == 'a') {
					player->leg->posX--;
					havelearned = 1;
				}
				break;
			case 1:
				Pos(10, 5);
				cout << "按 d 键向右移动，碰到■会死亡";
				if (_getch() == 'd') {
					player->leg->posX++;
					havelearned = 2;
				}	
				break;
			case 2:
				Pos(10, 5);
				cout << "按  空格键  跳跃，吃下☆增加一条生命";
				if (_getch() == ' ') {
					player->isJump = true;
					havelearned = 3;
					Pos(10, 5);
					cout << "                                   ";
				}
				break;
			default:
				break;
			}
		}
#pragma endregion
#pragma region player运动
		if(_kbhit()){
			input = _getch();
		if (input == ' ' && !player->isJump && player->leg->posX < WINDOWSIZEX * 2 - 4) {
			player->isJump = true;
		}
		else if (input == 'a' && player->leg->posX > 0) {
			player->leg->posX--;
			UpdatePlayerPos();
		}
		else if (input == 'd' && player->leg->posX < WINDOWSIZEX*1.5f) {
			player->leg->posX++;
			UpdatePlayerPos();
		}
		}
		if (player->isJump && jumpable < 3) {
			clearPlayer();
			playerJump();
			UpdatePlayerPos();
		}
		if (jumpable == 3) {
			jumpable = 0;
			player->isJump = false;
		}
#pragma endregion


		if(havelearned==3){
#pragma region 地图更新
		change = !change;
		if (change)
			mymap->deleteFirstCol();
		for (size_t i = 0; i < WINDOWSIZEY-2; i++)
		{
			for (size_t j = 0; j < WINDOWSIZEX; j++)
			{
				if (change)
					Pos(j * 2 + 1, i + 6);
				else
					Pos(j * 2, i + 6);
				switch (mymap->map2D[i][j])
				{
				case GROUND:cout << "■";break;
				case STAR:cout << "☆";break;
				default:break;
				}
			}
			if (mymap->map2D[i][0] == SPACE) {
				Pos(0, i + 6);
				cout << "  ";
			}
		}
#pragma endregion
		}
		if (mymap->arrayLen <= 50) {
			++havelearned;
			if (player->leg->posX == 75) {
				system("cls");
				Pos(10, 5);
				cout << "You Win!";
				Sleep(1000);
				system("pause");
				isSceneRun = false;
			}

		}
	}
}
//player移动跳跃控制
void GameScene::playerMove(char input) {
	//double start = clock() / CLOCKS_PER_SEC;
	switch (input)
	{
	case 'w':
		if (jumpable) {
			player->isJump = true;
			clearPlayer();
			playerJump();
			Sleep(50);
			playerJump();
			Sleep(50);
			playerJump();
			Sleep(50);
			/*while (clock() / CLOCKS_PER_SEC - start <= 0) {
				if (_kbhit() && player->isJump) {
					clearPlayer();
					switch (_getch())
					{
					case 'a': player->leg->posX -= 6;break;
					case 'd': player->leg->posX += 6;break;
					default: break;
					}
					UpdatePlayerPos();
					player->isJump = false;
				}
			}		*/
			player->isJump = false;
			UpdatePlayerPos();
		}
		break;
	case 'd':
		//if (mymap->GetMapType(player->head->posX + 2, player->head->posY) != GROUND)
		if (!player->isJump)
			++player->leg->posX;
		UpdatePlayerPos();
		break;
	case 'a':
		//if (mymap->GetMapType(player->head->posX - 2, player->head->posY) != GROUND)
		if (!player->isJump)
			--player->leg->posX;
		UpdatePlayerPos();
		break;
	default:UpdatePlayerPos();
		break;
	}

}

void GameScene::playerCollide() {
	if (!player->isJump&& mymap->GetMapType(player->leg->posX, player->leg->posY) != GROUND) {//player触底死亡
		clearPlayer();
		player->leg->posY++;
		//player->leg->posX++;
		UpdatePlayerPos();
		if (player->leg->posY == WINDOWSIZEY + 6)
			playerDead();
		playerCollide();
	}
	if (mymap->GetMapType(player->head->posX + 2, player->head->posY) == GROUND || mymap->GetMapType(player->head->_next->posX, player->head->_next->posY) == GROUND) {
		playerDead();
	}
	if (mymap->GetMapType(player->head->posX, player->head->posY - 1) == GROUND|| mymap->GetMapType(player->head->posX, player->head->posY - 2) == GROUND) {
		jumpable = 3;
	}
	if (mymap->GetMapType(player->head->_next->posX, player->head->_next->posY) == STAR) {
		mymap->map2D[player->head->_next->posY - 6][player->head->_next->posX / 2] = SPACE;
		++playerHP;
		Pos(10, 0);
		cout << playerHP;
	}

}

void GameScene::playerDead() {
	if (playerHP > 0) {
		--playerHP;
		Pos(10, 0);
		cout << playerHP;
		clearPlayer();
		player->leg->posY = 12;
		player->leg->posX -= 2;
		Pos(10, 5);
		cout << "dead，按 空格键 继续";
		bool input = true;
		while (input)
		{
			if (GetAsyncKeyState(VK_SPACE))
				input = false;
		}
		//system("pause");
		Pos(10, 5);
		cout << "                    ";
		UpdatePlayerPos();
		playerCollide();
	}	
	else {
		isSceneRun = false;
		return;
	}
}