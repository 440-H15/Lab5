#include "stdafx.h"

using namespace ShapeLibrary;

OpenPolyline::OpenPolyline(IWindowAPI& _windowAPI) :
	Shape(_windowAPI)
{
}

void OpenPolyline::draw() const
{
	windowAPI->setDrawingColor(getLineColor());

	if (getNumberOfPoints() < 2)
		throw runtime_error("In n'y a pas assez de points pour dessiner une ligne.");

	for (unsigned int i = 0; i < getNumberOfPoints() -1; ++i)
	{
		windowAPI->drawLine(getPoint(i), getPoint(i + 1));
	}
}
