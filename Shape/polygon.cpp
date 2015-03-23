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
	point.push_back(_point);
	nbPoint++;
	if (nbPoint > 2)//besoin au minimum de 2 ligne
	{

		if (!executeCheckLineOnOtherLine())
		{
			point.pop_back();
			nbPoint--;
			throw runtime_error("Deux lignes d'un polygone ne peuvent pas être empilées ou se croiser");
		}

		if (nbPoint > 3)
		{
			if (!executeCheckLineCross())
			{
				point.pop_back();
				nbPoint--;
				throw runtime_error("Deux lignes d'un polygone ne peuvent pas être empilées ou se croiser");
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
		this->windowAPI->drawLine(*it, *(it++));
	}

	this->windowAPI->drawLine(*(it = point.begin()), *(it = (point.end() - 1)));
}

bool Polygon::checkLineOnOtherLine(const Point & point1, const Point & point2, const Point & point3, const Point & point4)
{
	double x1 = point1.x, x2 = point2.x, x3 = point3.x, x4 = point4.x;
	double y1 = point1.y, y2 = point2.y, y3 = point3.y, y4 = point4.y;

	if ((x1 == x2 && y1 == y2) || (x3 == x4 && y3 == y4) || (x4 == x1 && y4 == y1)) return false;
	if (((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)) == 0) return true;
	return false;
}

bool Polygon::checkLineCrossOtherLine(const Point & point1, const Point & point2, const Point & point3, const Point & point4)
{
	double x1 = point1.x, x2 = point2.x, x3 = point3.x, x4 = point4.x;
	double y1 = point1.y, y2 = point2.y, y3 = point3.y, y4 = point4.y;

	double d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	if (d == 0) return false;

	double slope1 = 0, slope2 = 0, b1 = 0, b2 = 0;
	double xOfIntersection = NULL;
	double yOfIntersection = NULL;

	if (y2 == y1){ // droite horizontale
		yOfIntersection = y1;
		slope1 = NULL;
		b1 = y1;
	}
	else if (x2 == x1){ // droite verticale 
		xOfIntersection = x1;
		slope1 = NULL;
		b1 = 0;
	}
	else{
		slope1 = (y2 - y1) / (x2 - x1);
		b1 = y2 - (slope1 * x2);
	}

	if (y4 == y3){ // droite horizontale
		yOfIntersection = y3;
		slope2 = NULL;
		b2 = y3;
	}
	else if (x4 == x3){ // droite verticale 
		xOfIntersection = x3;
		slope2 = NULL;
		b2 = 0;
	}
	else{
		slope2 = (y4 - y3) / (x4 - x3);
		b2 = y4 - (slope2 * x4);
	}

	if (xOfIntersection == NULL || yOfIntersection == NULL)
	{
		if (xOfIntersection == NULL)
		{
			xOfIntersection = (b2 - b1) / (slope1 - slope2);
		}
		if (yOfIntersection == NULL)
		{
			double slopeFindY = 0;
			double bFindY = 0;
			if (slope1 == NULL) slopeFindY = slope2, bFindY = b2;
			else slopeFindY = slope1, bFindY = b1;
			yOfIntersection = (slopeFindY * xOfIntersection) + bFindY;
		}
	}

	if ((slope1 - slope2) == 0){ //vérifie si les droites sont parallèles
		return false;
	}
	if ((x1 == x2 && y1 == y2) || (x3 == x4 && y3 == y4) || (x4 == x1 && y4 == y1)) return false; // vérifie si deux points ne sont pas identiques

	if ((x2 == xOfIntersection) && (xOfIntersection == x3) && (y2 == yOfIntersection) && (yOfIntersection == y3)) return false;

	if ((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3) || (x3 == x4 && y3 == y4) || (x4 == x1 && y4 == y1)) return false;

	if ((xOfIntersection >= max(x1, x2) || xOfIntersection <= min(x2, x1)) && (xOfIntersection >= max(x3, x4) || xOfIntersection <= min(x4, x3))){
		if ((yOfIntersection >= max(y1, y2) || yOfIntersection <= min(y2, y1)) && (yOfIntersection >= max(y3, y4) || yOfIntersection <= min(y4, y3))){
			return false;
		}
	}
	return true;
}

bool Polygon::executeCheckLineCross()
{
	vector<Point>::iterator it;
	bool cross = true;
	Point lastPoint = *point.begin();
	Point penultimatePoint = *(point.begin() + 1);
	for (it = point.begin(); it <= (point.end() - 4); it++)
	{
		for (int i = 2; i < nbPoint - 1; i++)
		{
			if (checkLineCrossOtherLine(*it, *(it + 1), *(it + i), *(it + i + 1))) return false;
		}
	}
	return true;
}

bool Polygon::executeCheckLineOnOtherLine()
{
	vector<Point>::iterator it;
	Point lastPoint = *point.begin();
	Point penultimatePoint = *(point.begin() + 1);
	for (it = point.begin(); it <= (point.end() - 3); it++)
	{
		penultimatePoint = *(it + 1);
		lastPoint = *(it + 2);
		if (checkLineOnOtherLine(*it, penultimatePoint, penultimatePoint, lastPoint)) return false;

	}
	return true;
}