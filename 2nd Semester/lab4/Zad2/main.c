#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int czy_calkowite(char *cyfry){
	int i=0,f=1;	
	do{
		if(!isdigit(*(cyfry+i))){
			f=0;
			break;
		}
		i++;
	} while (*(cyfry+i)!=NULL);
	return f;
}
int czy_parzyste(char *cyfry){
int f=1,i;
for(i=0;i<strlen(cyfry);i++){
	if(((*(cyfry+i))%2)!=0){
		f=0;
	}
}
return f;
}
int main(int argc, char *argv[]) {
	int tab[5],tab2[5],i,j=0;
	char cyfry[50];
	for (i=0;i<5;i++){
		do{
			printf("Wpisz %i element:\n",i+1);
			scanf("%s",cyfry);
		}while(czy_calkowite(cyfry)!=1);
		*(tab+i)=atoi(cyfry);
		if ((czy_parzyste(cyfry)==1)&&(cyfry!=NULL)){
				*(tab2+j)=*(tab+i);
				printf("%i",*(tab2+j));
				j++;
		}
	}
	system("cls");
	for(i=0;i<j;i++){
			printf("%i\t",*(tab2+i));
	}
	return 0;
}
