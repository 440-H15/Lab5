#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Circle : public Shape
	{
	public:
		Circle(IWindowAPI& _windowAPI);
		void setCenter(Point& point);
		void setRadius(int _radius);
		void draw();
	private:
		IWindowAPI* windowAPI;
		int radius;
	};
}
