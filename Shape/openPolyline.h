#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class OpenPolyline
	{
	public:
		OpenPolyline(IWindowAPI& _windowAPI);
		~OpenPolyline();

		void add(Point _point);
		void draw();

		Point getPoint(int _index);
		int getNumberOfPoints();

		void setLineColor(Color _color);
		Color getLineColor();
		void setFillColor(Color _color);
		Color getFillColor();

	private:
		IWindowAPI* windowAPI;
		vector<Point> points;
		Color lineColor;
		Color fillColor;
	};
}
