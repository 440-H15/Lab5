#include "stdafx.h"

using namespace ShapeLibrary;

ShapeFactory::ShapeFactory(IWindowAPI &_windowAPI)
{
	windowAPI = &_windowAPI;
}

OpenPolyline & ShapeFactory::createOpenPolyLine()
{
	OpenPolyline * openPolyline = new OpenPolyline(*windowAPI);
	return *openPolyline;
}

ClosedPolyline & ShapeFactory::createClosedPolyLine()
{
	ClosedPolyline * closedPolyline = new ClosedPolyline(*windowAPI);
	return *closedPolyline;
}

Rectangle & ShapeFactory::createRectangle(Point & _center, const int _height, const int _width)
{
	Rectangle * rectangle = new Rectangle(*windowAPI);
	rectangle->setHeight(_height);
	rectangle->setWidth(_width);
	rectangle->setPosition(_center);
	return *rectangle;
}

Polygon & ShapeFactory::createPolygone()
{
	Polygon * polygone = new Polygon(*windowAPI);
	return * polygone;
}

Circle & ShapeFactory::createCircle(Point & _center, const int _radius)
{
	Circle * cercle = new Circle(*windowAPI);
	cercle->setCenter(_center);
	cercle->setRadius(_radius);
	return * cercle;
}

