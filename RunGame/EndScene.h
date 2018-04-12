#pragma once
#include "Scene.h"
class EndScene :
	public Scene
{
public:
	static int sceneID;
	EndScene();
	~EndScene();
	virtual void SceneRun();
private:
	void EndScene::changeChoice(bool clear);
};

