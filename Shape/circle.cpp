#include "stdafx.h"

using namespace ShapeLibrary;

Circle::Circle(IWindowAPI &_windowAPI) : Shape(_windowAPI){}

void Circle::draw()
{
	windowAPI->setDrawingColor(lineColor);
	windowAPI->drawCircle(*center, radius);
	windowAPI->fillCircle(*center, radius);
}

void Circle::setCenter(Point &_point)
{
	center = &_point;
}

void Circle::setRadius(const int _radius)
{
	radius = _radius;
}