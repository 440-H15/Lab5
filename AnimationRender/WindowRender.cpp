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
}