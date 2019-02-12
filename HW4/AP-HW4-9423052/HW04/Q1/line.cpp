#include "line.h"

line::line(const point& first,const point& second)
{
	p1 = new point(first.x, first.y) ;	
	p2 = new point(second.x, second.y) ;
}
line::line( const point* first, const point* second) : line(*first,*second){}
line::line( const line& L) : line(L.p1, L.p2){}
line::line(	const line*&& L) : p1 (L->p1), p2 (L->p2) {}
line::line( line&& L) : p1 (L.p1), p2 (L.p2) 
{
	L.p1 = nullptr;
	L.p2 = nullptr;
}

line::~line()
{
	delete p1;
	delete p2;
}
line& line::operator= ( const line& L)
{
	if( L == this )
		return *this;
	delete p1;
	delete p2;
	point first { *L.p1 }, 
		second { *L.p2 };
	p1 = new point(first.x, first.y) ;	
	p2 = new point(second.x, second.y) ;
	return *this;
}
line& line::operator= ( line&& L)
{
	p1 = L.p1;	p2 = L.p2;
	L.p1 = L.p2 = nullptr;
	return *this;	
}
line& line::operator= ( const line*&& L)
{
	p1 = L->p1;	p2 = L->p2;
	return *this;
}
bool line::operator== ( const line* L) const
{
	return isEqual(L);
}
bool line::operator== ( const line& L) const
{
	return isEqual(&L);
}
double line::ramp() const
{
	return (*p2 - *p1).ramp();
}
point line::continuance(double t, const point* P) const
{
	return *P + (*p2-*p1) * t;	
}
point line::continuance(double t) const
{
	return continuance(t,p1);
}

bool line::hasPoint( const point* P) const
{
	if( *p1 == *P || *p2 == *P)
		return true;
	return ramp() == p1->Line(P)->ramp();
}
bool line::isParallel( const line* L) const
{
	if( std::isinf( ramp() ) && std::isinf( L->ramp() ) )
		return true;
	return this->ramp() == L->ramp() ;
}
bool line::isEqual( const line* L) const
{
	if( isParallel(L) )
		return hasPoint(L->p1);
	return false;
}
bool line::isParpendicular( const line* L) const
{
	if( std::isinf( ramp() ) && L->ramp() == 0)
		return true;
	if( std::isinf( L->ramp() ) && ramp() ==0 ) 	
		return true;
	return this->ramp() * L->ramp() == -1;
}
point* line::intersection(line* L)
{
	double t{},r{};
	if( !solve (t,r, *p2 - *p1 , *(L->p1) - *(L->p2), *(L->p1) - *p1)  )
		return nullptr;
	p = new point ( continuance(t) ) ;
	return p;
}
line* line::parallel(point* P) 
{
	l = new line(*P, continuance(2,P) );		
	return l;
}

double line::length() const
{
	return (*p2 - *p1).abs();
}