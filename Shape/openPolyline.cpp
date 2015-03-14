#include "stdafx.h"

using namespace ShapeLibrary;
OpenPolyline::OpenPolyline()
{

}

OpenPolyline::OpenPolyline(IWindowAPI& _windowAPI)
{
	windowAPI = &_windowAPI;
	nbPoint = 0;
}

void OpenPolyline::add(Point _point)
{
	this->point.push_back(_point);
	nbPoint++;
}

void OpenPolyline::draw() //Pas sur que toute marche comme il faut
{
	if (nbPoint < 2) throw runtime_error("Il doit y avoir au minimum 2 points");
	this->windowAPI->setDrawingColor(Color::BLUE);
	vector<Point>::iterator it;
	for (it = point.begin(); it < (point.end() - 1); it)
	{
		this->windowAPI->drawLine(*it, *(it++));
	}
}