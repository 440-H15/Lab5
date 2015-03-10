#include "stdafx.h"

#include <stdexcept>

using namespace ShapeLibrary;


Point::Point( double _x, double _y ) :
	x(_x), 
	y(_y)
{	
	if (_x < 0 || _y < 0) throw std::invalid_argument("Les valeurs doivent être positives.");
}

bool Point::operator == (const Point & point) const
{	
	return (this->x == point.x && this->y == point.y);
}

bool Point::operator != (const Point & point) const
{
	throw logic_error("Not Implmented yet");
	return false; 
}
