#include "stdafx.h"
#include "closedPolyline.h"
using namespace ShapeLibrary;

ClosedPolyline::ClosedPolyline()
{

}

ClosedPolyline::ClosedPolyline(IWindowAPI& _windowAPI)
{
	nbPoint = 0;
	windowAPI = &_windowAPI;
}


void ClosedPolyline::draw()
{
	if (nbPoint < 3) throw runtime_error("Il doit y avoir au minimum 3 points");
	this->windowAPI->setDrawingColor(lineColor);
	vector<Point>::iterator it;
	for (it = point.begin(); it < (point.end() - 1); it)
	{
		this->windowAPI->drawLine(*it, *(it++));
	}

	this->windowAPI->drawLine(*(it = point.begin()), *(it = (point.end() - 1)));
}