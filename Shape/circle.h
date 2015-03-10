#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Circle : public Shape
	{
	public:
		Circle(IWindowAPI & _windowAPI);
		void setCenter(const Point & point);
		void setRadius(const int _radius);
		void draw() const override;
	private:
		unsigned int radius;
	};
}
