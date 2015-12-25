#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char text[500],sciezka[200];	
	scanf("%s",&sciezka);
	fgets(text,500,fopen(sciezka,"r"));
	printf("%s",text);
	return 0;
}
