#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void kopiuj(char *cel,char *zrodlo){
int i=0;
for (i=0;i<strlen(zrodlo);i++){
	*(cel+i)=*(zrodlo+i);	
}	
}
int main(int argc, char *argv[]) {
	char *zrodlo="randomowy tekst",*cel;
	cel=malloc(sizeof(char)*strlen(zrodlo));
	kopiuj(cel,zrodlo);
	printf("Pierwotny string: %s\nSkopiowany string: %s",zrodlo,cel);
	return 0;
}
