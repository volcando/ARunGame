#include "GameController.h"
#include"LoginScene.h"
#include"GameScene.h"
#include"EndScene.h"
GameController* GameController::instance = nullptr;

GameController::GameController()
{
	m_scenes[LoginScene::sceneID] = new LoginScene();
	m_scenes[GameScene::sceneID] = new GameScene();
	m_scenes[EndScene::sceneID] = new EndScene();
}


GameController::~GameController()
{
	delete instance;
}

GameController* GameController::GetInstance() {
	if (instance == nullptr) {
		instance = new GameController();
	}
	return instance;
}

void GameController::GameRun() {
	while (isGameRun)
	{
		m_scenes[curSceneID%m_scenes.size()]->SceneRun();
		if (!m_scenes[curSceneID%m_scenes.size()]->isSceneRun) {
			curSceneID++;
			m_scenes[curSceneID%m_scenes.size()]->isSceneRun = true;
			if (curSceneID > 1 && curSceneID % m_scenes.size() == 1) {
				m_scenes[GameScene::sceneID] = new GameScene();
				m_scenes[GameScene::sceneID]->havelearned = 3;
			}
				
		}			
	}
}
