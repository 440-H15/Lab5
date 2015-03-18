#include "stdafx.h"

using namespace ShapeLibrary;

Circle::Circle(IWindowAPI  & _windowApi){
	windowApi = &_windowApi;
}

Circle::~Circle(){

}

void Circle::setCenter(Point & _point){
	point.push_back(_point);
}

void Circle::setRadius(int _radius){
	radius = _radius;
}

void Circle::draw(){
	windowApi->setDrawingColor(Color());
	windowApi->drawCircle(point[0], radius);
}