#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Circle : public Shape
	{
	public:
		Circle(IWindowAPI& _windowAPI);
		~Circle();

		void setCenter(Point _point);
		void setRadius(int _radius);
		void draw();

	private:
		int radius;

	};
}
