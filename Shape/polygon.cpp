#include "stdafx.h"
#include <algorithm>

using namespace ShapeLibrary;

Polygon::Polygon(IWindowAPI & _windowApi) : ClosedPolyline(_windowApi){

}


Polygon::~Polygon(){

}


void Polygon::draw(){
	windowApi->setDrawingColor(Color());

	int lastIndexOfPoint = point.size() - 1;
	for (int i = 0; i < point.size(); i++){
		if (i != lastIndexOfPoint){
			windowApi->drawLine(point[i], point[i + 1]);
		}
		else{
			windowApi->drawLine(point[lastIndexOfPoint], point[0]);
		}
	}

}

void Polygon::add(Point & _point){
	int lastIndexOfVector = point.size() - 1;

	if (point.size() < 2){
		point.push_back(_point);
	}
	else if (point.size() == 2){
		if (checkIfPointIsOnSameLine(point[0], point[1], _point)){
			throw runtime_error("There should not be a point on a line");
		}
		point.push_back(_point);
	}
	else if (point.size() > 2){
		if (checkIfPointIsOnSameLine(point[lastIndexOfVector - 1], point[lastIndexOfVector], _point)) throw runtime_error("There should not be a point on a line");
		for (int i = 0; i < lastIndexOfVector - 1; i++){ //il est certain que les deux derniers ont une intersection
			if (checkIfIntersection(point[i], point[i + 1], point[lastIndexOfVector], _point)) throw runtime_error("A polygon should not contain an intersection");
		}
		point.push_back(_point);
	}
}
bool Polygon::checkIfPointIsOnSameLine(const Point & _point1, const Point & _point2, const Point & _point3) const{
	double x1 = _point1.x, x2 = _point2.x, x3 = _point3.x;
	double y1 = _point1.y, y2 = _point2.y, y3 = _point3.y;

	double variation = (y2 - y1) / (x2 - x1);
	double b = y1 - (variation * x1);


	if (y3 == (variation * x3) + b){
		return true;
	}
	else{
		return false;
	}

}

bool Polygon::checkIfIntersection(const Point & _point1, const Point & _point2, const Point & _point3, const Point & _point4) const{
	double x1 = _point1.x, x2 = _point2.x, x3 = _point3.x, x4 = _point4.x;
	double y1 = _point1.y, y2 = _point2.y, y3 = _point3.y, y4 = _point4.y;

	double d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	if (d == 0) return false;

	// Get the x and y
	double pre = (x1*y2 - y1*x2), post = (x3*y4 - y3*x4);
	double x = (pre * (x3 - x4) - (x1 - x2) * post) / d;
	double y = (pre * (y3 - y4) - (y1 - y2) * post) / d;

	// Check if the x and y coordinates are within both lines
	if (x < min(x1, x2) || x > max(x1, x2) ||
		x < min(x3, x4) || x > max(x3, x4)) return false;
	if (y < min(y1, y2) || y > max(y1, y2) ||
		y < min(y3, y4) || y > max(y3, y4)) return false;

	if ((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3) || (x3 == x4 && y3 == y4) || (x4 == x1 && y4 == y1)) return false;

	return true;
}
