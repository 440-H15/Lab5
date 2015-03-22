#include "stdafx.h"

using namespace ShapeLibrary;

Shape::Shape(IWindowAPI & _windowAPI)
{
	windowAPI = &_windowAPI;
	
}
void Shape::add(const Point & _point)
{
	points.push_back(_point);
}

Point Shape::getPoint(int _index)
{
	return points[_index];
}

void Shape::setLineColor(const Color &_lineColor)
{
	lineColor = _lineColor;
}

Color const Shape::getLineColor() const
{
	return lineColor;
}

void Shape::setFillColor(const Color &_fillColor)
{
	fillColor = _fillColor;
}

Color const Shape::getFillColor() const
{
	return fillColor;
}