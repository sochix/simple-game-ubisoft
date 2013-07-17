#include "StdAfx.h"
#include "ball.h"
#include <WinGDI.h>
#include <WinUser.h>

void Ball::Draw(HDC hdc)
{
	drawTail(hdc);
	drawBall(hdc);

	POINT centeredPos;
	centeredPos.x = GetPosition().x + RADIUS;
	centeredPos.y = GetPosition().y + RADIUS;
	tail.push_back(centeredPos);
}

void Ball::drawBall(HDC hdc) {
	RECT rct;
	HBRUSH blueBrush = CreateSolidBrush(RGB(0,0,255));
	HGDIOBJ old = SelectObject(hdc, blueBrush);
	
	Ellipse( hdc, GetPosition().x, GetPosition().y, GetPosition().x + DIAMETR, GetPosition().y + DIAMETR);
	
	SelectObject(hdc, old);
}

void Ball::drawTail(HDC hdc) {

	HPEN redPen = HPEN(RGB(255,0,0));
	HGDIOBJ old = SelectObject(hdc, redPen);

	Polyline(hdc, tail.data(),tail.size());
	
	SelectObject(hdc, old);
}

int Ball::GetWidth() const {
	return DIAMETR;
}

int Ball::GetHeight() const {
	return DIAMETR;
}

void Ball::ClearTail() {
	tail.clear();
}