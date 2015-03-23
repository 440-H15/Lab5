#pragma once
#include "stdafx.h"

#include <vector>

using namespace std;

namespace ShapeLibrary
{

	class Shape
	{
	public:
		virtual void add(Point _point);
		virtual void draw();
		virtual Point getPoint(const int& _index);
	protected:
		IWindowAPI* windowAPI;
		vector<Point> point;
		int nbPoint;
	};
}
