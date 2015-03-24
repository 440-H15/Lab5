#pragma once
#include "stdafx.h"

#include <vector>

using namespace std;

namespace ShapeLibrary
{

	class Shape
	{
	public:
		Shape();
		virtual void add(Point _point);
		virtual void draw();
		virtual void setLineColor(Color _color);
		virtual Color getLineColor();
		virtual void setFillColor(Color _color);
		virtual Color getFillColor();
		virtual Point getPoint(const int& _index);
	protected:
		IWindowAPI* windowAPI;
		vector<Point> point;
		int nbPoint;
		Color lineColor;
		Color fillColor;
	};
}
