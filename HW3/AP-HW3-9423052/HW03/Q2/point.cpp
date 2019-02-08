#include "point.h"

point::point (int X,int Y) : x(X),y(Y){}
point::point (const point*&& P): point(*P){}
point& point::operator= (const point*&& P)
{
	x = P->x;
	y = P->y;
	return *this;
}
point point::operator+ (const point& P) const
{
	point tmp{*this};
	tmp.x += P.x;
	tmp.y += P.y;
	return tmp;
}

point point::operator- (const point& P) const
{
	point tmp{*this};
	tmp.x -= P.x;
	tmp.y -= P.y;
	return tmp;
}

point point::operator* (double t) const
{
	point tmp{*this};
	tmp.x = static_cast<int>(t * x);
	tmp.y = static_cast<int>(t * y);
	return tmp;
}

bool point::operator== (const point& P) const
{
	if(x == P.x && y == P.y )
		return true;
	return false;
}

void point::show() const  
{
	std::cout << x << "\t"  << y << std::endl;
}

double point::abs() const
{
	return sqrt( x*x + y*y );
}
double point::ang() const
{
	return atan( ramp() ) * 180 / M_PI;
}
double point::ramp() const
{
	return static_cast<double> (y) / static_cast<double> (x) ;
}
int point::getX() const
{
	return x;
}
int point::getY() const
{
	return y;
}
int point::distance(point* P) const
{
	return (*this-*P).abs();
}

line* point::Line(const point* P) 
{ 
	l = new line ( this , P);
	return l;
}

line* point::Line(const point& P) 
{ 
	return Line(&P);
}

int det(const point& p1,const point& p2)
{
	return p1.getX() * p2.getY() - p2.getX() * p1.getY();	
}

bool solve (double& t, double& r, const point& A,const point& B, const point& C) //solve tA+rB=C
{
	if( det(A,B) == 0 )
		return false;
	t = static_cast<double>( det(C,B) ) / static_cast<double>( det(A,B) );
	r = static_cast<double>( det(A,C) ) / static_cast<double>( det(A,B) );
	return true;
}

