#pragma once

#include <windef.h>
#include "..\physics\IPhysicsObject.h"

class GameObject: public IPhysicsObject {
public:
	GameObject();
	virtual ~GameObject();
	virtual POINT GetPosition() const;
	virtual void SetPosition(POINT);
	virtual int GetWidth() const = 0;
	virtual int GetHeight() const = 0;
	virtual double GetMass() const = 0;

	virtual void Draw(HDC hdc) = 0;

private:
	POINT position;
};