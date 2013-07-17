#pragma once

#include <vector>
#include <WinDef.h>
#include "gameObject.h"

class Scene {
public:
	Scene(HWND);
	~Scene();
	void Draw(HDC hdc);
	void AddObject(GameObject * const);
	void SetInfo(int,int);

private:
	void drawGrid(HDC hdc);
	void drawInfo(HDC hdc);

private:	
	std::vector<GameObject*>* objects;
	std::wstring infString;
	HWND hWnd;
};