#pragma once
#include <WinDef.h>

/*
* Interface which represents physic object in the world. 
* All objects which wants to be simulated might implement this interface
*/
class IPhysicsObject {
public:
	virtual POINT  GetPosition()		const	= 0;
	virtual void   SetPosition(POINT p)			= 0;
	virtual int    GetWidth()			const	= 0;
	virtual int    GetHeight()			const	= 0;
};