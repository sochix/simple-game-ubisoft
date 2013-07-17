#pragma once

#include "gameObject.h"


class Ball: public GameObject {
public:
	virtual void Draw(HDC hdc);
	virtual int GetWidth() const;
	virtual int GetHeight() const;

private:
	static const int RADIUS = 15;
	static const int DIAMETR = RADIUS * 2;
};