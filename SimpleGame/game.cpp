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

	POINT ballPosition;
	ballPosition.x = 0;
	ballPosition.y = 340;
	
	ball = new Ball();
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
}

short int Game::GetDesiredFPS() const {
	return 50;
}

void Game::StartSimulation(int velocity, int angle) {
	POINT ballPosition;
	ballPosition.x = 0;
	ballPosition.y = 340;
	ball->SetPosition(ballPosition);
	physics->Simulate(ball, velocity, angle);
}