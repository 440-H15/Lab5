#include "stdafx.h"
#include "circle.h"

using namespace ShapeLibrary;

Circle::Circle(IWindowAPI& _windowAPI) :
radius(1)
{
	windowAPI = &_windowAPI;
	lineColor = Color::WHITE;
	fillColor = Color::INVISIBLE;
}

Circle::~Circle()
{
}

void Circle::setCenter(Point _point)
{
	points.pop_back();
	points.push_back(_point);
}

void Circle::setRadius(int _radius)
{
	if (_radius < 0) throw invalid_argument("Le rayon doit être plus grand que 0");
	radius = _radius;
}

void Circle::draw()
{
	if (points.size() == 0) throw runtime_error("Le point du centre est obligatoire");
	windowAPI->setDrawingColor(lineColor);
	windowAPI->drawCircle(points[0], radius);
	windowAPI->setDrawingColor(fillColor);
	windowAPI->fillCircle(points[0], radius);
}