#include "Lorry.h"
Lorry::Lorry(void) :Car()
{
	gruz = 0;
}
Lorry::~Lorry(void)
{
}
Lorry::Lorry(string M, int C, int P, int G) :Car(M, C, P)
{
	gruz = G;
}
Lorry::Lorry(const Lorry& L)
{
	mark = L.mark;
	cyl = L.cyl;
	power = L.power;
	gruz = L.gruz;
}
void Lorry::SetGruz(int G)
{
	gruz = G;
}
Lorry& Lorry::operator=(const Lorry& l)
{
	if (&l == this)return *this;
	mark = l.mark;
	power = l.power;
	cyl = l.cyl;
	gruz = l.gruz;
	return *this;
}
istream& operator>>(istream& in, Lorry& l)
{
	cout << "\nMark:"; in >> l.mark;
	cout << "\nPower:"; in >> l.power;
	cout << "\nCyl:"; in >> l.cyl;
	cout << "\nGruz:"; in >> l.gruz; return in;
}
ostream& operator<<(ostream& out, const Lorry& l)
{
	out << "\nMARK : " << l.mark;
	out << "\nCYL : " << l.cyl;
	out << "\nPOWER : " << l.power;
	out << "\nGRUZ : " << l.gruz; out << "\n";
	return out;
}
