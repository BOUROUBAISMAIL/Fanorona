void initialisetabprise(prise pion[],int taille){
    for(int i=0;i<taille;i++){
        pion[i].pionn.lig=-1;
        pion[i].pionn.col=-1;
        pion[i].directe=-1;
        pion[i].nombre_pion_prise=0;
    }
}
