#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void sort(int *tab){
	int i,j,s;
	for (i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(tab[i]<tab[j]){
				s=tab[j];
				tab[j]=tab[i];
				tab[i]=s;
			}
		}
	}
}
int czy_sort(int *tab){
	int f=1,i=0;
	do{
		if (tab[i]>tab[i+1]){
			f=0;
			break;
		}
		i++;
	}while(i<4);
	return f;
}
void scalaj(int *tab,int *tab2,int *tab3){
	int i,j=0,k=0;
	for (i=0;i<10;i++){
			if ((tab[j]<tab2[k])&&(j<5)){
				tab3[i]=tab[j];
				j++;
			} else {
				if (k<5){
					tab3[i]=tab2[k];
					k++;
				} else {
					tab3[i]=tab[j];
					j++;
				}
			}
	}
}
int main(int argc, char *argv[]) {
	int tab[5],tab2[5],tab3[10],i;
	srand(time(NULL));
	printf("A\tB\n\n");
	for (i=0;i<5;i++){
		tab[i]=rand()%10;
		printf("%i\t",tab[i]);
		tab2[i]=rand()%10;
		printf("%i\n",tab2[i]);
	}
	sort(tab);
	sort(tab2);
	if ((czy_sort(tab)==1)&&(czy_sort(tab2)==1)){	
		printf("\nPosortowane:\n\n");
		for (i=0;i<5;i++){
			printf("%i\t",tab[i]);
			printf("%i\n",tab2[i]);
		}
		printf("\nA+B: ");
		scalaj(tab,tab2,tab3);
		for (i=0;i<10;i++){
			printf("%i ",tab3[i]);
		}
	} else {
		printf("\nZbiory nie posortowaly sie prawidlowo , pardon zelipa pa i skuze mua.");
	}
	return 0;
}
