#include <iostream>
#include "InputOutputData.h"
#include"Test.h"

using namespace std;
	int dataInputOutput::GetTemperature()
	{
		setlocale(LC_ALL, "Russian");
		double envir_T;
		cout << "������� ����������� ���������� ����� (������� �������): " << endl;
		cin >> envir_T;
		return envir_T;
	}

	void dataInputOutput::WriteTime(const int time)
	{
		setlocale(LC_ALL, "Russian");
		if (time >= MAX_TIME)
			cout << endl << "��� ����� ����������� ��������� �� �����������" << endl;
		else
			cout << endl << "����� �� ������� ��������� ���������: " << time << " ���." << endl;
	}