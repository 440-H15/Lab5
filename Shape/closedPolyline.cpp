#include "stdafx.h"

using namespace ShapeLibrary;

ClosedPolyline::ClosedPolyline(IWindowAPI& _windowAPI) : 
	OpenPolyline(_windowAPI)
{
	
}

void ClosedPolyline::draw() const
{
	windowAPI->setDrawingColor(getLineColor());

	if (getNumberOfPoints() < 3)
		throw runtime_error("Une forme fermée doit avoir au moins 3 lignes.");

	for (unsigned int i = 0; i < getNumberOfPoints() - 1; ++i)
	{
		windowAPI->drawLine(getPoint(i), getPoint(i + 1));
	}
	windowAPI->drawLine(getPoint(getNumberOfPoints() -1), getPoint(1));
}