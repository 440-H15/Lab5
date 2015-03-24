#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Circle : public Shape
	{
	public:
		Circle(IWindowAPI &_windowAPI);
		virtual void draw();
		void setCenter(Point &_point);
		void setRadius(const int _radius);
		void add(const Point &_point) override;
	private:
		unsigned int radius;
	};
}
