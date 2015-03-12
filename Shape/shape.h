#pragma once
#include "stdafx.h"

#include <vector>

using namespace std;

namespace ShapeLibrary
{

	class Shape
	{
	public:
		Shape(IWindowAPI& _windowAPI);
		~Shape();
		void virtual draw() = 0;
		void setLineColor(const Color& _lineColor);
		const Color & getLineColor() const;
		void setFillColor(const Color& _fillColor);
		const Color & getFillColor() const;
		const Point & getPoint(const int index);
		int getNumberOfPoints() const;
		virtual void add(const Point &_point);
	protected:
		vector<Point> points;
		Color lineColor = Color::WHITE;
		Color fillColor;
		IWindowAPI * windowAPI;
	};
}
