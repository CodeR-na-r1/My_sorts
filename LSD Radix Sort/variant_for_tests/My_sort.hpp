#include <iostream>
using namespace std;

namespace My_sort
{
	class Sort
	{
	public:

		template<typename T, typename Type_iterator>
		// 
		static void LSD_sort(T& data, const Type_iterator size, const int count_value_digit = 256, const int offset = 8)
		{
			int* data_supporting = new int[size];	// Вспомогательный контейнер для записи сюда значений на этапах сортировки (для каждого разраяда)

			int* helper_exchange;	// Указатель для упрощения размена указателей (позволяет не делать копирование)

			int count_bytes = sizeof(T);	// Количество байт, занимаемое единицой коллекции (определяет количество этапов сортировки)

			int intermediate;	// Переменная для промежуточных даннх в процессе вычислений

			for (Type_iterator i = 0; i < count_bytes; i++)	// Цикл по кол-ву этапов сортировки
			{
				int indexes[256] = { 0 };		// вспомогательный массив
				for (Type_iterator j = 0; j < size; j++)
				{
					intermediate = data[j] >> (i * offset);		// Берём нужный для данного этапа кусок данных (по дефолту - 1 байт)
					++indexes[*(unsigned char*)&intermediate];	// Инкреминтируем данное значение
				}

				for (Type_iterator j = 1; j < count_value_digit; j++)
				{
					indexes[j] += indexes[j - 1];	// Аккумулируем индексы для адресации в дальнейшем
				}

				for (signed int j = size - 1; j >= 0; j--)
				{
					intermediate = data[j] >> (i * offset);
					//auto x = indexes[*(unsigned char*)&intermediate] - 1;	// debug use only
					//auto two = data[j];	// debug use only
					data_supporting[indexes[*(unsigned char*)&intermediate]-- - 1] = data[j];		// Сортируем по данному разряду
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