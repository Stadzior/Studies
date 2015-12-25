#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]){
	int i,j,x,y,suma,tab[5][5];
	srand(time(NULL));
for (i=0;i<5;i++){
	for(j=0;j<5;j++){
		tab[i][j]=rand()%10;
		printf("|  %i[%i][%i]  |",tab[i][j],i,j);
	}
	printf("\n");
}
printf("\n\nPodaj (wiersz/kolumne):\n");
scanf("%i,%i",&x,&y);
i=x-1;
j=y-1;
suma=0-tab[i][j];
printf("%i : tab[%i][%i] \n",suma,i,j);
for (i;i>=0;i--){
if (j<=0){
	break;
}
j--;
}
do {
	suma=suma+tab[i][j];
	printf("%i : tab[%i][%i]\n",suma,i,j);
	i++;
	j++;
} while ((i<5)&&(j<5));
i=x-1;
j=y-1;
for (i;i>0;i--){
	if(j>4){
		break;
	}
	j++;
}
do{
	suma=suma+tab[i][j];
	printf("%i : tab[%i][%i]\n",suma,i,j);
	i++;
	j--;
} while ((i<5)&&(j>=0));
printf("\nWynik sumy to: %i",suma);
	return 0;
}
