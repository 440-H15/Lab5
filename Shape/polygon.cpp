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
	if (points.size() >= 2)
	{
		if (isOnPreviousLine(_point))
			throw runtime_error("Deux points sur la m�me ligne!");

		if (crossesPreviousLines(_point))
			throw runtime_error("Un segment du polygone en croise un autre!");
	}

	ClosedPolyline::add(_point);
}

bool Polygon::isOnPreviousLine(const Point& _point) const
{
	if (points.size() < 2) throw runtime_error("Ligne pr�c�dente inexistante");

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

	/*
	Rappel d�finition colin�aire (de Antidote V8):
		Qui a la m�me direction et est situ� sur la m�me droite.
	*/
	bool pointEstSurDroite = isColineaire(prevPoint, _point, nextPoint);

	/**************************************************************************** 
	2) V�rifions ensuite si le point se situe sur le m�me segment.
	   (car contrairement � une droite, un segment n'est pas infini.
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

bool Polygon::crossesPreviousLines(const Point& _point) const
{
	/*
	 Le segment CD est le segment � en devenir du polygone si aucun segment se croise.
	 On va tester ce segment contre tous les autres segments du polygone afin de 
	 d�terminer si il croise au moins un segment de celui-ci;
	*/

	Point C = points.back();
	Point D = _point;

	for (auto it = points.begin(); next(it) < points.end(); ++it)
	{
		// On regarde si le segment CD croise un des segments AB du polygone.
		Point A = *it;
		Point B = *next(it);

		if (intersectsSegment(A, B, C, D))
			return true;
	}


	return false;
}

bool Polygon::isColineaire(const Point& _previousPoint, const Point& _currentPoint, const Point& _nextPoint) const
{
	// Retourne vrai si les trois points sont sur la m�me droite
	double resultat1 = (_nextPoint.x - _previousPoint.x) * (_nextPoint.y - _currentPoint.y);
	double resultat2 = (_nextPoint.y - _previousPoint.y) * (_nextPoint.x - _currentPoint.x);

	/* 
	Puisqu'on utilise des doubles, on doit faire attention lorsqu'on fait des comparaisons.
	Voir les commenaitaires de la m�thode areNearlyEqual.
	*/

	return areNearlyEqual(resultat1, resultat2);
}

