#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int znajdz(char *input,char a){
	int position,i;
		for(i=0;i<100;i++){
		if (*(input+i)==a){
			position=i;
		}
	}
	return position;
}
int main(int argc, char *argv[]) {
	char *input,a;
	int i;
	srand(time(NULL));
	input=malloc(sizeof(char)*100);
	printf("Wpisz cos:\n");
	scanf("%s",input);
	fflush(stdin);
	printf("Czego szukamy?\n");
	scanf("%c",&a);
	fflush(stdin);
	printf("Indeks szukanego znaku:%i",znajdz(input,a));
	return 0;
}
