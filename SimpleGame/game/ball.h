#pragma once
#include "gameObject.h"
#include <vector>

class Ball: public GameObject {
public:
	virtual void Draw(HDC hdc);
	virtual int GetWidth() const;
	virtual int GetHeight() const;
	void ClearTail();

private:
	void drawTail(HDC hdc);
	void drawBall(HDC hdc);

private:
	std::vector<POINT> tail;
	static const int RADIUS = 15;
	static const int DIAMETR = RADIUS * 2;
	static const int TAIL_DIAMETR = 2;
};