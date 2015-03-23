#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Polygon : public ClosedPolyline
	{
	public:
		Polygon(IWindowAPI &_windowAPI);
		~Polygon();
		void draw() const;
		void add(const Point & _point);
	private:
		bool isLineValid(const Point &_point);
		bool isNewLineCrossingPreviousLine(const Point &_point);
	};
}
