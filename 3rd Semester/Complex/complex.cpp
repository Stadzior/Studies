#pragma once
#include <iostream>
#include "complex.h"
#include "math.h"

	complex complex::operator=(const complex &complex)
	{
		this->Re = complex.Re;
		this->Im = complex.Im;
		return *this;
	}
	complex operator+(const complex &element1, const complex &element2)
	{
		return complex(element1.getRe() + element2.getRe(), element1.getIm() + element2.getIm());
	}

	complex operator-(const complex &element1, const complex &element2)
	{
		return complex(element1.getRe() - element2.getRe(), element1.getIm() - element2.getIm());
	}

	complex operator*(const complex &element1, const complex &element2)
	{
		return complex((element1.Re*element2.Re) - (element1.Im*element2.Im),(element1.Im*element2.Re) + (element1.Re*element2.Im));
	}

	complex operator/(const complex &element1, const complex &element2)
	{
		return complex(((element1.Re*element2.Re) + (element1.Im*element2.Im)) / ((element2.Re*element2.Re) + (element2.Im*element2.Im)),((element1.Im*element2.Re) - (element1.Re*element2.Im)) / ((element2.Re*element2.Re) + (element2.Im*element2.Im)));
	}

	complex &complex::operator+=(const complex &complex)
	{
		this->Im = this->Im + complex.Im;
		this->Re = this->Re + complex.Re;
		return *this;
	}

	complex &complex::operator-=(const complex &complex)
	{
		this->Im = this->Im - complex.Im;
		this->Re = this->Re - complex.Re;
		return *this;
	}
	//(ac-bd)+(bc+ad)i
	complex &complex::operator*=(const complex &complex)
	{
		double tempRe = this->Re;
		this->Re=((this->Re)*(complex.Re)) - ((this->Im)*(complex.Im));
		this->Im=((this->Im)*(complex.Re)) + ((tempRe)*(complex.Im));
		return *this;
	}
	//(ac+bd)/(c^2+d^2)+(bc-ad)/(c^2+d^2)i
	complex &complex::operator/=(const complex &complex)
	{
		double tempRe = this->Re;
		this->Re = (((this->Re)*(complex.Re)) + ((this->Im)*(complex.Im))) / (((complex.Re)*(complex.Re)) + ((complex.Im)*(complex.Im)));
		this->Im = (((this->Im)*(complex.Re)) - ((tempRe)*(complex.Im))) / (((complex.Re)*(complex.Re)) + ((complex.Im)*(complex.Im)));
		return *this;
	}

	int complex::operator==(const complex &complex)
	{
		int flag = 1;
		if ((this->Re != complex.Re) || (this->Im != complex.Im))
		{
			flag = 0;
		}
		return flag;
	}
	std::ostream& operator<<(std::ostream & stream,const complex &complex)
	{
		return stream << complex.getRe() << " + " << complex.getIm() << " i";
	}
	double complex::getRe() const
	{
		return this->Re;
	}

	double complex::getIm() const
	{
		return this->Im;
	}

	void complex::setRe(double value)
	{
		this->Re = value;
	}

	void complex::setIm(double value)
	{
		this->Im = value;
	}

	complex::complex(double Re, double Im)
	{
		this->setRe(Re);
		this->setIm(Im);
	}

	complex::complex(complex &complex)
	{
		if (this != &complex)
		{
			this->Re = complex.getRe();
			this->Im = complex.getIm();
		}
	}

	 complex::~complex()
	{
	}
	double fabs(const complex &complex)
	{
		 return sqrt(complex.getRe()*complex.getRe() + complex.getIm()*complex.getIm());
	}