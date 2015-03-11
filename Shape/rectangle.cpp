#include "stdafx.h"

using namespace ShapeLibrary;

Rectangle::Rectangle(IWindowAPI &_windowAPI) : Shape(_windowAPI){}

void Rectangle::draw()
{
	windowAPI->setDrawingColor(lineColor);
	windowAPI->drawRectangle(position, width, height);
}

void Rectangle::setHeight(const int _height)
{
	height = _height;
}

void Rectangle::setWidth(const int _width)
{
	width = _width;
}

void Rectangle::setPosition(const Point &_point)
{
	position = _point;
}
