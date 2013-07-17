#include "Stdafx.h"
#include "physics.h"

Physics::Physics(VECTOR gravity_, RECT world_):
gravity(gravity_),
world(world_) {

}

void Physics::PhysicsStep() {
	doCollisionDetection();
}

void Physics::doCollisionDetection() {
	for (auto it = objects.begin(); it != objects.end(); it++) {
		auto object = (*it);
		auto position = object->GetPosition();

		POINT newPos(position);
		//TODO: change velocity too
		if (position.y + object->GetHeight() >= world.bottom) {
			newPos.y = world.bottom - object->GetHeight();
			
		}

		if (position.y <= world.top) {
			newPos.y = world.top;
		}

		if (position.x + object->GetWidth() >= world.right) {
			newPos.x = world.right - object->GetWidth();
		}

		if (position.x <= world.left) {
			newPos.x = world.left;
		}
		object->SetPosition(newPos);
	}
}

void Physics::AddObject(IPhysicsObject* obj) {
	objects.push_back(obj);
}

