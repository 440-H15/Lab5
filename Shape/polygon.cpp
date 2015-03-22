#include "stdafx.h"
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
	//if (isCrossingLine(_point)) throw runtime_error("Une ligne ne peut pas en traverser une autre");
	points.push_back(_point);
}

bool Polygon::isOnSameLine(Point _dernierPoint)
{
	if (points.size() >= 2){
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

	return true;
}