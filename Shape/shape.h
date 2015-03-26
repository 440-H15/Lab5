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
		virtual void draw() = 0; //const

		void setLineColor(Color _color);
		Color getLineColor() const;
		void setFillColor(Color _color);
		Color getFillColor() const;
		Point getPoint(int _index) const;
		int getNumberOfPoints() const;

		bool operator==(const Shape &_source) const;

	private:
		Shape();
		
	protected:
	
		IWindowAPI *windowApi;
		vector<Point> point;
		Color lineColor;
		Color fillColor;
		};
	}
