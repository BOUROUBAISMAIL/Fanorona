


prise_courant pionETdirectionMax(prise PrisePionDirection[],int taille)
{

        int indiceMax=0;
        prise_courant Piondir;
        for(int i=1;i<15;i++){
            if(PrisePionDirection[indiceMax].nombre_pion_prise<PrisePionDirection[i].nombre_pion_prise) indiceMax=i;
        }
        Piondir.pionCourant=PrisePionDirection[indiceMax].pionn;
        Piondir.directionCourant=PrisePionDirection[indiceMax].directe;
        return Piondir;

}
