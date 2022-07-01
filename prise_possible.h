
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HAUTEUR 5
#define LARGEUR 9




int prise_possible(int joueur_courant, int plateau[HAUTEUR][LARGEUR])
{//detection de prise possible par approche ou par retrait pour un joueur donnée 
    deplacement *d= malloc(sizeof(deplacement));
    int percussion_possible;
    int aspiration_possible;
    int occupe, testdep;
    int i, j;
    for (i=0; i<HAUTEUR; i++)
    {
        for(j=0; j<LARGEUR; j++)
        {
            if (plateau[i][j]==joueur_courant)
            {
                (*d).pos_i.lig=i;
                (*d).pos_i.col=j;
                d=position_suivante(d, 0);    //simule position suivante HAUT
                occupe=position_non_vide(d, plateau);             //case occupée ?
                testdep=deplacement_allouer(d, plateau, 0);  //deplacement valide ?
                if(occupe==1 && testdep==1)         //case vide + deplacement valide
                {
                    percussion_possible=detect_percussion(d, 0, plateau, joueur_courant);  // detection percusion
                    aspiration_possible= detect_aspiration(d, 0, plateau, joueur_courant);  // detection aspiration
                    if(percussion_possible==1 || aspiration_possible==1)       //  une des captures possibles détectée
                    {
                        return 1;
                    }
                }

                d=position_suivante(d, 1);    // simule position suivante BAS
                occupe=position_non_vide(d, plateau);
                testdep=deplacement_allouer(d, plateau, 1);
                if(occupe==1 && testdep==1)
                {
                    d=position_suivante(d, 1);
                    percussion_possible=detect_percussion(d, 1, plateau, joueur_courant);
                    aspiration_possible= detect_aspiration(d, 1, plateau, joueur_courant);
                    if(percussion_possible==1 || aspiration_possible==1)
                    {
                        return 1;
                    }
                }

                d=position_suivante(d, 2);    // simule position suivante DROITE
                occupe=position_non_vide(d, plateau);
                testdep=deplacement_allouer(d, plateau, 2);
                if(occupe==1 && testdep==1)
                {
                    percussion_possible=detect_percussion(d, 2, plateau, joueur_courant);
                    aspiration_possible= detect_aspiration(d, 2, plateau, joueur_courant);
                     if(percussion_possible==1 || aspiration_possible==1)
                    {
                        return 1;
                    }
                }

                d=position_suivante(d, 3);    //simule position suivante GOUCHE
                occupe=position_non_vide(d, plateau);
                if(occupe==1 && testdep==1)
                {
                    testdep=deplacement_allouer(d, plateau, 3);
                    percussion_possible=detect_percussion(d, 3, plateau, joueur_courant);
                    aspiration_possible= detect_aspiration(d, 3, plateau, joueur_courant);
                    if(percussion_possible==1 || aspiration_possible==1)
                    {
                        return 1;
                    }
                }

                d=position_suivante(d, 4);   //simule position suivante HAUT_DROITE
                occupe=position_non_vide(d, plateau);
                testdep=deplacement_allouer(d, plateau, 4);
                if(occupe==1 && testdep==1)
                {
                    percussion_possible=detect_percussion(d, 4, plateau, joueur_courant);
                    aspiration_possible= detect_aspiration(d, 4, plateau, joueur_courant);
                    if(percussion_possible==1 || aspiration_possible==1)
                    {
                        return 1;
                    }
                }

                d=position_suivante(d, 5);   //simule position suivante HAUT_GOUCHE
                occupe=position_non_vide(d, plateau);
                testdep=deplacement_allouer(d, plateau, 5);
                if(occupe==1 && testdep==1)
                {
                    percussion_possible=detect_percussion(d, 5, plateau, joueur_courant);
                    aspiration_possible= detect_aspiration(d, 5, plateau, joueur_courant);
                    if(percussion_possible==1 || aspiration_possible==1)
                    {
                        return 1;
                    }
                }

                d=position_suivante(d, 6);  //simule position suivante BAS_DROITE
                occupe=position_non_vide(d, plateau);
                testdep=deplacement_allouer(d, plateau, 6);
                if(occupe==1 && testdep==1)
                {
                    percussion_possible=detect_percussion(d, 6, plateau, joueur_courant);
                    aspiration_possible= detect_aspiration(d, 6, plateau, joueur_courant);
                    if(percussion_possible==1 || aspiration_possible==1)
                    {
                        return 1;
                    }
                }

                d=position_suivante(d, 7);  //simule position suivante BAS_GOUCHE
                occupe=position_non_vide(d, plateau);
                testdep=deplacement_allouer(d, plateau, 7);
                if(occupe==1 && testdep==1)
                {
                    percussion_possible=detect_percussion(d, 7, plateau, joueur_courant);
                    aspiration_possible= detect_aspiration(d, 7, plateau, joueur_courant);
                    if(percussion_possible==1 || aspiration_possible==1)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
