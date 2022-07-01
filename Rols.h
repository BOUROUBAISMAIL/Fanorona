#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void Rols()// affichage des regles du jeu qui se trouve dans le fichier Rlos.txt
{
    system("cls");

    //lecture du fichier des regles
    FILE * fp;
    fp = fopen("Rlos.txt" , "r") ;

    if (fp==NULL){
      printf("Erreur de pointeur\n");
      return 1 ;
       }
    char c = fgetc(fp) ;// permet de deplacer le cursor d'un caractere
     while (c != EOF){
       printf("%c",c);
      c = fgetc(fp);
    }
    // pour revenir au menu principale
    printf("\n   Si vous voulez revenir au menu principale tape 1 :");
    int revenir;
    do {
    scanf("%d",&revenir);
    }while (revenir!=1);
    main();// menu principale

}
