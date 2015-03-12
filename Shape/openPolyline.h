#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class OpenPolyline
	{
	public:
		OpenPolyline(IWindowAPI& _fakeWindowAPI);

		void add(Point _point);
		void draw();
	private:
		IWindowAPI* fakeWindowAPI;
		vector<Point> point;
		int nbPoint;
	};
}
