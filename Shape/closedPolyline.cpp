#include "stdafx.h"

using namespace ShapeLibrary;

ClosedPolyline::ClosedPolyline(IWindowAPI & _windowApi) : OpenPolyline(_windowApi)
{
	windowApi = &_windowApi;
}

ClosedPolyline::~ClosedPolyline(){

}

void ClosedPolyline::draw(){
	if (point.size() < 3) throw runtime_error("La forme doit avoir aumoins 3 points");
	int lastIndex = point.size() - 1;
	windowApi->setDrawingColor(Color());

	for (int i = 0; i < point.size() - 1; i++){
		windowApi->drawLine(point[i], point[i + 1]);
	}

	windowApi->drawLine(point[lastIndex], point[0]);
}