#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void przetworz_dane(char *nazwa,const char *nag1,const char*nag2,float *input,char *output){
int i;
size_t Size,przeczytano;
FILE *pFile = fopen(nazwa,"w");
fprintf(pFile,"%s\n%s",nag1,nag2);
for(i=0;i<10;i++){
	fprintf(pFile,"\n    %i      %.4f     %.4f      %.4f        %.4f",i+1,input[i],input[i+10],input[i+20],input[i+30]);
}
fseek (pFile , 0 , SEEK_END);
  Size = ftell (pFile);
  rewind (pFile);
  fclose(pFile);
  pFile=fopen(nazwa,"r");
przeczytano=fread(output,sizeof(char),Size,pFile);
fclose(pFile);
}
int main(int argc, char *argv[]) {
char nag1[56]="Nr obiektu  Pole      Obwod       Srodek-X     Srodek-Y";
char nag2[54]="   [  ]    [mm2]      [mm]        [mm]           [mm]";
char output[1000];
float input[40];
int i;
srand(time(NULL));
for (i=0;i<40;i++){
	input[i]=(float)(rand()%2000)/10000;
}
przetworz_dane("wyniki.txt",nag1,nag2,input,output);
printf("%s",output);
	return 0;
}
