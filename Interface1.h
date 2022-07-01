#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void Interface1(){
    L:
    affiche_Fanorona();
    printf("\n\n\n\t\t Veuillez choisir un nombre pour continuer :  ");
    int choix ;
    scanf("%d",&choix);

    switch(choix){
    case 1:Play();
        break;
    case 2:Rols();
        break;
    case 3:Help();
        break;
    case 4:Exit();
        break;
    default:
        system("cls");
        goto L ;

    }


}