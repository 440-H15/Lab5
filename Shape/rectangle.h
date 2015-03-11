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
		void setPosition(Point &_point);
	private:
		Point * position = nullptr;
		unsigned int height = 0;
		unsigned int width = 0;
	};
}