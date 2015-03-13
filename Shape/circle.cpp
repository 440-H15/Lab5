#include "stdafx.h"

using namespace ShapeLibrary;

Circle::Circle(IWindowAPI& _windowAPI)
{
	lineColor = Color::BLUE;
	point = nullptr;
	radius = 0;
	windowAPI = &_windowAPI;
}

void Circle::setCenter(Point& _point)
{
	point = &_point;
}

void Circle::setRadius(int _radius)
{
	if (_radius < 0) throw invalid_argument("Le rayon doit être positif");
	radius = _radius;
}

void Circle::draw()
{
	if (point == nullptr) throw runtime_error("Le cercle n'a pas de point centrale");
	this->windowAPI->setDrawingColor(lineColor);
	this->windowAPI->drawCircle(*point, radius);
}

void Circle::setFillColor(Color _color)
{
	this->windowAPI->fillCircle(*point, radius);
}

void Circle::setLineColor(Color _color)
{
	lineColor = _color;
}