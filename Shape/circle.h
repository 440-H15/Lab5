#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Circle : Shape
	{
	public:
		
		Circle(IWindowAPI & _windowApi);
		~Circle();

		void setCenter(Point & _point);
		void setRadius(int _radius);
		void draw();

	private:
		int radius;
	};
}
