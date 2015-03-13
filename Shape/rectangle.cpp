#include "stdafx.h"

using namespace ShapeLibrary;

Rectangle::Rectangle(IWindowAPI& _windowAPI)
{
	point = nullptr;
	windowAPI = &_windowAPI;
	width = 0;
	height = 0;
	lineColor = Color::BLUE;
}

void Rectangle::setPosition(Point& _point)
{
	this->point = &_point;
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
	if (point == nullptr) throw runtime_error("Le rectangle n'a pas de position");
	this->windowAPI->setDrawingColor(lineColor);
	
	this->windowAPI->drawRectangle(*point, width, height);
	
}

void Rectangle::setFillColor(Color _color)
{
	this->windowAPI->fillRectangle(*point, width, height);
}

void Rectangle::setLineColor(Color _color)
{
	lineColor = _color;
}