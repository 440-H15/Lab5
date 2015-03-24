#pragma once
#include "stdafx.h"

namespace ShapeLibrary 
{
	class ClosedPolyline : public OpenPolyline
	{
	public:
		ClosedPolyline(IWindowAPI & _windowAPI);
		void draw() override;
	};
}