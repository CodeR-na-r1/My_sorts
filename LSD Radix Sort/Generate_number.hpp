#include <random>
#include <time.h>

void generate(int* arr, const int begin, const int end)
{
	srand(time(nullptr));
	for (int i(begin); i < end; i++)
	{
		arr[i] = rand();
	}
}

template<typename T, typename TT = unsigned long long>
void unique_gen(T* arr, const TT begin, const TT end, TT diapazon = 0)
{
	int N = end - begin;
	if (!diapazon)
	{
		diapazon = N * 3;
	}
	++diapazon; //101
	T* temp = new T[diapazon]; //100
	for (TT i = 0; i < diapazon; i++)
	{
		temp[i] = i;
	}
	for (TT i = begin; i < end; i++)
	{
		TT index = rand() % diapazon;
		arr[i] = temp[index];
		if (index != (diapazon - 1))
		{
			temp[index] = temp[diapazon - 1];
		}
		--diapazon;
	}
	delete[] temp;
}

bool check(const int* arr, const int begin, const int end)
{
	for (int i(begin); i < end; i++) {
		for (int j(i + 1); j < end; j++) {
			if (arr[i] == arr[j])
				return false;
		}
	}
	return true;
}