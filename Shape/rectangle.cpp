#include "stdafx.h"

using namespace ShapeLibrary;

Rectangle::Rectangle(IWindowAPI & _windowApi) : Shape(_windowApi){

}

Rectangle::~Rectangle(){

}

void Rectangle::setPosition(Point & _point){
	if (point.size() > 0) throw runtime_error("La position est déjà choisie");
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


void Rectangle::draw(){
	if (point.empty()) throw runtime_error("Starting positin should be set before drawing");

	windowApi->setDrawingColor(Shape::getLineColor());
	windowApi->drawRectangle(point[0], width, height);

	windowApi->setDrawingColor(Shape::getFillColor());
	windowApi->fillRectangle(point[0], width - 1, height -     1);

}

void Rectangle::add(Point & _point){
	throw runtime_error("Point cant be added to ca rectangle, this method cant be called");
}