#include <stdio.h>
#include <stdlib.h>
#define HAUTEUR 5
#define LARGEUR 9
#define VIDE 0

int position_non_vide(deplacement* d, int plateau_jeu[HAUTEUR][LARGEUR])
{
    if (((*d).pos_f.lig > HAUTEUR - 1 || (*d).pos_f.lig < 0) || ((*d).pos_f.col > LARGEUR - 1 || (*d).pos_f.col < 0))
    {
        return 0;
    }
    else if (plateau_jeu[(*d).pos_f.lig][(*d).pos_f.col] != VIDE )
    {
        return 0;
    }
    else
    {
        return 1;
    }
    return 0;
}
