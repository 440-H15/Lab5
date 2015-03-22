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
	if (isCrossingLine(_point)) throw runtime_error("Une ligne ne peut pas en traverser une autre");
	points.push_back(_point);
}

bool Polygon::isOnSameLine(Point _dernierPoint)
{
	if (points.size() >= 2){
		int penteDerniereLigne = (points[points.size() - 1].y - points[points.size() - 2].y) / (points[points.size() - 1].x - points[points.size() - 2].x);
		int penteNouveauPoint = (_dernierPoint.y - points[points.size() - 1].y) / (_dernierPoint.x - points[points.size() - 1].x);
		
		int b = (penteDerniereLigne * _dernierPoint.x) / _dernierPoint.y;
		int bNouveauPoint = (penteNouveauPoint * _dernierPoint.x) / _dernierPoint.y;

		return (penteDerniereLigne == penteNouveauPoint) && (b == bNouveauPoint);
	}
	return false;
}

bool Polygon::isCrossingLine(Point _dernierPoint)
{

	return false;
}