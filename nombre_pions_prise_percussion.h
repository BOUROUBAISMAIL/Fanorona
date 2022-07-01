
#include <stdio.h>
#include <stdlib.h>
#define HAUTEUR 5
#define LARGEUR 9
#define VIDE 0


int nombre_pions_prise_percussion(plateau_jeu* jeu, deplacement*d, enum direction dir, int joueur_courant)    // Capture des pions par approche
{
    int nombre_pion_manges=0;
    deplacement *dsuiv=malloc(sizeof(deplacement));
    (*dsuiv).pos_i.lig =(*d).pos_f.lig ;
    (*dsuiv).pos_i.col =(*d).pos_f.col ; // dsuiv
    dsuiv=position_suivante(dsuiv,dir);
    while ((*jeu).plateau[(*dsuiv).pos_f.lig ][(*dsuiv).pos_f.col]!=VIDE && (*jeu).plateau[(*dsuiv).pos_f.lig ][(*dsuiv).pos_f.col]!=joueur_courant && (*dsuiv).pos_f.lig >= 0 && (*dsuiv).pos_f.lig < HAUTEUR && dsuiv->pos_f.col >= 0 && dsuiv->pos_f.col < LARGEUR)
    {
        nombre_pion_manges++;
        (*dsuiv).pos_i.lig =(*dsuiv).pos_f.lig ;
        (*dsuiv).pos_i.col =(*dsuiv).pos_f.col ;
        dsuiv=position_suivante(dsuiv,dir); //pour que la postion final soit la position initiales de la prochaine déplacement
        if (((*dsuiv).pos_f.lig <0 )|| ((*dsuiv).pos_f.lig >= HAUTEUR )||  ((*dsuiv).pos_f.col<0 )|| ((*dsuiv).pos_f.col >= LARGEUR) )
        {
            break;   //si les condition precédent ne sont pas réaliser on a un break
        }

    }
    return nombre_pion_manges;
}