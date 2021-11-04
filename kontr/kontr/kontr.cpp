#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "Library.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;


int main(int argc, char* argv[])
{
	string a = "", search = "", word = "";
	string Line; //хранение строки
	string FileText; //хранение текста файла
	int k, v, n = 0, m, q;
	//int DeleteLine = 0; 
	int LineC = 0; //счетчик строк
	int ArrDeleteLine[5]; //массив строк на удаление
	setlocale(LC_ALL, "ru");

	string path = "File.txt";
	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app);

	if (!fs.is_open())
	{
		cout << "Ошибка при открытии файла!" << endl;
	}
	else
	{
		cout << "Файл успешно открыт" << endl;
		cout << "Введите 1 для ручного формирования каталога/добавления книг в каталог" << endl;
		cout << "Введите 2 для загрузки каталога из файла" << endl;
		cin >> v;

		if (v == 1)
		{
			cout << "Сколько книг добавляем?" << endl;
			cin >> n;
		}

		Library* Book = new Library[n];

		switch (v)
		{
		case 1: //Ручное формирование файла
			for (int count = 0; count < n; count++)
			{
				cout << "Введите информацию о книге" << endl;

				cin.get();

				cout << "Название: ";
				SetConsoleCP(1251);
				getline(cin, a); //Обеспечение ввода нескольких слов через пробел
				Book[count].SetName(a);
				SetConsoleCP(866);


				cout << "Автор: ";
				SetConsoleCP(1251);
				getline(cin, a); //Обеспечение ввода нескольких слов через пробел
				Book[count].SetAuth(a);
				SetConsoleCP(866);


				cout << "Количество книг: ";
				cin >> k;
				Book[count].SetQuant(k);

				cout << "Количество книг на руках: ";
				cin >> k;
				Book[count].SetQuantOH(k);

				cout << endl << endl;

			}

			//возврат и взятие читателем книги из библиотеки

			cout << "Читатель взял книгу\nУкажите номер взятой книги и их количество" << endl;
			cin >> m;
			cin >> q;
			while (q > Book[m - 1].GetQuant())
			{
				cout << "Нельзя взять больше!\nВведите количество еще раз!" << endl;
				cin >> q;
			}

			k = Book[m - 1].GetQuant();
			Book[m - 1].SetQuant(k - q);
			k = Book[m - 1].GetQuantOH();
			Book[m - 1].SetQuantOH(k + q);

			cout << "\nЧитатель вернул книгу\nУкажите номер возвращенной книги и их количество" << endl;
			cin >> m;
			cin >> q;
			while (q > Book[m - 1].GetQuantOH())
			{
				cout << "Нельзя вернуть больше!\nВведите количество еще раз!" << endl;
				cin >> q;
			}

			k = Book[m - 1].GetQuant();
			Book[m - 1].SetQuant(k + q);
			k = Book[m - 1].GetQuantOH();
			Book[m - 1].SetQuantOH(k - q);

			cout << endl;

			for (int count = 0; count < n; count++)
			{
				fs << Book[count] << "\n\n";
			}
			fs.close();
			cout << "Файл закрыт" << endl;
			break;

		case 2: //Вывод каталога из файла
			cout << "Выводим каталог..." << endl;
			while (!fs.eof())
			{
				a = "";
				getline(fs, a);
				cout << a << endl;
			}
			fs.close();
			cout << "Файл закрыт" << endl;
			break;

		default:
			cout << "Неправильное число\n" << endl;
			fs.close();
			cout << "Файл закрыт" << endl;
			return 0;
		}

		//Выполнение поиска в каталоге

		cout << "\nВыполнение поиска в каталоге" << endl;

		ifstream fin(path);
		string str;
		cout << "Введите слово для поиска" << endl;
		SetConsoleCP(1251);
		cin >> str;
		SetConsoleCP(866);
		using input_it = istream_iterator<string>;

		if ((find(input_it(fin), input_it(), str) != input_it()) == true)
		{
			cout << "Совпадение найдено\n" << endl;
		}
		else
		{
			cout << "Совпадения нет\n" << endl;
		}

		//Удаление записей из файла

		cout << "Удаление записей из файла" << endl;

		fs.open(path);

		if (!fs.is_open())
		{
			cout << "Ошибка при открытии файла!" << endl;
		}
		else
		{
			cout << "Файл открыт для удаления записей" << endl;
			cout << "Введите номер строки с названием книги для удаления \n(Удалится запись о всей книге)\n"; //указываем номер строки в файле, в которой содержится первое поле объекта класса Library
			cin >> ArrDeleteLine[0];

			for (int count = 1; count < 5; count++)
			{
				ArrDeleteLine[count] = ArrDeleteLine[count - 1] + 1;
			}

			while (getline(fs, Line))
			{
				LineC++;
				if (!(LineC == ArrDeleteLine[0] || LineC == ArrDeleteLine[1] || LineC == ArrDeleteLine[2] || LineC == ArrDeleteLine[3] || LineC == ArrDeleteLine[4]))
				{
					FileText.insert(FileText.size(), Line); //добавляем строку в переменную
					FileText.insert(FileText.size(), "\r\n"); //переносим строку
				}
			}
			fs.close();

			//FileLine содержит текст исходного файла без строк, помеченных на удаление. Перезаписываем файл

			ofstream fs;
			fs.open(path, ios::trunc | ios::binary);
			fs.write(FileText.c_str(), FileText.size()); // запись данных из FileLine в файл
			fs.clear();	//установка флага ошибки в положение "нет ошибки"
			cout << endl << "Удалено" << endl;
		}

	}

	system("pause");
	return 0;
}