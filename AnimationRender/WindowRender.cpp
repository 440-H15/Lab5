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

void WindowsRender::attach(Shape& _shape)
{
	shapes.push_back(&_shape);
}

void WindowsRender::render()
{
	bool quit = false;
	while (!quit)
	{
		windowAPI->clearScreen();
		for (int i = 0; i < shapes.size(); i++)
		{
			shapes[i]->draw();
		}
		if (windowAPI->hasEvent())
		{
			if (windowAPI->getEvent().getEventType() == QUIT)
			{
				quit = true;
			}
		}
		windowAPI->displayScreen();
		windowAPI->wait(1000 / 60);
	}
}

void WindowsRender::putOnTop(Shape& _shape)
{
	for (int i = 0; i < shapes.size(); i++)
	{
		if (shapes[i] == &_shape)
		{
			shapes.erase(shapes.begin() + i);
		}
	}
	shapes.push_back(&_shape);
}