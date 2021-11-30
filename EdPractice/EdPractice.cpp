#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <random>
#include <Windows.h>
#include "VectorLibrary.h"
#pragma warning(disable : 4996)
using namespace std;
using namespace VectorFuns;

Vector vect[10];
HANDLE out;
HANDLE Ride, write;
string str0;
string str[10];


int main()
{
	int A[100];
	char buf;
	setlocale(LC_ALL, ".1251");
	time_t now = time(0);
	tm* date_time = localtime(&now);
	ifstream F1("file1.txt");


	cout << "ФИО: Самойлов Евгений Александрович" << endl;
	cout << "Группа: 501" << endl;
	cout << "Дата: " << date_time->tm_mday << "." << 1 + date_time->tm_mon << "." << date_time->tm_year + 1900;
	cout << " Время: " << date_time->tm_hour << ":" << date_time->tm_min << ":" << date_time->tm_sec << endl;
	cout << " " << endl;

	cout << "Файл: " << endl;
	if (F1.is_open()) {
		char ch;
		for (int i = 0; i < 10; i++) {
			cout << "  ";
			for (int j = 0; j < 10; j++) {
				F1.get(ch);
				vect[i].push_back(ch);
				cout << ch;
			}
			cout << '\n';
		}
		cout << endl;
		F1.close();
	}
	else {
		cout << "\nПроизошла ошибка! Файл не удалось открыть" << endl;
	}
	ifstream F2("File1.txt");

	if (F2.is_open()) {
		getline(F2, str0);
		cout << "Все символы: " << str0 << endl;
	}
	else cout << "Не удалось открыть";
	F2.close();
	 

	CreatePipe(&Ride, &write, NULL, 100);
	ReadFile(Ride, str, 100, NULL, NULL);

	

	ofstream F3("File2.csv");
	for (int i = 0; i < 10; i++) {
		F3 << str[i];
		F3 << ";";
	}

	return 0;
}
