#ifndef POLYNOMCONSOLE_H_INCLUDED
#define POLYNOMCONSOLE_H_INCLUDED
#include <string>
#include <vector>
#include "Polynom.h"
//Objektum elvű alkalmazások fejesztése gyakorlat 1. beadandó
//Sándor Balézs - AZA6NL

class PolynomConsole: public Polynom
{
    public:
	PolynomConsole();
	//Konstruktor 2 - Egy tömb alapján hoz létre egy új polinomot
	PolynomConsole(double*, int);
	//Konstruktor 3 - Egy vektor alapján hoz létre egy új polinomot
	PolynomConsole(std::vector<double>&);
	//Konstruktor 4 - konvertáló
	PolynomConsole(const Polynom&);
	//A másoló konstruktor
	PolynomConsole(const PolynomConsole&);
	void read();
	void write() const;
	static Polynom readExpression();
	static std::vector<std::string> tokenizer(std::string&, char);
};

#endif