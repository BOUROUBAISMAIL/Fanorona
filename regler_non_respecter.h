#include <stdio.h>
#include <stdlib.h>


void regler_non_respecter(int testdep, int occupe, int bon_pion,int capture_poss)
{
    //Affichage des messages d'erreurs en fonction des différents tests de deplacement
    if (testdep==0)
    {
        printf("\n*********************************************************************************************************** \n");
        printf("\n DEPLACEMENT IMPOSSIBLE : Vous ne pouvez pas effectuer de mouvement en diagonale a partir de cette case \n");
        printf("\n*********************************************************************************************************** \n");
    }
    else if (occupe==0)
    {
        printf("\n*********************************************************************************************************** \n");
        printf("\n DEPLACEMENT IMPOSSIBLE : La case d'arrivee de votre pion n'est pas vide ou le coup effectuee sort du plateau \n");
        printf("\n*********************************************************************************************************** \n");
    }
    else if (bon_pion==0)
    {
        printf("\n************************************************************************************************************ \n");
        printf("\n ATTENTION : Vous ne pouvez pas jouer avec un pion adverse \n");
        printf("\n************************************************************************************************************ \n");
    }
    else if (capture_poss==1)
    {
        printf("\n************************************************************************************************************ \n");
        printf("\n ATTENTION : Une capture est possible dans le jeu. Veuillez en effectuer une. \n");
        printf("\n************************************************************************************************************ \n");


    }
}