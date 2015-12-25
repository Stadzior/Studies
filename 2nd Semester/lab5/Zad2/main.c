#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAKS 5
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct wpis{
	char nazwisko[30];
	int kierunkowy;
	char numer[7];
};

int main(int argc, char *argv[]) {
	int i;
	struct wpis ksiazka[MAKS];
	FILE *pFile=fopen("ksiazka.txt","a");
	for (i=0;i<MAKS;i++){
		system("cls");
		printf("Podaj %i nazwisko ,numer kierunkowy(bez zera) i numer telefonu zatwierdzajac enterem:\n",i+1);
		scanf("%s\n%i\n%s",ksiazka[i].nazwisko,&ksiazka[i].kierunkowy,ksiazka[i].numer);
		fprintf(pFile,"\n%s\t\t%i\t\t%s",ksiazka[i].nazwisko,ksiazka[i].kierunkowy,ksiazka[i].numer);
	}
	fclose(pFile);
	return 0;
}
