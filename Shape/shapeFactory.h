#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class	ShapeFactory
	{
	public:
		ShapeFactory(IWindowAPI &_windowAPI);
		OpenPolyline & createOpenPolyLine();
		ClosedPolyline & createClosedPolyLine();
		Rectangle & createRectangle(Point & _center, const int _height, const int _width);
		Polygon & createPolygone();
		Circle & createCircle(Point & _center,const int radius);
	private:
		IWindowAPI * windowAPI;
	};
}