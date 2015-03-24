#include "stdafx.h"

using namespace ShapeLibrary;

Rectangle::Rectangle(IWindowAPI &_windowAPI) : Shape(_windowAPI){}

void Rectangle::draw()
{
	if (position == nullptr) throw std::runtime_error("Une des dimention n'a pas été définie");
	windowAPI->setDrawingColor(fillColor);
	windowAPI->fillRectangle(*position, width, height);
	windowAPI->setDrawingColor(lineColor);	
	windowAPI->drawRectangle(*position, width, height);
}

void Rectangle::setHeight(const int _height)
{
	if (_height < 1) throw std::invalid_argument("La valeur doit au moins être de 1");
	height = _height;
}

void Rectangle::setWidth(const int _width)
{
	if (_width < 1) throw std::invalid_argument("La valeur doit au moins être de 1");
	width = _width;
}

void Rectangle::setPosition(Point &_point)
{
	position = &_point;
}

void Rectangle::add(const Point &_point)
{
	throw std::runtime_error("Cette fonction n'est pas appliquable ppour cette forme");
}