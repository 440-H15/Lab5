#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Circle : public Shape
	{
	public:
		Circle(IWindowAPI & _windowApi);
	    ~Circle();

		void setCenter(Point & _point);
		void setRadius(int _radius);

		void draw();
		void add(Point & _point);

	private:
		int radius;
	};
}
