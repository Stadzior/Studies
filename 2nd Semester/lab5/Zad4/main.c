#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAKS 1

union unia{
           double liczba;
           char tab[sizeof(double)];
};
int czy_liczba(char *string){
	int i,f=1;
	for(i=0;i<strlen(string);i++){
		if(isalpha(string[i])){
			f=0;	
		}
	}
	return f;
}
void zapisz(union unia unia[]){
	    int i;
	    FILE *pFile;
	    do{
	    	system("cls");
	 		printf("Podaj liczbe: ");
	 		scanf("%s", unia.tab);
	 		fflush(stdin);
	 	}while(czy_liczba(unia.tab)!=1);
			printf("\nPodana liczba: %s | \n", unia.tab);	
			system("pause");
		for (i=0;i<strlen(unia.tab); i++){
			
		}
}

void wczytaj(union unia unia[]){
	
}
int main()
{
	char check[1], f='f';
	union unia unia;
	 unia.liczba=2.5;
    printf("%d",unia.liczba);	
	 do {
	system("cls");
    printf("1 - Zapisz liczbe");
    printf("\n2 - Wczytaj liczbe");
    printf("\n3 - Zakoncz\n");
    scanf("%c",check);
    fflush(stdin);
    
    switch(check[0]) {
             case '1':
                  {
                  zapisz(&unia);
                  break;
                  }
                  
             case '2':
                  {
                  wczytaj(&unia);
                  break;
                  }
                
             
             case '3':
                  {
					f='t';
                  break;
                  }
             default:{
             	system("cls");
             	printf("Podales zla wartosc!\nWybierz '1' , '2' lub '3'.");
             	system("pause");
             	break;
             }
          
             }
     fflush(stdin);
	} while (f!='t');
	
}

