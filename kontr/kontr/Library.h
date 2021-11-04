#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace std;

class Library
{
	string Name;
	string Author;
	int Quantity;
	int QuantityOH;
public:
	Library(void);
	Library(string, string, int, int);
	~Library();

	Library(const Library&);

	Library& operator=(const Library&);

	void SetName(string);
	void SetAuth(string);
	void SetQuant(int);
	void SetQuantOH(int);

	string GetName() { return Name; }
	string GetAuth() { return Author; }
	int GetQuant() { return Quantity; }
	int GetQuantOH() { return QuantityOH; }

	friend istream& operator>> (istream& in, Library& c);
	friend ostream& operator<< (ostream& out, const Library& c);
};