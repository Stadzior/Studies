#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct student{
	char imie[20];
	char nazwisko[40];
	char indeks[6];
	char kierunek[50];
	char rok[4];
};
void setall(struct student Student[]){
	scanf("%s",Student[0].imie);
	fflush(stdin);
	scanf("%s",Student[0].nazwisko);
	fflush(stdin);
	scanf("%s",Student[0].indeks);
	fflush(stdin);
	scanf("%s",Student[0].kierunek);
	fflush(stdin);
	scanf("%s",Student[0].rok);	
	fflush(stdin);
}
void set(struct student Student[],char *check){
		system("cls");
	switch(check[0]){
		case '1':{
			scanf("%s",Student[0].imie);
			fflush(stdin);
			break;
		}
		case '2':{
			scanf("%s",Student[0].nazwisko);
			fflush(stdin);
			break;
		}
		case '3':{
			scanf("%s",Student[0].indeks);
			fflush(stdin);
			break;
		}
		case '4':{
			scanf("%s",Student[0].kierunek);
			fflush(stdin);
			break;
		}
		case '5':{
			scanf("%s",Student[0].rok);
			fflush(stdin);
			break;
		}
		default :{
			printf("Cusik poszlo nie tak\n");
			fflush(stdin);
			break;
		}
	}
}
void printall(struct student Student[]){
	system("cls");
	printf("%s\n",Student[0].imie);
	printf("%s\n",Student[0].nazwisko);
	printf("%s\n",Student[0].indeks);
	printf("%s\n",Student[0].kierunek);
	printf("%s\n",Student[0].rok);
	system("pause");	
}
void print(struct student Student[],char *check){
	system("cls");
	switch(check[0]){
		case '1':{
			printf("%s",Student[0].imie);
			break;
		}
		case '2':{
			printf("%s",Student[0].nazwisko);
			break;
		}
		case '3':{
			printf("%s",Student[0].indeks);
			break;
		}
		case '4':{
			printf("%s",Student[0].kierunek);
			break;
		}
		case '5':{
			printf("%s",Student[0].rok);
			break;
		}
		default :{
			printf("Cusik poszlo nie tak\n");
			break;
		}
	}
	printf("\n");
	system("pause");
}
int main(int argc, char *argv[]) {
	char check[1];
	struct student Student[0];
	do{
		system("cls");
		printf("Co chcesz zrobic?:\n1)Wypelnij wszystko\n2)Wypelnij wybrane pole\n3)Wydrukuj wszystko\n4)Wydrukuj wybrane pole\nq)Zakoncz\n");
		scanf("%c",&check[0]);
		fflush(stdin);
		switch (check[0]){
			case '1':{
				setall(Student);
				break;
			}
			case '2':{
				do{
				system("cls");
				printf("Które pole Cie interesuje:\n1)imie\n2)nazwisko\n3)indeks\n4)kierunek\n5)rok\nq)powrot do menu glownego...\n");
				scanf("%c",&check[0]);
				fflush(stdin);
				} while ((check[0]!='1')&&(check[0]!='2')&&(check[0]!='3')&&(check[0]!='4')&&(check[0]!='5')&&(check[0]!='q'));
				if (check[0]!='q'){
				set(Student,check);
				}
				check[0]=' ';
				break;
			}
			case '3':{
				printall(Student);
				break;
			}
			case '4':{
				do{
				system("cls");
				printf("Które pole Cie interesuje:\n1)imie\n2)nazwisko\n3)indeks\n4)kierunek\n5)rok\nq)powrot do menu glownego...\n");
				scanf("%c",&check[0]);
				fflush(stdin);
				} while ((check[0]!='1')&&(check[0]!='2')&&(check[0]!='3')&&(check[0]!='4')&&(check[0]!='5')&&(check[0]!='q'));
				if (check[0]!='q'){
				print(Student,check);
				}
				check[0]=' ';
				break;
			}
		} 
	} while (check[0]!='q');
	return 0;
}
