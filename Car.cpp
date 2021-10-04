#include "Car.h"
Car::Car(void)
{
	mark = "";
	cyl = 0;
	power = 0;
}
Car::~Car(void)
{
}
Car::Car(string M, int C, int P)
{
	mark = M;
	cyl = C;
	power = P;
}
Car::Car(const Car& car)
{
	mark = car.mark;
	cyl = car.cyl;
	power = car.power;
}
void Car::Setcyl(int C)
{
	cyl = C;
}
void Car::Setmark(string M)
{
	mark = M;
}
void Car::Setpower(int P)
{
	power = P;
}
Car& Car::operator=(const Car& c)
{
	if (&c == this) return *this;
	mark = c.mark;
	power = c.power;
	cyl = c.cyl;
	return *this;
}
istream& operator>>(istream& in, Car& c)
{
	cout << "\nMark:"; in >> c.mark;
	cout << "\nPower:"; in >> c.power;
	cout << "\nCyl:"; in >> c.cyl; return in;
}
ostream& operator<<(ostream& out, const Car& c)
{
	out << "\nMARK : " << c.mark;
	out << "\nCYL : " << c.cyl;
	out << "\nPOWER : " << c.power;
	out << "\n"; return out;
}
