#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Rectangle : public Shape
	{
	public:
		Rectangle(IWindowAPI& _windowAPI);
		void setPosition(Point & _point);
		void setWidth(const int _width);
		void setHeight(const int _height);
		void draw() const override;

	private:
		unsigned int width;
		unsigned int height;
	};
}