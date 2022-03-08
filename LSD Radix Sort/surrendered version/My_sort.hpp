#include <iostream>
using namespace std;

namespace My_sort
{
	class Sort
	{
	public:

		template<typename T>
		static void LSD_sort(T& data, const unsigned int size, const int count_value_digit = 256, const int offset = 8)
		{
			int* data_supporting = new int[size];	// Вспомогательный контейнер для записи сюда значений на этапах сортировки (для каждого разраяда)

			int* helper_exchange;	// Указатель для упрощения размена указателей (позволяет не делать копирование)

			int count_bytes = sizeof(T);	// Количество байт, занимаемое единицой коллекции (определяет количество этапов сортировки)

			int intermediate;	// Переменная для промежуточных даннх в процессе вычислений

			for (unsigned int i = 0; i < count_bytes; i++)	// Цикл по кол-ву этапов сортировки
			{
				int indexes[256] = { 0 };		// вспомогательный массив
				for (unsigned int j = 0; j < size; j++)
				{
					intermediate = data[j] >> (i * offset);		// Берём нужный для данного этапа кусок данных (по дефолту - 1 байт)
					++indexes[intermediate & 0x000000FF];	// Инкреминтируем данное значение
				}

				for (unsigned int j = 1; j < count_value_digit; j++)
				{
					indexes[j] += indexes[j - 1];	// Аккумулируем индексы для адресации в дальнейшем
				}

				for (signed int j = size - 1; j >= 0; j--)
				{
					intermediate = data[j] >> (i * offset);
					data_supporting[indexes[intermediate & 0x000000FF]-- - 1] = data[j];		// Сортируем по данному разряду
				}

				// Для избавления от копирования массивов, размениваем указатели
				helper_exchange = data;
				data = data_supporting;		// В указатель для контейнера с основными данными забираем актуальные данные
				data_supporting = helper_exchange;	// В указатель для вспомогательного контейнера забираем уже неактуальные данные
			}

			// Так как указатели на одну область память указывают, то:
			helper_exchange = nullptr;
			delete[] data_supporting;

			return;
		}
	};
}