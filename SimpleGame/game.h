#pragma once

#include <WinDef.h>
#include "game\scene.h"

class Game {
public:
	Game(HWND hWnd);
	void Draw(HDC hdc);
private:
	Scene* scene;
};