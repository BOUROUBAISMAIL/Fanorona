#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void afficher_plateau(int plateau[HAUTEUR][LARGEUR]){
   Color(15,0);
   printf("\t\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  \n\t\t|");
   for (int k=0;k<9;k++) printf("_%d_|",k);

   printf("\n\t\t_____________________________________\t  _________________________________________\n\t _ _   |\t\t\t\t     | \t |\t\t\t\t\t   |\n");


  for (int i=0; i<HAUTEUR; i++){
    if (i!= HAUTEUR -1){
      for (int j=0; j<LARGEUR; j++){
            if (j!=LARGEUR-1){
               if (plateau[i][j]==1){
                  if (j==0){Color(15,0);printf("\t|_%d_|  | ",i);Color(14,0);printf(" %d ", plateau[i][j]);}
                  else {Color(14,0);printf(" %d ", plateau[i][j]);}
                                    }
               else if(plateau[i][j]==2){
                  if (j==0){Color(15,0);printf("\t|_%d_|  | ",i);Color(9,0);printf(" %d ", plateau[i][j]);}
                  else {Color(9,0);printf(" %d ", plateau[i][j]);}
                                       }
               else{
                 if (j==0){Color(15,0);printf("\t|_%d_|  | ",i);printf(" %d ", plateau[i][j]);}
                  else {Color(15,0);printf(" %d ", plateau[i][j]);}
                  }
               Color(15,0);printf("-");
                                    }
            else if(j==LARGEUR-1){
                if (plateau[i][j]==1){Color(14,0);;printf(" %d", plateau[i][j]);Color(15,0);printf("  |");}
                else if(plateau[i][j]==2){Color(9,0);printf(" %d", plateau[i][j]);Color(15,0);printf("  |");}
                else {Color(15,0);printf(" %d  |", plateau[i][j]);}
                switch(i){
                    case 0 : {printf("\t |  Les directions:\t\t\t   |");break;}
                    case 1 : {printf("\t |    HAUT       --> 0  BAS        --> 1   |");break;}
                    case 2 : {printf("\t |    DROITE     --> 2  GAUCHE     --> 3   |");break;}
                    case 3 : {printf("\t |    HAUT_DROITE--> 4  HAUT_GAUCHE--> 5   |");break;}
                }

                             }
                                    }
      Color(15,0);printf("\n\t _ _   | ");
      for (int t=0; t<LARGEUR-1; t++){
            if ((i+t)%2==0){Color(15,0);printf(" | \\");}
            if ((i+t)%2!=0){Color(15,0);printf(" | /");}
                                     }
      printf(" |  |   |\t\t\t\t\t   |\n");
                            }
    else if(i==HAUTEUR -1){
      Color(15,0);printf("\t|_%d_|  | ",i);
      for (int j=0; j<LARGEUR; j++){
            if (j!=LARGEUR-1){
                    if (plateau[i][j]==2){Color(9,0);printf(" %d ", plateau[i][j]);}
                    else if (plateau[i][j]==1){Color(14,0);printf(" %d ", plateau[i][j]);}
                    else {Color(15,0);printf(" %d ", plateau[i][j]);}

                    Color(15,0);printf("-");
            }
            else if(j==LARGEUR-1){if (plateau[i][j]==1){Color(14,0);;printf(" %d", plateau[i][j]);Color(15,0);printf("  |");}
                                  else if(plateau[i][j]==2){Color(9,0);printf(" %d", plateau[i][j]);Color(15,0);printf("  |");}
                                  else {Color(15,0);printf(" %d  |", plateau[i][j]);}
                                  printf("   |    BAS_DROITE --> 6  BAS_GAUCHE --> 7   |");

                                  }
                                   }

                          }
                                    }
  Color(15,0);
  printf("\n\t       |_____________________________________|   |_________________________________________|\n\n");
}
