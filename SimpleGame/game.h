#pragma once

#include <WinDef.h>
#include "game\scene.h"
#include "physics\physics.h"
#include "game\ball.h"

class Game {
public:
	Game(HWND);
	~Game();
	void Draw(HDC hdc);
	void MainGameLoop();
	void StartSimulation(int velocity, int angle);
	short int GetDesiredFPS() const;
private:
	Scene* scene;
	Physics* physics;
	Ball* ball;
	HWND hWnd;
};