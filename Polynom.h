#ifndef POLYNOM_H
#define POLYNOM_H

class Polynom
{
    private:
		int *p;
		int n;
    public:
		Polynom();
		Polynom(int* t, int n);
		Polynom(const Polynom &p);
		Polynom& operator= (const Polynom &p);
		Polynom operator+(const Polynom &p) const;
		Polynom operator*(const Polynom &p) const;
		Polynom operator*(const int c, const Polynom &p)
		friend Polynom operator*(const int c, const Polynom &p);
		Polynom operator+(const int c, const Polynom &p)
		friend Polynom operator+(const int c, const Polynom &p);
};
#endif