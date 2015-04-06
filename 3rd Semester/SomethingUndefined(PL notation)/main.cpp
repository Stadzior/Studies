#include <iostream>
#include "string.h"
#include "stdlib.h"
#include "math.h"
using namespace std;
int nwd(int a,int b)                        //Funkcja wyznaczajaca najwiekszy wspolny dzielnik
{
	int i;
	if(a>b)
	{
		i=b;
	}
	else
	{
		i=a;
	}
	for(i;i>0;i--)
	{
		if((a%i==0)&&(b%i==0))
		{
			return i;
		}
	}
}
int skracalny(int licznik,int mianownik)        //Funkcja sprawdzaj¹ca czy ulamek jest skracalny
{
	int flag=0;
	if(nwd(licznik,mianownik)>1)
	{
		flag=1;
	}
	return flag;
}
char *numbersLoss(int nBits,int dBits)                 //Funkcja/Metoda wyznaczajaca porzadane dane
{
	char *wynik,*buffer;
	wynik= new char[1000];
	buffer= new char[100];
	long unsigned int overall=pow(2,nBits)*pow(2,dBits);
	long unsigned int Loss=pow(2,nBits);
	overall-=Loss;
	itoa(Loss,buffer,10);
	strcpy(wynik,"Straty przez zero w mianowniku:");
	strcat(wynik,buffer);
	Loss=0;
	int i,j;
	for(i=0;i<pow(2,nBits);i++)
	{
		for(j=1;j<pow(2,dBits);j++)
		{
			if(skracalny(i,j)||((i==0)&&(j!=1)))
			{
				Loss++;
			}
		}
	} 
	overall-=Loss;
	itoa(Loss,buffer,10);
	strcat(wynik,"\nStraty w wyniku powtorek:");
	strcat(wynik,buffer);
	itoa(overall,buffer,10);
	strcat(wynik,"\nTyle mozna zapisac roznych liczb wymiernych:");
	strcat(wynik,buffer);
	delete [] buffer;
	return wynik;
	delete []wynik;
}
int main(int argc, char** argv)
{
	int nBits,dBits;
	cout<<"Podaj liczbe bitow jaka przeznaczasz na licznik:"<<endl;
	cin>>nBits;
	system("cls");
	cout<<"Podaj liczbe bitow jaka przeznaczasz na mianownik:"<<endl;
	cin>>dBits;
	system("cls");
	cout<<numbersLoss(nBits,dBits);
}
