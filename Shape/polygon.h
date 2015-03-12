#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Polygon : public ClosedPolyline
	{
	public:
		Polygon(IWindowAPI &_windowAPI);
		void add(const Point &_point) override;
	private:
		bool pointOnPreviousLine(const Point &_point) const;
		bool lineCrossLine(const Point &_point) const;
		float findSlope(const Point& _firstPoint,const Point & _secondPoint) const;
	};

}
