#include "stdafx.h"

using namespace ShapeLibrary;

Shape::Shape(const IWindowAPI &_windowAPI)
{
	*this->windowAPI = _windowAPI;
}


Shape::~Shape()
{
	//delete windowAPI;
}


void Shape::add(const Point& _point)
{
	this->points.push_back(_point);
}


void Shape::draw()
{
	
}

void Shape::setLineColor(Color _color)
{
	this->lineColor = _color;
}


Color Shape::getLineColor() const
{
	return this->lineColor;
}


void Shape::setFillColor(Color _color)
{
	this->fillColor = _color;
}


Color Shape::getFillColor() const
{
	return this->fillColor;
}


Point Shape::getPoint(const unsigned int& _index) const
{
	if (_index < this->points.size())
	{
		return this->points[_index];
	}
	else
	{
		throw invalid_argument::exception("invalid parameter");
	}
}



int Shape::getNumberOfPoints() const
{
	return this->points.size();
}

