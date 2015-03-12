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
}