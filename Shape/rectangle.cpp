#include "stdafx.h"

using namespace ShapeLibrary;

Rectangle::Rectangle(IWindowAPI& _windowApi) : Shape(_windowApi)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::setPosition(const Point& _position)
{
	add(_position);
}

void Rectangle::setHeight(const int& _height)
{
	if (_height < 0) throw invalid_argument("Hauteur n�gative non permise.");
	height = _height;
}

void Rectangle::setWidth(const int& _width)
{
	if (_width < 0) throw invalid_argument("Largeur n�gative non permise.");
	width = _width;
}

void Rectangle::draw() const
{
	if (points.size() == 0) throw runtime_error("Aucune position n'a �t� configur�e!");

	if (fillColor.isVisible())
	{
		windowApi->setDrawingColor(fillColor);
		windowApi->fillRectangle(points.back(), width, height);
	}

	windowApi->setDrawingColor(lineColor);
	windowApi->drawRectangle(points.back(), width, height);
}