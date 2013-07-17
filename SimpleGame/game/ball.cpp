#include "StdAfx.h"
#include "ball.h"
#include <WinGDI.h>
#include <WinUser.h>

void Ball::Draw(HDC hdc)
{
	RECT rct;

	HBRUSH blueBrush = CreateSolidBrush(RGB(0,255,0));
	HGDIOBJ old = SelectObject(hdc, blueBrush);
	
	Ellipse( hdc, GetPosition().x, GetPosition().y, GetPosition().x + RADIUS, GetPosition().y + RADIUS);
	
	SelectObject(hdc, old);
}

