#include "stdafx.h"
#include "openPolyline.h"

using namespace ShapeLibrary;

OpenPolyline::OpenPolyline()
{
}

OpenPolyline::OpenPolyline(IWindowAPI& _windowAPI)
{
	windowAPI = &_windowAPI;
	lineColor = Color::WHITE;
	fillColor = Color::INVISIBLE;
}

OpenPolyline::~OpenPolyline()
{
}

void OpenPolyline::draw()
{
	if (points.size() < 2) throw runtime_error("Minimum de deux points pour pouvoir dessiner");
	windowAPI->setDrawingColor(lineColor);
	for (int i = 0; i < points.size(); i++)
	{
		if ((i + 1) < points.size())
		{
			windowAPI->drawLine(points[i], points[i + 1]);
		}
	}
}