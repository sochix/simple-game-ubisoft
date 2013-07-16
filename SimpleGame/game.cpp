#include "stdafx.h"

#include "game.h"
#include "game\ball.h"


Game::Game(HWND hWnd) {
	scene = new Scene(hWnd);
	auto ball = new Ball();
	scene->AddObject(ball);
	
}
void Game::Draw(HDC hdc) {

	scene->Draw(hdc);
}