#include  "stdafx.h"
#include "WindowRender.h"
using namespace WindowRender;
using namespace ShapeLibrary;

WindowsRender::WindowsRender(IWindowAPI& _windowAPI)
{
	windowAPI = &_windowAPI;
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
	/*windowAPI->hasEvent();
	windowAPI->getEvent();
	windowAPI->clearScreen();
	windowAPI->displayScreen();
	windowAPI->wait(3000);*/
}

void WindowsRender::attach(Shape& _shape)
{
	shapes.push_back(&_shape);
}

void WindowsRender::putOnTop(Shape& _shape)
{
	vector<Shape*>::iterator it;
	for (it = shapes.begin(); it < (shapes.end() - 1); it++)
	{
		if (*it == &_shape)
		{
			shapes.erase(it + 1);
		}
	}
	shapes.push_back(&_shape);
	
}