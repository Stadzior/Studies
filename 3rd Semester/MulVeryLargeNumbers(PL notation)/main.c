#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SizeofElements 100
#define SizeofsubResult 1000
#define SizeofResult 10000

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
////////////////////////////////////////////////
char* swap(char*string){											//Funkcja odwracaj¹ca podwynik , poniewaz ten zostal...
	int i;															//...wczesniej zapisany w odwrotnej kolejnosci
	char temp;
	for(i=1;i<(strlen(string)/2)+1;i++)
			{
				temp=string[strlen(string)-i];
				string[strlen(string)-i]=string[i-1];
				string[i-1]=temp;
			}
	return string;
}
///////////////////////////////////////////////
char *addCarry(char* string,int carry)								//Dodanie ostatniego carry na kolejnej pozycji
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
char *addMultipler(char* string,int j)                                 //Dodanie odpowiedniej ilosci zer przy odpowiednim podwyniku
{
	int i;
	for(i=-1;i<j;i++)
		{
			if(i>-1)
			{
				strcat(string,"0");
			}
		}
		return string;
}
///////////////////////////////////////////////
char *initialize(char* string,size_t SIZE){                                   //Funkcja inicjalizuj¹ca podwynik subResult czyszcz¹c z niego smieci
	memcpy(string,"",SIZE);
	printf("Podwynik po wyczyszczeniu --->%s<---",string);
	//free(temp);
	return string;
}
//////////////////////////////////////////////
char *addString(char* pierwszy,char* drugi)															//Funkcja dodajaca do siebie dwa lancuchy tekstowe zawierajace inty
{
	int i,j,k,elementDrugi,elementPierwszy,carry,temp;
	char* result=malloc(SizeofResult);
	for(j=strlen(drugi)-1;j>=0;j--)							//Dodawanie pisemne podWynikow
		{
			result=initialize(result,SizeofsubResult);
			elementDrugi=drugi[j]-'0';											//W tym momencie w 1-szej iteracji nastepuje wyciek
			for(i=strlen(pierwszy)-1,k=0;i>=0;i--,k++)
			{
				elementPierwszy=pierwszy[i]-'0'; 
				temp=carry;
				temp+=elementDrugi+elementPierwszy; 
				carry=temp/10;
				result[k]='0'+(temp%10);
				printf("\n%i\t%i\t%i\t%c\t%s\t%i\n\n",elementPierwszy,elementDrugi,carry,result[k],result,k);   //Wyswietlanie danych
			}
			result=swap(result);                                    //Przetwarzanie
			if(carry!=0)														//
			{																	//
				result=addCarry(result,carry);							//
			}														//Wyniku
			carry=0;
		}
	return result;
	free(result);
}
///////////////////////////////////////////////
char* mnoz(char *pierwszy,char *drugi)                                          //Funkcja mnozaca , bez uzycia operatora mnozenia.
{
	char* result=malloc(sizeof(char)*SizeofResult);
	if((!isDigit(pierwszy))||(!isDigit(drugi)))
	{
		system("cls");
		printf("Conajmniej jeden ze skladnikow nie jest liczba calkowita dziesietna!");	
	}
	else                                                                              
	{ 	
		int carry=0,elementPierwszy,elementDrugi,i,j,k,pierwszyPos,drugiPos,temp;
		printf("A\tB\tCarry\tReszta\n\n");
		char* subResult=malloc(SizeofsubResult*sizeof(char));
		for(drugiPos=strlen(drugi)-1,j=0;drugiPos>=0;drugiPos--,j++)							//Mnozenie pisemne
		{
			subResult=initialize(subResult,SizeofsubResult);
			elementDrugi=drugi[drugiPos]-'0';											//W tym momencie w 1-szej iteracji nastepuje wyciek
			for(pierwszyPos=strlen(pierwszy)-1,k=0;pierwszyPos>=0;pierwszyPos--,k++)
			{
				elementPierwszy=pierwszy[pierwszyPos]-'0'; 
				temp=carry;
				for(i=0;i<elementDrugi;i++)                            //Mnozenie dwoch skladnikow za pomoca dodawania
				{
					temp+=elementPierwszy;
				} 
				carry=temp/10;
				subResult[k]='0'+(temp%10);
				printf("\n%i\t%i\t%i\t%c\t%s\t%i\n\n",elementPierwszy,elementDrugi,carry,subResult[k],subResult,k);   //Wyswietlanie danych
			}
			subResult=swap(subResult);                                    //Przetwarzanie
			if(carry!=0)														//
			{																	//
				subResult=addCarry(subResult,carry);							//
			}																	//
			subResult=addMultipler(subResult,j);						//PodWyniku aby nadawal sie do sumowania
			carry=0;
			result=addString(result,subResult);
		}
		free(subResult);
	}          
	return result;
	free(result);
}
////////////////////////////////////////////////
int main(int argc, char *argv[]) {
	char *pierwszy=(char*)malloc(SizeofElements*sizeof(char));
	char *drugi=(char*)malloc(SizeofElements*sizeof(char));
	printf("Podaj pierwszy skladnik:\n");
	scanf("%s",pierwszy);
	fflush(stdin);
	printf("Podaj drugi skladnik:\n");
	scanf("%s",drugi);
	fflush(stdin);
	printf("\n\nWynik mnozenia metoda pisemna: %s",mnoz(pierwszy,drugi));
	return 0;
}
