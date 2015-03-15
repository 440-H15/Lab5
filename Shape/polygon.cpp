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
	if (points.size() >= 2 && isOnPreviousLine(_point))
			throw runtime_error("Deux points sur la m�me ligne!");

	ClosedPolyline::add(_point);	
}

bool Polygon::isOnPreviousLine(const Point& _point) const
{
	Point prevPoint = points.at(points.size() - 2);
	Point nextPoint = points.back();

	/****************************************************************************
	Prenons la droite suivante:

	      /C    o�:
	     /      A = prevPoint
	   B/       B = _point
	   /        C = nextPoint
	A /

	1) Regardons si le point B se situe sur la droite qui passe par AC
	
	D'abords, on regarde si la pente de A � C est la m�me que celle de B � C :
	    (C.x - A.x)   (C.x - B.x)
	    ----------- = -----------
	    (C.y - A.y)   (C.y - B.y)

	Afin d'�viter les nombres d�cimaux (on ne veut pas de perte de pr�cision), 
	on regarde si le produit des extr�mes est �gale au produit des moyens:
	    (C.x - A.x) * (C.y - B.y) = (C.x - B.x) * (C.y - A.y)

	Si c'est �gale, les points A ,B et C sont tous sur la m�me droite
	(Donc AC et BC sont parall�les).
	***************************************************************************/

	bool pointEstSurDroite = isColineaire(prevPoint, _point, nextPoint);

	/**************************************************************************** 
	2) V�rifions ensuite si le point se situe sur le m�me segment.
	   (car contrairement � une droite, un segment n'est pas infinie.
	   Un segment est d�limit� par 2 points).

	   Pour faire �a, on v�rifie si les les valeurs de x et y se situe entre les
	   valeurs de x et y des 2 points qui l'entoure.
	****************************************************************************/

	bool pointEstSurSegment = false;
	if (pointEstSurDroite)
	{
		pointEstSurSegment = isBetween(prevPoint.x, _point.x, nextPoint.x) &&
			isBetween(prevPoint.y, _point.y, nextPoint.y);
	}

	// Si les 2 conditions sont respect�es, le point est sur le m�me segment.
	return pointEstSurDroite && pointEstSurSegment;
}

bool Polygon::isColineaire(const Point& _previousPoint, const Point& _currentPoint, const Point& _nextPoint) const
{
	// Retourne vrai si les trois points sont sur la m�me droite
	return (_nextPoint.x - _previousPoint.x) * (_nextPoint.y - _currentPoint.y) == (_nextPoint.y - _previousPoint.y) * (_nextPoint.x - _currentPoint.x);
}

bool Polygon::isBetween(const double& _a, const double& _b, const double& _c) const
{
	// On v�rifie de deux mani�res, afin de g�rer les nombres n�gatifs.
	// Retourne vrai si _b se situe entre _a et _c
	return _a <= _b && _b <= _c || _c <= _b && _b <= _a;
}