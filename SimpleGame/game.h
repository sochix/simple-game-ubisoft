#pragma once

#include <WinDef.h>
#include "game\scene.h"
#include "physics\physics.h"
#include "game\ball.h"

/*
* Main class which represents game, and contains all game objects and logic
*/
class Game {
public:
	Game(HWND);
	~Game();
	void Draw(HDC hdc);
	void MainGameLoop(); //send requests to update window
	void StartSimulation(int velocity, int angle);
	short int GetDesiredFPS() const;
	
private:
	static DWORD WINAPI physicsThreadStart(void* Param);
	DWORD physicsThreadProc(void);

private:
	Scene* scene;
	Physics* physics;
	Ball* ball;
	HWND hWnd;
	POINT ballPosition;
	HANDLE hPhysicsThread;
	static const int EPS = 3;
};