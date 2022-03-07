#include <iostream>
using namespace std;

namespace My_sort
{
	class Sort
	{
	public:

		template<typename T, typename Type_iterator>
		static void LSD_sort(T& data, const Type_iterator size, const int count_value_digit = 256, const int offset = 8)
		{
			int* data_supporting = new int[size];

			int* helper_exchange;

			int count_bytes = sizeof(T);

			int intermediate;

			for (Type_iterator i = 0; i < count_bytes; i++)
			{
				int indexes[256] = { 0 };	// вспомогательный массив	// [count_value_digit]
				for (Type_iterator j = 0; j < size; j++)
				{
					intermediate = data[j] >> (i * offset);
					++indexes[*(unsigned char*)&intermediate];	// Возможно мы приводим не то (временный объект мэйби)
				}

				for (Type_iterator j = 1; j < count_value_digit; j++)
				{
					indexes[j] += indexes[j - 1];	// Аккумулируем индексы для адресации в дальнейшем
				}

				for (signed int j = size - 1; j >= 0; j--)
				{
					intermediate = data[j] >> (i * offset);
					auto x = indexes[*(unsigned char*)&intermediate] - 1;
					auto two = data[j];
					data_supporting[indexes[*(unsigned char*)&intermediate]-- - 1] = data[j];		// Сортируем по данному разряду
				}

				// Для избавления от копирования массивов, размениваем указатели
				helper_exchange = data;
				data = data_supporting;
				data_supporting = helper_exchange;

				cout << endl << i << endl;
				for (size_t i = 0; i < size; i++)
				{
					cout << data[i] << " ";
				}
			}

			helper_exchange = nullptr;
			delete[] data_supporting;

			return;
		}
	};
}