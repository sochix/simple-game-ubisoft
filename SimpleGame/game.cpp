#include "stdafx.h"
#include <iostream>
#include "game.h"
#include "game\ball.h"

using namespace std;

Game::Game(HWND hWnd_):
hWnd(hWnd_) {
	RECT world;
	GetClientRect(hWnd, &world);

	scene = new Scene(hWnd);
	physics = new Physics(9.8, world);

	ball = new Ball();

	ballPosition.x = EPS;
	ballPosition.y = world.bottom - ball->GetHeight() - EPS;
	ball->SetPosition(ballPosition);

	scene->AddObject(ball);
	physics->AddObject(ball);

	hPhysicsThread = CreateThread(NULL, 0, &physicsThreadStart, (void*) this, 0, NULL);
}

Game::~Game() {
	TerminateThread( hPhysicsThread, 0 );
	delete scene;
	delete physics;
	delete ball;
}

void Game::Draw(HDC hdc) {
	scene->Draw(hdc);
}

void Game::MainGameLoop() {
	InvalidateRect(hWnd,NULL,TRUE);	
}

short int Game::GetDesiredFPS() const {
	return 50;
}

void Game::StartSimulation(int velocity, int angle) {
	ball->SetPosition(ballPosition);
	ball->ClearTail();
	scene->SetInfo(velocity, angle);
	physics->Simulate(ball, velocity, angle);
}

DWORD Game::physicsThreadProc(void) {
	int delay = 1000 / GetDesiredFPS();
    while (true) { 
		physics->PhysicsStep();
		Sleep(delay);
	}
}

DWORD WINAPI Game::physicsThreadStart(void* Param) {
    Game* This = (Game*) Param;
	return This->physicsThreadProc();
}