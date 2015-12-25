#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int check (char *tab){
		int i,f=1;
	for(i=0;i<strlen(tab);i++){
		if(!(isalpha(tab[i]))){	                   //funkcja check , która sprawdza znak po znaku czy       
		f=0;                                       //u¿ytkownik przypadkiem nie wpisa³ czegos zlosliwego
		}
	}
	return f;
}
void male(char *tab){
	int i;
	for(i=0;i<strlen(tab);i++){
		*(tab+i)=tolower(*(tab+i));
	}
}
void wielkie(char *tab){
		int i;
	for(i=0;i<strlen(tab);i++){
		*(tab+i)=toupper(*(tab+i));
	}
}
int main(int argc, char *argv[]) {
	char tab[50],x;
	printf("Napisz jakis wyraz:\n");
	do{
		scanf("%s",&tab);
		fflush(stdin);
	} while(check(tab)==0);
	do{
		system("cls");
		printf("Co wybierasz?\n (m)ale litery\n (w)ielkie litery\nWprowadz odpowiednia litere z nawiasu.\n");
		x=getchar();
	} while((x!='m')&&(x!='w'));
	switch(x){
		case 'm':{
			system("cls");
			male(tab);
			printf("%s",tab);
			break;
		}
		case 'w':{
			system("cls");
			wielkie(tab);
			printf("%s",tab);
			break;
		}
		default:{
			printf("Cos poszlo nie tak.");
			break;
		}
	}
	return 0;
}
