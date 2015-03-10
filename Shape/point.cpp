#include "stdafx.h"

#include <stdexcept>

using namespace ShapeLibrary;


Point::Point( double _x, double _y )
{	
	if (_x < 0 || _y < 0)
		throw invalid_argument("Les coordonn�es ne peuvent pas �tre n�gatives.");
}

bool Point::operator == (const Point & point) const
{
	return (this->x == point.x && this->y == point.y);
}

bool Point::operator != (const Point & point) const
{
	return (this->x != point.x || this->y != point.y);
}
