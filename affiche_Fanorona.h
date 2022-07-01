#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void affiche_Fanorona(){

     FILE * fp; // declaration d'un pointeur  sur un objet de type file == pointeur fichier
    fp = fopen("Fanorona.txt" , "r") ; // mode lecture

    if (fp==NULL){
      printf("Erreur de pointeur\n");
      return 1 ;
       }
    char c = fgetc(fp) ;// permet de deplacer le cursor d'un caractere
    Color(11,0);
    while (c != EOF){
       printf("%c",c);
      c = fgetc(fp);
    }

}
