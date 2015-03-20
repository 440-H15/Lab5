#pragma once
#include "stdafx.h"
#include <vector>

namespace ShapeLibrary
{
	class OpenPolyline : public Shape
	{
	public:
		OpenPolyline(IWindowAPI & _windowApi);
		~OpenPolyline(); 
		
		virtual void draw();

	};
}
