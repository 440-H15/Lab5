#include  "stdafx.h"

using namespace WindowRender;
using namespace ShapeLibrary;

WindowsRender::WindowsRender(IWindowAPI &_windowAPI)
{
	windowAPI = &_windowAPI;
}

WindowsRender::~WindowsRender()
{
	for (Shape * shape : shapes)
	{
		delete shape;
	}
}

void WindowsRender::render()
{
	bool dontQuit = true;
	while (dontQuit)
	{
		while (windowAPI->hasEvent())
		{
			if (windowAPI->getEvent().getEventType() == QUIT)
				delete windowAPI->getEvent();
				dontQuit = false;
		}		
		windowAPI->clearScreen();
		for (Shape * shape : shapes)
		{
			shape->draw();
		}
		windowAPI->displayScreen();
		windowAPI->wait(100);
	}	
}

void WindowsRender::attach(Shape &_shape)
{
	shapes.push_back(&_shape);
}

void WindowsRender::putOnTop(Shape &_shape)
{
	for (int index = 0; index < shapes.size(); index++)
	{
		if (shapes.at(index) == &_shape)
		{
			shapes.erase(shapes.begin() + index);
			shapes.push_back(&_shape);
		}
	}
}