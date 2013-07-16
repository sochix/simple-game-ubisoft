#pragma once

#include "gameObject.h"


class Ball: public GameObject {
public:
	virtual void Draw(HDC hdc);
private:
	static const int RADIUS = 30;
};