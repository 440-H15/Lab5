#include "stdafx.h"

using namespace ShapeLibrary;

Polygon::Polygon(IWindowAPI& _windowApi): ClosedPolyline(_windowApi)
{
}

Polygon::~Polygon()
{
	
}

void Polygon::add(Point& _point)
{
	if (points.size() >= 2 && isOnPreviousLine(points.at(points.size() - 2), _point, points.back()))
			throw runtime_error("Deux points sur la m�me ligne!");

	ClosedPolyline::add(_point);
	
}

bool Polygon::isOnPreviousLine(const Point& _previousPoint, const Point& _currentPoint, const Point& _nextPoint) const
{
	/****************************************************************************
	Prenons la droite suivante:

	      /C    o�:
	     /      A = _previousPoint
	   B/       B = _currentPoint
	   /        C = _nextPoint
	A /

	1) Regardons si la droite qui passe par AC est parall�le � la
	   droite qui passe par BC.
	
	D'abords, on regarde si la pente de A � C est la m�me que celle de B � C :
	    (C.x - A.x)   (C.x - B.x)
		----------- = -----------
		(C.y - A.y)   (C.y - B.y)

	Afin d'�viter les nombres d�cimaux (on ne veut pas de perte de pr�cision), 
	on regarde si le produit des extr�mes est �gale au produit des moyens:
	    (C.x - A.x) * (C.y - B.y) = (C.x - B.x) * (C.y - A.y)

	Si c'est �gale, la droite qui passe par AC est parall�le � la
	droite qui passe par BC.
	***************************************************************************/

	bool droiteEstParallele = (_nextPoint.x - _previousPoint.x) * (_nextPoint.y - _currentPoint.y) == (_nextPoint.y - _previousPoint.y) * (_nextPoint.x - _currentPoint.x);

	/**************************************************************************** 
	2) V�rifions ensuite si le point se situe sur le m�me segment.
	   (car contrairement � une droite, un segment n'est pas infinie.
	   Un segment est d�limit� par 2 points).

	   Pour faire �a, on v�rifie si les les valeurs de x et y se situe entre les
	   valeurs de x et y des 2 points qui l'entoure.
	****************************************************************************/

	bool pointEstSurSegment = false;
	if (droiteEstParallele)
	{
		pointEstSurSegment = isBetween(_previousPoint.x, _currentPoint.x, _nextPoint.x) &&
			isBetween(_previousPoint.y, _currentPoint.y, _nextPoint.y);
	}

	// Si les 2 conditions sont respect�es, le point est sur le m�me segment.
	return droiteEstParallele && pointEstSurSegment;
}

bool Polygon::isBetween(const double& _a, const double& _b, const double& _c) const
{
	//On v�rifie de deux mani�res, afin de g�rer les nombres n�gatifs. 
	return _a <= _b && _b <= _c || _c <= _b && _b <= _a;
}