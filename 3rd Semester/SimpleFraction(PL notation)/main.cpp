#include <iostream>
#include "string.h"
#include "stdlib.h"
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
void isDigit(char *string){                 //Funkcja sprawdzajaca czy podane przez uzytkownika wartosci s¹ liczbami ca³kowitymi
	int f=1,i;
	for (i=0;i<strlen(string);i++){
		if(!(isdigit(string[i]))){
			f=0;
		}
	}
	if(f==0)
	{
		throw std::exception();
	}	
}
char* ulamek (int licznik, int mianownik)                          //Funkcja przetwarzajaca i skracajaca nasz ulamek
{
	char *wynik;
	wynik= new char[100];
	if(mianownik==0)
	{
		wynik="Nie wolno dzielic przez zero!";	
	}
	else
	{
		if(licznik==0)
		{
			wynik="0";
		}
		else
		{
			int i,j,tempPosInStr;
			char* strLicznik;
			strLicznik= new char[100];
			
			do														//Skracanie ulamka
			{																
				i=nwd(licznik,mianownik);									
				licznik/=i;													
				mianownik/=i;												
			}while(nwd(licznik,mianownik)>1);	
								
			itoa(licznik,strLicznik,10);
			
			for(i=0;i<strlen(strLicznik);i++)                         //Formatowanie wyniku do postaci " LICZNIK / MIANOWNIK "
			{
				wynik[i]=strLicznik[i];
			}
			delete[]strLicznik;
			wynik[i]='/';
			i++;
			tempPosInStr=i;
			char* strMianownik;
			strMianownik= new char[100];
			itoa(mianownik,strMianownik,10);
			for(i,j=0;i<strlen(strMianownik)+tempPosInStr;i++,j++)
			{
				wynik[i]=strMianownik[j];
			}
			delete[]strMianownik;
			for(i;i<100;i++)
			{
				wynik[i]=0;                                     //Czyszczenie ewentualnych smieci z reszty miejsca zarezerwowanego na wynik
			}
		}
	}
	return wynik;
	delete[]wynik;
}
int main(int argc, char** argv) 
{
	char* licznik;
	char* mianownik;
	licznik= new char[100];
	mianownik=new char[100];
	cout<<"Podaj licznik:"<<endl;
	cin>>licznik;
	try
		{
			isDigit(licznik);
			static int intLicznik=atoi(licznik);
			delete[]licznik;
			cout<<"Podaj mianownik:"<<endl;
			cin>>mianownik;
			try
			{
				isDigit(mianownik);
				static int intMianownik=atoi(mianownik);
				delete[]mianownik;
				cout<<endl<<ulamek(intLicznik,intMianownik);
				return 0;
			}
			catch (std::exception &)
			{
				system("cls");
				cout << "Niepoprawny mianownik!"<<endl;
			}
		}
		catch (std::exception &)
		{
			system("cls");	
			cout << "Niepoprawny licznik!"<<endl;
		}
	
}
