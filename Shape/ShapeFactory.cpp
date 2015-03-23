#include "stdafx.h"

using namespace ShapeLibrary;

ShapeFactory::ShapeFactory(IWindowAPI& _windowAPI) :
windowAPI(&_windowAPI)
{
}

Shape& ShapeFactory::createOpenPolyLine()
{
	return * new OpenPolyline(*windowAPI);
}

Shape& ShapeFactory::createCircle(Point& _center, int _radius)
{
	Circle *circle = new Circle(*windowAPI);
	circle->setCenter(_center);
	circle->setRadius(_radius);

	return *circle;
}

Shape& ShapeFactory::createRectangle(Point& _position, int _width, int _height)
{
	Rectangle *rect = new Rectangle(*windowAPI);
	rect->setPosition(_position);
	rect->setWidth(_width);
	rect->setHeight(_height);

	return *rect;
}

Shape& ShapeFactory::createClosedPolyLine()
{
	return *new ClosedPolyline(*windowAPI);
}

Shape& ShapeFactory::createPolygone()
{
	return *new Polygon(*windowAPI);
}