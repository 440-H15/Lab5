#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Rectangle
	{
	public:
		Rectangle(IWindowAPI& _windowAPI);
		void setPosition(Point& _point);
		void setHeight(int _height);
		void setWidth(int _width);
		void draw();
		void setFillColor(Color _color);
		void setLineColor(Color _color);
	private:
		IWindowAPI* windowAPI;
		Point* point;
		Color lineColor;
		int height;
		int width;
	};
}