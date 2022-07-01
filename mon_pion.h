#include <stdio.h>
#include <stdlib.h>
#define HAUTEUR 5
#define LARGEUR 9
int mon_pion(deplacement*d, int joueur_courant, int plateau[HAUTEUR][LARGEUR])
 {//Le pion sélectionné est-il celui du joueur courant ?
    if (plateau[(*d).pos_i.lig][(*d).pos_i.col] == joueur_courant) return 1;

    else return 0;
}
