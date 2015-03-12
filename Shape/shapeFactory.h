#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class	ShapeFactory
	{
	public:
		ShapeFactory(IWindowAPI &_windowAPI);
		Shape& createOpenPolyLine();
		Shape& createCircle(Point &_center, int _radius);
		Shape& createRectangle(Point &_position, int _width, int _height);
		Shape& createClosedPolyLine();
		Shape& createPolygone();
	private:
		IWindowAPI *windowAPI;
	};
}