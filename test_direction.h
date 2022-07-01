#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HAUTEUR 5
#define LARGEUR 9
int test_direction(deplacement* dip, int plateau[HAUTEUR][LARGEUR],int joueur_courant,position pos_histor[12],int dir_histor[8] )
{// cette fonction permert de tester si on a une capture possible apres une prise pour un pion donné et de vérifié si la position final suivant
    //une direction n'était pas visité --> on test toutes les directions possible
    deplacement* d=malloc(sizeof(deplacement));
    d->pos_i=dip->pos_i;

    int percusion_possible;
    int aspiration_possible;
    int occupe, testdep;
    int test_historique;

//==============================================================================direction=0
    d=position_suivante(d, 0);    //simule position suivante nord
    occupe=position_non_vide(d, plateau);             //case occupée ?
    testdep=deplacement_allouer(d, plateau, 0);//deplacement valide ?
    test_historique=test_histor(pos_histor,dir_histor,0,d);//position déja parouru ! direction déja utilisé
    if(occupe==1 && testdep==1 && test_historique==1)         //case vide + deplacement valide
    {
        percusion_possible=detect_percussion(d, 0, plateau, joueur_courant);  // detection approche
        aspiration_possible= detect_aspiration(d, 0, plateau, joueur_courant);  // detection retrait
        if(percusion_possible==1 || aspiration_possible==1)      //  une des captures possibles détectée
        {
            return 1;
        }
    }
//==============================================================================direction=1
    d=position_suivante(d, 1);    // simule position suivante sud
    occupe=position_non_vide(d, plateau);
    testdep=deplacement_allouer(d, plateau, 1);
    test_historique=test_histor(pos_histor,dir_histor,1,d);//position déja parouru ! direction déja utilisé
    if(occupe==1 && testdep==1 && test_historique==1)
    {
        d=position_suivante(d, 1);
        percusion_possible=detect_percussion(d, 1, plateau, joueur_courant);
        aspiration_possible= detect_aspiration(d, 1, plateau, joueur_courant);
        if(percusion_possible==1 || aspiration_possible==1)
        {
            return 1;
        }
    }

//==============================================================================direction=2
    d=position_suivante(d, 2);    // simule position suivante est
    occupe=position_non_vide(d, plateau);
    testdep=deplacement_allouer(d, plateau, 2);
    test_historique=test_histor(pos_histor,dir_histor,2,d);//position déja parouru ! direction déja utilisé
    if(occupe==1 && testdep==1 && test_historique==1)
    {
        percusion_possible=detect_percussion(d, 2, plateau, joueur_courant);
        aspiration_possible= detect_aspiration(d, 2, plateau, joueur_courant);
        if(percusion_possible==1 || aspiration_possible==1)
        {
            return 1;
        }
    }
//==============================================================================direction=3
    d=position_suivante(d, 3);    //simule position suivante ouest
    occupe=position_non_vide(d, plateau);
    testdep=deplacement_allouer(d, plateau, 3);
    test_historique=test_histor(pos_histor,dir_histor,3,d);//position déja parouru ! direction déja utilisé
    if(occupe==1 && testdep==1&& test_historique==1)
    {
        percusion_possible=detect_percussion(d, 3, plateau, joueur_courant);
        aspiration_possible= detect_aspiration(d, 3, plateau, joueur_courant);
        if(percusion_possible==1 || aspiration_possible==1)
        {
            return 1;
        }
    }
//==============================================================================direction=4
    d=position_suivante(d, 4);   //simule position suivante Nord-est
    occupe=position_non_vide(d, plateau);
    testdep=deplacement_allouer(d, plateau, 4);
    test_historique=test_histor(pos_histor,dir_histor,4,d);//position déja parouru ! direction déja utilisé
    if(occupe==1 && testdep==1&& test_historique==1)
    {
        percusion_possible=detect_percussion(d, 4, plateau, joueur_courant);
        aspiration_possible= detect_aspiration(d, 4, plateau, joueur_courant);
        if(percusion_possible==1 || aspiration_possible==1)
        {
            return 1;
        }
    }
//==============================================================================direction=5
    d=position_suivante(d, 5);   //simule position suivante Nord-ouest
    occupe=position_non_vide(d, plateau);
    testdep=deplacement_allouer(d, plateau, 5);
    test_historique=test_histor(pos_histor,dir_histor,5,d);//position déja parouru ! direction déja utilisé
    if(occupe==1 && testdep==1&& test_historique==1)
    {
        percusion_possible=detect_percussion(d, 5, plateau, joueur_courant);
        aspiration_possible= detect_aspiration(d, 5, plateau, joueur_courant);
        if(percusion_possible==1 || aspiration_possible==1)
        {
            return 1;
        }
    }
//==============================================================================direction=6
    d=position_suivante(d, 6);  //simule position suivante Sud-est
    occupe=position_non_vide(d, plateau);
    testdep=deplacement_allouer(d, plateau, 6);
    test_historique=test_histor(pos_histor,dir_histor,6,d);//position déja parouru ! direction déja utilisé
    if(occupe==1 && testdep==1&& test_historique==1)
    {
        percusion_possible=detect_percussion(d, 6, plateau, joueur_courant);
        aspiration_possible= detect_aspiration(d, 6, plateau, joueur_courant);
        if(percusion_possible==1 || aspiration_possible==1)
        {
            return 1;
        }
    }
//==============================================================================direction=7
    d=position_suivante(d, 7);  //simule position suivante Sud-ouest
    occupe=position_non_vide(d, plateau);
    testdep=deplacement_allouer(d, plateau, 7);
    test_historique=test_histor(pos_histor,dir_histor,7,d);//position déja parouru ! direction déja utilisé
    if(occupe==1 && testdep==1&& test_historique==1)
    {
        percusion_possible=detect_percussion(d, 7, plateau, joueur_courant);
        aspiration_possible= detect_aspiration(d, 7, plateau, joueur_courant);
        if(percusion_possible==1 || aspiration_possible==1)
        {
            return 1;
        }
    }
    return 0;

}
