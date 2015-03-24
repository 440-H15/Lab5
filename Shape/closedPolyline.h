#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class ClosedPolyline :	public OpenPolyline
	{
	public:
		ClosedPolyline();
		ClosedPolyline(IWindowAPI& _windowAPI);
		void draw();
	
	};
}