#include "stdafx.h"

using namespace ShapeLibrary;

ShapeFactory::ShapeFactory(IWindowAPI & _windowApi){
	windowApi = &_windowApi;
}
ShapeFactory::~ShapeFactory(){

}

Shape & ShapeFactory::createOpenPolyLine() const{
	OpenPolyline * openPolyLine = new OpenPolyline(*windowApi);
	return *openPolyLine;
}

Shape & ShapeFactory::createClosedPolyLine() const{
	ClosedPolyline * closedPolyline = new ClosedPolyline(*windowApi);
	return *closedPolyline;
}

Shape & ShapeFactory::createPolygone() const{
	Polygon * polygon = new Polygon(*windowApi);
	return *polygon;
}


Shape & ShapeFactory::createRectangle(Point &_point, int _height, int _width) const{
	Rectangle * rectangle = new Rectangle(*windowApi);
	rectangle->setPosition(_point);
	rectangle->setHeight(_height);
	rectangle->setWidth(_width);
	rectangle->setFillColor(Color::BLUE);

	return *rectangle;
}

Shape & ShapeFactory::createCircle(Point &_point, int _radius) const{

	Circle * circle = new Circle(*windowApi);
	circle->setFillColor(Color::RED);
	circle->setCenter(_point);
	circle->setRadius(_radius);

	return *circle;
}
