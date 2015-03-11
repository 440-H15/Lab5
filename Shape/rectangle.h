#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Rectangle : public Shape
	{
	public:
		Rectangle(IWindowAPI &_windowAPI);
		virtual void draw();
		void setHeight(const int _height);
		void setWidth(const int _width);
		void setPosition(const Point &_point);
	private:
		Point position = Point(0,0);
		unsigned int height;
		unsigned int width;
	};
}