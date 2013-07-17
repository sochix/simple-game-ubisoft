#include "StdAfx.h"
#include "scene.h"
#include <vector>
#include <WinGDI.h>
#include <WinUser.h>
#include <sstream>

using namespace std;

Scene::Scene(HWND hWnd_): hWnd(hWnd_) {
	objects = new vector<GameObject*>;
}

Scene::~Scene() {
	delete objects;
}

void Scene::AddObject(GameObject* obj) {
	objects->push_back(obj);
}

void Scene::Draw(HDC hdc) {
	drawFloor(hdc);
	for (auto it = objects->begin(); it != objects->end(); it++) {
		(*it)->Draw(hdc);		
	}
	drawInfo(hdc);
}

void Scene::drawFloor(HDC hdc) {
	//TODO: extract brushes from this method to private members of class
	RECT rct;
	GetClientRect(hWnd, &rct);

	COLORREF colOfAxis = RGB(0,127,14);
	HPEN axisPen = CreatePen(PS_DASH,8,colOfAxis); 
	HGDIOBJ old = SelectObject(hdc, axisPen);

	vector<POINT> xAxis(2);
	xAxis[0].y = xAxis[1].y = rct.bottom;
	xAxis[0].x = rct.left;
	xAxis[1].x = rct.right;
	Polyline(hdc, xAxis.data(), xAxis.size());

	SelectObject(hdc, old);
}

void Scene::drawInfo(HDC hdc) {
	RECT rct;
	GetClientRect(hWnd, &rct);

	COLORREF colOfAxis = RGB(0,0,0);
	HPEN axisPen = CreatePen(2,4,colOfAxis);
	HGDIOBJ old = SelectObject(hdc, axisPen);
	
	TextOut(hdc, rct.left+4, rct.top, infString.c_str() ,infString.size());
	
	SelectObject(hdc, old);
}

void Scene::SetInfo(int velocity, int angle) {
	wstringstream str;
	str << "Velocity: " << velocity << " m/s, Angle: " << angle << endl;
	infString = str.str();
}