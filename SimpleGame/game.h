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
	static DWORD WINAPI physicsThreadStart(void* Param);
	DWORD physicsThreadProc(void);
    void startMyThread()
    {
       DWORD ThreadID;
      
    }

	Scene* scene;
	Physics* physics;
	Ball* ball;
	HWND hWnd;
	POINT ballPosition;
	HANDLE hPhysicsThread;
	static const int EPS = 3;
};