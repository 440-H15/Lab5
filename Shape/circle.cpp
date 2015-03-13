#include "stdafx.h"
#include "circle.h"

using namespace ShapeLibrary;

Circle::Circle(IWindowAPI& _windowAPI) :
radius(1)
{
}

Circle::~Circle()
{
}

void Circle::setCenter(Point _point)
{
}

void Circle::setRadius(int _radius)
{
	radius = _radius;
}

void Circle::draw()
{

}