#include "stdafx.h"

namespace ShapeLibrary
{
	class Rectangle : public Shape
	{
	public:
		void draw() const;
		Rectangle(IWindowAPI& _windowAPI);
		~Rectangle();
		void setPosition(Point _point);
		void setHeight(int _height);
		void setWidth(int _width);

	private:
		int height;
		int width;

	};


}