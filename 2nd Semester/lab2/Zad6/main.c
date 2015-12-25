#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int dlugosc(char *napis){
	int i=0;
	do{
		i++;
	}while(napis[i]!=NULL);
	return i;
}
int main(int argc, char *argv[]) {
	char napis[50];
	printf("Napisz cos:\n");
	scanf("%s",napis);
	fflush(stdin);
	printf("\nDlugosc lancucha wedlug mojej funkcji:%i\nDlugosc lancucha wedlug strlen:%i",dlugosc(napis),strlen(napis));
	return 0;
}
