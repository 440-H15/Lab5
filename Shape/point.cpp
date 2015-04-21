#include "stdafx.h"

#include <stdexcept>

using namespace ShapeLibrary;


Point::Point( double _x, double _y ) :
	x(_x), 
	y(_y)
{	
	if (x < 0 || y < 0){
		throw invalid_argument("The value must be a positive value");
	}
}

bool Point::operator == (const Point & point) const
{
	if (point.x == x && point.y == y){
		return true;
	}
	else{
		return false;
	}
}

bool Point::operator != (const Point & point) const
{
	if (point == *this){
		return false;
	}
	else{
		return true;
	}
	
}
