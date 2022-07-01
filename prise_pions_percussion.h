#include <stdio.h>
#include <stdlib.h>

#define HAUTEUR 5
#define LARGEUR 9
#define VIDE 0

void prise_pions_percussion(plateau_jeu* jeu, deplacement*d, enum direction dir, int joueur_courant)    // Capture des pions par approche
{
    deplacement *dsuiv=malloc(sizeof(deplacement));
    (*dsuiv). pos_i.lig = (*d).pos_f.lig ;
    (*dsuiv). pos_i.col = (*d).pos_f.col ; // dsuiv
    dsuiv=position_suivante(dsuiv,dir);
    while ((*jeu).plateau[(*dsuiv).pos_f.lig ][(*dsuiv).pos_f.col]!=VIDE &&
           (*jeu).plateau[(*dsuiv).pos_f.lig ][(*dsuiv).pos_f.col]!=joueur_courant &&
            (*dsuiv).pos_f.lig >= 0 && (*dsuiv).pos_f.lig < HAUTEUR && (*dsuiv).pos_f.col >= 0 && (*dsuiv).pos_f.col < LARGEUR)
    {
        (*jeu).plateau[(*dsuiv).pos_f.lig][(*dsuiv).pos_f.col]=VIDE ;
        (*dsuiv).pos_i.lig = (*dsuiv).pos_f.lig ;
        (*dsuiv).pos_i.col = (*dsuiv).pos_f.col ;
        dsuiv=position_suivante(dsuiv,dir); //pour que la postion final soit la position initiales de la prochaine déplacement
        if (((*dsuiv).pos_f.lig <0 )|| ((*dsuiv).pos_f.lig >= HAUTEUR )||  ((*dsuiv).pos_f.col<0 )|| ((*dsuiv).pos_f.col >= LARGEUR) )
        {
            break;   //si les condition precédent ne sont pas réaliser on a un break
        }

    }
}