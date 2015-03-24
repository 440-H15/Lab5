#include "stdafx.h"
#include "shapeFactory.h"
using namespace ShapeLibrary;

ShapeFactory::ShapeFactory(IWindowAPI& _windowAPI)
{
	windowAPI = &_windowAPI;
}

Shape& ShapeFactory::createOpenPolyLine()
{
	Shape* openPolyLine = new OpenPolyline(*windowAPI);
	return *openPolyLine;
}

Shape& ShapeFactory::createCircle(Point _centerPoint, float _radius)
{
	Circle* circle = new Circle(*windowAPI);
	circle->setCenter(_centerPoint);
	circle->setRadius(_radius);
	return *circle;
}

Shape& ShapeFactory::createRectangle(Point _centerPoint, float _width, float _height)
{
	Rectangle* rectangle = new Rectangle(*windowAPI);
	rectangle->setHeight(_height);
	rectangle->setWidth(_width);
	rectangle->setPosition(_centerPoint);
	return *rectangle;
}

Shape& ShapeFactory::createClosedPolyLine()
{
	Shape* closedPolyLine = new ClosedPolyline(*windowAPI);
	return *closedPolyLine;
}

Shape& ShapeFactory::createPolygone()
{
	Polygon* polygon = new Polygon(*windowAPI);
	return *polygon;
}