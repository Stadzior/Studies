#include <stdio.h>
#include <stdlib.h>
#define N 50
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int dd_test (int n, float(*A)[N]) {
int f=1,i,j;
float suma=0;
for (i=0;i<N;i++){
	for(j=0;j<N;j++){
		suma=suma+abs(A[i][j]);
	}
	if ((abs(A[i][i]))<suma){
		f=0;
		break;
	}
	suma=0;
}
return f;
}
int main(int argc, char *argv[]) {
	float A[N][N];
	int i,j;
	srand(time(NULL));
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			A[i][j]=(rand()%31)-10;
		}
	}
	printf("%i",dd_test(N,A));
	return 0;
}
