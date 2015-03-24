#include "stdafx.h"

using namespace ShapeLibrary;

OpenPolyline::OpenPolyline(IWindowAPI &_windowAPI) : Shape(_windowAPI){}

void OpenPolyline::draw()
{
	if (points.size() < 2) throw std::runtime_error("Nombre de points insuffisant.");

	windowAPI->setDrawingColor(lineColor);
	for (int index = 0; index < points.size(); index++)
	{
		if (index + 1 < points.size())
		{
			windowAPI->drawLine(points.at(index), points.at(index + 1));
		}
	}
}
