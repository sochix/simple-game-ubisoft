#include "stdafx.h"

#include "game.h"
#include "game\ball.h"


Game::Game(HWND hWnd_):
hWnd(hWnd_) {
	scene = new Scene(hWnd);
	auto ball = new Ball();
	scene->AddObject(ball);
	
}
void Game::Draw(HDC hdc) {
	scene->Draw(hdc);
}

void Game::MainGameLoop() {
	InvalidateRect(hWnd,NULL,TRUE);	
	//Sleep(100);
}

short int Game::GetDesiredFPS() const {
	return 50;
}