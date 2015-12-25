#include <stdio.h>
#include <stdlib.h>

int main () {
  FILE *pFile;
  long ROZMIAR;
  char from[200],to[200];
  size_t przeczytane=0;
  char *bufor;
  scanf("%s\n%s",&from,&to);
  pFile = fopen (from , "r" );
  if (pFile==NULL) {
  	system("cls");
  	printf("Nie ma takiego pliku");
  }
  fseek (pFile , 0 , SEEK_END);
  ROZMIAR = ftell (pFile);
  rewind (pFile);
  bufor = malloc (sizeof(char)*ROZMIAR);
  if (bufor == NULL) {
  	system("cls");
  	printf("Cos nie tak z buforem");
  }
  przeczytane=fread (bufor,sizeof(char),ROZMIAR,pFile);
  if (przeczytane != ROZMIAR) {
  printf("Cos nie tak z odczytem");
  }
  
  printf("Przeczytano:%i\n",przeczytane);
  fclose (pFile);
  pFile=fopen(to,"w");
  przeczytane=fwrite(bufor,sizeof(char),ROZMIAR,pFile);
  printf("Zapisano:%i",przeczytane);
  fclose(pFile);
  free (bufor);
  return 0;
}
