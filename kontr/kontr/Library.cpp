#include "pch.h"
#include "Library.h"


Library::Library(void)
{
	Name = "";
	Author = "";
	Quantity = 0;
	QuantityOH = 0;
}

Library::Library(string N, string A, int Q, int QOH)
{
	Name = N;
	Author = A;
	Quantity = Q;
	QuantityOH = QOH;
}


Library::~Library()
{
}

Library::Library(const Library& lib)
{
	Name = lib.Name;
	Author = lib.Author;
	Quantity = lib.Quantity;
	QuantityOH = lib.QuantityOH;
}

Library& Library::operator=(const Library& c)
{
	if (&c == this) return *this;
	Name = c.Name;
	Author = c.Author;
	Quantity = c.Quantity;
	QuantityOH = c.QuantityOH;
	return *this;
}

void Library::SetName(string N)
{
	Name = N;
}

void Library::SetAuth(string A)
{
	Author = A;
}

void Library::SetQuant(int Q)
{
	Quantity = Q;
}

void Library::SetQuantOH(int QOH)
{
	QuantityOH = QOH;
}


istream& operator>>(istream& in, Library& c)
{
	in >> c.Name >> c.Author >> c.Quantity >> c.QuantityOH;
	return in;
}

ostream& operator<<(ostream& out, const Library& c)
{
	out << "Имя: " << c.Name
		<< "\nАвтор: " << c.Author
		<< "\nКоличество: " << c.Quantity
		<< "\nКоличество на руках: " << c.QuantityOH;
	return out;
}