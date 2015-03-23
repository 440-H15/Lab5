#include  "stdafx.h"
#include "WindowRender.h"

using namespace WindowRender;
using namespace ShapeLibrary;

WindowsRender::WindowsRender(IWindowAPI& _windowAPI)
{
	windowAPI = &_windowAPI;
}

WindowsRender::~WindowsRender()
{
}

void WindowsRender::attach(Shape _shape)
{
	shapes.push_back(_shape);
}

void WindowsRender::render()
{
	
	while (true)
	{
		for (int i = 0; i < shapes.size(); i++)
		{
			shapes[i].draw();
		}
		if (windowAPI->hasEvent())
		{
			windowEvents.push_back(windowAPI->getEvent());
		}
	}
}

void WindowsRender::putOnTop(Shape _shape)
{
}