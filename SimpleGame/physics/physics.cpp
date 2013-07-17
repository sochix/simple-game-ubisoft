#include "Stdafx.h"
#include "physics.h"
#include <math.h>

const	double	Physics::PI			= 3.14;
		double	Physics::time		= 0;
		bool	Physics::running	= false;

Physics::Physics(double gravity_, RECT world_):
gravity(gravity_),
world(world_) {

}

void Physics::PhysicsStep() {
	if (running) {
		doSimulateStep();
		doCollisionDetection();
		time+=0.1;
	}
}

void Physics::doCollisionDetection() {
	for (auto it = objects.begin(); it != objects.end(); it++) {
		auto object = (*it);
		auto position = object->GetPosition();
		POINT newPos(position);
		
		//below code for checking collisions betwee each bound of the world and object
		if (position.y + object->GetHeight() >= world.bottom) {
			newPos.y = world.bottom - object->GetHeight();
			stopSimulate();
		}

		if (position.y <= world.top) {
			newPos.y = world.top;
			stopSimulate();
		}

		if (position.x + object->GetWidth() >= world.right) {
			newPos.x = world.right - object->GetWidth();
			stopSimulate();
		}

		if (position.x < world.left) {
			newPos.x = world.left;
			stopSimulate();
		}

		object->SetPosition(newPos);
	}
}

void Physics::AddObject(IPhysicsObject* obj) {
	objects.push_back(obj);
}

void Physics::Simulate(IPhysicsObject* obj, int velocity, int angle) {
	SimulateParams* params = new SimulateParams();
	params->angle = angle * PI / 180.f;
	params->velocity = velocity;
	params->obj = obj;
	params->position = obj->GetPosition();

	objectsToSimulate.push_back(params);
	startSimulate();
}

void Physics::doSimulateStep() {
	for (auto it = objectsToSimulate.begin(); it != objectsToSimulate.end(); it++) {
		auto params = (*it);
		POINT newPos; 
		newPos.x =  params->position.x + params->velocity * cosf(params->angle) * time;
		newPos.y =  params->position.y - params->velocity * sinf(params->angle) * time + 0.5 * gravity * time * time;

		params->obj->SetPosition(newPos);
	}
}

void Physics::startSimulate() {
	running = true;
}

void Physics::stopSimulate() {
	time = 0.0;
	running = false;
}