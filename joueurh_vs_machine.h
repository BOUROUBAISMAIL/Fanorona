#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void joueurh_vs_machine(){

        mouvais_choix_machine :
         system("cls");
         int level;
         affiche_machine();
         printf("\n\n\n\t\t\t Choisissez un nombre entre 1 et 3 s'il vous plait : ");
         scanf("%d",&level);
         switch(level){
             case 1 :Play_level1();
                 break;
             case 2 :Play_level2();;
                 break;
             case 3 :system("cls");
                 Play();
                 break;
             default : goto mouvais_choix_machine;
     }



}
