#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class OpenPolyline :public Shape
	{
		
	public:
		explicit OpenPolyline(const IWindowAPI& _windowAPI);
		void add(const Point& _point);
	    void draw();
		
	};
}
