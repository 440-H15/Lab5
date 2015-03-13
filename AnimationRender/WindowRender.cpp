#include  "stdafx.h"

using namespace WindowRender;
using namespace ShapeLibrary;

WindowsRender::WindowsRender(IWindowAPI &_windowAPI)
{
	windowAPI = &_windowAPI;
}

void WindowsRender::render()
{
	windowAPI->clearScreen();
	if (windowAPI->hasEvent()) windowAPI->getEvent();
	for (Shape * shape : shapes)
	{
		shape->draw();
	}
	windowAPI->wait(1000);
	windowAPI->displayScreen();
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