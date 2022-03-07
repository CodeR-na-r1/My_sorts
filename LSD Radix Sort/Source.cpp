#include <iostream>

#include "Generate_number.h"

#include "My_sort.h"
using namespace My_sort;

using namespace std;

#define SIZE 8

int main()
{
	int* arr = new int[SIZE];

	unique_gen(arr, 0, SIZE, 10000);

	cout << endl;
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	
	My_sort::Sort::LSD_sort(arr, SIZE);
	
	cout << endl;
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	
	delete[] arr;

	return 0;
}