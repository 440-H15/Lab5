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

		void attach();
		void render();
		void putOnTop();

	private:
		IWindowAPI* windowAPI;
		vector<Shape> shapes;

	};
}