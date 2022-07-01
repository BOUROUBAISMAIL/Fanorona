#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define HAUTEUR 5
#define LARGEUR 9



deplacement* recherche_p(int joueur_courant, int plateau[HAUTEUR][LARGEUR])
{
    int percussion_possible;
    int aspiration_possible;
    int occupe, testdep;
    deplacement *d= malloc(sizeof(deplacement));

    for (int i=0; i<HAUTEUR; i++)
    {
        for(int j=0; j<LARGEUR; j++)
        {
            if (plateau[i][j]==joueur_courant)
            {
                (*d).pos_i.lig=i;
                (*d).pos_i.col=j;
                d=position_suivante(d, 0);    //simule position suivante nord
                occupe=position_non_vide(d, plateau);             //case occupée ?
                testdep=deplacement_allouer(d, plateau, 0);	//deplacement valide ?
                if(occupe==1 && testdep==1) 				//case vide + deplacement valide
                {
                    percussion_possible=detect_percussion(d, 0, plateau, joueur_courant);  // detection approche
                    aspiration_possible= detect_aspiration(d, 0, plateau, joueur_courant);  // detection retrait
                    if(percussion_possible==1 || aspiration_possible==1) 	//  une des captures possibles détectée
                    {


                        return d;
                    }
                }

                d=position_suivante(d, 1);    // simule position suivante sud
                occupe=position_non_vide(d, plateau);
                testdep=deplacement_allouer(d, plateau, 1);
                if(occupe==1 && testdep==1)
                {

                    percussion_possible=detect_percussion(d, 1, plateau, joueur_courant);
                    aspiration_possible= detect_aspiration(d, 1, plateau, joueur_courant);
                    if(percussion_possible==1 || aspiration_possible==1)
                    {

                        return d;
                    }
                }

                d=position_suivante(d, 2);    // simule position suivante est
                occupe=position_non_vide(d, plateau);
                testdep=deplacement_allouer(d, plateau, 2);
                if(occupe==1 && testdep==1)
                {
                    percussion_possible=detect_percussion(d, 2, plateau, joueur_courant);
                    aspiration_possible= detect_aspiration(d, 2, plateau, joueur_courant);
                    if(percussion_possible==1 || aspiration_possible==1)
                    {

                        return d;
                    }
                }


                d=position_suivante(d, 3);    //simule position suivante ouest
                occupe=position_non_vide(d, plateau);
                testdep=deplacement_allouer(d, plateau, 3);
                if(occupe==1 && testdep==1)
                {

                    percussion_possible=detect_percussion(d, 3, plateau, joueur_courant);
                    aspiration_possible=detect_aspiration(d, 3, plateau, joueur_courant);
                    if(percussion_possible==1 || aspiration_possible==1)
                    {

                        return d;
                    }
                }


                d=position_suivante(d, 4);   //simule position suivante Nord-est
                occupe=position_non_vide(d, plateau);
                testdep=deplacement_allouer(d, plateau, 4);
                if(occupe==1 && testdep==1)
                {
                    percussion_possible=detect_percussion(d, 4, plateau, joueur_courant);
                    aspiration_possible=detect_aspiration(d, 4, plateau, joueur_courant);
                    if(percussion_possible==1 || aspiration_possible==1)
                    {

                        return d;
                    }
                }


                d=position_suivante(d, 5);   //simule position suivante Nord-ouest
                occupe=position_non_vide(d, plateau);
                testdep=deplacement_allouer(d, plateau, 5);
                if(occupe==1 && testdep==1)
                {
                    percussion_possible=detect_percussion(d, 5, plateau, joueur_courant);
                    aspiration_possible=detect_aspiration(d, 5, plateau, joueur_courant);
                    if(percussion_possible==1 || aspiration_possible==1)
                    {

                        return d;
                    }
                }

                d=position_suivante(d, 6);  //simule position suivante Sud-est
                occupe=position_non_vide(d, plateau);
                testdep=deplacement_allouer(d, plateau, 6);
                if(occupe==1 && testdep==1)
                {
                    percussion_possible=detect_percussion(d, 6, plateau, joueur_courant);
                    aspiration_possible=detect_aspiration(d, 6, plateau, joueur_courant);
                    if(percussion_possible==1 || aspiration_possible==1)
                    {

                        return d;
                    }
                }

                d=position_suivante(d, 7);  //simule position suivante Sud-ouest
                occupe=position_non_vide(d, plateau);
                testdep=deplacement_allouer(d, plateau, 7);
                if(occupe==1 && testdep==1)
                {
                    percussion_possible=detect_percussion(d, 7, plateau, joueur_courant);
                    aspiration_possible=detect_aspiration(d, 7, plateau, joueur_courant);
                    if(percussion_possible==1|| aspiration_possible==1)
                    {

                        return d;
                    }
                }

            }
        }
    }
    //pas de capture possible
    for (int i=0; i<HAUTEUR; i++)
    {
        for(int j=0; j<LARGEUR; j++)
        {
            if (plateau[i][j]==joueur_courant)
            {
                for(int dire=0; dire<8; dire++)
                {
                    d=position_suivante(d,dire);
                    occupe=position_non_vide(d, plateau);
                    testdep=deplacement_allouer(d, plateau, 1);
                    if(occupe==1 && testdep==1)
                    {
                        return d ;
                    }
                }
            }
        }
    }
}
