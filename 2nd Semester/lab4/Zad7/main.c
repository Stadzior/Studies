#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int check(char *string){
	int i,f=1;
	for(i=0;i<strlen(string);i++){
		if(!isdigit(string[i])){
		f=0;	
		}
	}
	return f;
}
int min(int *input,int i,int row,int col){
	int min,j;
	for (j=0;j<row;j++){
		if (j==0){
			min=*(input+i);
		} else {
			if (min>*(input+i+col)){
				min=*(input+i+col);
			}
		}
	}
	return min;
}
int max(int *input,int i,int row,int col){
	int max,j;
		for (j=0;j<row;j++){
		if (j==0){
			max=*(input+i);
		} else {
			if (max<*(input+i+col)){
				max=*(input+i+col);
			}
		}
	}
	return max;
}
int sr(int *input,int i,int row,int col){
	int sr=0,j;
		for (j=0;j<row;j++){
			sr=sr+(*(input+i+(col*j)));
		}
		sr=sr/row;
	return sr;
}
void wypelnij(int *input,int row, int col){
	int i,j=0;
	do{
		for(i=(col*j);i<(col*(j+1));i++){
			*(input+i)=rand()%10;
			printf("%i\t",*(input+i));
		}
		j++;
		printf("\n");
	} while (j<row);
}
void opracuj(int *input,int row,int col){
	int i,j;
	for (i=0;i<col;i++){
		printf("Kolumna %i:\tmin=%i\tmax=%i\tsrednia=%i\t\n",i,min(input,i,row,col),max(input,i,row,col),sr(input,i,row,col));
	}
}
int main(int argc, char *argv[]) {
	srand(time(NULL));
	char rows[20],cols[20];
	int row,col;
	do{
		printf("Podaj liczbe wierszy:\n");
		scanf("%s",rows);
	} while (check(rows)!=1);
	row=atoi(rows);
	do{
		printf("Podaj liczbe kolumn:\n");
		scanf("%s",cols);
	} while (check(cols)!=1);
	col=atoi(cols);
	int *input;
	input=malloc(sizeof(int)*row*col);
	system("cls");
	wypelnij(input,row,col);
	opracuj(input,row,col);
	return 0;
}
