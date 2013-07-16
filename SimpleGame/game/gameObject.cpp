#include "stdafx.h"
#include "gameObject.h"

GameObject::GameObject() {
	position.x = position.y = 0; 
}

GameObject::~GameObject() {
}

POINT GameObject::GetPosition() const {
	return position;
}
void GameObject::SetPosition(POINT p) {
	position = p;
}