
void recherchePion(int plateau[HAUTEUR][LARGEUR],  prise pion[] , int joueur_courant ){
    int percussion_possible;
    int aspiration_possible;
    int occupe, testdep;
    deplacement *d= malloc(sizeof(deplacement));
    int t=0;
    for (int i=0; i<HAUTEUR; i++)
    {
        for(int j=0; j<LARGEUR; j++)
        {
            if (plateau[i][j]==joueur_courant)
            {
                (*d).pos_i.lig=i;
                (*d).pos_i.col=j;
                d=position_suivante(d, 0);    //simule position suivante nord
                occupe=position_non_vide(d, plateau);             //case occupée ?
                testdep=deplacement_allouer(d, plateau, 0); //deplacement valide ?
                if(occupe==1 && testdep==1)                 //case vide + deplacement valide
                {
                    percussion_possible=detect_percussion(d, 0, plateau, joueur_courant);  // detection approche
                    aspiration_possible= detect_aspiration(d, 0, plateau, joueur_courant);  // detection retrait
                    if(percussion_possible==1 || aspiration_possible==1)    //  une des captures possibles détectée
                    {
                        if (percussion_possible==1 ){
                            pion[t].pionn=(*d).pos_i;
                            pion[t].directe=0;
                            pion[t].nombre_pion_prise=nombre_pion_prisemultiple(plateau,d,0,joueur_courant);
                            t++;
                        }
                        else if (aspiration_possible==1) {
                           pion[t].pionn=(*d).pos_i;
                           pion[t].directe=0;
                           pion[t].nombre_pion_prise=nombre_pion_prisemultiple(plateau,d,0,joueur_courant);
                           t++;
                        }

                    }
                }

                d=position_suivante(d, 1);    // simule position suivante sud
                occupe=position_non_vide(d, plateau);
                testdep=deplacement_allouer(d, plateau, 1);
                if(occupe==1 && testdep==1)
                {

                    percussion_possible=detect_percussion(d, 1, plateau, joueur_courant);
                    aspiration_possible= detect_aspiration(d, 1, plateau, joueur_courant);
                    if(percussion_possible==1 || aspiration_possible==1)
                    {

                         if (percussion_possible==1 ){
                            pion[t].pionn=(*d).pos_i;
                            pion[t].directe=1;
                            pion[t].nombre_pion_prise=nombre_pion_prisemultiple(plateau,d,1,joueur_courant);
                            t++;
                        }
                        else if (aspiration_possible==1) {
                           pion[t].pionn=(*d).pos_i;
                           pion[t].directe=1;
                           pion[t].nombre_pion_prise=nombre_pion_prisemultiple(plateau,d,1,joueur_courant);
                           t++;
                        }
                    }
                }

                d=position_suivante(d, 2);    // simule position suivante est
                occupe=position_non_vide(d, plateau);
                testdep=deplacement_allouer(d, plateau, 2);
                if(occupe==1 && testdep==1)
                {
                    percussion_possible=detect_percussion(d, 2, plateau, joueur_courant);
                    aspiration_possible= detect_aspiration(d, 2, plateau, joueur_courant);
                    if(percussion_possible==1 || aspiration_possible==1)
                    {

                         if (percussion_possible==1 ){
                            pion[t].pionn=(*d).pos_i;
                            pion[t].directe=2;
                            pion[t].nombre_pion_prise=nombre_pion_prisemultiple(plateau,d,2,joueur_courant);
                            t++;
                        }
                        else if (aspiration_possible==1) {
                           pion[t].pionn=(*d).pos_i;
                           pion[t].directe=2;
                           pion[t].nombre_pion_prise=nombre_pion_prisemultiple(plateau,d,2,joueur_courant);
                           t++;
                        }
                    }
                }


                d=position_suivante(d, 3);    //simule position suivante ouest
                occupe=position_non_vide(d, plateau);
                testdep=deplacement_allouer(d, plateau, 3);
                if(occupe==1 && testdep==1)
                {

                    percussion_possible=detect_percussion(d, 3, plateau, joueur_courant);
                    aspiration_possible=detect_aspiration(d, 3, plateau, joueur_courant);
                    if(percussion_possible==1 || aspiration_possible==1)
                    {
                         if (percussion_possible==1 ){
                            pion[t].pionn=(*d).pos_i;
                            pion[t].directe=3;
                            pion[t].nombre_pion_prise=nombre_pion_prisemultiple(plateau,d,3,joueur_courant);
                            t++;
                        }
                        else if (aspiration_possible==1) {
                           pion[t].pionn=(*d).pos_i;
                           pion[t].directe=3;
                           pion[t].nombre_pion_prise=nombre_pion_prisemultiple(plateau,d,3,joueur_courant);
                           t++;
                        }
                    }
                }


                d=position_suivante(d, 4);   //simule position suivante Nord-est
                occupe=position_non_vide(d, plateau);
                testdep=deplacement_allouer(d, plateau, 4);
                if(occupe==1 && testdep==1)
                {
                    percussion_possible=detect_percussion(d, 4, plateau, joueur_courant);
                    aspiration_possible=detect_aspiration(d, 4, plateau, joueur_courant);
                    if(percussion_possible==1 || aspiration_possible==1)
                    {
                        if (percussion_possible==1 ){
                            pion[t].pionn=(*d).pos_i;
                            pion[t].directe=4;
                            pion[t].nombre_pion_prise=nombre_pion_prisemultiple(plateau,d,4,joueur_courant);
                            t++;
                        }
                        else if (aspiration_possible==1) {
                           pion[t].pionn=(*d).pos_i;
                           pion[t].directe=4;
                           pion[t].nombre_pion_prise=nombre_pion_prisemultiple(plateau,d,4,joueur_courant);
                           t++;
                        }
                    }
                }


                d=position_suivante(d, 5);   //simule position suivante Nord-ouest
                occupe=position_non_vide(d, plateau);
                testdep=deplacement_allouer(d, plateau, 5);
                if(occupe==1 && testdep==1)
                {
                    percussion_possible=detect_percussion(d, 5, plateau, joueur_courant);
                    aspiration_possible=detect_aspiration(d, 5, plateau, joueur_courant);
                    if(percussion_possible==1 || aspiration_possible==1)
                    {
                        if (percussion_possible==1 ){
                            pion[t].pionn=(*d).pos_i;
                            pion[t].directe=5;
                            pion[t].nombre_pion_prise=nombre_pion_prisemultiple(plateau,d,5,joueur_courant);
                            t++;
                        }
                        else if (aspiration_possible==1) {
                           pion[t].pionn=(*d).pos_i;
                           pion[t].directe=5;
                           pion[t].nombre_pion_prise=nombre_pion_prisemultiple(plateau,d,5,joueur_courant);
                           t++;
                        }
                    }
                }

                d=position_suivante(d, 6);  //simule position suivante Sud-est
                occupe=position_non_vide(d, plateau);
                testdep=deplacement_allouer(d, plateau, 6);
                if(occupe==1 && testdep==1)
                {
                    percussion_possible=detect_percussion(d, 6, plateau, joueur_courant);
                    aspiration_possible=detect_aspiration(d, 6, plateau, joueur_courant);
                    if(percussion_possible==1 || aspiration_possible==1)
                    {
                         if (percussion_possible==1 ){
                            pion[t].pionn=(*d).pos_i;
                            pion[t].directe=6;
                            pion[t].nombre_pion_prise=nombre_pion_prisemultiple(plateau,d,6,joueur_courant);
                            t++;
                        }
                        else if (aspiration_possible==1) {
                           pion[t].pionn=(*d).pos_i;
                           pion[t].directe=6;
                           pion[t].nombre_pion_prise=nombre_pion_prisemultiple(plateau,d,6,joueur_courant);
                           t++;
                        }
                    }
                }

                d=position_suivante(d, 7);  //simule position suivante Sud-ouest
                occupe=position_non_vide(d, plateau);
                testdep=deplacement_allouer(d, plateau, 7);
                if(occupe==1 && testdep==1)
                {
                    percussion_possible=detect_percussion(d, 7, plateau, joueur_courant);
                    aspiration_possible=detect_aspiration(d, 7, plateau, joueur_courant);
                    if(percussion_possible==1|| aspiration_possible==1)
                    {
                         if (percussion_possible==1 ){
                            pion[t].pionn=(*d).pos_i;
                            pion[t].directe=7;
                            pion[t].nombre_pion_prise=nombre_pion_prisemultiple(plateau,d,7,joueur_courant);
                            t++;
                        }
                        else if (aspiration_possible==1) {
                           pion[t].pionn=(*d).pos_i;
                           pion[t].directe=7;
                           pion[t].nombre_pion_prise=nombre_pion_prisemultiple(plateau,d,7,joueur_courant);
                           t++;
                        }
                    }
                }

            }
        }
    }

}