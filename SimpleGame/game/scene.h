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

private:
	void drawGrid(HDC hdc);
	void CreatePens(std::vector<HPEN>& gPens);
	
private:	
	std::vector<GameObject*>* objects;
	HWND hWnd;
};