#include "stdafx.h"

using namespace ShapeLibrary;

Rectangle::Rectangle(IWindowAPI& _windowAPI)
	: Shape(_windowAPI)
{
}

void Rectangle::setPosition(Point& _point)
{
	Shape::add(_point);
}

void Rectangle::setWidth(const int _width)
{
	if (_width < 0)
		throw invalid_argument("La largeur ne peut pas être négative.");

	width = _width;
}

void Rectangle::setHeight(const int _height)
{
	if (_height < 0)
		throw invalid_argument("La hauteur ne peut pas être négative.");

	height = _height;
}

void Rectangle::draw() const
{
	if (getNumberOfPoints() < 1)
		throw runtime_error("La position doit être précisée.");

	windowAPI->setDrawingColor(getFillColor());
	windowAPI->fillRectangle(getPoint(0), width, height);
	windowAPI->setDrawingColor(getLineColor());
	windowAPI->drawRectangle(getPoint(0), width, height);
}
