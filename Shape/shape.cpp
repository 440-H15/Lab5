#include "stdafx.h"

using namespace ShapeLibrary;

Shape::Shape(IWindowAPI& _windowAPI)
{
	this->windowAPI = &_windowAPI;
}

void Shape::draw() const
{
	windowAPI->setDrawingColor(lineColor);
}

void Shape::setLineColor(const Color& _color)
{
	lineColor = _color;
}

const Color& Shape::getLineColor() const
{
	return lineColor;
}

void Shape::setFillColor(const Color& _color)
{
	fillColor = _color;
}

const Color& Shape::getFillColor() const
{
	return fillColor;
}

const Point& Shape::getPoint(const unsigned _index) const
{
	if (_index > getNumberOfPoints())
		throw invalid_argument("L'index est plus grand que le nombre de points.");
	return point[_index];
}

unsigned int Shape::getNumberOfPoints() const
{
	return point.size();
}

void Shape::add(const Point& _point)
{
	point.push_back(_point);
}

Shape::~Shape()
{
	point.clear();
}