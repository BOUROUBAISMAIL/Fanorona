#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void Help(){
    system("cls");
    printf("Help : \n");
    printf("\tcontact:\n\t Envoyer votre questions s'il vous plait a l'un des e-mail suivants : " );
    printf(" \n\t\t --> mostafasissi@gmail.com \n\t\t --> anouaressabbari@gmail.com \n\t\t --> ismailbourouba@gmail.com" );

    // pour revenir au menu principale
    printf("\n\t Si vous voulez retourner au menue principale tapez 1 : ");
    int revenir;
    do {
    scanf("%d",&revenir);
    }while (revenir!=1);
    main();

}
