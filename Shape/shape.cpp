#include "stdafx.h"

using namespace ShapeLibrary;

Shape::Shape(){

}

Shape::~Shape(){

}

void Shape::add(Point & _point){
	point.push_back(_point);
}

//void Shape::setLineColor(){
//
//}
//
//Color Shape::getLineColor(){
//
//}
//
//void Shape::setFillColor(){
//
//}
//
//Color Shape::getFillColor(){
//
//}
//
//Point Shape::getPoint(int _index){
//
//}
//
//int Shape::getNumberOfPoints(){
//
//}