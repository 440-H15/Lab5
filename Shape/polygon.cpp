#include "stdafx.h"

using namespace ShapeLibrary;

Polygon::Polygon(IWindowAPI & _windowAPI)
	: ClosedPolyline(_windowAPI)
{
}

Polygon::~Polygon()
{
}

void Polygon::draw() const
{
	windowAPI->setDrawingColor(getLineColor());
	ClosedPolyline::draw();
}

void Polygon::add(const Point & _point)
{
	if (!isLineValid(_point)) throw runtime_error("The point is on the previous line.");
	if (isNewLineCrossingPreviousLine(_point)) throw runtime_error("The line the new point is forming is crossing a previous line");
	points.push_back(_point);
}

bool Polygon::isLineValid(const Point &_point)
{
	if (points.size() < 2) return true;
	double x1 = points[points.size() - 2].x, x2 = points[points.size() - 1].x, x3 = _point.x;
	double y1 = points[points.size() - 2].y, y2 = points[points.size() - 1].y, y3 = _point.y;

	double variation = (y3 - y2) / (x3 - x2);
	double origin = y3 - (variation * x3);
	double previousLineVariation = (y2 - y1) / (x2 - x1);
	double previousLineOrigin = y1 - (previousLineVariation * x1);

	if (variation + origin == previousLineVariation + previousLineOrigin) return false;

	return true;
}

bool Polygon::isNewLineCrossingPreviousLine(const Point &_point)
{
	if (points.size() < 2) return false;
	double x1, x2, x3 = _point.x;
	double y1, y2, y3 = _point.y;

	for (unsigned int i = 0; i < points.size(); i += 2)
	{
		x1 = points[i].x, y1 = points[i].y;
		x2 = points[i + 1].x, y2 = points[i + 1].y;

		if (((x1 - x2) * (x2 - x3) - (y1 - y2) * (y2 - y3)) == 0) return true;
	}
	return false;
}