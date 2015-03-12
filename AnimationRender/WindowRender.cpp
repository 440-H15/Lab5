#include  "stdafx.h"

using namespace WindowRender;
using namespace ShapeLibrary;

WindowsRender::WindowsRender(IWindowAPI &_windowAPI):
	windowAPI(&_windowAPI)
{
}

void WindowsRender::render()
{
	if (windowAPI->hasEvent())
		windowAPI->getEvent();

	for (Shape* shape : shapes)
	{
		shape->draw();
	}

	windowAPI->clearScreen();
	windowAPI->displayScreen();
	windowAPI->wait(1000);
}

void WindowsRender::attach(Shape& _shape)
{
	shapes.push_back(&_shape);
}

void WindowsRender::putOnTop(Shape& _shape)
{
	vector<Shape*> tempoShapes;

	while (shapes.front() != &_shape)
	{
		tempoShapes.push_back(shapes.front());
		shapes.pop_back();
	}
	shapes.pop_back();

	for (int i = tempoShapes.size(); i > 0; i--)
	{
		shapes.push_back(tempoShapes.front());
		tempoShapes.pop_back();
	}
	shapes.push_back(&_shape);
}