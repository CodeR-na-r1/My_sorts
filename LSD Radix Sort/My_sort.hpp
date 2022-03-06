namespace My_sort
{
	class Sort
	{
	public:

		template<typename T>
		static void LSD_sort(T& data, const size_t size, const int count_value_digit = 256, const int offset = 8)
		{
			int count_bytes = sizeof(T);

			for (size_t i = 0; i < count_bytes; i++)
			{
				int indexes[count_value_digit] = { 0 };	// 
				for (size_t j = 0; j < size; j++)
				{
					++indexes[*(unsigned char*)&(data[j] >> (i * offset))];	// Возможно мы приводим не то (временный объект мэйби)
				}

				for (size_t j = 1; j < count_value_digit; j++)
				{
					indexes[j] += indexes[j - 1];	// Аккумулируем индексы для адресации в дальнейшем
				}

				for (size_t j = 1; j < count_value_digit; j++)
				{
						// 
				}
			}

			return;
		}
	};
}