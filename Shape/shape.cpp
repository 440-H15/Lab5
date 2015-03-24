#include "stdafx.h"
#include "shape.h"
using namespace ShapeLibrary;

Shape::Shape()
{
	nbPoint = 0;
}

void Shape::add(Point _point)
{
	point.push_back(_point);
	nbPoint++;
}

void Shape::draw()
{

}

Point Shape::getPoint(const int& _index)
{
	return *(this->point.begin() + _index);
}

void Shape::setLineColor(Color _color)
{
	lineColor = _color;
}

Color Shape::getLineColor()
{
	return lineColor;
}

void Shape::setFillColor(Color _color)
{
	fillColor = _color;
}

Color Shape::getFillColor()
{
	return fillColor;
}