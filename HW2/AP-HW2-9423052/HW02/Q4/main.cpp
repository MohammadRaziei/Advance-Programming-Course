#include<iostream>
#include<string>

template <class T>
void swap(T& xp, T& yp);
template <class T>
void selectionSort(T arr[], int n);
template <class T>
void printArray(T arr[], int size);

int main()
{
    int arr[]{64, 25, 12, 22, 11};
	int n { sizeof(arr) / sizeof(arr[0]) };
	selectionSort(arr, n);
	std::cout <<"Sorted array:  " << std::endl;;
	printArray(arr, n);
	return 0;
}

template <class T>
void swap(T& xp, T& yp)
{
	T temp = xp;
	xp = yp;
	yp = temp;
}
template <class T>
void selectionSort(T arr[], int n)
{
	// One by one move boundary of unsorted subarray
	for (int i {}; i < n-1; i++)
	{
	// Find the minimum element in unsorted array
		int min_idx {i};
		for (int j {i+1}; j < n; j++)
			if (arr[j] < arr[min_idx])
		min_idx = j;																  
		// Swap the found minimum element with the first element
		swap(arr[min_idx], arr[i]);
	}
}
   
   /* Function to print an array */
template <class T>
void printArray(T arr[], int size)
{
	for (int i{}; i < size; i++)
		std::cout << arr[i] << std::endl;
	std::cout << std::endl;
}
    


