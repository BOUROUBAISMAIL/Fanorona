#include <stdio.h>
#include <stdlib.h>



deplacement * position_suivante(deplacement *pos, enum direction dir)
{
    switch (dir)
    {
    case HAUT :
        (*pos).pos_f.lig = (*pos).pos_i.lig - 1;
        (*pos).pos_f.col = (*pos).pos_i.col;
        break;
    case BAS :
        (*pos).pos_f.lig =(*pos).pos_i.lig + 1;
        (*pos).pos_f.col = (*pos).pos_i.col;
        break;
    case DROITE :
        (*pos).pos_f.col = (*pos).pos_i.col + 1;
        (*pos).pos_f.lig = (*pos).pos_i.lig;
        break;
    case GAUCHE :
        (*pos).pos_f.col = (*pos).pos_i.col - 1;
        (*pos).pos_f.lig = (*pos).pos_i.lig;
        break;
    case HAUT_DROITE :
        (*pos).pos_f.lig = (*pos).pos_i.lig - 1;
        (*pos).pos_f.col = (*pos).pos_i.col + 1;
        break;
    case HAUT_GAUCHE :
        (*pos).pos_f.lig = (*pos).pos_i.lig - 1;
        (*pos).pos_f.col = (*pos).pos_i.col - 1;
        break;
    case BAS_DROITE :
        (*pos).pos_f.lig = (*pos).pos_i.lig + 1;
        (*pos).pos_f.col = (*pos).pos_i.col + 1;
        break;
    case BAS_GAUCHE :
        (*pos).pos_f.lig = (*pos).pos_i.lig + 1;
        (*pos).pos_f.col = (*pos).pos_i.col - 1;
        break;
    }
    return pos;
}