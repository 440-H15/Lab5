#include "stdafx.h"

using namespace ShapeLibrary;

Shape::Shape(IWindowAPI & _windowApi){
	windowApi = &_windowApi;
}

Shape::~Shape(){

}

void Shape::add(Point & _point){
	point.push_back(_point);
}

void Shape::setLineColor(Color _color){
	lineColor = _color;
}

//Color Shape::getLineColor(){
//
//}
//

void Shape::setFillColor(Color _color){
	fillColor = _color;
}

//
//Color Shape::getFillColor(){
//
//}
//
Point Shape::getPoint(int _index){
	return point[_index];
}
//
//int Shape::getNumberOfPoints(){
//
//}