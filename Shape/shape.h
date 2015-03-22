#pragma once
#include "stdafx.h"

#include <vector>

using namespace std;

namespace ShapeLibrary
{

	class Shape
	{
	public:
		virtual ~Shape()
		{
		}

		Shape(IWindowAPI & windowAPI);
		virtual void draw()const = 0;
		virtual void add(const Point & _point);
		virtual Point getPoint(const int _index) const;
		virtual void setLineColor(const Color &_lineColor);
		virtual const Color getLineColor() const;
		virtual void setFillColor(const Color &_fillColor);
		virtual const Color getFillColor() const;
	protected:

		IWindowAPI * windowAPI;
		vector<Point> points;
	private:
		Color lineColor;
		Color fillColor;
	};
}
