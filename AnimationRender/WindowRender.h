#pragma once
#include "stdafx.h"

using namespace std;
using namespace ShapeLibrary;

namespace WindowRender
{
	class WindowsRender
	{
	public:
	void render();

	private :
		IWindowAPI * windowAPI;
		vector <Shape*> shapes;

		
	};
}