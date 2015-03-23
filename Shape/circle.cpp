#include "stdafx.h"

using namespace ShapeLibrary;

Circle::Circle(IWindowAPI& _windowAPI)
	: Shape(_windowAPI)
{}

Circle::~Circle()
{
}

void Circle::setCenter(Point _point)
{
	add(_point);
}

void Circle::setRadius(int _radius)
{
	radius = _radius;
}

void Circle::draw() const
{
	windowAPI->setDrawingColor(getLineColor());
	windowAPI->drawCircle(getPoint(0), radius);
}