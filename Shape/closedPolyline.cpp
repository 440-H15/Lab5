#include "stdafx.h"

using namespace ShapeLibrary;

ClosedPolyline::ClosedPolyline(IWindowAPI& _windowApi): OpenPolyline(_windowApi)
{
}

ClosedPolyline::~ClosedPolyline()
{
	
}

void ClosedPolyline::draw(const Color& _color) const
{
	if (points.size() < 3) throw runtime_error("Nombre de points insufisants. Minimum 3 points.");
	
	OpenPolyline::draw(_color);

	// Il ne reste qu'� fermer le polygone
	windowApi->drawLine(points.back(), points.front());
}