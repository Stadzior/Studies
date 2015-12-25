#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void copy(char *from,char *to){
	FILE *pFile=fopen(from,"r"),*pFile2=fopen(to,"w");
	int rozmiar=0;
	do{
		fseek(pFile,rozmiar,SEEK_SET);
		rozmiar++;
	}while(fgetc(pFile)!=EOF);
	int i=1;
	do{
	fseek(pFile,-i,SEEK_END);
	fputc(fgetc(pFile),pFile2);
	i++;
} while(i<rozmiar);
fclose(pFile);
}
int main(int argc, char *argv[]) {
	char from[300],to[300];
	scanf("%s\n%s",&from,&to);
	copy(from,to);
	return 0;
}
