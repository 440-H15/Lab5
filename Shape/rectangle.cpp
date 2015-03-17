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
	height = _height;
}

void Rectangle::setWidth(int _width){
	width = _width;
}

void Rectangle::draw(){
	windowApi->setDrawingColor(Color());
	windowApi->drawRectangle(point[0], width, height);
}