
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define HAUTEUR 5
#define LARGEUR 9



int direction_dep(deplacement* d)
{
    deplacement* test=malloc(sizeof(deplacement));
    (*test).pos_i.lig=(*d).pos_i.lig;
    (*test).pos_i.col=(*d).pos_i.col;
    for (int direct=0; direct<8; direct++ )
    {
        test=position_suivante(test,direct);
       if ((*test).pos_i.lig==(*d).pos_i.lig && (*test).pos_i.col==(*d).pos_i.col && (*test).pos_f.lig==(*d).pos_f.lig && (*test).pos_f.col==(*d).pos_f.col){
            return direct;
        }
    }


}