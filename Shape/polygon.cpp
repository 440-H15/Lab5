#include "stdafx.h"

using namespace ShapeLibrary;

Polygon::Polygon(IWindowAPI& _windowAPI) :
	ClosedPolyline(_windowAPI)
{
}

void Polygon::add(const Point& _point)
{
	if (getNumberOfPoints() > 1 && pointOnPreviousLine(_point))
		throw runtime_error("Le point est sur la ligne");

	if (getNumberOfPoints() >= 3 && lineCrossLine(_point))
		throw runtime_error("La ligne en croise une autre");

	Shape::add(_point);
}

bool Polygon::pointOnPreviousLine(const Point& _point) const
{
	//y = ax + b
	float slope, b;
	for (int i = 0; i < getNumberOfPoints() - 1; i++)
	{
		slope = findSlope(getPoint(i), getPoint(i + 1));
		b = getPoint(i).y - (slope * getPoint(i).x);

		if (_point.y == ((slope * _point.x) + b) && ((_point.y > getPoint(i).y || _point.y > getPoint(i + 1).y) && (_point.y < getPoint(i).y || _point.y < getPoint(i + 1).y)))
			return true;
	}

	return false;
}

bool Polygon::lineCrossLine(const Point& _point) const
{
	float currentSlope = findSlope(getPoint(getNumberOfPoints() - 1), _point);
	float currentB = _point.y - (currentSlope * _point.x);
	float slope, b;
	for (int i = 0; i < getNumberOfPoints() - 1; i++)
	{
		slope = findSlope(getPoint(i), getPoint(i + 1));
		if (slope == currentSlope)
			continue;

		b = getPoint(i).y - (slope * getPoint(i).x);

		float x = ((currentB - b) / (slope - currentSlope));

		if ((x < getPoint(i).x && x > getPoint(i + 1).x) || (x > getPoint(i).x && x < getPoint(i + 1).x))
			return true;
	}
	return false;
}

float Polygon::findSlope(const Point& _firstPoint, const Point& _secondPoint) const
{
	if (_secondPoint.x != _firstPoint.x)
		return (_secondPoint.y - _firstPoint.y) / (_secondPoint.x - _firstPoint.x);
	else
		return 0;
}