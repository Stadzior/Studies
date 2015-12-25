#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void strswap(char *tab){
	int i,size=strlen(tab)-1;
	char s;
	for(i=0;i<(size/2);i++){
		s=*(tab+i);
		*(tab+i)=*(tab+(size-i));
		*(tab+(size-i))=s;
	}
}
int main(int argc, char *argv[]) {
	char tab[100];
	printf("Wpisz cos:\n");
	scanf("%s",tab);
	strswap(tab);
	printf("%s",tab);
	return 0;
}
