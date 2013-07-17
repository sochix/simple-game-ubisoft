#include "stdafx.h"

#include "game.h"
#include "game\ball.h"


Game::Game(HWND hWnd_):
hWnd(hWnd_) {
	RECT world;
	GetClientRect(hWnd, &world);

	VECTOR gravity;
	gravity.x = 0;
	gravity.y = -10;

	scene = new Scene(hWnd);
	physics = new Physics(gravity, world);

	POINT ballPosition;
	ballPosition.x = 20;
	ballPosition.y = 30;
	auto ball = new Ball();
	ball->SetPosition(ballPosition);
	scene->AddObject(ball);
	physics->AddObject(ball);
}

Game::~Game() {
	delete scene;
	delete physics;
}

void Game::Draw(HDC hdc) {
	scene->Draw(hdc);
}

void Game::MainGameLoop() {
	InvalidateRect(hWnd,NULL,TRUE);	
	physics->PhysicsStep();
	//Sleep(100);
}

short int Game::GetDesiredFPS() const {
	return 50;
}