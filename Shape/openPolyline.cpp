#include "stdafx.h"
#include "openPolyline.h"
using namespace ShapeLibrary;
OpenPolyline::OpenPolyline()
{

}

OpenPolyline::OpenPolyline(IWindowAPI& _windowAPI)
{
	windowAPI = &_windowAPI;
	lineColor = Color::WHITE;
	fillColor = Color::INVISIBLE;
}


void OpenPolyline::draw() //Pas sur que toute marche comme il faut
{
	if (this->nbPoint < 2) throw runtime_error("Il doit y avoir au minimum 2 points");
	this->windowAPI->setDrawingColor(lineColor);
	vector<Point>::iterator it;
	for (it = point.begin(); it < (point.end() - 1); it)
	{
		this->windowAPI->drawLine(*it, *(it++));
	}
}