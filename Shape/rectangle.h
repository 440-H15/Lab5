#pragma once
#include "stdafx.h"

namespace ShapeLibrary 
{
	class Rectangle : public Shape
	{
	public:
		Rectangle(IWindowAPI & _windowApi);
		~Rectangle();

		void setPosition(Point & _point);
		void setHeight(int _height);
		void setWidth(int _width);
		void draw();
		void add(Point & _point);
	
	private:
		int height;
		int width;
	};
}