#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	size_t n,rozmiar;
	int i,j=0,k,suma=0;
	char temp[0];
	FILE *pFile=fopen("wej.txt","r");
	fseek (pFile , 0 , SEEK_END);
    rozmiar = (ftell (pFile));
    n=rozmiar/2;                             //Nie zrozumia³em sk¹d to n ma siê braæ wiêc wybra³em takie
    rewind (pFile);
	for (i=0;i<rozmiar;i++){
		temp[0]=fgetc(pFile);
		if (isdigit(temp[0])){
			k=atoi(temp);
			if(k>0){
				suma=suma+k;
				j++;
			}
		}
		if (j>=n){
			break;
		}
	}
		if (j<n){
		suma=-1;	
		}
	pFile=fopen("wyj.txt","w");
	fprintf(pFile,"%i",suma);
	return 0;
}
