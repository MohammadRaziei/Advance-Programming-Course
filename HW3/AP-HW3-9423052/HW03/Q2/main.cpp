#include<iostream>
#include<string>
#include "line.h"
int main()
{
	
	point p1{1,1}, p2{-1,-1}, p3{1,-1}, p4{-1,1};

	std::cout << "p1 = (" << p1.getX() <<"," << p1.getY() << ") =  " 
			<< p1.abs() << " |_ " << p1.ang() << std::endl;
	std::cout << "distance p1,p2  =  " << p1.distance(&p2) << std::endl; 
	line L12 {p1,p2};
	line L13 {p1,p3};
	line L14 {p1,p4};
	line L23 {p2,p3};
	line L24 {p2,p4};
	line L34 {p3,p4};
	
	line L21 {p2,p1 * 2};
	line L {p1.Line(&p2)};  
	std::cout << L12.ramp() << "\t" << L23.ramp() << "\t" <<L13.ramp() << std::endl;	
	point p5 {L12.intersection(&L23) };
	p5.show();
	L12.intersection(&L34) -> show();
	std::cout << L13.isParallel(&L23) << "\t" << L21.isEqual(&L12) << "\t" 
				<< L13.isParpendicular(&L14) << "\t" << L12.isParpendicular(&L34)
				<< "\t" << L12.isParpendicular(&L14) << std::endl;

	line L1;
	L1 = L13.parallel(&p4);
	std::cout << "check L1.isParallel L13    : " << L1.isParallel(&L13) << std::endl;
	L1 = p3.Line(&p2);
	std::cout << "check L1.isEqual    L23    : " << L1.isEqual(&L23) << std::endl;
	line L3 = L12.parallel(&p3);
	std::cout << "check L3.isParallel L12    : " << L3.isParallel(&L12) << std::endl;

	return 0;
}



