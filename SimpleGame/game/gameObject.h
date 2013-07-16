#pragma once

#include <windef.h>

class GameObject {
public:
	GameObject();
	virtual ~GameObject();
	POINT GetPosition() const;
	void SetPosition(POINT);
	virtual void Draw(HDC hdc) = 0;
private:
	POINT position;
};