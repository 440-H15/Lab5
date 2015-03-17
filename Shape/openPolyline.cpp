#include "stdafx.h"

using namespace ShapeLibrary;

OpenPolyline::OpenPolyline(IWindowAPI & _windowApi){
	windowApi = &_windowApi;
	windowApi->setDrawingColor(Color());
}

OpenPolyline::~OpenPolyline(){

}

void OpenPolyline::draw(){
	for (int i = 0; i < point.size(); i++){
		windowApi->drawLine(point[i], point[i + 1]);
	}
}