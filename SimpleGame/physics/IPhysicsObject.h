#pragma once
#include <WinDef.h>

typedef POINT VECTOR;

class IPhysicsObject {
public:
	virtual POINT GetPosition() const = 0;
	virtual void SetPosition(POINT p) = 0;
	virtual int GetWidth() const = 0;
	virtual int GetHeight() const = 0;
};