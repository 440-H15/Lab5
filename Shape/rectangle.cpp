#include "stdafx.h"

using namespace ShapeLibrary;

Rectangle::Rectangle(IWindowAPI& _windowAPI)
{
	windowAPI = &_windowAPI;
	width = 0;
	height = 0;
}

void Rectangle::setPosition(Point& _point)
{
	this->point = &_point;
}

void Rectangle::setHeight(int _height)
{
	height = _height;
}

void Rectangle::setWidth(int _width)
{
	width = _width;
}

void Rectangle::draw()
{
	this->windowAPI->setDrawingColor(Color::BLUE);
	
	this->windowAPI->drawRectangle(*point, width, height);
	
}