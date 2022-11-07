#include <stdio.h>
#include <string.h>
#include"point.h"

int main()
{
    obsevateur O1= {1111111,15,5,1970,"MOHSEN","GHORBEL","NON ETRANGER","TECHNICIEN","HOMME"},O2= {1111112,15,5,1970,"SOUMAYA","OUNI","NON ETRANGER","TECHNICIENNE","FEMME"},O3;
    int x=ajouter("observateur.txt", O1);
    /*
    if(x==1)
        printf("\najout de OBSERVATEUR avec succés");
    else printf("\nechec ajout");
        */
    x=modifier("observateur.txt",1,O2 );

    if(x==1)
        printf("\nModification de OBSERVATEUR avec succés");
    else printf("\nechec Modification");
    x=supprimer("observateur.txt",1 );
    if(x==1)
        printf("\nSuppression de OBSERVATEUR avec succés");
    else printf("\nechec Suppression");
    O3=chercher("observateur.txt",3 );
    if(O3.Id==-1)
        printf("introuvable");
    return 0;
}
