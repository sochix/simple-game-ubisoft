#pragma once
#include "gameObject.h"
#include <vector>

/*
* Class represents Ball in the game
*/

class Ball: public GameObject {
public:
	virtual void Draw(HDC hdc);
	virtual int GetWidth() const;
	virtual int GetHeight() const;
	void ClearTail(); //clear traectory

private:
	void drawTail(HDC hdc); //drawing traectory of the ball
	void drawBall(HDC hdc);

private:
	std::vector<POINT> tail;
	static const int RADIUS = 15;
	static const int DIAMETR = RADIUS * 2;
};