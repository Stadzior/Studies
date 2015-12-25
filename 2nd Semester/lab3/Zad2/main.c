#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main ()
{
  FILE * pFile;
  int n = 0;
  char sciezka[200];
  scanf("%s",&sciezka);
  pFile = fopen (sciezka,"r");
  if (pFile==NULL) perror ("\nNie udalo sie otworzyc pliku.");
  else
  {
    while (fgetc(pFile) != EOF) {
      ++n;
    }
    float m = n;
    if (feof(pFile)) {
      printf ("\nRozmiar pliku: %.3f kb\n", m/1000);
    }
    else printf("\nDostalem sie do pliku ale cos poszlo nie tak");
    fclose (pFile);
  }
  return 0;
}
