#pragma once
#include "stdafx.h"

using namespace std;
using namespace ShapeLibrary;

namespace WindowRender
{
	class WindowsRender
	{
	public:
		WindowsRender(IWindowAPI & _windowsApi);
		~WindowsRender();

		void attach(Shape &_shape);
		void putOnTop(Shape &_shape);
		void render();

	private:
		IWindowAPI * windowsApi;
		vector<Shape*> shapes;
	};
}