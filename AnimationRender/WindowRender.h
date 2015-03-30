#pragma once
#include "stdafx.h"

using namespace std;
using namespace ShapeLibrary;

namespace WindowRender
{
	class WindowsRender
	{
	public:
		WindowsRender(IWindowAPI& _windowAPI);
		~WindowsRender();

		void attach(Shape& _shape);
		void render();
		void putOnTop(Shape& _shape);

	private:
		IWindowAPI* windowAPI;
		vector<Shape*> shapes;
	};
}