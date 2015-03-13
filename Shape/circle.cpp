#include "stdafx.h"

using namespace ShapeLibrary;

Circle::Circle(IWindowAPI& _windowAPI) :
	Shape(_windowAPI)
{
}

void Circle::setCenter(const Point& point)
{
	add(point);
}

void Circle::setRadius(const int _radius)
{
	if (_radius < 0)
		throw invalid_argument("Le rayon ne peut pas être négatif.");

	radius = _radius;
}

void Circle::draw() const
{
	if (getNumberOfPoints() < 1)
		throw runtime_error("Le cercle doit avoir un centre.");

	windowAPI->setDrawingColor(getFillColor());
	windowAPI->fillCircle(getPoint(0), radius);

	windowAPI->setDrawingColor(getLineColor());
	windowAPI->drawCircle(getPoint(0), radius);
}