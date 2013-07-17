#pragma once

#include <vector>
#include <WinDef.h>
#include "gameObject.h"

/*
* Class which handle all drawable objects in the game
*/
class Scene {
public:
	Scene(HWND);
	~Scene();
	void Draw(HDC hdc);
	void AddObject(GameObject * const);
	void SetInfo(int,int); //displays information, such as velocity and angle

private:
	void drawFloor(HDC hdc);
	void drawInfo(HDC hdc);

private:	
	std::vector<GameObject*>* objects;
	std::wstring infString;
	HWND hWnd;
};