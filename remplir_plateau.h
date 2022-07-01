#include <stdio.h>
#include <stdlib.h>
#define HAUTEUR 5
#define LARGEUR 9
#define JAUNE 1
#define BLEU_FLUO 2
#define VIDE 0

void remplir_plateau(int plateau[HAUTEUR][LARGEUR])
{//Placer les pions dans le plateau à l'etat initial
    for (int i=0; i<HAUTEUR/2; i++)
    {
        for (int j=0; j<LARGEUR; j++)
        {// remplir les deux premiere lignes et les deux derniere lignes
            plateau[i][j]=JAUNE;//les lignes 0 et 1
            plateau[i+HAUTEUR/2+1][j]=BLEU_FLUO;// les lignes 3 et 4
        }
    }

    //placer les pions de ligne au milieu
    plateau[HAUTEUR/2][(LARGEUR/2)]=VIDE;

    for (int j=0; j<LARGEUR/2; j++)
    {
        if(j%2==0)
        {
            plateau[HAUTEUR/2][j]=JAUNE;
        }
        else
        {
            plateau[HAUTEUR/2][j]=BLEU_FLUO;
        }
        plateau[HAUTEUR/2][j+LARGEUR/2+1]=plateau[HAUTEUR/2][j];
    }
}
