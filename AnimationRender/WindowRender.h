#pragma once
#include "stdafx.h"

using namespace std;
using namespace ShapeLibrary;

namespace WindowRender
{
	class WindowsRender
	{
	public:
		WindowsRender(IWindowAPI &_windowAPI);
		void render();	
	private:
		IWindowAPI * windowAPI;
	};
}