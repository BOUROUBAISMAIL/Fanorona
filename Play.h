#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void Play(){
    mauvais_choix_joueur :
    system("cls");
    affiche_Play();
    int mode ;
    printf("\n\n\n\t\t\t Choisissez un nombre entre  1 et 3 s'il vous plait  : ");
    scanf("%d",&mode);
    switch (mode){
        case 1 :Joueur_Joueur();
         break;
        case 2 :joueurh_vs_machine();
         break;
        case 3 :system("cls");
         main();
         break;
        default : goto mauvais_choix_joueur;
    }




}
