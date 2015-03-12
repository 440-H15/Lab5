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
	private:
		IWindowAPI* windowAPI;
		Point* point;
		int height;
		int width;
	};
}