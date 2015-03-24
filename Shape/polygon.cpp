#include "stdafx.h"

using namespace ShapeLibrary;

Polygon::Polygon(IWindowAPI &_windowAPI) : ClosedPolyline(_windowAPI){}

void Polygon::add(const Point &_point)
{
	if (points.size() >= 2)
	{
		Point line2[] {points.at(points.size() - 1), _point};
		for (int index = points.size() - 2; index >= 0; index--)
		{
			Point line1[] {points.at(index), points.at(index + 1)};
			if (doLineCross(line1,line2))
				throw std::runtime_error("Point invalide");
		}
	}	
	points.push_back(_point);
}

bool Polygon::doLineCross(Point line1[], Point line2[])
{
	float pente1 = (line1[1].y - line1[0].y) / (line1[1].x - line1[0].x);
	float pente2 = (line2[1].y - line2[0].y) / (line2[1].x - line2[0].x);
	float origine1 = line1[0].y - (pente1 * line1[0].x);
	float origine2 = line2[0].y - (pente2 * line2[0].x);

	if (pente1 == pente2 && origine1 == origine2) return true;

	float commonX = 0;
	float commonY = 0;
	
	if (line1[1].x == line1[0].x)
	{
		commonX = line1[0].x;
		commonY = commonX * pente2 + origine2;
	}
	else if (line2[1].x == line2[0].x)
	{
		commonX = line2[0].x;
		commonY = commonX * pente1 + origine1;
	}
	else
	{
		commonX = (origine1 - origine2) / (pente2 - pente1); 
		commonY = commonX * pente2 + origine2;
	}
	
	commonX = roundf(commonX * 10) / 10;
	commonY = roundf(commonY * 10) / 10;
	
	bool inXRange = (commonX >= min(line2[0].x, line2[1].x) && commonX <= max(line2[0].x, line2[1].x));
	bool inYRange = (commonY >= min(line2[0].y, line2[1].y) && commonY <= max(line2[0].y, line2[1].y));

	return (inXRange && inYRange && line2[0] != line1[1]);
}

float Polygon::min(float value1, float value2)
{
	return (value1 < value2) ? value1 : value2;
}

float Polygon::max(float value1, float value2)
{
	return (value1 > value2) ? value1 : value2;
}