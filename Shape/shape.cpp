#include "stdafx.h"

using namespace ShapeLibrary;


Shape::Shape()
{
}

Shape::~Shape()
{
}

void Shape::add(Point _point)
{
	points.push_back(_point);
}

void Shape::draw()
{
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

Point Shape::getPoint(int _index)
{
	return points[_index];
}

int Shape::getNumberOfPoints()
{
	return points.size();
}