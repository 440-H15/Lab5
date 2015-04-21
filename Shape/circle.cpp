#include "stdafx.h"

using namespace ShapeLibrary;

Circle::Circle(IWindowAPI  & _windowApi) : Shape(_windowApi){

}

Circle::~Circle(){

}

void Circle::setCenter(Point & _point){
	point.push_back(_point);
}

void Circle::setRadius(int _radius){
	if (_radius < 0) throw invalid_argument("The value should be positive");
	radius = _radius;
}

void Circle::draw(){
	if (point.empty()) throw runtime_error("There should be a starting point before drawing a circle");

	windowApi->setDrawingColor(Shape::getLineColor());
	windowApi->drawCircle(point[0], radius + 1);

	windowApi->setDrawingColor(Shape::getFillColor());
	windowApi->fillCircle(getPoint(0), radius);

}

void Circle::add(Point & _point){
	throw runtime_error("Point cant be added to a circle");
}