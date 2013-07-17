#pragma once
#include "IPhysicsObject.h"
#include <vector>
#include <WinDef.h>

typedef POINT VECTOR;

class Physics{
public:
	Physics(VECTOR, RECT);
	void PhysicsStep();
	void ApplyForce(IPhysicsObject*, double angle, double speed);
	void AddObject(IPhysicsObject*);
private:
	void doCollisionDetection();
private:
	std::vector<IPhysicsObject*> objects;
	VECTOR gravity;
	RECT world;
};