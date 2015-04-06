#pragma once
#include <iostream>
class complex
{
private:
	double Re;
	double Im;
public:
	complex operator=(const complex&);
	friend complex operator+(const complex &, const complex &);
	friend complex operator-(const complex &, const complex &);
	friend complex operator*(const complex &, const complex &);
	friend complex operator/(const complex &, const complex &);
	complex &operator+=(const complex&);
	complex &operator-=(const complex&);
	complex &operator*=(const complex&);
	complex &operator/=(const complex&);
	int operator==(const complex&);
	friend std::ostream& operator<< (std::ostream&, const complex&);
	double getRe() const;
	double getIm() const;
	void setRe(double);
	void setIm(double);
	complex(double re=0, double im=0);
	complex(complex &complex);
	virtual ~complex();
};
double fabs(const complex&);