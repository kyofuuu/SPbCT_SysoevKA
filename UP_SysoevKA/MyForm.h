#ifndef UNICODE
#define UNICODE
#endif

#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "netapi32.lib")

#pragma once

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include <Lm.h>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <csignal>
#include <conio.h>
#include <cstdlib>
#include <string>
#include "Pipe.h"
#include <msclr\marshal_cppstd.h>

namespace shishkinCLR {

	using namespace msclr::interop;
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
		char    read[1024];     //буфер для чтения данных
		char    send[1024];     //передаваемое значение
	}TheadParms;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label3;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(309, 409);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(165, 42);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Запуск";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(16, 409);
			this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 42);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Выход";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F));
			this->groupBox1->Location = System::Drawing::Point(16, 15);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Size = System::Drawing::Size(457, 279);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Выходные данные";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->label3->Location = System::Drawing::Point(8, 235);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 17);
			this->label3->TabIndex = 1;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(8, 31);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(440, 187);
			this->textBox1->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F));
			this->groupBox2->Location = System::Drawing::Point(16, 302);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Size = System::Drawing::Size(457, 100);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Метаданные";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 52);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 25);
			this->label2->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 27);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(283, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Сысоев Кирилл 500 группа";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(136, 409);
			this->button3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(165, 42);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Создать пользователя";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(491, 465);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		setlocale(0, "");

		SECURITY_ATTRIBUTES sa;//атрибуты защиты канала
		sa.lpSecurityDescriptor = NULL; //защита по умолчанию
		sa.nLength = sizeof(SECURITY_ATTRIBUTES);
		sa.bInheritHandle = true;//разрешаем наследование дескрипторов

	//обработка ошибок
		SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOOPENFILEERRORBOX | SEM_NOALIGNMENTFAULTEXCEPT);

		TheadParms tp = {};         //структура общих данных

		CreatePipe(&tp.parent_out, &tp.child_in, &sa, 0); //канал для stdin дочернего процесса
		CreatePipe(&tp.child_out, &tp.parent_in, &sa, 0); //канал для stdout дочернего процесса

		STARTUPINFO si;
		ZeroMemory(&si, sizeof(STARTUPINFO));
		si.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
		//  si.wShowWindow = SW_HIDE;//скрываем окно дочернего процесса
			//подменяем дескрипторы
		si.hStdOutput = tp.parent_in;
		si.hStdError = tp.parent_in;
		si.hStdInput = tp.parent_out;

		//Создаём дочерний процесс
		WCHAR ModuleName[] = L"shishkin.exe";
		PROCESS_INFORMATION pi;
		CreateProcess(ModuleName, NULL, NULL, NULL, TRUE, ABOVE_NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi);                // здесь будут дескрипторы и идентификаторы нового процесса и его первичного потока

		//Создаем события для синхнонизации
		tp.hePipeStart = CreateEvent(NULL,   // no security
			FALSE,  // explicit auto reset req
			FALSE,  // initial event reset
			NULL);  // no name

		tp.hePipeReply = CreateEvent(NULL,   // no security
			FALSE,  // explicit auto reset req
			FALSE,  // initial event reset
			NULL);  // no name

	//Создаем тред пайпов
		DWORD dwPipesThreadID;
		HANDLE hPipesThread = CreateThread((LPSECURITY_ATTRIBUTES)NULL, 0,
			(LPTHREAD_START_ROUTINE)Pipe::Arithmetic::PipesProc, &tp, 0, &dwPipesThreadID);  //параметром передаем адрес структуры данных

		SetEvent(tp.hePipeStart);

		Sleep(1000);

		//закрываем все, что понаоткрывали
		CloseHandle(tp.child_in);//закрываем канал stdin дочернего процесса
		CloseHandle(tp.parent_out);//закрываем родительский принимающий пайп
		CloseHandle(tp.parent_in);
		CloseHandle(tp.child_out);

		CloseHandle(tp.hePipeReply);
		CloseHandle(tp.hePipeStart);
		TerminateThread(hPipesThread, 0);

		TerminateProcess(pi.hProcess, 0);//убиваем дочерний процесс
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);

		this->textBox1->Text = "";

		string str;

		ifstream file("text.txt");

		if (file.is_open() == true)
		{
			while (getline(file, str)) {
				System::String^ systemString = msclr::interop::marshal_as<System::String^>(str);
				this->textBox1->Text += systemString + "\r\n";
			}
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		exit(1);
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		time_t rawtime;
		struct tm* timeinfo;
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		string str = asctime(timeinfo);
		System::String^ systemString = msclr::interop::marshal_as<System::String^>(str);
		this->label2->Text = systemString;
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	USER_INFO_1 ui;
	DWORD dwLevel = 1;
	DWORD dwError = 0;
	NET_API_STATUS nStatus;

	ui.usri1_name = (LPWSTR)L"KirillS";
	ui.usri1_password = (LPWSTR)L"123456789";
	//ignored by NetUserAdd
	//ui.usri1_password_age = -1;
	ui.usri1_priv = USER_PRIV_USER; //USER_PRIV_ADMIN;
	ui.usri1_home_dir = NULL;
	ui.usri1_comment = NULL;
	ui.usri1_flags = UF_SCRIPT;
	ui.usri1_script_path = NULL;

	nStatus = NetUserAdd(NULL, dwLevel, (LPBYTE)&ui, &dwError);

	string str = "1";
	switch (nStatus)
	{
	case NERR_Success:
	{
		str = "SUCCESS!";
		break;
	}
	case NERR_InvalidComputer:
	{
		str = "A system error has occurred: NERR_InvalidComputer";
		break;
	}
	case NERR_NotPrimary:
	{
		str = "A system error has occurred: NERR_NotPrimary";
		break;
	}
	case NERR_GroupExists:
	{
		str = "A system error has occurred: NERR_GroupExists";
		break;
	}
	case NERR_UserExists:
	{
		str = "A system error has occurred: NERR_UserExists";
		break;
	}
	case NERR_PasswordTooShort:
	{
		str = "A system error has occurred: NERR_PasswordTooShort";
		break;
	}
	case ERROR_ACCESS_DENIED:
	{
		str = "Ошибка системы: ДОСТУП ЗАПРЕЩЕН!";
		break;
	}
	}

	System::String^ systemString = msclr::interop::marshal_as<System::String^>(str);
	this->label3->Text = systemString;
}
};
}
