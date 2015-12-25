#include <stdio.h>
#include <stdlib.h>
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
int dodaj(float *a,float *b,float *wynikw,int f,float wynik){
	*wynikw=*a+*b;
	if(*wynikw==wynik){
		f=1;
	}
return f;
}
int odejmij(float *a,float *b,float *wynikw,int f,float wynik){
		*wynikw=*a-*b;
	if(*wynikw==wynik){
		f=1;
	}
return f;
}
int pomnoz (float *a,float *b,float *wynikw,int f,float wynik){
	*wynikw=(*a)*(*b);
	if(*wynikw==wynik){
		f=1;
	}
return f;
}
int podziel (float *a,float *b,float *wynikw,int f,float wynik){
	*wynikw=(*a)/(*b);
	if(*wynikw==wynik){
		f=1;
	}
return f;
}
int main(int argc, char *argv[]) {
	char as[50],bs[50],x,f=0;
	float a,b,wynik,*aw,*bw,*wynikw;
	aw=&a;
	bw=&b;
	wynikw=&wynik;
	do{
		printf("Podaj liczbe a:\n");
		gets(as);
		system("cls");
	}while(check(as)==0);
	a=atof(as);
	do{
		printf("Podaj liczbe b:\n");
		gets(bs);
		system("cls");
	} while(check(bs)==0);
    b=atof(bs);
    do{
    	system("cls");
    printf("Co chcesz zrobic?\n(d)odac?\n(o)djac?\n(p)pomnozyc?\n(/)podzielic?\nWprowadz odpowiadajacy operacji znak w nawiasie.\n");
    x=getchar();
    } while ((x!='d')&&(x!='o')&&(x!='p')&&(x!='/'));
	switch(x){
    	case 'd':{
    		system("cls");
    		wynik=a+b;
    		printf("%i",dodaj(aw,bw,wynikw,f,wynik));
    		break;
    	}
    	case 'o':{
    		system("cls");
    		wynik=a-b;
    		printf("%i",odejmij(aw,bw,wynikw,f,wynik));
    		break;
    	}
    	case 'p':{
    		system("cls");
    		wynik=a*b;
    		printf("%i",pomnoz(aw,bw,wynikw,f,wynik));
    		break;    	
    	}
    	case '/':{
    		system("cls");
    		wynik=a/b;
    		printf("%i",podziel(aw,bw,wynikw,f,wynik));
    		break;
    	}
    	default:{
    		system("cls");
    		printf("Cos poszlo nie tak.");
    		break;
    	}
    }    
	return 0;
}
