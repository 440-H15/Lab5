#include "stdafx.h"
#include "point.h"
#include <stdexcept>

using namespace ShapeLibrary;


Point::Point(double _x, double _y)
{
	if (_x < 0) throw invalid_argument("La coordonn�e X doit �tre positive");
	if (_y < 0) throw invalid_argument("La coordonn�e Y doit �tre positive");
	x = _x;
	y = _y;
}

bool Point::operator == (const Point & point) const
{
	if (this->x != point.x) return false;
	if (this->y != point.y) return false;

	return true;
}

bool Point::operator != (const Point & point) const
{
	return !this->operator==(point);
}
