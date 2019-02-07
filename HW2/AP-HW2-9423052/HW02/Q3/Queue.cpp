#include"Queue.h"
#include<sstream>

Queue::Queue(int size):head(0),tail(0),size(size+1) 
{
	data = new double[size];
}
Queue::Queue():data(nullptr),head(0),tail(0),size(0){}
Queue::Queue(const Queue& q):head(0),tail(0),size(0)
{
	size = q.Size();
	data = new double[size];
}
Queue::Queue(const char* fileName):head(0),tail(1)
{
	std::ifstream file (fileName);
	file >> size;
	data = new double[++size];
	std::string tmp;
	file >> tmp;
	size_t s{tmp.find(",")};
	while ( s != std::string::npos)
	{
		tmp.replace(s,1," ");
		s = tmp.find(",");
		tail++;
	}

	std::istringstream stm{tmp};
	int i{};
	while( i < tail ) 
		stm >> data[i++];
	while( i < size )
		data[i++] = 0;
	file.close();
}
Queue::~Queue()
{
	delete[] data;
}
double Queue::enQueue(double input)
{
	if ( isFull() )
	{
		std::cout << "Cannot enQueue(" << input << ") because dataStructure is full" << std::endl;
	}
	data[tail] = input;
	tail = inc(tail);
	return input;
}
double Queue::deQueue()
{
	if ( isEmpty() )
	{
		std::cout << "Cannot deQueue() because dataStructure is  empty" << std::endl;
	}
	double tmp{data[head]};
	head = inc(head);
	return tmp;
}
int Queue::inc(int i) const 
{
	return (( i + 1 ) % size);
}
int Queue::Size() const
{
	return size;
}
void Queue::displayQueue() const
{
	for(int i{head}; !isEmpty() && i < tail; i = inc(i) )	
		std::cout << data[i] << std::endl;
	std::cout << "____________________" << std::endl;
}
bool Queue::isEmpty() const
{
	return head == tail;
}
bool Queue::isFull() const
{
	return ((head-tail)%size == 1);
}
