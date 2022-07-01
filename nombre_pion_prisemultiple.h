int nombre_pion_prisemultiple(int plateau[HAUTEUR][LARGEUR], deplacement* d,int dir, int joueur_courant){

    position pos_histor[12]= {(-1,-1),(-1,-1),(-1,-1),(-1,-1),(-1,-1),(-1,-1),(-1,-1),(-1,-1),(-1,-1),(-1,-1),(-1,-1),(-1,-1)};
    int dir_histor[8]= {-1,-1,-1,-1,-1,-1,-1,-1};

    int test_d;
    int contour=0;
    int nombrePionPrise=0;

    deplacement* test=malloc(sizeof(deplacement));
    (*test).pos_i.lig=(*d).pos_i.lig;
    (*test).pos_i.col=(*d).pos_i.col;

    do {
            position_suivante(test,dir);

        if(detect_percussion(test, dir, plateau, joueur_courant)){
            nombrePionPrise+=nombre_pions_prise_percussion(plateau,test,dir,joueur_courant);
        }
        else if (detect_aspiration(test,dir,plateau,joueur_courant)){
            nombrePionPrise+=nombre_pions_prise_asperation(plateau,test,dir,joueur_courant);
                 }
        // enregistrer les positions histor
         pos_histor[contour].lig=(*test).pos_i.lig;
         pos_histor[contour].col=(*test).pos_i.col;
         dir_histor[contour]=dir;

        (*test).pos_i=(*test).pos_f;

        test_d=test_direction(test,plateau,joueur_courant,pos_histor,dir_histor);

        dir=recherche_direction(test, plateau, joueur_courant, pos_histor, dir_histor );

    }while (test_d==1);

    return nombrePionPrise;
}
