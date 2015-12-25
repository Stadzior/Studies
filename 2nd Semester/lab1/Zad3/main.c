#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int check (char *tab){
		int i,f=1;
	for(i=0;i<strlen(tab);i++){
		if(!(isdigit(tab[i]))){	                   //funkcja check , która sprawdza znak po znaku czy       
		f=0;                                       //u¿ytkownik przypadkiem nie wpisa³ czegos zlosliwego
		}
	}
	return f;
}
int pierwsza(int a){
	int i=2,f=1;
	while (i<=sqrt(a)){
		if ((a%i)==0){
			f=0;
			break;
		}
	i++;
	};
	return f;
}
int marsenne(int n){
	if (pierwsza(n)==1)	{
		if (pierwsza(pow(2,n)-1)){
			n=(pow(2,n)-1);
		}
	} else {
		n=0;
	}
return n;
}
int main(int argc, char *argv[]) {
	char a[30],b[30];
	int ai,bi,i=0,m;
	do{
		if(i>0){
			printf("Wprowadzaj tylko liczby calkowite!\n");
		}
		printf("Wprowadz kres dolny przedzialu:\n");
		scanf("%s",&a);
		fflush(stdin);
		system("cls");
		i++;
	}while (check(a)==0);
	ai=atoi(a);
	i=0;
	do{
		if(i>0){
			printf("Wprowadzaj tylko liczby calkowite!\n");
		}
		printf("Wprowadz kres gorny przedzialu:\n");
		scanf("%s",&b);
		fflush(stdin);
		system("cls");
		if (check(b)==1){
			bi=atoi(b);
		}
		if (ai>bi){
			printf("Kres dolny nie moze miec wiekszej wartosci niz kres gorny!\n");
		}
		i++;
	}while ((check(b)==0)||(ai>bi));
	printf("Twoj przedzial to: <%i,%i>\nA oto liczby Marsenne'a:\n",ai,bi);
	i=ai;
	do{
		m=marsenne(i);
		if(m!=0){
			printf("%i - %i\n",i,m);
		}
		i++;
	}while(i<=bi);
	return 0;
}
