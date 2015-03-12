#include "stdafx.h"

#include <stdexcept>

using namespace ShapeLibrary;


Point::Point(double _x, double _y) :
x(_x),
y(_y)
{
	if (_x < 0 || _y < 0) throw invalid_argument("Valeur négative pour un point impossible");
}

bool Point::operator == (const Point & _point) const
{
	if (x != _point.x || y != _point.y)
	{
		return false;
	}
	return true;
}

bool Point::operator != (const Point & _point) const
{
	if (operator==(_point))
	{
		return false;
	}
	return true;
}
