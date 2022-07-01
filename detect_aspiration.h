#include <stdio.h>
#include <stdlib.h>
#define HAUTEUR 5
#define LARGEUR 9
#define VIDE 0



int detect_aspiration(deplacement*d, enum direction dir, int plateau[HAUTEUR][LARGEUR], int joueur_courant)
{//permet de detecter si on a une aspiration pour une position donnée suivant une direction donnée 
    deplacement *dopp=malloc(sizeof(deplacement));
    deplacement *dsui=malloc(sizeof(deplacement));
    (*dopp).pos_i.lig = (*d).pos_i.lig ;
    (*dopp).pos_i.col = (*d).pos_i.col ;
    int diropp=direction_inverse(dir);
    dopp=position_suivante(dopp,diropp); //simule déplacement dans la direction  opposée
    (*dsui).pos_i.lig = (*d).pos_i.lig ;
    (*dsui).pos_i.col = (*d).pos_i.col ;
    position_suivante(dsui,dir);
    if ((*dopp).pos_f.lig >= 0 && (*dopp).pos_f.lig < HAUTEUR && (*dopp).pos_f.col >= 0 && (*dopp).pos_f.col < LARGEUR)
    {
        if(plateau[(*dsui).pos_f.lig][(*dsui).pos_f.col]==VIDE && plateau[(*dopp).pos_f.lig][(*dopp).pos_f.col]!=joueur_courant && plateau[(*dopp).pos_f.lig][(*dopp).pos_f.col]!=VIDE )  // il faut que la position suivante soit vide et la position  finale soit égale à un pion adverse
        {
            return 1;
        }
        return 0;
    }
    return 0;
}