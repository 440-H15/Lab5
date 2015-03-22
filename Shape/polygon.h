#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Polygon : public ClosedPolyline
	{
	public:
		Polygon(IWindowAPI& _windowAPI);
		~Polygon();

		void add(Point _point);

	private:
		bool isOnSameLine(Point _dernierPoint);
		bool isCrossingLine(Point _dernierPoint);
	};
}
