#include "stdafx.h"
#include "openPolyline.h"

using namespace ShapeLibrary;

OpenPolyline::OpenPolyline(IWindowAPI& _windowAPI)
{
	windowAPI = &_windowAPI;
	lineColor = Color::WHITE;
	fillColor = Color::INVISIBLE;
}

OpenPolyline::~OpenPolyline()
{
}