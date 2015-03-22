#include "stdafx.h"

using namespace ShapeLibrary;


Rectangle::Rectangle(IWindowAPI& _windowAPI)
	: Shape(_windowAPI)
{}

Rectangle::~Rectangle()
{
}

void Rectangle::setPosition(Point _point)
{
	add(_point);
}

void Rectangle::setHeight(int _height)
{
	height = _height;
}

void Rectangle::setWidth(int _width)
{
	width = _width;
}

void Rectangle::draw() const
{
	windowAPI->setDrawingColor(getLineColor());
	windowAPI->drawRectangle(this->getPoint(0), width, height);
}
