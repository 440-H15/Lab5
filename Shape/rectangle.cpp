#include "stdafx.h"
#include "rectangle.h"

using namespace ShapeLibrary;

Rectangle::Rectangle(IWindowAPI& _windowAPI) :
width(1),
height(1)
{
	windowAPI = &_windowAPI;
	lineColor = Color::WHITE;
	fillColor = Color::INVISIBLE;
}

Rectangle::~Rectangle()
{
}

void Rectangle::setPosition(Point _point)
{
	points.push_back(_point);
}

void Rectangle::setHeight(int _height)
{
	if (_height <= 0) throw invalid_argument("Une hauteur plus petite ou égal à 0 est impossible");
	height = _height;
}

void Rectangle::setWidth(int _width)
{
	if (_width <= 0) throw invalid_argument("Une largeur de 0 est impossible");
	width = _width;
}

void Rectangle::draw()
{
	if (points.size() == 0) throw runtime_error("Il doit y avoir au moins 1 point");
	windowAPI->setDrawingColor(lineColor);
	windowAPI->drawRectangle(points[0], width, height);
	windowAPI->setDrawingColor(fillColor);
	windowAPI->fillRectangle(points[0], width, height);
}