#include "stdafx.h"
#include <algorithm>
using namespace ShapeLibrary;

Polygon::Polygon(IWindowAPI& _fakeWindowAPI)
{
	windowAPI = &_fakeWindowAPI;
	nbPoint = 0;
}

void Polygon::add(Point _point)
{
	bool lineNotOnOtherLine = true;
	point.push_back(_point);
	nbPoint++;
	if (nbPoint > 2)//besoin au minimum de 2 ligne
	{
		vector<Point>::iterator it;
		Point lastPoint = *point.begin();
		for (it = point.begin(); it <= (point.end() - 2); it++)
		{
			if (it == (point.end() - 2))
			{
				lastPoint = *point.begin();
			}
			else
			{
				lastPoint = *(it + 2);
			}
			lineNotOnOtherLine = checkLineOnOtherLine(*it, *(it + 1), *(it + 1), lastPoint);
			if (lineNotOnOtherLine)
			{
				point.pop_back();
				nbPoint--;
				throw runtime_error("Deux lignes d'un polygone ne peuvent pas être empilées");
			}
		}
	}
}

void Polygon::draw()
{
	if (nbPoint < 3) throw runtime_error("Il doit y avoir au minimum 3 points");
	this->windowAPI->setDrawingColor(Color::BLUE);
	vector<Point>::iterator it;
	for (it = point.begin(); it < (point.end() - 1); it)
	{
		checkLineOnOtherLine(*it, *(it + 1), *(it + 1), *(it + 2));
		this->windowAPI->drawLine(*it, *(it++));
	}

	this->windowAPI->drawLine(*(it = point.begin()), *(it = (point.end() - 1)));
}

bool Polygon::checkLineOnOtherLine(const Point & point1, const Point & point2, const Point & point3, const Point & point4)
{
	double x1 = point1.x, x2 = point2.x, x3 = point3.x, x4 = point4.x;
	double y1 = point1.y, y2 = point2.y, y3 = point3.y, y4 = point4.y;

	if ((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3) || (x3 == x4 && y3 == y4) || (x4 == x1 && y4 == y1)) return true;
	if (((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)) == 0) return true;
	return false;
}

//bool Polygon::checkIfIntersection(const Point & point1, const Point & point2, const Point & point3, const Point & point4){
//	double x1 = point1.x, x2 = point2.x, x3 = point3.x, x4 = point4.x;
//	double y1 = point1.y, y2 = point2.y, y3 = point3.y, y4 = point4.y;
//
//	double d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
//	if (d == 0) return false; 
//
//	// Get the x and y
//	double pre = (x1*y2 - y1*x2), post = (x3*y4 - y3*x4);
//	double x = (pre * (x3 - x4) - (x1 - x2) * post) / d;
//	double y = (pre * (y3 - y4) - (y1 - y2) * post) / d;
//
//	// Check if the x and y coordinates are within both lines
//	if (x < min(x1, x2) || x > max(x1, x2) ||
//		x < min(x3, x4) || x > max(x3, x4)) return false;
//	if (y < min(y1, y2) || y > max(y1, y2) ||
//		y < min(y3, y4) || y > max(y3, y4)) return false;
//
//	if ((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3) || (x3 == x4 && y3 == y4) || (x4 == x1 && y4 == y1)) return false;
//
//	return true;
//}