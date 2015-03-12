#include "stdafx.h"

using namespace ShapeLibrary;

Polygon::Polygon(IWindowAPI &_windowAPI) : ClosedPolyline(_windowAPI){}

void Polygon::add(const Point &_point)
{
	if (points.size() >= 2)
	{
		for (int index = points.size() - 2; index >= 0; index--)
		{
			Point line1[] {points.at(points.size() - 1), _point};
			Point line2[] {points.at(index), points.at(index + 1)};
			if (doLineCross(line1,line2))
				throw std::runtime_error("Point invalide");
		}
	}	
	points.push_back(_point);
}

void Polygon::draw()
{ 
	
}

bool Polygon::doLineCross(Point line1[], Point line2[])
{
	float pente1 = (line1[1].y - line1[0].y) / (line1[1].x - line1[0].x);
	float pente2 = (line2[1].y - line2[0].y) / (line2[1].x - line2[0].x);
	float origine1 = line1[0].y - (pente1 * line1[0].x);
	float origine2 = line2[0].y - (pente2 * line2[0].x);
	
	if (pente1 == pente2 && origine1 == origine2) return true;

	float commonPoint = (origine1 - origine2) / (pente2- pente1);

	int minX = 1000;
	int maxX = -1000;
	for (int index = 0; index < 2; index++)
	{
		if (maxX < line1[index].x) maxX = line1[index].x;
		if (maxX < line2[index].x) maxX = line2[index].x;
		if (minX > line1[index].x) minX = line1[index].x;
		if (minX > line2[index].x) minX = line2[index].x;
	}
	return (commonPoint > minX && commonPoint < maxX);
}