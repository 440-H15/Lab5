#include "stdafx.h"

using namespace ShapeLibrary;

Rectangle::Rectangle(IWindowAPI& _windowApi) : windowApi(&_windowApi)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::setPosition(const Point& _position)
{
	position = make_unique<Point>(_position);
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

void Rectangle::setFillColor(const Color& _fillColor)
{
	Shape::setFillColor(_fillColor);
}

void Rectangle::setLineColor(const Color& _lineColor)
{
	Shape::setLineColor(_lineColor);
}

void Rectangle::draw(const Color& _color) const
{
	if (position == nullptr) throw runtime_error("Aucune position n'a �t� configur�e!");
	windowApi->setDrawingColor(_color);
	windowApi->drawRectangle(*position, width, height);

	if (fillColor.isVisible())
	{
		windowApi->fillRectangle(*position, width, height);
	}
}