bool Polygon::intersectsSegment(const Point& _A, const Point& _B, const Point& _C, const Point& _D) const
{
	/****************************************************************************
	
	On a le segment AB, et le segment CD. On veut savoir s'ils se croisent.

	Comment?

	La th�orie en question provient d'un professeur en Computer Science de
	la prestigieuse universit� Berkeley: https://www.cs.cmu.edu/~quake/robust.html

	Je vais essayer d'expliquer la th�orie de ce professeur (car la page est un peu
	vide...).

	-----
	
	On a 4 matrices de points:

	1)				2)				3)				4)
	Ax Ay | 1		Ax Ay | 1		Ax Ay | 1		Bx By | 1
	Bx By | 1		Bx By | 1		Cx Cy | 1		Cx By | 1
	Cx Cy | 1		Dx Dy | 1		Dx Dy | 1		Dx Dy | 1

	(On est techniquement en 3 dimensions, on ajoute une rang�e de '1'
	afin qu'on puisse faire les calculs qui vont suivre. �a donne un volume,
	mais ce volume est l'�quivalent de son p�rim�tre en 2D, car '1' n'affecte pas
	le r�sultat). Je crois...

	Il y a 4 matrices, car je compare chaque point d'un segment avec
	les deux points d'un autre segment, soit:
	    - Le point C avec le segment AB
		- Le point D avec le segment AB
		- Le point A avec le segment CD
		- Le point B avec le segment CD

	On calcule ensuite le d�terminant de chaque matrice :

		  Det1                  Det2
	1)    | Ax-Cx  Bx-Cx |      | Ax-Dx  Bx-Dx |
		  | Ay-Cy  By-Cy |  vs  | Ay-Dy  By-Dy |

		  Det3                  Det4
	2)    | Cx-Ax  Dx-Ax |      | Cx-Bx  Dx-Bx |
		  | Cy-Ay  Dy-Ay |  vs  | Cy-By  Dy-By |
		  
	Pourquoi? On veut d�terminer si un point est � gauche ou � droite
	d'un segment. Pour �a il faut savoir son orientation face au segment/vecteur
	en question (est-il � gauche ou � droite du segment ou sur le segment).
	Le signe du d�terminant d�termine l'orientation du volume r�sultant.
	
	On comprend mieux avec un sch�ma :
	
		   C
		   |
		   |
	A--------------B
		   |
		   |
		   D

	Je regarde si le point A se situe � gauche ou � droite du point C et D.
	Je regarde ensuite si le point B se situe � gauche ou � droite du point 
	C et D.

	-  Si un point est � gauche d'un segment, le d�terminant de la matrice sera > 0
	-  Si un point est � droite d'un segment, le d�terminant de la matrice sera < 0
	-  Si un point est sur le segment, le d�terminant de la matrice sera 0 ***
	   
	   *** Je ne v�rifie pas cette condition dans cette fonction. Je m'en occupe d�j� avec
	   ma fonction isColineaire (qui est appel�e avant intersectsSegment avant l'ajout
	   d'un point au polygone, et qui v�rifie justement que le point ajout� ne se situe pas
	   sur la ligne pr�c�dente. Elle est aussi moins couteuse.).

	Pour que le segment CD croise le segment AB, un des 4 sc�narios suivants
	doit �tre vrai:
		1) A est gauche du point C, et B est � droite du point C.
		    -> ( det1  et -det2 )  et ( det3  et -det4 ) 
		2) A est � droite du point C, et B est gauche du point C.
		    -> (-det1  et  det2 )  et ( det3  et -det4 )
		3) B est � gauche du point D, et A est � droite du point D.
		    -> ( det3  et -det4 )  et ( det1  et -det2 )
		4) B est � droite du point D, et A est � gauche du point D.
		    ->  (-det3  et  det4 ) et ( det1  et -det2 )

	Si aucun sc�nario correspond au r�sultat, la droite CD ne croise pas
	la droite AB.

	****************************************************************************/


	// Calcul des d�terminants
	double det1 = (_A.x - _C.x) * (_B.y - _C.y) - (_B.x - _C.x) * (_A.y - _C.y);
	double det2 = (_A.x - _D.x) * (_B.y - _D.y) - (_B.x - _D.x) * (_A.y - _D.y);

	double det3 = (_C.x - _A.x) * (_D.y - _A.y) - (_D.x - _A.x) * (_C.y - _A.y);
	double det4 = (_C.x - _B.x) * (_D.y - _B.y) - (_D.x - _B.x) * (_C.y - _B.y);

	// Comparaison avec les 4 sc�narios 
	if ((det1 > 0 && det2 < 0) && (det3 > 0 && det4 < 0))
	{
		return true;
	}

	if ((det1 < 0 && det2 > 0) && (det3 < 0 && det4 > 0))
	{
		return true;
	}

	if ((det1 > 0 && det2 < 0) && (det3 < 0 && det4 > 0))
	{
		return true;
	}

	if ((det1 < 0 && det2 > 0) && (det3 > 0 && det4 < 0))
	{
		return true;
	}

	// Aucun croisement
	return false;
}


bool Polygon::isBetween(const double& _a, const double& _b, const double& _c) const
{
	// On v�rifie de deux mani�res, afin de g�rer les nombres n�gatifs.
	// Retourne vrai si _b se situe entre _a et _c
	return _a <= _b && _b <= _c || _c <= _b && _b <= _a;
}

bool Polygon::areNearlyEqual(const double& _a, const double& _b) const
{
	/*
	Ici j'�tablie une "marge d'erreur" afin d'�tablir si un chiffre �gale � 0.
	Car comparer des doubles n'est pas la m�me chose qu'avec des entiers.
	
	Sinon, cette fonction peut ne pas retourner un r�sultat v�ridique (car avec
	des doubles, des fois 0 != 0).

	Plus d'information ici: http://stackoverflow.com/q/13698927
	et ici http://realtimecollisiondetection.net/blog/?p=89
	*/

	return fabs(_a - _b) < numeric_limits<double>::epsilon();
}