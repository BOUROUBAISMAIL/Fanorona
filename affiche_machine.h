#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void affiche_machine(){
    FILE * fp;
    fp = fopen("Play_vs_machine.txt" , "r") ;

    if (fp==NULL){
      printf("Erreur de pointeur\n");
      return 1 ;
       }
    char c = fgetc(fp) ;// permet de deplacer le cursor d'un caractere
     while (c != EOF){
       printf("%c",c);
      c = fgetc(fp);
    }

    }
