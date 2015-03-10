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
		~Shape();
		void virtual draw();
		void setLineColor(const Color& _lineColor);
		Color & getLineColor() const;
		void setFillColor(const Color& _fillColor);
		const Color & getFillColor() const;
		const Point & getPoint(const int index);
		int getNumberOfPoints() const;
		void add(const Point &_point);
	private:
		IWindowAPI * windowAPI;
		vector<Point> points;
		Color lineColor;
		Color fillColor;
	};
}
