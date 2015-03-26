#include "stdafx.h"

using namespace ShapeLibrary;

OpenPolyline::OpenPolyline(IWindowAPI & _windowApi) : Shape(_windowApi){

}

OpenPolyline::~OpenPolyline(){

}

void OpenPolyline::draw(){
	if (point.size() < 2) throw runtime_error("La forme doit avoir aumoins 2 points");
	windowApi->setDrawingColor(Shape::getLineColor());
	for (int i = 0; i < point.size() - 1; i++){
		windowApi->drawLine(point[i], point[i + 1]);
	}
}