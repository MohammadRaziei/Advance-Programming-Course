#include<iostream>
#include<string>
#include"polygon.h"
int main()
{
	point p[4]	{ {-1,0},{0,2},{1,0},{0,-1} };
	point p2[4]	{ {-1,0},{0,1},{2,0},{0,-1} };
	polygon poly{p,4};
	polygon poly2{p2,4};
	point p11{1,1}, p10{1,-1} ,p00{-1,-1}, p01{-1,1}, p20{2,-1};
	point pall[] {p11,p01,p00,p10},
		 pall2[] {p00,p10,p20};
	polygon t1{pall,3}, t2{pall2,3}, s1{pall,4};
	point shift{1,2};
	polygon poly3{poly+shift};


	std::cout << poly.isSquare() << s1.isSquare() 
			<< t1.isTriangle() << t2.isTriangle()  
			<< poly.isEqual(poly2) << poly.isEqual(s1) << poly.isEqual(poly2)
			<< std::endl;
	return 0;
}



