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
	if (_height < 0) throw invalid_argument("Height cannot be negative");
	height = _height;
}

void Rectangle::setWidth(int _width)
{
	if (_width < 0) throw invalid_argument("Width cannot be negative");
	width = _width;
}

void Rectangle::draw() const
{
	if (points.empty()) throw runtime_error("Rectangle does not have a position");

	windowAPI->setDrawingColor(getLineColor());
	windowAPI->fillRectangle(this->getPoint(0), width, height);
	windowAPI->drawRectangle(this->getPoint(0), width, height);
}
