#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Polygon : public ClosedPolyline
	{
	public:
		Polygon(IWindowAPI & _windowApi);
		~Polygon();

		void draw();
		void add(Point & _point);

	private:
		bool checkIfPointIsOnSameLine(const Point & _point1, const Point & _point2, const Point & _point3);
		bool checkIfIntersection(const Point & _point1, const Point & _point2, const Point & _point3, const Point & _point4);
	};
}
