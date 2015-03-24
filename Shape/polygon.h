#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Polygon : public ClosedPolyline
	{
	public:
		Polygon(IWindowAPI &_windowAPI);
		~Polygon();
		void add(const Point &_point) override;
	private:
		bool doLineCross(Point line1[], Point line2[]);
		float min(float value1, float value2);
		float max(float value1, float value2);
	};
}
