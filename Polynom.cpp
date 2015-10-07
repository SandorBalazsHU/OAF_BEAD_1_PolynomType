#include "Polynom.h"
//Objektum elvű alkalmazások fejesztése gyakorlat 1. beadandó
//Sándor Balézs - AZA6NL

//Konstruktorok
	//Az üres polinomot nullpolinomként értelmezzük
	Polynom::Polynom()
	{
		_n = 0;
	}
	//Konstruktor 2 - Egy tömb alapján hoz létre egy új polinomot
	Polynom::Polynom(double* t, int n)
	{
		//az elemek számának másolása
		_n = n;
		//dinamikus helyfoglalású tömb létrehozása a polinom valós együtthatóinak tárolásához
		_p = new double[n];
		//a paraméterként kapott tömb elemeinek másolása
		for(int i=0; i<n; i++)
		{
			_p[i] = t[n];
		}
	}
	//A másoló konstruktor
	Polynom::Polynom(const Polynom& p)
	{
		//az elemek számának másolása
		_n = p._n;
		//dinamikus helyfoglalású tömb létrehozása a polinom valós együtthatóinak tárolásához
		_p = new double[_n];
		//a paraméterként kapott tömb elemeinek másolása
		for(int i=0; i<_n; i++)
		{
			_p[i] = p._p[i];
		}
	}

//Destruktor
	Polynom::~Polynom()
	{
		delete[] _p;
	}
	
//Műveletek
	//Az értékadó operátor
	Polynom& Polynom::operator= (const Polynom &p)
	{
		if (this == &p) return *this;
		delete[] _p;
		//az elemek számának másolása
		_n = p._n;
		//dinamikus helyfoglalású tömb létrehozása a polinom valós együtthatóinak tárolásához
		_p = new double[_n];
		//a paraméterként kapott tömb elemeinek másolása
		for(int i=0; i<_n; i++)
		{
			_p[i] = p._p[i];
		}
		return *this;
	}
	
//Kommutatív műveletek polinom és polinom között
	//Két polinom összeadása (Kommutatív)
	Polynom Polynom::operator+(const Polynom& p) const
	{
		double* polynom = _p;
		int nuberOfElements = _n;
		if(_n > p._n)
		{
			polynom = p._p;
			nuberOfElements = p._n;
		}
		for(int i=0; i<nuberOfElements; i++)
		{
			polynom[i] = _p[i]+p._p[i];
		}
		return Polynom(polynom, nuberOfElements);
	}
	//Két polinom szorzata (Kommutatív)
	Polynom Polynom::operator*(const Polynom &p) const
	{
		int nuberOfElements = _n+p._n-2;
		double newPolynom[nuberOfElements];

		for(int i=0; i<_n; i++)
		{
			for(int j=0; j<p._n; j++)
			{
				newPolynom[i+j] += _p[i]*p._p[j];
			}
		}
		return Polynom(newPolynom,nuberOfElements);
	}

//Kommutatív műveletek polinom és egy konstans között
	//Polinom szorzata konstansal (nem Kommutatív)
	Polynom Polynom::operator*(const double c)
	{
		double newPolynom[_n];
		for(int i=0; i<_n; i++)
		{
			newPolynom[i] = _p[i]*c;
		}
		return Polynom(newPolynom, _n);
	}
	//Polinom szorzata konstansal (A kommutativitás megolsása)
	Polynom operator*(const double c, const Polynom &p)
	{
		double newPolynom[p._n];
		for(int i=0; i<p._n; i++)
		{
			newPolynom[i] = p._p[i]*c;
		}
		return Polynom(newPolynom, p._n);
	}
	//Polinom összeadása konstansal (nem Kommutatív)
	Polynom Polynom::operator+(const double c)
	{
		double newPolynom[_n];
		for(int i=0; i<_n; i++)
		{
			newPolynom[i] = _p[i];
		}
		newPolynom[0] = newPolynom[0] +c;
		return Polynom(newPolynom, _n);
	}
	//Polinom összeadása konstansal (A kommutativitás megolsása)
	Polynom operator+(const double c, const Polynom &p)
	{
		double newPolynom[p._n];
		for(int i=0; i<p._n; i++)
		{
			newPolynom[i] = p._p[i];
		}
		newPolynom[0] = newPolynom[0] + c;
		return Polynom(newPolynom, p._n);
	}