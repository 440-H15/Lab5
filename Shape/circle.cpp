#include "stdafx.h"

using namespace ShapeLibrary;

Circle::Circle(IWindowAPI &_windowAPI) : Shape(_windowAPI){}

void Circle::draw()
{
	if (center == nullptr) throw std::runtime_error("Le centre n'a pas �t� d�finie");
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
	if (_radius < 1) throw std::invalid_argument("Le rayon doit au moins �tre de 1");
	radius = _radius;
}