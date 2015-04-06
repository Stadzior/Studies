#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isDigit(char *string)							  //Funkcja sprawdzaj¹ca czy ciag znakow to same cyfry calkowite dziesietne.
{
	int flag=1,i=0;
	do
	{
		if(!isdigit(string[i]))                      //Sprawdzamy czy podanq liczbq jest liczb¹ ca³kowit¹ dziesiêtn¹.
		{
			flag=0;
			break;
		}
		i++;
	} while(i<strlen(string));
	return flag;
}
///////////////////////////////////////////////
char *addCarry(char* string,int carry)							//Funkcja dodajaca carry na kolejna pozycje w podWyniku
{
	int i;
	for(i=strlen(string);i>=0;i--)
				{
						string[i+1]=string[i];
				}
				string[0]='0'+carry;
	return string;
}
///////////////////////////////////////////////
long int mnoz(char *pierwszy,char *drugi)                                          //Funkcja mnozaca , bez uzycia operatora mnozenia.
{
	long int result=0;
	if((!isDigit(pierwszy))||(!isDigit(drugi)))
	{
		system("cls");
		printf("Conajmniej jeden ze skladnikow nie jest liczba calkowita dziesietna!");	
	}
	else                                                                              
	{ 	
		int carry=0,elementPierwszy,elementDrugi,i,pierwszyPos,drugiPos,temp,Multipler=1;
		long int finalSubResult;
		printf("A\tB\tCarry\tReszta\n\n");
		for(drugiPos=strlen(drugi)-1;drugiPos>=0;drugiPos--)
		{
			finalSubResult=0;
			char *subResult=malloc(1000*sizeof(char));
			elementDrugi=drugi[drugiPos]-'0';
			for(pierwszyPos=strlen(pierwszy)-1;pierwszyPos>=0;pierwszyPos--)
			{
				elementPierwszy=pierwszy[pierwszyPos]-'0'; 
				temp=carry;
				for(i=0;i<elementDrugi;i++)
				{
					temp+=elementPierwszy;
				} 
				carry=temp/10;
				subResult[pierwszyPos]='0'+(temp%10);
				printf("%i\t%i\t%i\t%c\n\n",elementPierwszy,elementDrugi,carry,subResult[pierwszyPos]);           
			}		
			
				printf("\t\t%i\n",carry);
				if(carry!=0)
				{
					subResult=addCarry(subResult,carry);
				}
		
				for(i=0;i<Multipler;i++)
				{
					finalSubResult+=atoi(subResult);
				} 
				temp=Multipler;
				for(i=0;i<9;i++)
				{
					Multipler+=temp;
				}
				carry=0;
				result+=finalSubResult;
				printf("\n%i\n----------------\n",finalSubResult);
				free(subResult);
		}
	}          
	return result;
}
////////////////////////////////////////////////
long int mnozProsto(char* pierwszy,char* drugi)
{
	int result=0,i;
		if((!isDigit(pierwszy))||(!isDigit(drugi)))
		{
			system("cls");
			printf("Conajmniej jeden ze skladnikow nie jest liczba calkowita dziesietna!");	
		}
		else
		{
			int elementPierwszy=atoi(pierwszy);
			int elementDrugi=atoi(drugi);
		for(i=0;i<elementDrugi;i++)
			{
				result+=elementPierwszy;
			}
		}
	return result;
}
/////////////////////////////////////////////////
int main(int argc, char *argv[]) {
	char *pierwszy=(char*)malloc(1000*sizeof(char));
	char *drugi=(char*)malloc(1000*sizeof(char));
	int i;
	for(i=0;i<1000;i++)
	{
		pierwszy[i]='0';
		drugi[i]='0';
	}
	printf("Podaj pierwszy skladnik:\n");
	scanf("%s",pierwszy);
	fflush(stdin);
	printf("Podaj drugi skladnik:\n");
	scanf("%s",drugi);
	fflush(stdin);
	printf("\n\nWynik mnozenia metoda pisemna: %i\nWynik mnozenia przez dodawanie: %i",mnoz(pierwszy,drugi),mnozProsto(pierwszy,drugi));
	return 0;
}
