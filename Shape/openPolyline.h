#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class OpenPolyline
	{
	public:
		OpenPolyline(IWindowAPI& _windowAPI);

		void add(Point _point);
		void draw();
	private:
		IWindowAPI* windowAPI;
		vector<Point> point;
		int nbPoint;
	};
}
