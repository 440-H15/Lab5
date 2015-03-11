#include "stdafx.h"

using namespace ShapeLibrary;

Shape::Shape(IWindowAPI & _windowAPI)
{
	windowAPI = &_windowAPI;
}

Shape::~Shape()
{
	
}

void Shape::setLineColor(const Color& _lineColor)
{
	lineColor = _lineColor;
}

const Color & Shape::getLineColor() const
{
	return lineColor;
}

void Shape::setFillColor(const Color& _fillColor)
{
	fillColor = _fillColor;
}

const Color & Shape::getFillColor() const
{
	return fillColor;
}

const Point & Shape::getPoint(const int index)
{
	return points.at(index);
}

int Shape::getNumberOfPoints() const
{
	return points.size();
}

void Shape::add(const Point &_point)
{
	points.push_back(_point);
}
