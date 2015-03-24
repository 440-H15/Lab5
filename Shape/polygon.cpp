#include "stdafx.h"
#include <algorithm>
#include "polygon.h"

using namespace ShapeLibrary;

Polygon::Polygon(IWindowAPI& _windowAPI)
{
	windowAPI = &_windowAPI;
	lineColor = Color::WHITE;
	fillColor = Color::INVISIBLE;
}

Polygon::~Polygon()
{
}

void Polygon::add(Point _point)
{
	if (isOnSameLine(_point)) throw runtime_error("Un point le peut pas être sur une ligne existente");
	if (isCrossingLine(_point)) throw runtime_error("Une ligne ne peut pas en traverser une autre");
	points.push_back(_point);
}

bool Polygon::isOnSameLine(Point _dernierPoint)
{
	if (points.size() >= 2)
	{
		double x1 = points[points.size() - 2].x, x2 = points[points.size() - 1].x, x3 = _dernierPoint.x;
		double y1 = points[points.size() - 2].y, y2 = points[points.size() - 1].y, y3 = _dernierPoint.y;

		double penteDerniereLigne = (y2 - y1) / (x2 - x1);
		double penteNouveauPoint = (y3 - y2) / (x3 - x2);

		double origineDerniereLigne = y1 - (penteDerniereLigne * x1);
		double origineNouveauPoint = y3 - (penteNouveauPoint * x3);

		return (penteDerniereLigne + origineDerniereLigne == penteNouveauPoint + origineNouveauPoint);
	}
	return false;
}

bool Polygon::isCrossingLine(Point _dernierPoint)
{
	if (points.size() >= 3)
	{
		double x1, x2, x3, x4 = _dernierPoint.x;
		double y1, y2, y3, y4 = _dernierPoint.y;

		for (int i = 0; i < points.size() - 2; i += 3)
		{
			x1 = points[i].x;
			y1 = points[i].y;
			x2 = points[i + 1].x;
			y2 = points[i + 1].y;
			x3 = points[i + 2].x;
			y3 = points[i + 2].y;

			double d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
			if (d == 0) return false;

			double x = ((x1*y2 - y1*x2) * (x3 - x4) - (x1 - x2) * (x3*y4 - y3*x4)) / d;
			double y = ((x1*y2 - y1*x2) * (y3 - y4) - (y1 - y2) * (x3*y4 - y3*x4)) / d;

			if (x < min(x1, x2) || x > max(x1, x2) || x < min(x3, x4) || x > max(x3, x4)) return false;
			if (y < min(y1, y2) || y > max(y1, y2) || y < min(y3, y4) || y > max(y3, y4)) return false;

			if ((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3) || (x3 == x4 && y3 == y4) || (x4 == x1 && y4 == y1)) return false;
		}
		return true;
	}
	return false;
}