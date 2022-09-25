#include <iostream>
#include "InputOutputData.h"
#include"Test.h"

using namespace std;
	int dataInputOutput::GetTemperature()
	{
		setlocale(LC_ALL, "Russian");
		double envir_T;
		cout << "Введите температуру окружающей среды (градусы Цельсия): " << endl;
		cin >> envir_T;
		return envir_T;
	}

	void dataInputOutput::WriteTime(const int time)
	{
		setlocale(LC_ALL, "Russian");
		if (time >= MAX_TIME)
			cout << endl << "При такой температуре двигатель не перегреется" << endl;
		else
			cout << endl << "Время до момента перегрева двигателя: " << time << " сек." << endl;
	}