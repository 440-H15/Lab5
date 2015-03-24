#include "stdafx.h"

using namespace ShapeLibrary;

ClosedPolyline::ClosedPolyline(IWindowAPI &_windowAPI) : OpenPolyline(_windowAPI){}

void ClosedPolyline::draw()
{
	if (points.size() <= 2) throw std::runtime_error("Nombre de points insuffisant.");

	windowAPI->setDrawingColor(lineColor);
	for (int index = 0; index < points.size(); index++)
	{
		if (index + 1 < points.size())
		{
			windowAPI->drawLine(points.at(index), points.at(index + 1));
		}
		else
		{
			windowAPI->drawLine(points.at(index), points.at(0));
		}
	}
}