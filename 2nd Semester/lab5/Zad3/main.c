#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#define MAKS 1

struct pacjent{

           char imie[50];
           char nazwisko[50];
           int wiek;
           char plec;
           char adres[50];
           char pesel[11];
           int nr_choroby;
};

void wprowadz_pacjenta(struct pacjent wpis[]){
		char wiek[3];	

		system("cls");
  	    printf("\nPodaj imie: ");
		gets(wpis[0].imie);
		fflush(stdin);
		
		system("cls");
		printf("\nPodaj nazwisko: ");
		gets(wpis[0].nazwisko);
		fflush(stdin);
		
		do {
		system("cls");
		printf("\nPodaj wiek: ");
		scanf("%s",wiek);
		fflush(stdin);
		} while(wiek_approved(wiek)!=1);
		wpis[0].wiek=atoi(wiek);
		
		do {
		system("cls");
		printf("\nPodaj plec(K/M)): ");
		scanf("%c", &wpis[0].plec);
		fflush(stdin);
		} while((wpis[0].plec!='K')&&(wpis[0].plec!='M'));
		
		system("cls");
		printf("\nPodaj adres: ");
		gets(wpis[0].adres);
		fflush(stdin);
		
		do {
		system("cls");
		printf("\nPodaj pesel: ");
		gets(wpis[0].pesel);
		fflush(stdin);
		} while(pesel_approved(wpis[0].pesel)!=1);
		
		system("cls");
		printf("\nPodaj numer choroby: ");
		scanf("%i", &wpis[0].nr_choroby);
		fflush(stdin);
}

int czy_calkowite(char *string){
	int i,f=1;
	for(i=0;i<strlen(string);i++){
		if(!isdigit(string[i])){
			f=0;	
		}
	}
	return f;
}

int wiek_approved(char *wiek){
	int f=1;
	if ((czy_calkowite(wiek)!=1)||(atoi(wiek)>150)){
		f=0;
	}
	return f;
}

int pesel_approved(char *pesel){
	int f=1;
	if ((czy_calkowite(pesel)!=1)||(strlen(pesel)!=11)){
		f=0;
	}
	return f;
}
void zapisz_pacjenta(struct pacjent wpis[]){
		FILE *pFile;
		pFile=fopen("pacjenci.txt","a");
		fprintf(pFile,"\n%s\t%s\t%i\t%c\t%s\t%s\t%i\n",wpis[0].imie,wpis[0].nazwisko,wpis[0].wiek,wpis[0].plec,wpis[0].adres,wpis[0].pesel,wpis[0].nr_choroby);
		fclose(pFile);
}
int czy_mozna_zapisac(struct pacjent wpis[]){
		char sample[11],*pesel;
	pesel=malloc(sizeof(char)*11);
	pesel=wpis[0].pesel;
	FILE *pFile;
	int f=1,i;

	size_t size;
	pFile=fopen("pacjenci.txt","r");
		fseek (pFile, 0, SEEK_END);   
	    size=ftell(pFile);  
		for(i=0;i<(size-11);i++){		
			fseek(pFile,i,SEEK_SET);
			if((fgetc(pFile)==pesel[0])&&((size-11)>0)){
				fseek(pFile,-1,SEEK_CUR);
				fgets(sample,12,pFile);
				if(strcmp(pesel,sample)==0){
					f=0;
					break;
				}
			}
		}
		free(pesel);	
		fclose(pFile);
		return f;
}

void znajdz_pacjenta(){
	char sample[11],*pesel,*dane_pacjenta;
	pesel=malloc(sizeof(char)*11);
	FILE *pFile;
	int f=0,i,j,length=0;
	size_t size;
	fpos_t last_pesel_char_position;
	do{
		system("cls");
		printf("Podaj pesel szukanego pacjenta:\n");
		scanf("%s",pesel);
		fflush(stdin);
	} while(pesel_approved(pesel)!=1);
	pFile=fopen("pacjenci.txt","r");
	fseek (pFile, 0, SEEK_END);   
	size=ftell(pFile);  
		for(i=0;i<(size-11);i++){		
			fseek(pFile,i,SEEK_SET);
			if((fgetc(pFile)==pesel[0])&&((size-11)>0)){
				fseek(pFile,-1,SEEK_CUR);
				fgets(sample,12,pFile);
				if(strcmp(pesel,sample)==0){
					f=1;
					j=1;
					fgetpos(pFile,&last_pesel_char_position);
					do{
						fsetpos(pFile,&last_pesel_char_position);
						fseek(pFile,j,SEEK_CUR);
						printf("%i - %c\n",j,fgetc(pFile));
						j++;
					}while(fgetc(pFile)!='\n');
					length=j;
					j=1;
					do{
						fsetpos(pFile,&last_pesel_char_position);
						fseek(pFile,-j,SEEK_CUR);
						j++;
					} while(fgetc(pFile)!='\n');
					length=length+j;
					dane_pacjenta=malloc(sizeof(char)*length+1);
					fgets(dane_pacjenta,length,pFile);
					system("cls");
					printf("Znalazlem!\n\n%s\n",dane_pacjenta);
					break;
				}
			}
		}
	free(pesel);
	if (f!=1){
		printf("Nie ma takiego pacjenta.\n");
	}
	fclose(pFile);
	system("pause");
}
int main() {
    int i,czy_wprowadzono=0;
	char check;   
    struct pacjent wpis[MAKS];
    fprintf(fopen("pacjenci.txt","a"),"\n");
    do {
    	do {
    		system("cls");
		    printf("Wybierz opcje: ");
   			printf("\n1)Wprowadz pacjenta");
   			printf("\n2)Zapisz pacjenta");
   			printf("\n3)Znajdz pacjenta");
   		 	printf("\nq)Zakoncz\n");
    		scanf("%c", &check);
    		fflush(stdin);
    	} while ((check!='q')&&(check!='1')&&(check!='2')&&(check!='3'));
    	switch (check) {
             case '1':{
                  wprowadz_pacjenta(wpis);
                  czy_wprowadzono=1;
                  break;
            }
            case '2':{
            	if(czy_wprowadzono!=1){
            		printf("Nie ma czego zapisac!\n");
            		
            	} else {
            		if (czy_mozna_zapisac(wpis)!=1){
            			printf("Wprowadzony pacjent jest juz zapisany!\n");
            		} else {
            			zapisz_pacjenta(wpis);
            			printf("Zapisano pomyslnie\n");
            		}
            	}
            		system("pause");
            	break;
            }
            case '3':{
                 znajdz_pacjenta();
                  break;
            }
             case 'q':{
             	break;
            }
			default:{
				   printf("Cos nie pyklo");	
				   break;
			}
    	}
    	fflush(stdin);
            
	} while (check!='q');    
}
