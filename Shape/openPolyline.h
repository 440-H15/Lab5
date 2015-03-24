#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class OpenPolyline : public Shape
	{
	public:
		OpenPolyline(IWindowAPI & _iWindowAPI);
		~OpenPolyline();
		void draw() const;
	};
}
