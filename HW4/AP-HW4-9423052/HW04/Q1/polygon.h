#include"point.h"
class polygon
{
public:
	polygon(point* arr, int size);
	polygon(line* arr, int size);
	bool isTriangle() const;
	bool isSquare() const;
	bool isEqual(const polygon &p) const;
////////////////////////////////
	polygon(const polygon&);
	polygon(polygon&&);
	polygon() = default;
	~polygon();
	polygon& operator=(const polygon&);
	polygon& operator=(polygon&&);
	polygon operator+(const point&) const;
	bool operator==(const polygon&) const;
	line** graph() const;
	bool isClockWise() const;
	int Size() const;
	int num_diag() const;
	int num_branchs() const;
protected:
	bool isEqual2(const polygon &p) const; //second algoritm
	point* sort() const;
	polygon rotate(int) const;
	polygon inverse(const polygon&) const;
	point* Left_top(int&) const;
private:
	point* points;
	int size;

};
