#include "stdafx.h"

using namespace ShapeLibrary;

OpenPolyline::OpenPolyline(IWindowAPI & _iWindowAPI)
	: Shape(_iWindowAPI)
{}

OpenPolyline::~OpenPolyline()
{

}

void OpenPolyline::draw() const
{
	if (points.size() <= 1) throw runtime_error("nombre de point inférieur à 2");
	windowAPI->setDrawingColor(getLineColor());
	for (size_t i = 0; i < points.size(); i++)
	{
		if (i + 1 < points.size())
		{
			windowAPI->drawLine(points[i], points[i + 1]);
		}
	}
}


