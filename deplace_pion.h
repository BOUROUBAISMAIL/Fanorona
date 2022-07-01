#include <stdio.h>
#include <stdlib.h>
#define HAUTEUR 5
#define LARGEUR 9
#define VIDE 0
void deplace_pion(deplacement* d, plateau_jeu* jeu, int joueur_courant)
{
    (*jeu).plateau[(*d).pos_i.lig][(*d).pos_i.col] = VIDE;
    (*jeu).plateau[(*d).pos_f.lig][(*d).pos_f.col] = joueur_courant;
}
