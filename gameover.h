#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gameover() 
{
  FILE * fp;
      fp = fopen("Gameover.txt" , "r") ;


    if (fp==NULL){
      printf("Erreur de pointeur\n");
      return 1 ;
       }
    char c = fgetc(fp) ;// permet de deplacer le cursor d'un caractere
     while (c != EOF){
       Color(11,0);
       printf("%c",c);
      c = fgetc(fp);
    }
}
