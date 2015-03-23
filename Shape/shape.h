#pragma once
#include "stdafx.h"

#include <vector>

using namespace std;

namespace ShapeLibrary
{

	class Shape
	{
	public:
		Shape(IWindowAPI & _windowApi);
		virtual ~Shape();

		virtual void add(Point & _point);
		virtual void draw() = 0;
		virtual void setLineColor(Color _color);
		virtual Color getLineColor() const;
		virtual void setFillColor(Color _color);
		virtual Color getFillColor() const;
		virtual Point getPoint(int _index) const;
		virtual int getNumberOfPoints() const;
		
		bool operator==(const Shape &_source) const;

	protected:
		IWindowAPI *windowApi;
		vector<Point> point;
		Color lineColor;
		Color fillColor;
		};
	}
