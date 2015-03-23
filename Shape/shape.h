#pragma once
#include "stdafx.h"

#include <vector>

using namespace std;

namespace ShapeLibrary
{
	class Shape abstract
	{
	public:
		Shape(IWindowAPI & _windowAPI);
		virtual void draw() const;
		void setLineColor(const Color &_color);
		const Color & getLineColor() const;
		void setFillColor(const Color &_color);
		const Color & getFillColor() const;
		const Point & getPoint(const unsigned int _index) const;
		unsigned int getNumberOfPoints() const;
		virtual void add(const Point & _point);
		virtual ~Shape();
	private:
		vector<Point> point;
		Color lineColor;
		Color fillColor;
	protected:
		IWindowAPI *windowAPI;
	};
}
