#include <stdio.h>
#include <stdlib.h>
#define HAUTEUR 5
#define LARGEUR 9


int direction_inverse ( enum direction dir)
{
    switch (dir)
    {
    case HAUT :
        return ( BAS );
        break;
    case BAS :
        return ( HAUT );
        break;
    case GAUCHE :
        return ( DROITE );
        break;
    case DROITE :
        return ( GAUCHE );
        break;
    case  HAUT_DROITE:
        return ( BAS_GAUCHE );
        break;
    case BAS_GAUCHE :
        return ( HAUT_DROITE );
        break;
    case HAUT_GAUCHE :
        return ( BAS_DROITE );
        break;
    case BAS_DROITE :
        return ( HAUT_GAUCHE );
        break;
    }
    return -1;
}
