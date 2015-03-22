#include "stdafx.h"

using namespace ShapeLibrary;


OpenPolyline::OpenPolyline(const IWindowAPI& _windowAPI) :Shape(_windowAPI)
{
}


void OpenPolyline::add(const Point& _point) 
{
	Shape::add(_point);
}

void OpenPolyline::draw()
{
	if (getNumberOfPoints() < 2) throw runtime_error("Not enough points");

	this->windowAPI->setDrawingColor(getFillColor());

	for (auto i = 1; i < getNumberOfPoints(); i++)
	{
		windowAPI->drawLine(getPoint(i - 1), getPoint(i));
	}

}

