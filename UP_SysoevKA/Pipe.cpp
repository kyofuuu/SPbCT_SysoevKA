#include "Pipe.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <csignal>
#include <conio.h>
#include <cstdlib>
#include <string>
#include <lm.h>

namespace Pipe
{
	typedef struct
	{
		//дескрипторы событий
		HANDLE  hePipeStart;
		HANDLE  hePipeReply;
		//дескрипторы пайпов
		HANDLE  child_in;
		HANDLE  parent_out;
		HANDLE  child_out;
		HANDLE  parent_in;
		//буфера
		char    read[1024];     //буфер дл€ чтени€ данных
		char    send[1024];     //передаваемое значение
	}TheadParms;

	//тред пайпов
	BOOL FAR PASCAL Arithmetic::PipesProc(LPSTR lpData)
	{
		TheadParms* ptp = (TheadParms*)lpData;     //переданный параметр - адрес общих данных
		DWORD       num;                            //количество переданых/прочитаных байт

		while (1)                                   //бесконечный цикл
		{
			WaitForSingleObject(ptp->hePipeStart, INFINITE);   //ждем бесконечно событие

			//передача данных
			WriteFile(ptp->child_in, ptp->send, lstrlenA(ptp->send), &num, NULL);   //передаем готовые данные
			std::cout << "ƒанные переданы: " << ptp->send;                            //выведем переданные данные здесь

			//чтение данных
			ReadFile(ptp->child_out, ptp->read, 1023, &num, NULL);                  //читаем ответ в буфер
			SetEvent(ptp->hePipeReply);                                             //и взводим событие готовности
		}
	}
}