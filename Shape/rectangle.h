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
		void add(const Point &_point) override;
	private:
		Point * position = nullptr;
		unsigned int height = 0;
		unsigned int width = 0;
	};
}