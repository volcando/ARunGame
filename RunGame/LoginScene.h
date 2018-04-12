#pragma once
#include "Scene.h"
class LoginScene :
	public Scene
{
public:
	static int sceneID;
	LoginScene();
	~LoginScene();
	virtual void SceneRun();
private:
	void changeChoice(bool clear);
	void playerFollow();
};

