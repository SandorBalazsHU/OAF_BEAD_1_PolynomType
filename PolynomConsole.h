#ifndef POLYNOMCONSOLE_H_INCLUDED
#define POLYNOMCONSOLE_H_INCLUDED
#include "Polynom.h"
//Objektum elvű alkalmazások fejesztése gyakorlat 1. beadandó
//Sándor Balézs - AZA6NL

class PolynomConsole: public Polynom
{
    public:
	void read();
	void write();
};

#endif