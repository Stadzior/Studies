#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int lower(char *tab){
	int i,j=0;
	for(i=0;i<strlen(tab);i++){                 //Funkcja lower zliczaj¹ca ma³e litery stringów.
		if(islower(tab[i])){
			j++;	
		}
	}
	return j;
}
int check (char *tab){
		int i,f=1;
	for(i=0;i<strlen(tab);i++){
		if(!(isalpha(tab[i]))){	                   //funkcja check , która sprawdza znak po znaku czy       
		f=0;                                       //u¿ytkownik przypadkiem nie wpisa³ czegos zlosliwego
		}
	}
	return f;
}
void sort(int (*tab2)[2],char (*tab)[30]){
	int i,j,s;
	char tab3[10][30];
	for (i=0;i<10;i++){
		for(j=0;j<10;j++){                              //sortowanie przez wybor indeksow naszych napisow
			if (tab2[i][1]>tab2[j][1]){
				s=tab2[j][1];
				tab2[j][1]=tab2[i][1];
				tab2[i][1]=s;
				s=tab2[j][0];
				tab2[j][0]=tab2[i][0];
				tab2[i][0]=s;
			}
		}
	}		
	for (i=0;i<10;i++){
		strcpy(tab3[i],tab[tab2[i][0]]);                  //Kopiowanie stringow z tab2 do lokalnej tab3 ju¿
	}                                                     //w odpowiedniej kolejnosci a nastepnie zapisanie
	for (i=0;i<10;i++){                                   //ich spowrotem do tab2.
		strcpy(tab[i],tab3[i]);
	}
}
void printtab(char (*tab)[30]){
	system("cls");
	int i;
	for (i=0;i<10;i++){                             //funkcja printtab wyswietlajaca posortowana tablice
		printf("%s\n",tab[i]);
	}
}
int main(int argc, char *argv[]) {
	int i,j,f;
	char tab[10][30];
	int tab2[10][2];
	printf("Wprowadz napisy potwierdzajac kazdy enterem\n(Wpisane cyfr badz znakow specjalnych nie jest akceptowane!).\n\n");
	for (i=0;i<10;i++){
		j=0;
		do{
			if (j>0){
				printf("Wpisuj tylko litery alfabetu!\n");
			}
			printf("Podaj %i element:\n",i);
			scanf("%s",&tab[i]);
			fflush(stdin);
			system("cls");
			j++;
		}while(check(*(tab+i))==0);	
		tab2[i][0]=i;
		tab2[i][1]=lower(*(tab+i));
	}
	sort(tab2,tab);
	printtab(tab);
	return 0;
}
