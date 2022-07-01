#include <stdio.h>
#include <stdlib.h>

#define HAUTEUR 5
#define LARGEUR 9
#define VIDE 0

void prise_pions_aspiration(plateau_jeu* jeu, deplacement*d, enum direction dir, int joueur_courant)
{
    //Capture des pions par retrait
    int diropp;
    deplacement*dopp=malloc(sizeof(deplacement));
    (*dopp).pos_i.lig = (*d).pos_i.lig ;//il rest a la position initial car si on veut monger par retour la position initial pour monger ca vat commencer par la pos_i cuz il monge se qui est devant lui
    (*dopp).pos_i.col = (*d).pos_i.col ;
    diropp=direction_inverse(dir);//il vat monger ce que devant lui donc il faut avoir la dir forward
    dopp=position_suivante(dopp,diropp);
    while ((*jeu).plateau[(*dopp).pos_f.lig ][(*dopp).pos_f.col]!=VIDE &&
           (*jeu).plateau[(*dopp).pos_f.lig ][(*dopp).pos_f.col]!=joueur_courant &&
            (*dopp).pos_f.lig >= 0  && (*dopp).pos_f.lig < HAUTEUR && (*dopp).pos_f.col >= 0 && (*dopp).pos_f.col < LARGEUR)
    {

        (*jeu).plateau[(*dopp).pos_f.lig][(*dopp).pos_f.col]=VIDE ;
        (*dopp).pos_i.lig = (*dopp).pos_f.lig ;
        (*dopp).pos_i.col = (*dopp).pos_f.col ;
        dopp=position_suivante(dopp,diropp);
        if (((*dopp).pos_f.lig <0 )|| ((*dopp).pos_f.lig >= HAUTEUR )||  ((*dopp).pos_f.col<0 )|| ((*dopp).pos_f.col >= LARGEUR) )
        {
            break;
        }

    }
}

