#include <stdio.h>
#include <stdlib.h>
#define HAUTEUR 5
#define LARGEUR 9
//========================== POUR CONTROLER LES AUTORISATIONS DE DEPLACEMENT HD HG BD BG =================================
int deplacement_allouer(deplacement* d, int plateau_jeu[HAUTEUR][LARGEUR], enum direction dir )
{
    if (((((*d).pos_i.col)+ ((*d).pos_i.lig))%2!=0) && ((dir == BAS_DROITE) || ( dir == HAUT_DROITE ) || (dir==BAS_GAUCHE) || (dir==HAUT_GAUCHE)))
    {
        return 0 ;
    }
    else
    {
        return 1 ;
    }
}
