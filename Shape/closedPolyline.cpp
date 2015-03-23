#include "stdafx.h"

using namespace ShapeLibrary;

ClosedPolyline::ClosedPolyline(IWindowAPI& _windowAPI)
	: OpenPolyline(_windowAPI)
{}

ClosedPolyline::~ClosedPolyline()
{
}

void ClosedPolyline::draw() const
{
	if (points.size() < 3) throw runtime_error("nombre de point inférieur à 3");

	windowAPI->setDrawingColor(getLineColor());
	for (auto i = 0; i < points.size(); i++)
	{
		if (i + 1 < points.size()) windowAPI->drawLine(points[i], points[i + 1]);
		if (i + 1 == points.size()) windowAPI->drawLine(points[i], points[0]);
	}
}