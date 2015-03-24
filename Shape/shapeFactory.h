#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class	ShapeFactory
	{
	public:
		ShapeFactory(IWindowAPI& _windowAPI);
		Shape& createOpenPolyLine();
		Shape& createCircle(Point _centerPoint, float _radius);
		Shape& createRectangle(Point _centerPoint, float _width, float _height);
		Shape& createClosedPolyLine();
		Shape& createPolygone();
	private:
		IWindowAPI* windowAPI;
	};
}