#pragma once

#include <WinDef.h>
#include "game\scene.h"

class Game {
public:
	Game(HWND);
	void Draw(HDC hdc);
	void MainGameLoop();
	short int GetDesiredFPS() const;
private:
	Scene* scene;
	HWND hWnd;
};