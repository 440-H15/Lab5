#include "stdafx.h"

using namespace ShapeLibrary;

Circle::Circle(IWindowAPI &_windowAPI) : Shape(_windowAPI){}

void Circle::draw()
{
	if (points.size() == 0) throw std::runtime_error("Le centre n'a pas été définie");
	windowAPI->setDrawingColor(fillColor);
	windowAPI->fillCircle(points.at(0), radius);
	windowAPI->setDrawingColor(lineColor);
	windowAPI->drawCircle(points.at(0), radius);
}

void Circle::setCenter(Point &_point)
{
	points.push_back(_point);
}

void Circle::setRadius(const int _radius)
{
	if (_radius < 1) throw std::invalid_argument("Le rayon doit au moins être de 1");
	radius = _radius;
}

void Circle::add(const Point &_point)
{
	throw std::runtime_error("Cette fonction n'est pas appliquable ppour cette forme");
}