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
		//����������� �������
		HANDLE  hePipeStart;
		HANDLE  hePipeReply;
		//����������� ������
		HANDLE  child_in;
		HANDLE  parent_out;
		HANDLE  child_out;
		HANDLE  parent_in;
		//������
		char    read[1024];     //����� ��� ������ ������
		char    send[1024];     //������������ ��������
	}TheadParms;

	//���� ������
	BOOL FAR PASCAL Arithmetic::PipesProc(LPSTR lpData)
	{
		TheadParms* ptp = (TheadParms*)lpData;     //���������� �������� - ����� ����� ������
		DWORD       num;                            //���������� ���������/���������� ����

		while (1)                                   //����������� ����
		{
			WaitForSingleObject(ptp->hePipeStart, INFINITE);   //���� ���������� �������

			//�������� ������
			WriteFile(ptp->child_in, ptp->send, lstrlenA(ptp->send), &num, NULL);   //�������� ������� ������
			std::cout << "������ ��������: " << ptp->send;                            //������� ���������� ������ �����

			//������ ������
			ReadFile(ptp->child_out, ptp->read, 1023, &num, NULL);                  //������ ����� � �����
			SetEvent(ptp->hePipeReply);                                             //� ������� ������� ����������
		}
	}
}