#include <stdio.h>
#include <stdlib.h>
#define HAUTEUR 5
#define LARGEUR 9
#define BLEU_FLUO 2



int nb_pions_joueur2(int plateau_jeu[HAUTEUR][LARGEUR])     //Calcul du nombre de pions BLEU_FLUO dans le plateau
{
    int i, j ;
    int nbr_p_j2 = 0 ;
    for (i=0; i<HAUTEUR; i++)
    {
        for (j=0; j<LARGEUR; j++)
        {
            if (plateau_jeu[i][j] == BLEU_FLUO)
            {
                nbr_p_j2++;
            }
        }
    }

    return( nbr_p_j2);
}
