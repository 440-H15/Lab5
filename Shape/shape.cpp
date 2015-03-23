#include "stdafx.h"

using namespace ShapeLibrary;

Shape::Shape(IWindowAPI & _windowApi){
	windowApi = &_windowApi;
	fillColor = Color();
}

Shape::~Shape(){

}

void Shape::add(Point & _point){
	point.push_back(_point);
}

void Shape::setLineColor(Color _color){
	lineColor = _color;
}

Color Shape::getLineColor() const{
	return lineColor;
}


void Shape::setFillColor(Color _color){
	fillColor = _color;
}


Color Shape::getFillColor() const {
	return fillColor;
}

Point Shape::getPoint(int _index) const{
	return point[_index];
}

int Shape::getNumberOfPoints() const{
	return point.size();
}

bool Shape::operator==(const Shape &_source) const{

	if (&_source == this){
		return true;
	}
	else{
		return false;
	}
}