#include "stdafx.h"
#include "closedPolyline.h"

using namespace ShapeLibrary;

ClosedPolyline::ClosedPolyline()
{
}

ClosedPolyline::ClosedPolyline(IWindowAPI& _windowAPI)
{
	windowAPI = &_windowAPI;
	lineColor = Color::WHITE;
	fillColor = Color::INVISIBLE;
}

ClosedPolyline::~ClosedPolyline()
{
}

void ClosedPolyline::draw()
{
	if (points.size() < 3) throw runtime_error("Minimum de 3 points pour pouvoir dessiner");
	windowAPI->setDrawingColor(lineColor);
	for (int i = 0; i < points.size(); i++)
	{
		if ((i + 1) < points.size())
		{
			windowAPI->drawLine(points[i], points[i + 1]);
		}
		else
		{
			windowAPI->drawLine(points[i], points[0]);
		}
	}
}