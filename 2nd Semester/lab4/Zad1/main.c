#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int czy_pierwsza(int j){
	int f=1,i;
	for(i=2;i<j;i++){
		if (j%i==0)	{
		f=0;
		}
	}
	return f;
}
int load_size(char *SIZE){
	int i=-1,f=0;
do{
		scanf("%s",SIZE);
		fflush(stdin);
		do{
			i++;
		} while (isdigit(SIZE[i]));
		if(SIZE[i]==NULL){
			f=1;
		}
	} while(f==0);
	return atoi(SIZE);
}
int main(int argc, char *argv[]) {
	int i,j=1,size,size2,x=0;
	char SIZE[20],SIZE2[20];
	size=load_size(SIZE);
	size2=load_size(SIZE2);
	int index1=0,index2=0,*tab;
	tab=malloc(sizeof(int)*size*size2);
	printf("%i\t%i\n\n",size,size2);	
	for(i=0;i<(size*size2);i++){
		index1=i-((size)*x);
		do {
			*(tab+i)=j;
			j++;
		} while(czy_pierwsza(j-1)==0);
		if ((index1%3==0)&&(index2%3==0)){
			printf("%i\t%i\t%i\n",*(tab+i),index1,index2);
		}
		if (((i+1)%(size)==0)&&(i!=0)){
			x++;
			index2++;
		}	
		if(index2>(size2-1)){
			break;
		}	 
	}
	return 0;
}
