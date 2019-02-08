#pragma once
#include "line.h"
#include <cmath>

class line;

class point
{
public:
	point (int x = 0,int y = 0);					//Wanted
	point (const point*&&);
	point& operator= (const point*&&);
	point operator+ (const point& ) const;			//Wanted
	point operator- (const point& ) const;
	point operator* (double ) const;
	bool operator== (const point&) const;
	int getX() const;								//Wanted
	int getY() const;								//Wanted
	void show() const;
	double abs() const;
	double ang() const;
	double ramp() const;	
	int distance(point*) const;						//Wanted
	line* Line (const point*);						//Wanted
	line* Line (const point&);
private:
	int x, y;
	line* l;
	friend class line;
};

int det(const point& p1,const point& p2);
bool solve (double& t, double& r, const point& A,const point& B, const point& C); //solve tA+rB=C

