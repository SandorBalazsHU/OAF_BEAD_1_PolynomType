#ifndef POLYNOM_H_INCLUDED
#define POLYNOM_H_INCLUDED
//Objektum elvű alkalmazások fejesztése gyakorlat 1. beadandó
//Sándor Balézs - AZA6NL

//A kódban a polinomot a valós együtthatóik sorozatával reprezentáljuk. (0-együthatóval együtt)
class Polynom
{
    private:
		//A polinomot reprezentáló dinamikus helyfoglalású tömb első elemére mutató pointer
		double* _p;
		//A polinom elemszáma
		int _n;
		
    public:
	//Konstruktorok
		//Az üres polinomot nullpolinomként értelmezzük
		Polynom();
		//Konstruktor 2 - Egy tömb alapján hoz létre egy új polinomot
		Polynom(double* t, int n);
		//A másoló konstruktor
		Polynom(const Polynom &p);
		
	//Műveletek
		//Az értékadó operátor
		Polynom& operator= (const Polynom &p);
		
	//Kommutatív műveletek polinom és polinom között
		//Két polinom összeadása (Kommutatív)
		Polynom operator+(const Polynom &p) const;
		//Két polinom szorzata (Kommutatív)
		Polynom operator*(const Polynom &p) const;
		
	//Kommutatív műveletek polinom és egy konstans között
		//Polinom szorzata konstansal (nem Kommutatív)
		Polynom operator*(const double c);
		//Polinom szorzata konstansal (A kommutativitás megolsása)
		friend Polynom operator*(const double c, const Polynom &p);
		//Polinom összeadása konstansal (nem Kommutatív)
		Polynom operator+(const double c);
		//Polinom összeadása konstansal (A kommutativitás megolsása)
		friend Polynom operator+(const double c, const Polynom &p);
	
	//Destruktor
		~Polynom();
};
#endif