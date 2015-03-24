#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class	ShapeFactory
	{
	public:
		ShapeFactory(IWindowAPI &_windowAPI);
		OpenPolyline & createOpenPolyLine() const;
		ClosedPolyline & createClosedPolyLine() const;
		Rectangle & createRectangle(Point & _center, const int _height, const int _width) const;
		Polygon & createPolygone() const;
		Circle & createCircle(Point & _center, const int radius) const;
	private:
		IWindowAPI * windowAPI;
	};

}