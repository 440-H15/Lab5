#pragma once
#include "stdafx.h"

#include <vector>

using namespace std;

namespace ShapeLibrary
{

	class Shape
	{
	public:
		~Shape();
		Shape(const IWindowAPI &_windowAPI);
		void draw();
		void setLineColor(Color _color);
		Color getLineColor() const;
		void setFillColor(Color _color);
		Color getFillColor() const;
		Point getPoint(const unsigned int& _index) const;
		int getNumberOfPoints() const;

	protected:
		void add(const Point& _point);
		IWindowAPI * windowAPI;
		vector<Point> points;
		Color lineColor;
		Color fillColor;


	};
}
