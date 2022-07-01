#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define HAUTEUR 5
#define LARGEUR 9
#define JAUNE 1
#define BLEU_FLUO 2
#define joueur_1 JAUNE
#define joueur_2 BLEU_FLUO

enum direction {HAUT, BAS, DROITE, GAUCHE, HAUT_DROITE, HAUT_GAUCHE, BAS_DROITE, BAS_GAUCHE};

typedef struct position position;
struct position
{
    int lig, col;
};

typedef struct deplacement deplacement;
struct deplacement
{
    position pos_i, pos_f; // pos_i : position initiale
} ;         // pos_f : position finale
typedef struct plateau_jeu plateau_jeu ;
 struct plateau_jeu
{
    int plateau[HAUTEUR][LARGEUR];//Etat du plateau
} ;

void Joueur_Joueur(){
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
    int i, j ;//i=abscisse , j=ordonnée
    int nb_joueur1,nb_joueur2;
    int nbr_p_app;
    int nbr_p_ret;

    int capture_poss;
    int test_d;
    int test_historique;
    int coup_joueur=0;
    int bon_pion;
    int occupe;
    int testdep;


Mauvais_choix://<<<= ce label utilisé dans le cas d'un mauvais choix de pion && direction && deplacement
    afficher_plateau(plateau);
    nb_joueur1=nb_pions_joueur1(plateau);
    nb_joueur2=nb_pions_joueur2(plateau);
    printf("le nombre de pions rester du joueur 1 est : %d \n",nb_joueur1);
    printf("le nombre de pions rester du joueur 2 est : %d \n",nb_joueur2);


    do
    {
        int contour=0;
        printf("le joueur qui vat jouer est %d \n",joueur_courant);
        printf("Entrer la position ligne:");
        scanf("%d", &i );
        printf("\nEntrer la position colone:");
        scanf("%d", &j );
        (*pos).pos_i.lig = i;
        (*pos).pos_i.col = j;
        printf("Entrer la direction :");
        scanf("%d",&dir);

        deplacement* position_suivante(deplacement* pos, enum direction dir);
        pos=position_suivante(pos,dir);

prise://label utilisé dans le cas de prise multiple

        occupe=position_non_vide(pos,plateau);
        bon_pion = mon_pion(pos, joueur_courant, plateau);
        capture_poss=prise_possible(joueur_courant,  plateau );
        testdep=deplacement_allouer(pos,plateau, dir );



        if (bon_pion==1 && occupe==1 && testdep==1  )
        {
            position_suivante(pos,dir);
            nbr_p_ret=nombre_pions_prise_asperation(plateau,pos, dir, joueur_courant);
            nbr_p_app=nombre_pions_prise_percussion(plateau,pos, dir, joueur_courant);
            if (nbr_p_ret!=0 || nbr_p_app!=0)
            {
                if (nbr_p_ret!=0 && nbr_p_app!=0 )//le cas ou on'a prise par percussion et asspiration
                {
                    int type_mange ;
                    printf(" choisir 1 si vous voulez par retrait ou 2 si vous voulez par approche :");
                    scanf("%d",&type_mange);
                    if (type_mange==1)
                    {
                        prise_pions_aspiration(plateau,pos,dir,joueur_courant);
                        coup_joueur++;
                    }
                    else
                    {
                        prise_pions_percussion(plateau,pos,dir,joueur_courant);
                        coup_joueur++;

                    }
                }
                else if (nbr_p_app!=0)//percussion
                {

                    prise_pions_percussion(plateau,pos,dir,joueur_courant);
                    coup_joueur++;
                }
                else if (nbr_p_ret!=0)//aspiration
                {
                    prise_pions_aspiration(plateau,pos,dir,joueur_courant);
                    coup_joueur++;

                }

                deplace_pion(pos,plateau,joueur_courant );
                afficher_plateau(plateau);
                nb_joueur1=nb_pions_joueur1(plateau);
                nb_joueur2=nb_pions_joueur2(plateau);
                printf("le nombre de pions rester du joueur 1 est : %d \n",nb_joueur1);
                printf("le nombre de pions rester du joueur 2 est : %d \n",nb_joueur2);
                //stackage de la position et direction visité
                pos_histor[contour].lig=(*pos).pos_i.lig;
                pos_histor[contour].col=(*pos).pos_i.col;
                dir_histor[contour]=dir;


            }
            else
            {
                if (capture_poss==1)// capture possible
                {
                    regler_non_respecter( testdep, occupe, bon_pion, capture_poss);
                    goto Mauvais_choix;
                }

                else    //pas de capture de pion mangé
                {
                    deplace_pion(pos,plateau,joueur_courant );
                    afficher_plateau(plateau);
                    printf("le nombre de pions rester du joueur 1 est : %d \n",nb_joueur1);
                    printf("le nombre de pions rester du joueur 2 est : %d \n",nb_joueur2);
                    goto deplacement_simple;// Dans le cas d'un deplacement on ne peut pas avoir de prise multiple (on saute le traitement de prise multiple)
                }
            }
        }

        else
        {
            regler_non_respecter( testdep, occupe, bon_pion, capture_poss);
            goto Mauvais_choix;
        }

        // avant de passer à tester les prises multiple on doit mettre la pos finale dans la pos initial
        (*pos).pos_i=(*pos).pos_f;

        test_d=test_direction(pos,plateau,joueur_courant,pos_histor,dir_histor);
        if (coup_joueur>2){//prise multiple est interdites sur le premier coup de chaque joueur
        if (test_d==1){//detection d'une prise multiple

            mauvais_direction: //Dans le cas ou la direction choisi est inaproprié

            printf("Vous avez encore la chance de mange d'autre pion \nEntrer la direction :");
            scanf("%d",&dir);
            // on doit  vérifier que la position final n'était pas parcouru

            position_suivante(pos,dir);

            test_historique=test_histor(pos_histor,dir_histor,dir,pos);
            occupe=position_non_vide(pos, plateau);
            testdep=deplacement_allouer(pos, plateau, dir);

            int  percussion_possible=detect_percussion(pos, dir, plateau, joueur_courant);
            int  aspiration_possible=detect_aspiration(pos, dir, plateau, joueur_courant);
            if(occupe==1 && testdep==1&& test_historique==1)//  position suivant non occupé && direction possible && (position final n'était pas parcouru && direction)
           {
                    if (percussion_possible==1 && aspiration_possible==1){
                        contour++;
                        goto prise ;}
                    else{//pas de capture possible dans cette direction choisi
                        regler_non_respecter( testdep, occupe, bon_pion, capture_poss);
                        afficher_plateau(plateau);
                        printf("le nombre de pions rester du joueur 1 est : %d \n",nb_joueur1);
                        printf("le nombre de pions rester du joueur 2 est : %d \n",nb_joueur2);
                        goto mauvais_direction ; //redemandé d'entre la direction
                      }
                    }
            else{//position suivant occupé || direction impossible || direction ou position final deja parcouru pendant un seul coup
                    regler_non_respecter( testdep, occupe, bon_pion, capture_poss);
                    afficher_plateau(plateau);
                    printf("le nombre de pions rester du joueur 1 est : %d \n",nb_joueur1);
                    printf("le nombre de pions rester du joueur 2 est : %d \n",nb_joueur2);
                    goto mauvais_direction ;
            }
        }
        //initialisation a nouveau de position historique et les directions historique
        for (int i=0;i<12;i++){ pos_histor[i].lig=-1;  pos_histor[i].col=-1;}
        for (int i=0;i<12;i++){dir_histor[i]=-1;}}

deplacement_simple:

         //changement de joueur
        if (joueur_courant==1  )
        {
            joueur_courant=joueur_2;
        }
        else
        {
            joueur_courant=joueur_1;
        }

    }
    while(nb_joueur1!=0 && nb_joueur2!=0);

// joueur gagnant
    if(nb_joueur1==0)
    {
        printf("Le gagnant est le joueur %d \n", joueur_1);
        winer(1); // affichage du  Coupe pour joueur1


    }
    else if(nb_joueur2==0)
    {
        printf("Le gagnant est le joueur %d \n", joueur_2);
        winer(2);// affichage du coup pour joueur2

    }



    return 0;
}


