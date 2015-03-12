#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Polygon : public ClosedPolyline
	{
	public:
		Polygon(IWindowAPI &_windowAPI);
		virtual void draw();
		void add(const Point &_point) override;
	private:
		bool doLineCross(Point line1[], Point line2[]);
	};
}
