#pragma once
#include "stdafx.h"
#include "IWindowAPI.h"
namespace ShapeLibrary
{
	class Polygon : public ClosedPolyline
	{
	public:
		Polygon(IWindowAPI& _fakeWindowAPI);
		void add(Point _point);
		void draw();
	private:
		IWindowAPI* windowAPI;
		vector<Point> point;
		int nbPoint;
		bool checkLineOnOtherLine(const Point & point1, const Point & point2, const Point & point3, const Point & point4);
	};
}
