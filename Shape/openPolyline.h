#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class OpenPolyline : public Shape
	{
	public :
		OpenPolyline(IWindowAPI& _windowAPI);
		virtual void draw() const override;
	private :
	};

}
