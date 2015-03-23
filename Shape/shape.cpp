#include "stdafx.h"

using namespace ShapeLibrary;

void Shape::add(Point _point)
{

}

void Shape::draw()
{

}

Point Shape::getPoint(const int& _index)
{
	return *(this->point.begin() + _index);
}