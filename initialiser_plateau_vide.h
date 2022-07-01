#include <stdio.h>
#include <stdlib.h>
#define HAUTEUR 5
#define LARGEUR 9

#define VIDE 0



void initialiser_plateau_vide(int plateau[HAUTEUR][LARGEUR]){
  int i, j;
  for (i=0; i<HAUTEUR; i++){
    for (j=0; j<LARGEUR; j++){
      plateau[i][j]=VIDE;
    }
  }
}