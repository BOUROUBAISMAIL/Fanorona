int test_histor(position pos_histor[12],int dir_histor[8],int dir ,deplacement* pos){
    //permet de tester si une position et une direction donnée est deja parcouru 
    for(int s=0; s<12; s++){
            for(int di=0; di<8; di++){
                if((pos_histor[s].lig==(*pos).pos_f.lig && pos_histor[s].col==(*pos).pos_f.col) || dir_histor[di]==dir){
                    return 0;
                }
                }}
                return 1;

}