
#include <stdio.h>
#include <stdlib.h>
#define HAUTEUR 5
#define LARGEUR 9
#define JAUNE 1


int nb_pions_joueur1(int plateau_jeu[HAUTEUR][LARGEUR])     //Calcul du nombre de pions JAUNE dans le plateau
{
    int i, j;
    int nbr_p_j1 = 0 ;
    for (i=0; i<HAUTEUR; i++)
    {
        for (j=0; j<LARGEUR; j++)
        {
            if (plateau_jeu[i][j] == JAUNE) nbr_p_j1++ ;
        }
    }

    return( nbr_p_j1);
}
