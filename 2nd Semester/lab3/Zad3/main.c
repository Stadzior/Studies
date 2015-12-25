#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char text[200],text2[1000],from[200],to[200];
	scanf("%s\n%s",&from,&to);
	FILE *pFile=fopen(from,"r");
	do{
	fgets(text,200,pFile);
	strcat(text2,text);	
} while(fgetc(pFile)!=EOF);
fclose(pFile);
pFile=fopen(to,"w");
fputs(text2,pFile);
fclose(pFile);
	return 0;
}
