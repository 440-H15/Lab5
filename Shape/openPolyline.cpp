#include "stdafx.h"

using namespace ShapeLibrary;

OpenPolyline::OpenPolyline(IWindowAPI& _fakeWindowAPI)
{
	fakeWindowAPI = &_fakeWindowAPI;
	nbPoint = 0;
}

void OpenPolyline::add(Point _point)
{
	this->point.push_back(_point);
	nbPoint++;
}

void OpenPolyline::draw() //Pas sur que toute marche comme il faut
{
	this->fakeWindowAPI->setDrawingColor(Color::BLUE);
	vector<Point>::iterator it;
	for (it = point.begin(); it < (point.end() - 1); it)
	{
		this->fakeWindowAPI->drawLine(*it, *(it++));
	}
}