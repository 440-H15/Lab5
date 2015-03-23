#include "stdafx.h"
#include "shapeFactory.h"

using namespace ShapeLibrary;


ShapeFactory::ShapeFactory(IWindowAPI& _windowAPI)
{
	windowAPI = &_windowAPI;
}

ShapeFactory::~ShapeFactory()
{
}

Shape& ShapeFactory::createOpenPolyLine()
{
	Shape* openPolyLine = new OpenPolyline(*windowAPI);
	return *openPolyLine;
}

Shape& ShapeFactory::createCircle(Point _point, int _rayon)
{
	Circle* circle = new Circle(*windowAPI);
	circle->setCenter(_point);
	circle->setRadius(_rayon);
	return *circle;
}

Shape& ShapeFactory::createRectangle(Point _point, int _height, int _width)
{
	Rectangle* rectangle = new Rectangle(*windowAPI);
	rectangle->setPosition(_point);
	rectangle->setHeight(_height);
	rectangle->setWidth(_width);
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