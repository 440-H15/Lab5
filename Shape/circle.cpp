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
	if (_radius < 0) throw invalid_argument("Radius cannot be negative");
	radius = _radius;
}

void Circle::draw() const
{
	if (points.empty()) throw runtime_error("Circle does not have a center");
	windowAPI->setDrawingColor(getLineColor());
	windowAPI->drawCircle(getPoint(0), radius);
	windowAPI->fillCircle(getPoint(0), radius);
}