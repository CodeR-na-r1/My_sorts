#include <iostream>

#include "Mytime.hpp"	// Для замера времени выполнения участка кода с сортировкой

#include "Generate_number.hpp"	// Для генерации неповторяющихся случайных чисел

#include "My_sort.hpp"	// Тут версия алгоритма LSD
using namespace My_sort;

using namespace std;

#define SIZE 52'428'800ULL	// Количество элементов в коллекции для сортировки

void print_arr(int* arr, int size)	// Функция для выввода массива
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int cmp(const void* one, const void* two)	// Аля типо функтор для std::qsort
{
	return *(int*)one > *(int*)two ? 1 : -1;
}

int main()
{
	int* data = new int[SIZE];	// Основной контейнер с неповторяющиися рандомными числами
	int* arr = new int[SIZE];	// Вспомогательный контейнер

	unique_gen(data, 0ULL, SIZE);	// Генерация неповторяющихся случайных чисел

	// ----------------- LSD_sort -------------------------

	std::copy(data, data + SIZE, arr);	// Копируем данные во вспомогательный контейнер для передачи следующему алгоритму сортировки
	Mytime time;	// Замер времени
	My_sort::Sort::LSD_sort(arr, SIZE);	// LSD_sort
	cout << "LSD Sort time -> \t" << time.get_time() << endl;	// Выввод времени

	// ----------------- std::qsort -------------------------

	std::copy(data, data + SIZE - 1, arr);	// Копируем данные во вспомогательный контейнер для передачи следующему алгоритму сортировки
	time.retime();	// Сброс времени
	std::qsort(arr, SIZE, sizeof(int), cmp);	// std::qsort
	cout << "qsort Sort time -> \t" << time.get_time() << endl;

	// ----------------- std::sort -------------------------

	std::copy(data, data + SIZE - 1, arr);	// Копируем данные во вспомогательный контейнер для передачи следующему алгоритму сортировки
	time.retime();
	std::sort(arr, arr + SIZE);	// std::sort
	cout << "sort Sort time -> \t" << time.get_time() << endl;
	
	delete[] arr;	// Чистим данные
	delete[] data;

	return 0;
}