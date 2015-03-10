#include "stdafx.h"

#include <stdexcept>

using namespace ShapeLibrary;


Point::Point( double _x, double _y )
{	
	if (_x < 0 || _y < 0)
		throw invalid_argument("Les coordonnées ne peuvent pas être négatives.");
}

bool Point::operator == (const Point & point) const
{
	return (this->x == point.x && this->y == point.y);
}

bool Point::operator != (const Point & point) const
{
	return (this->x != point.x || this->y != point.y);
}
