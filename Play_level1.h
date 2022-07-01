
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HAUTEUR 5
#define LARGEUR 9
#define JAUNE 1
#define BLEU_FLUO 2
#define VIDE 0
#include <windows.h>
#define j_machine JAUNE
#define j_humain BLEU_FLUO



deplacement* recherche_p(int joueur_courant, int plateau[HAUTEUR][LARGEUR]);

deplacement* position_suivante(deplacement* pos, enum direction dir);

void Play_level1(){
	//=== declaration && initialisation du plateau
    plateau_jeu plateau[HAUTEUR][LARGEUR];
    initialiser_plateau_vide(plateau);
    remplir_plateau(plateau);
    //===declaration et initialisation de deux tableau l'un pour stocké les position historique l'autre pour stocké les diretions historique lors d'un seul tour
    position pos_histor[12]= {(-1,-1),(-1,-1),(-1,-1),(-1,-1),(-1,-1),(-1,-1),(-1,-1),(-1,-1),(-1,-1),(-1,-1),(-1,-1),(-1,-1)};
    int dir_histor[8]= {-1,-1,-1,-1,-1,-1,-1,-1};
    //choix aleatoire du joueur qui va commancé
    int joueur_courant;
    srand(time(NULL));
    joueur_courant=(rand()%2)+1; //choix de joueur aleatoire

    deplacement* pos=(deplacement*)malloc(sizeof(deplacement));
    int dir ;
    int i, j ; //i=abscisse , j=ordonnée
    int nbr_p_app;
    int nbr_p_ret;
    int bon_pion;
    int nb_joueur1,nb_joueur2;

    int capture_poss;
    int test_d;
    int test_historique;

Mouvais_choix:
    afficher_plateau(plateau);
    nb_joueur1=nb_pions_joueur1(plateau);
    nb_joueur2=nb_pions_joueur2(plateau);
    printf("le nombre de pions rester du joueur_Mach est : %d \n",nb_joueur1);
    printf("le nombre de pions rester du joueur_Hum est : %d \n",nb_joueur2);
    int contour;
    int condition_init=0;
    int testdep;
    int occupe;


    do
    {

        if (joueur_courant==j_humain)
        {
            printf("votre role de jouer avec 2\n");
            contour=0; // initialisation du contour pour stocké les pos et dir historique
            printf("Entrer la position ligne:");
            scanf("%d", &i );
            printf("\nEntrer la position colone:");
            scanf("%d", &j );
            printf("Entrer la direction :");
            scanf("%d",&dir);
            pos->pos_i.lig = i;
            pos->pos_i.col = j;

            pos=position_suivante(pos,dir);
prise_humaine:

            occupe=position_non_vide(pos,plateau);
            capture_poss=prise_possible(joueur_courant,  plateau );
            bon_pion=mon_pion(pos, joueur_courant, plateau);
            testdep=deplacement_allouer(pos,plateau, dir );

            if (bon_pion==1 && occupe==1 && testdep==1  )
            {
                position_suivante(pos,dir);
                nbr_p_ret=nombre_pions_prise_asperation(plateau,pos, dir, joueur_courant);
                nbr_p_app=nombre_pions_prise_percussion(plateau,pos, dir, joueur_courant);
                if (nbr_p_ret!=0 || nbr_p_app!=0)
                {
                    if (nbr_p_ret!=0 && nbr_p_app!=0 )
                    {
                        int type_mange ;
                        printf(" choisir 1 si vous voulez par retrait ou 2 si vous voulez par approche :");
                        scanf("%d",&type_mange);
                        if (type_mange==1)
                        {
                            prise_pions_aspiration(plateau,pos,dir,joueur_courant);
                            condition_init++;
                        }
                        else
                        {

                            prise_pions_percussion(plateau,pos,dir,joueur_courant);
                            condition_init++;
                        }
                    }
                    else if (nbr_p_app!=0)
                    {

                        prise_pions_percussion(plateau,pos,dir,joueur_courant);
                        condition_init++;

                    }
                    else if (nbr_p_ret!=0)
                    {
                        prise_pions_aspiration(plateau,pos,dir,joueur_courant);
                        condition_init++;

                    }

                    deplace_pion(pos,plateau,joueur_courant );
                    afficher_plateau(plateau);
                    nb_joueur1=nb_pions_joueur1(plateau);
                    nb_joueur2=nb_pions_joueur2(plateau);
                    printf("le nombre de pions rester du joueur_Hum  est : %d \n",nb_joueur1);
                    printf("le nombre de pions rester du joueur_Mach  est : %d \n",nb_joueur2);
                    //stocké les positions historiques et les directions
                    pos_histor[contour].lig=(*pos).pos_i.lig;
                    pos_histor[contour].col=(*pos).pos_i.col;
                    dir_histor[contour]=dir;
                }
                else
                {
                    if (capture_poss==1)
                    {
                        regler_non_respecter( testdep, occupe, bon_pion, capture_poss);
                        goto Mouvais_choix;
                    }

                    else    //pas de capture de pion mongé
                    {
                        deplace_pion(pos,plateau,joueur_courant );
                        afficher_plateau(plateau);
                        printf("le nombre de pions rester du joueur_Mach  est : %d \n",nb_joueur1);
                        printf("le nombre de pions rester du joueur_Hum est : %d \n",nb_joueur2);
                        goto deplacement_simple;// un deplacement sans prise => pas de prise multiple
                    }
                }

            }
            else
            {
                regler_non_respecter( testdep, occupe, bon_pion, capture_poss);
                goto Mouvais_choix;
            }
        }

//===================================le  de l'ordinateur ========================================================


        else
        {
            contour=0; //initialisation du contour pour stocké les positions et les directions historique
            pos=recherche_p(1,plateau);
            dir=direction_dep(pos);

prise_machine:

            position_suivante(pos,dir );
            nbr_p_ret=nombre_pions_prise_asperation(plateau,pos, dir, joueur_courant);
            nbr_p_app=nombre_pions_prise_percussion(plateau,pos, dir, joueur_courant);

            if (nbr_p_app!=0)
            {

                prise_pions_percussion(plateau,pos,dir,joueur_courant);
                condition_init++;

            }
            else
            {
                prise_pions_aspiration(plateau,pos,dir,joueur_courant);
                condition_init++;

            }


            deplace_pion(pos,plateau,1);
            afficher_plateau(plateau);
            nb_joueur1=nb_pions_joueur1(plateau);
            nb_joueur2=nb_pions_joueur2(plateau);
            printf("le nombre de pions rester du joueur_Mach  est : %d \n",nb_joueur1);
            printf("le nombre de pions rester du  joueur_Hum est : %d \n",nb_joueur2);
            pos_histor[contour].lig=(*pos).pos_i.lig;
            pos_histor[contour].col=(*pos).pos_i.col;
            dir_histor[contour]=dir;
        }


        (*pos).pos_i=(*pos).pos_f;

        test_d=test_direction(pos,plateau,joueur_courant,pos_histor,dir_histor);
        if ( condition_init>2)
        {
            if (test_d==1)
            {
                if (joueur_courant==j_humain)
                {
mauvais_direction: //Dans le cas ou la direction choisi est inaproprié
                    printf("Vous avez encore la chance de mange d'autre pion \nEntrer la direction :");
                    scanf("%d",&dir);
                    // on doit  vérifier que la position final n'était pas parcouru

                    position_suivante(pos,dir);
                    test_historique=test_histor(pos_histor,dir_histor,dir,pos);
                    occupe=position_non_vide(pos, plateau);
                    testdep=deplacement_allouer(pos, plateau, dir);

                    int  percussion_possible=detect_percussion(pos, dir, plateau, joueur_courant);
                    int  aspiration_possible= detect_aspiration(pos, dir, plateau, joueur_courant);
                    if(occupe==1 && testdep==1&& test_historique==1)
                    {
                        if (percussion_possible==1 || aspiration_possible==1)
                        {
                            contour++;
                            goto prise_humaine;
                        }
                        else
                        {
                            regler_non_respecter( testdep, occupe, bon_pion, capture_poss);

                            afficher_plateau(plateau);
                            printf("le nombre de pions rester du joueur 1 est : %d \n",nb_joueur1);
                            printf("le nombre de pions rester du joueur 2 est : %d \n",nb_joueur2);
                            goto mauvais_direction ;
                        }
                    }
                    else
                    {
                        regler_non_respecter( testdep, occupe, bon_pion, capture_poss);
                        afficher_plateau(plateau);
                        printf("le nombre de pions rester du joueur 1 est : %d \n",nb_joueur1);
                        printf("le nombre de pions rester du joueur 2 est : %d \n",nb_joueur2);
                        goto mauvais_direction ;
                    }


                }
                else  //joueur_courant==j_machine
                {

                    dir=recherche_direction(pos, plateau, joueur_courant, pos_histor, dir_histor );

                    goto prise_machine;


                }
            }
        }
        //initialisation a nouveau de position historique et les directions historique
        for (int i=0; i<12; i++)
        {
            pos_histor[i].lig=-1;
            pos_histor[i].col=-1;
        }
        for (int i=0; i<12; i++)
        {
            dir_histor[i]=-1;
        }

deplacement_simple:
        if (joueur_courant==j_humain  )
        {
            joueur_courant=j_machine;
        }
        else
        {
            joueur_courant=j_humain;
        }

    }
    while(nb_joueur1!=0 && nb_joueur2!=0);
    if(nb_joueur1==0)
    {
        printf("Vous avez gagner Bravo !!! \n");
        winer(1);
    }
    else if(nb_joueur2==0)
    {
        printf("Vous avez perder !!!!\n");
        gameover();

    }


}
