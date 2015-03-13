#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class ClosedPolyline : public Shape
	{
	public:
		ClosedPolyline(IWindowAPI& _windowAPI);
		~ClosedPolyline();

		void draw();

	private:

	};
}