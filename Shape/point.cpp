#include "stdafx.h"

#include <stdexcept>

using namespace ShapeLibrary;


Point::Point( double _x, double _y )
{	
	if (_x < 0) throw invalid_argument("La coordonnée X doit être positive");
	if (_y < 0) throw invalid_argument("La coordonnée Y doit être positive");
	x = _x;
	y = _y;
}

bool Point::operator == (const Point & point) const
{
	throw logic_error("Not Implmented yet");
	return true;
}

bool Point::operator != (const Point & point) const
{
	throw logic_error("Not Implmented yet");
	return false; 
}
