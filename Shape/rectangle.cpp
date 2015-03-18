#include "stdafx.h"

using namespace ShapeLibrary;

Rectangle::Rectangle(IWindowAPI & _windowApi){
	windowApi = &_windowApi;
}

Rectangle::~Rectangle(){

}

void Rectangle::setPosition(Point & _point){
	point.push_back(_point);
}

void Rectangle::setHeight(int _height){
	if (_height < 0) throw invalid_argument("Height must be a positive value");
	height = _height;
}

void Rectangle::setWidth(int _width){
	if (_width < 0) throw invalid_argument("Width must be a positive value");
	width = _width;
}

void Rectangle::setFillColor(Color _color){
	windowApi->fillRectangle(point[0], width, height);
}

void Rectangle::draw(){
	if (point.empty()) throw runtime_error("Starting positin should be set before drawing");
	windowApi->setDrawingColor(Color());
	windowApi->drawRectangle(point[0], width, height);
}

void Rectangle::add(Point & _point){
	throw runtime_error("Point cant be added to ca rectangle, this method cant be called");
}