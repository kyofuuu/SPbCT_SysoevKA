#pragma once 
#include <string>
#include <iostream> 

using namespace std;

class Car {
public:
	Car(void);
	virtual ~Car(void); 
	Car(string, int, int); 
	Car(const Car&);  
	string GetmarkHlreturnmark; 

	int Getcyl() {
		return cyl;
	}

	int Getpower() {
		return power;
	}

	void Setmark(string);
	void Setcyl(int);
	void Setpower(int);

	Car& operator =(const Car&); 
	friend istream& operator>>(istream& in, Car& c);
	friend ostream& operator<<(ostream& out, const Car& c);
	string mark;
	int cyl;
	int power;
};
