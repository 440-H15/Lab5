#include "stdafx.h"

#include <stdexcept>

using namespace ShapeLibrary;


Point::Point( double _x, double _y ) :
	x(_x), 
	y(_y)
{	
	if (_x < 0 || _y < 0) throw invalid_argument("parameters cannot be negatives");
	
}

bool Point::operator == (const Point & _point) const
{
	bool egal = true;

	if (&_point != &*this)
	{
		if (_point.x != this->x || _point.y != this->y)
		{
			egal = false;
		}
	}

	return egal;

}

bool Point::operator != (const Point & _point) const
{
	return !(*this == _point);
}
