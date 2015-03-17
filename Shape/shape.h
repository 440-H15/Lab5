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
		virtual ~Shape();
		virtual void add(Point & _point);
		virtual void draw() = 0;
		//virtual void setLineColor();
		//virtual Color getLineColor();
		//virtual void setFillColor();
		//virtual Color getFillColor();
		//virtual Point getPoint(int _index);
		//virtual int getNumberOfPoints();

	protected:
		IWindowAPI *windowApi;
		vector<Point> point;
		Color lineColor;
		Color fillColor;
		};
	}
