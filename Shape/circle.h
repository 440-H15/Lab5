#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Circle
	{
	public:
		Circle(IWindowAPI& _windowAPI);
		void setCenter(Point& point);
		void setRadius(int _radius);
		void draw();
		void setFillColor(Color _color);
		void setLineColor(Color _color);
	private:
		IWindowAPI* windowAPI;
		Point* point;
		Color lineColor;
		int radius;
	};
}
