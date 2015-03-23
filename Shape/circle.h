#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Circle : public Shape
	{
	public:
		void draw() const;
		Circle(IWindowAPI& _windowAPI);
		~Circle();
		void setCenter(Point _point);
		void setRadius(int _radius);

	private:
		int radius;
	};
}
