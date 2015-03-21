#include  "stdafx.h"

using namespace WindowRender;
using namespace ShapeLibrary;

WindowsRender::WindowsRender(IWindowAPI &_windowAPI):
	windowAPI(&_windowAPI)
{
}

void WindowsRender::render()
{
	bool quit = false;
	while (!quit)
	{
		while (windowAPI->hasEvent()){
			if (windowAPI->getEvent().getEventType() == QUIT)
				quit = true;
		}

		windowAPI->clearScreen();
		for (Shape* shape : shapes)
		{
			shape->draw();
		}
		windowAPI->displayScreen();
		windowAPI->wait(100);
	}
}

void WindowsRender::attach(Shape& _shape)
{
	shapes.push_back(&_shape);
}

void WindowsRender::putOnTop(Shape& _shape)
{
	int position = 0;
	for (Shape *shape : shapes){
		if (shape == &_shape)
			break;

		position++;
	}

	shapes.erase(shapes.begin() + position);

	shapes.push_back(&_shape);
}

WindowsRender::~WindowsRender(){
	for (Shape *shape : shapes){
		delete shape;
	}
}