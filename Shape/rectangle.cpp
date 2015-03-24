#include "stdafx.h"
#include "rectangle.h"
using namespace ShapeLibrary;

Rectangle::Rectangle(IWindowAPI& _windowAPI)
{
	windowAPI = &_windowAPI;
	width = 0;
	height = 0;
	lineColor = Color::WHITE;
	fillColor = Color::INVISIBLE;
}

void Rectangle::setPosition(Point& _point)
{
	if (point.size() > 0)
	{
		point.pop_back();
	}
	point.push_back(_point);
}

void Rectangle::setHeight(int _height)
{
	if (_height < 0) throw invalid_argument("La hauteur doit être positive");
	height = _height;
}

void Rectangle::setWidth(int _width)
{
	if (_width < 0) throw invalid_argument("La longueur doit être positive");
	width = _width;
}

void Rectangle::draw()
{
	if (point.size() <= 0) throw runtime_error("Le rectangle n'a pas de position");
	this->windowAPI->setDrawingColor(fillColor);
	this->windowAPI->fillRectangle(point[0], width, height);
	this->windowAPI->setDrawingColor(lineColor);
	this->windowAPI->drawRectangle(point[0], width, height);
}
