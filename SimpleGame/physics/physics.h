#pragma once
#include "IPhysicsObject.h"
#include <vector>
#include <WinDef.h>

typedef POINT VECTOR;

struct SimulateParams {
	double angle;
	int velocity;
	POINT position;
	IPhysicsObject* obj;
};

class Physics{
public:
	Physics(double, RECT);
	void PhysicsStep();
	void AddObject(IPhysicsObject*);
	void Simulate(IPhysicsObject* obj, int velocity, int angle);

private:
	void doCollisionDetection();
	void doSimulateStep();
	void startSimulate();
	void stopSimulate();
private:
	std::vector<IPhysicsObject*> objects;
	std::vector<SimulateParams*> objectsToSimulate;
	double gravity;
	RECT world;
	static const double PI;
	static double time;
	static bool running;
};