#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "Interface1.h"

#include "affiche_Fanorona.h"
#include "affiche_Play.h"
#include "affiche_machine.h"
#include "joueurh_vs_machine.h"
#include "Joueur_Joueur.h"
#include "Play_level1.h"
#include "Play_level2.h"
#include "Play.h"
#include "Rols.h"
#include "Help.h"
#include "Exit.h"
#include "Color.h"
#include "affiche_plateau.h"
#include "position_suivante.h"
#include "initialiser_plateau_vide.h"
#include "remplir_plateau.h"
#include "deplace_pion.h"
#include "nb_pions_joueur1.h"
#include "nb_pions_joueur2.h"
#include "mon_pion.h"
#include "prise_pions_percussion.h"
#include "prise_pions_aspiration.h"
#include "direction_inverse.h"
#include "position_non_vide.h"
#include "detect_aspiration.h"
#include "detect_percussion.h"
#include "deplacement_allouer.h"
#include "prise_possible.h"
#include "regler_non_respecter.h"
#include "nombre_pions_prise_asperation.h"
#include "nombre_pions_prise_percussion.h"
#include "test_direction.h"
#include "test_histor.h"

#include "recherche_direction.h"
#include "direction_dep.h"
#include "recherche_p.h"
#include "winer.h"
#include "gameover.h"

#include "initialisetabprise.h"
#include "nombre_pion_prisemultiple.h"
#include "recherchePion.h"
#include "pionETdirectionMax.h"

void Interface1();

void affiche_Fanorona();
void affiche_Play();
void affiche_machine();
void joueurh_vs_machine();
void Joueur_Joueur();
void Play_level1();
void Play_level2();
void Play();
void Rols();
void Help();
void Exit();
void Color(int couleurDuTexte,int couleurDeFond);
void affiche_plateau(int plateau[HAUTEUR][LARGEUR]);
deplacement* position_suivante(deplacement* pos, enum direction dir);
void initialiser_plateau_vide(int plateau[HAUTEUR][LARGEUR]);
void remplir_plateau(int plateau[HAUTEUR][LARGEUR]);
void deplace_pion(deplacement* d, plateau_jeu* jeu, int joueur_courant);
int nb_pions_joueur1(int plateau_jeu[HAUTEUR][LARGEUR]);
int nb_pions_joueur2(int plateau_jeu[HAUTEUR][LARGEUR]);
int mon_pion(deplacement*d, int joueur_courant, int plateau[HAUTEUR][LARGEUR]);
void prise_pions_percussion(plateau_jeu* jeu, deplacement*d, enum direction dir, int joueur_courant);
void prise_pions_aspiration(plateau_jeu* jeu, deplacement*d, enum direction dir, int joueur_courant);
int direction_inverse ( enum direction dir) ;
int position_non_vide(deplacement* d, int plateau_jeu[HAUTEUR][LARGEUR]);
int detect_aspiration(deplacement*d, enum direction dir, int plateau[HAUTEUR][LARGEUR], int joueur_courant);
int detect_percussion(deplacement*d, enum direction dir, int plateau[HAUTEUR][LARGEUR], int joueur_courant);
int deplacement_allouer(deplacement* d, int plateau_jeu[HAUTEUR][LARGEUR], enum direction dir );
int prise_possible(int joueur_courant, int plateau[HAUTEUR][LARGEUR]);
void regler_non_respecter(int testdep, int occupe, int bon_pion ,int capture_poss);
int nombre_pions_prise_asperation(plateau_jeu* jeu, deplacement*d, enum direction dir, int joueur_courant);
int nombre_pions_prise_percussion(plateau_jeu* jeu, deplacement*d, enum direction dir, int joueur_courant);
int test_direction(deplacement* dip, int plateau[HAUTEUR][LARGEUR],int joueur_courant,position pos_histor[12],int dir_histor[8] );
int test_histor(position pos_histor[12],int dir_histor[8],int dir ,deplacement* pos);

int recherche_direction(deplacement* dip, int plateau[HAUTEUR][LARGEUR],int joueur_courant,position pos_histor[12],int dir_histor[8] );
int direction_dep(deplacement* d);
deplacement* recherche_p(int joueur_courant, int plateau[HAUTEUR][LARGEUR]);
void winer();
void gameover();



void initialisetabprise(prise pion[],int taille);
prise_courant pionETdirectionMax(prise PrisePionDirection[],int taille);
int nombre_pion_prisemultiple(int plateau[HAUTEUR][LARGEUR], deplacement* d,int dir, int joueur_courant);
void recherchePion(int plateau[HAUTEUR][LARGEUR],  prise pion[] , int joueur_courant );
