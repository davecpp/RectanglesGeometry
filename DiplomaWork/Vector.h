#pragma once
#include <cmath>
#include "Point.h"
#include "Angles.h"

BEGIN_GEOMETRY
using product_t = double;
END_GEOMETRY

IN_NAEMSPACE_GEOMETRY(nm_Vector)

using namespace nm_Point;
using namespace nm_Angles;

class Vector {

	Point begin, end;
public:

	explicit Vector(Point begin, Point end) : begin(begin), end(end) {}
	explicit Vector(Point end) : begin(Point(0, 0)), end(end) {}
	explicit Vector(coord_t x, coord_t y) :Vector(Point(x, y)) {}

	//Point getBegin() { return begin; }
	//Point getEnd() { return end; }
	//void setBegin(Point p) { begin = p; }
	//void setEnd(Point p) { end = p; }

private:
	NODISCARD coord_t getX() const { return Point::delta_x(end, begin); };
	NODISCARD coord_t getY() const { return Point::delta_y(end, begin); }

public:
	NODISCARD distance_t module() const { return Point::distance(begin, end); };

	NODISCARD Point VectorBegin() const { return begin; };
	NODISCARD Point VectorEnd() const { return end; };

/*
	//Vector Product
	NODISCARD static Vector CrossProduct(Vector v1, Vector v2);
	//Cross Product
	NODISCARD static Vector VectorProduct(Vector v1, Vector v2) {
		return CrossProduct(v1, v2);
	}*/


	//Scalar Product
	NODISCARD static product_t DotProduct(Vector v1, Vector v2);
	//Dot Product
	NODISCARD static product_t ScalarProduct(Vector v1, Vector v2) {
		return DotProduct(v1, v2);
	}

	//Vector product module
	NODISCARD static product_t PseudoScalarProduct(Vector v1, Vector v2);
	//with radian
	NODISCARD static radian_t Angle_rad(Vector v1, Vector v2);
	//with degree
	NODISCARD static angle_t Angle(Vector v1, Vector v2);

};

END_NAMESPACE_GEOMETRY(nm_Vector)

