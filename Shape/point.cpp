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
	throw logic_error("Not Implmented yet");
	return true;
}

bool Point::operator != (const Point & point) const
{
	throw logic_error("Not Implmented yet");
	return false; 
}
