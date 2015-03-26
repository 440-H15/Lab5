#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class ShapeFactory
	{
	public:
		ShapeFactory(IWindowAPI & windowApi);
		~ShapeFactory();

		Shape & createOpenPolyLine() const;
		Shape & createClosedPoylLine() const;
		Shape & createPolygone() const;
		Shape & createClosedPolyLine() const;
		Shape & createRectangle(Point &_point, int _height, int _width) const;
		Shape & createCircle(Point &_point, int _radius) const;
		
	private:
		IWindowAPI *windowApi;
	};
}