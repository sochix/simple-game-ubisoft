#pragma once
#include "IPhysicsObject.h"
#include <vector>
#include <WinDef.h>

/*
* Struct which contains params needed to simulate throwing ob object
*/
struct SimulateParams {
	double angle;
	int velocity;
	POINT position;
	IPhysicsObject* obj;
};

/*
* Class which represent simple Physics library
*/
class Physics{
public:
	Physics(double, RECT);
	void PhysicsStep(); //should be called in cycle for updating physics in world
	void AddObject(IPhysicsObject*); //add object to world
	void Simulate(IPhysicsObject* obj, int velocity, int angle); //simulate object throwing

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