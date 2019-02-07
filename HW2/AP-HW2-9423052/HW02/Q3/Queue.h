#include <iostream>
#include <fstream>
#include <string>


class Queue
{
public:
	Queue(int);
	Queue(const char*);
	Queue();
	Queue(const Queue&);
	~Queue();
	int Size() const;
	double enQueue(double);
	double deQueue();
	void displayQueue() const;
	bool isEmpty() const;
	bool isFull() const;
	int inc(int) const;
private:	
	double* data;
	int head;
	int tail;
	int size;
};
