#include "stdafx.h"
#include "circle.h"
using namespace ShapeLibrary;

Circle::Circle(IWindowAPI& _windowAPI)
{
	radius = 0;
	windowAPI = &_windowAPI;
	lineColor = Color::WHITE;
	fillColor = Color::INVISIBLE;
}

void Circle::setCenter(Point& _point)
{
	if (point.size() > 0)
	{
		point.pop_back();
	}
	point.push_back(_point);
}

void Circle::setRadius(int _radius)
{
	if (_radius < 0) throw invalid_argument("Le rayon doit être positif");
	radius = _radius;
}

void Circle::draw()
{
	if (point.size() <= 0) throw runtime_error("Le cercle n'a pas de point centrale");
	this->windowAPI->setDrawingColor(fillColor);
	this->windowAPI->fillCircle(point[0], radius);
	this->windowAPI->setDrawingColor(lineColor);
	this->windowAPI->drawCircle(point[0], radius);
}
