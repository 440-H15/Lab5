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

	};
}
