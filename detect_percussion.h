#include <stdio.h>
#include <stdlib.h>
#define VIDE 0
#define HAUTEUR 5
#define LARGEUR 9





int detect_percussion(deplacement*d, enum direction dir, int plateau[HAUTEUR][LARGEUR], int joueur_courant)
{//permet de detecter si on a une percussion pour une position donnée suivant une direction donnée 
    deplacement *dsuiv=malloc(sizeof(deplacement));
    (*dsuiv).pos_i.lig= (*d). pos_f.lig ;
    (*dsuiv).pos_i.col= (*d).pos_f.col;
    dsuiv=position_suivante(dsuiv,dir);                      //simule déplacement dans la même direction
    if ((*dsuiv).pos_f.lig >= 0 && (*dsuiv).pos_f.lig < HAUTEUR && (*dsuiv).pos_f.col >= 0 && (*dsuiv).pos_f.col < LARGEUR)   //controle des extrimité du plateau(ne pas sortir du plateau)
    {
        if(plateau[(*dsuiv).pos_i.lig][(*dsuiv).pos_i.col]==VIDE && plateau[(*dsuiv).pos_f.lig][(*dsuiv).pos_f.col]!=VIDE && plateau[(*dsuiv).pos_f.lig][(*dsuiv).pos_f.col]!=joueur_courant)   // il faut que la position suivant soit vide et la position finale  soit égale à un pion adverse 
        {
            return 1;
        }
        return 0;

    }
    return 0;
}