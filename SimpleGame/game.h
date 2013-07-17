#pragma once

#include <WinDef.h>
#include "game\scene.h"
#include "physics\physics.h"

class Game {
public:
	Game(HWND);
	~Game();
	void Draw(HDC hdc);
	void MainGameLoop();
	short int GetDesiredFPS() const;
private:
	Scene* scene;
	Physics* physics;
	HWND hWnd;
};