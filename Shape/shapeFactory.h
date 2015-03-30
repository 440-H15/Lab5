#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class ShapeFactory
	{
	public:
		ShapeFactory(IWindowAPI& _windowAPI);
		~ShapeFactory();

		Shape& createOpenPolyLine();
		Shape& createCircle(Point _point, int _rayon);
		Shape& createRectangle(Point _point, int _height, int _width); 
		Shape& createClosedPolyLine();
		Shape& createPolygone();
		
	private:
		IWindowAPI* windowAPI;
	};
}