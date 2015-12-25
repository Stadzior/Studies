#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int intWrt00=0,intWrt01=0,intWrt02=0,intWrt03=0,intWrt04=0,i,j,intTab[5],*pInt;
	for (i=0;i<5;i++){
		intTab[i]=0;
	}
	pInt=&intWrt00;
	*pInt=10;
	pInt=&intWrt01;
	*pInt=11;
	pInt=&intWrt02;
	*pInt=12;
	pInt=&intWrt03;
	*pInt=13;
	pInt=&intWrt04;
	*pInt=14;
	for(i=0,j=110;i<5,j<115;i++,j++){
	pInt=intTab;
	*(pInt+i)=j;
	}
	printf("intWrt00=%i   intWrt01=%i   intWrt02=%i   intWrt03=%i   intWrt04=%i\n",intWrt00,intWrt01,intWrt02,intWrt03,intWrt04);
	for(i=0;i<5;i++){
		printf("%i |  ",intTab[i]);
	}
	printf("\n%i",sizeof(*pInt));
	return 0;
}
    /* *pInt - Wartosc wyluskana spod adresu na który wskazuje wskaŸnik pInt
        pInt - adres komórki pamiêci, na który wskazuje pInt
        &pInt - adres wskaŸnika pInt
        *(pInt+i)=(110+i) - przypisanie wartosci i-temu elementowi tablicy intTab za pomoc¹ operatora wy³uskania i wskaŸnika pInt 
		(pInt+i) - adres i-tego elementu tablicy intTab, zapisany za pomoca wskaŸnika pInt
		&pInt+i - adres elementu poprzedzajacego i-ty element tablicy 
		*/
