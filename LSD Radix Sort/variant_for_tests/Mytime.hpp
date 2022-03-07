#pragma once

#include <iostream>
#include <chrono>

class Mytime
{
private:
	std::chrono::steady_clock::time_point start, end;
	std::chrono::duration<float> duration;

public:
	Mytime() {	// ������������� �������� ������� + ����� �������
		start = std::chrono::high_resolution_clock::now();
	}

	void retime() { start = std::chrono::high_resolution_clock::now(); }	// ����� �������� �������

	void output_time()	// ������ � �������
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		std::cout << "Time is code = " << duration.count() << "s" << std::endl;
	}

	float get_time()	// ��������� ��������
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		return this->duration.count();
	}

	~Mytime() {
	}
};