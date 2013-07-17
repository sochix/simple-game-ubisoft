#pragma once
#include <WinDef.h>

typedef POINT VECTOR;

class IPhysicsObject {
public:
	IPhysicsObject() {
		velocity.x = velocity.y = 0;
		acc.x = acc.y = 0;
	}	

	virtual POINT GetPosition() const = 0;
	virtual void SetPosition(POINT p) = 0;
	virtual int GetWidth() const = 0;
	virtual int GetHeight() const = 0;
	virtual double GetMass() const = 0;

	inline VECTOR GetVelocity()  const {return velocity;}
	inline void SetVelocity(VECTOR velocity_)  {velocity = velocity_;}

	inline VECTOR GetAcceleration() const  {return acc;}
	inline void SetAcceleration(VECTOR acc_)  {acc = acc_;}
private:
	VECTOR velocity;
	VECTOR acc;
};