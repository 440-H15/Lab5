#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class OpenPolyline : public Shape
	{
	public:
		OpenPolyline();
		OpenPolyline(IWindowAPI& _windowAPI);
		~OpenPolyline();

		void draw();

	private:
	};
}
