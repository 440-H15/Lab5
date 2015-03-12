#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Rectangle
	{
	public:
		Rectangle(IWindowAPI& _windowAPI);
		~Rectangle();

		void setPosition(Point _point);
		void setHeight(int _height);
		void setWidth(int _width);
		void draw();

		void setLineColor(Color _color);
		Color getLineColor();
		void setFillColor(Color _color);
		Color getFillColor();

	private:
		IWindowAPI* windowAPI;
		vector<Point> points;
		int height;
		int width;
		Color lineColor;
		Color fillColor;

	};
}