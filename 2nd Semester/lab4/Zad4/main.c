#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int minimum(int *tab,int size){
	int min,i;
	for(i=0;i<size;i++){
		if (i==0){
			min=tab[i];
		} else {
			if (tab[i]<min){
				min=tab[i];
			}
		}
	}
	return min;
}
int main(int argc, char *argv[]) {
	int size=50;
	int tab[size],i;
	srand(time(NULL));
	for(i=0;i<size;i++){
		tab[i]=rand()%101;
	}
	printf("%i",minimum(tab,size));
	return 0;
}
