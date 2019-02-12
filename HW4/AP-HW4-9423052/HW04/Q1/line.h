#pragma once
#include "point.h"
#include <iostream>
class point;
class line
{
public:
	line(const point*, const point*);				//Wanted
	line(const point& ,const point&);
	line(const line&);
	line(const line*&&);
	line(line&&);
	line() = default;
	~line();
	line& operator= ( const line&);
	line& operator= (line&&);
	line& operator= ( const line*&&);
	bool operator== ( const line&) const;
	bool operator== ( const line* ) const;
	bool isParallel( const line*) const;			//Wanted
	bool isEqual( const line*) const;
	bool isParpendicular( const line*) const;		//Wanted
	bool hasPoint( const point*) const;
	point* intersection(line*);						//Wanted
	line* parallel(point*);							//Wanted
	point continuance(double, const point* ) const;
	point continuance(double ) const;
	double ramp() const;
	double length() const;
private:
	point* p1;
	point* p2;
	point* p;
	line* l;
	friend class point;
};

