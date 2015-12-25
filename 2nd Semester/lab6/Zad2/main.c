#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int czy_calkowite(char *ROZMIARs){
	int f=1,i;
	for (i=0;i<strlen(ROZMIARs);i++){
		if(!(isdigit(ROZMIARs[i]))){
			f=0;
		}
	}
	return f;	
}
void scal(int *tab,int head,int srodek,int tail){
    int i=head,j=srodek+1,t=0,tmp[200],k=0,tmp2=srodek-head+tail-(srodek+1)+2;

	while(i<=srodek && j<=tail){
    if(tab[i]<tab[j]){
          tmp[t++]=tab[i++];
        }
		else{
           tmp[t++]=tab[j++];
        }
}
if(i<=srodek){
    while(i<=srodek)   {
        tmp[t++]=tab[i++];
    }
}
else{
    while(j<=tail){
           tmp[t++]=tab[j++];

    }
}
for(t=0;t<tmp2;t++){
  	 	 tab[head++]=tmp[t];
	}	
	printf("\n");
}
void sortowanie(int tab[],int head,int tail){
    int srodek,i;
    if(head<tail){
    	srodek=(head+tail)/2;
    	sortowanie(tab,head,srodek);
    	sortowanie(tab,srodek+1,tail);
    	scal(tab,head,srodek,tail);
 }
}
int main(int argc, char *argv[]) {
	int i;
	size_t ROZMIAR;
	char ROZMIARs[3];
	srand(time(NULL));
	do{
		system("cls");
		printf("Podaj liczbe elementow w sortowanym zbiorze:\n");
		scanf("%s",ROZMIARs);
		fflush(stdin);
	} while (czy_calkowite(ROZMIARs)==0);
	ROZMIAR=atoi(ROZMIARs);
	int tab[ROZMIAR];
	int head=0,tail=ROZMIAR;
	printf("Zbior wyjsciowy: ");
	for (i=0;i<ROZMIAR;i++){
		tab[i]=rand()%10;
		printf("%i ",tab[i]);
	}
	printf("\n\n");
	sortowanie(tab,head,tail-1);
	printf("\n\n");
	printf("\nZbior posortowany: ");
	for (i=0;i<ROZMIAR;i++){
		printf("%i ",tab[i]);
	}
	return 0;
}
