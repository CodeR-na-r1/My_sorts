#include <iostream>

#include "Generate_number.hpp"

#include "My_sort.hpp"
using namespace My_sort;

using namespace std;

#define SIZE 1'000//'000

int main()
{
	int* arr = new int[SIZE];

	unique_gen(arr, 0, SIZE);

	Sort::LSD_sort(arr, SIZE);

	delete[] arr;

	return 0;
}