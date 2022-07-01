#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void winer(int joueur_courant  ) 
{
  FILE * fp;
  int mode ;
  if (joueur_courant==1){ // joueur 1 gagne 
    fp = fopen("winer1.txt" , "r") ;
  }
  else if (joueur_courant==2) { // joueur 2 gagne 
    fp = fopen("winer2.txt" , "r") ;
  }


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
