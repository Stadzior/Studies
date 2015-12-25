#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int check (char *tab){
		int i,f=1;
	for(i=0;i<strlen(tab);i++){
		if(!(isdigit(tab[i]))){	                   //funkcja check , która sprawdza znak po znaku czy       
		f=0;                                       //u¿ytkownik przypadkiem nie wpisa³ czegos zlosliwego
		}
	}
	return f;
}
int main(int argc, char *argv[]) {
int *tabi,i,ROZMIAR;
char ROZMIARS[30],*tabc;
float *tabf;
srand(time(NULL));
do{
printf("Podaj rozmiar tablicy(liczba calkowita dodatnia):\n");
scanf("%s",&ROZMIARS);
fflush(stdin);
check(ROZMIARS);
ROZMIAR=atoi(ROZMIARS);
system("cls");
}while((check==0)||(ROZMIAR<=0));
tabi=malloc(sizeof(int)*ROZMIAR);
tabc=malloc(sizeof(int)*ROZMIAR);
tabf=malloc(sizeof(int)*ROZMIAR);
for (i=0;i<=ROZMIAR;i++){
	*(tabi+i)=rand()%10;
	if((i%3==0)&&(i<(ROZMIAR-1))){
		*(tabc+i)='a';
		*(tabc+i+1)='b';
		*(tabc+i+2)='c';
	}
	*(tabf+i)=(rand()%10)+0.5;
	if(i%2==0){
		printf("%i:\t%i\t%c\t%f\n",i,*(tabi+i),*(tabc+i),*(tabf+i));
	}
	if((i%50==0)&&(i!=0)){
		system("pause");
	}
}
free(tabi);
free(tabc);
free(tabf);
			return 0;
}
