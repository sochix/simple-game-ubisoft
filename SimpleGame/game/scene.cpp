#include "StdAfx.h"
#include "scene.h"
#include <vector>
#include <WinGDI.h>
#include <WinUser.h>

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
	//drawGrid(hdc);
	for (auto it = objects->begin(); it != objects->end(); it++) {
		(*it)->Draw(hdc);
		auto oldPos = (*it)->GetPosition();
		POINT newPos;
		newPos.x = oldPos.x + 2;
		newPos.y = oldPos.y + 2;
		(*it)->SetPosition(newPos); 
	}
}

void Scene::drawGrid(HDC hdc) {
	
	RECT rct;
	GetClientRect(hWnd, &rct);

	const int	height  = rct.top - rct.bottom,
				width	= rct.left - rct.right;
	COLORREF col = RGB(150,150,150);
	HPEN gridPen = CreatePen(2,1,col); //TODO: do proper style

	HGDIOBJ old = SelectObject(hdc, gridPen);
	 
	vector<POINT> horizGrid(2);
	for (int i=rct.top; i < rct.bottom; i+=20) {
		horizGrid[0].y = horizGrid[1].y = i;
		horizGrid[0].x = rct.left;
		horizGrid[1].x = rct.right;

		Polyline(hdc, horizGrid.data(), horizGrid.size());
	}

	vector<POINT> vertGrid(2);
	for (int i=rct.left; i < rct.right; i+=20) {
		vertGrid[0].x = vertGrid[1].x = i;
		vertGrid[0].y = rct.top;
		vertGrid[1].y = rct.bottom;

		Polyline(hdc, vertGrid.data(), vertGrid.size());
	}

	COLORREF colOfAxis = RGB(0,0,0);
	HPEN axisPen = CreatePen(2,4,colOfAxis); //TODO: do proper style
	SelectObject(hdc, axisPen);

	vector<POINT> xAxis(2);
	xAxis[0].y = xAxis[1].y = abs(rct.top - rct.bottom) / 2;
	xAxis[0].x = rct.left;
	xAxis[1].x = rct.right;
	Polyline(hdc, xAxis.data(), xAxis.size());

	SelectObject(hdc, old);
}



void Scene::CreatePens(std::vector<HPEN>& gPens)
{
	for (int i=0;i<gPens.size();i++)
	{
		int style=rand()%4;
		int width=1+rand()%8;
		COLORREF col=RGB(rand()%255,rand()%255,rand()%255);

		gPens[i]=CreatePen(style,width,col);
	}
/*
	for (i=0;i<NUM_BRUSHES;i++)
		gBrushes[i]=CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
*/
}