double x1 = _point1.x, x2 = _point2.x, x3 = _point3.x, x4 = _point4.x;
double y1 = _point1.y, y2 = _point2.y, y3 = _point3.y, y4 = _point4.y;

double slope1 = 0, slope2 = 0, b1 = 0, b2 = 0;

	
	if ((slope1 - slope2) == 0){ //vérifie si les droites sont parallèles
		return false;
	}
	if ((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3) || (x3 == x4 && y3 == y4) || (x4 == x1 && y4 == y1)) return false; // vérifie si deux points ne sont pas identiques

	double xOfIntersection = (b2 - b1) / (slope1 - slope2);
	double yOfIntersection = (slope1 * xOfIntersection) + b1;

	if ((xOfIntersection >= x1 && xOfIntersection <= x2) && (xOfIntersection >= x3 && xOfIntersection <= x4)){
		if ((yOfIntersection >= y1 && yOfIntersection <= y2) && (yOfIntersection >= y3 && yOfIntersection <= y4)){
			return true;
		}
		return false;
	}
	return false;