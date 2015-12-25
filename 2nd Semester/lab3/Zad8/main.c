#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void zapisz(int size,float *tab){
	int i;
	FILE *pFile=fopen("wyniki.txt","w");
	for(i=0;i<=size;i++){
		fprintf(pFile,"%.0f\t\t%.2f\n",tab[i],tab[i+size+1]);
	}
}
int main(int argc, char *argv[]) {
	int a,b,size,i;
	printf("Podaj granice zakresow (dolny+enter+gorny)\n");
	scanf("%i\n%i",&a,&b);
	fflush(stdin);
	size=b-a;
	float tab[2*size];
	for (i=0;i<=size;i++){
		tab[i]=a;
		if ((a<=-1)||(a>=10)){
			tab[i+size+1]=sqrt((a*a)+5);
		} else { 
				if ((a>-1)&&(a<=0)){
					tab[i+size+1]=2*sin(a);
				} else {
						tab[i+size+1]=((a*a)+3*a)/(float)((a+1)*(a+2));
				}
		} 
		a++;
	}
	zapisz(size,tab);
	return 0;
}
