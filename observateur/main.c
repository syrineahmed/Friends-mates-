#include <stdio.h>
#include <string.h>
#include"observateur.h"

int main()
{   
    observateur ob1= {1,1,1999,1,"folen","trab","nonetranger","prof","homme"};
    observateur ob2= {1,1,1888,2,"folna","rekik","etranger","doctor","femme"},ob3;
    observateur ob4= {1,1,1777,4,"faloun","feki","etranger","prof","homme"};
    
    int X=ajouter("OBSERVATEUR.txt", ob1);
    int Y=ajouter("OBSERVATEUR.txt", ob2);
    int Z=ajouter("OBSERVATEUR.txt", ob4);
    if (X==1)
        printf("\najout de election avec succés");
    else printf("\nechec ajout");
    
    if(Y==1)
        printf("\najout de election avec succés");
    else printf("\nechec ajout");

    if(Z==1)
        printf("\najout de election avec succés");
    else printf("\nechec ajout");
    

    X=modifier("OBSERVATEUR.txt",4,ob2 );
    if(X==1)
        printf("\nModification de election avec succés");
    else printf("\nechec Modification");
    X=supprimer("OBSERVATEUR.txt",111 );
    if(X==1)
        printf("\nSuppression de election avec succés");
    else printf("\nechec Suppression");
    ob3=chercher("OBSERVATEUR.txt",4 );
    if(ob3.identifiant==-1)
        printf("\nintrouvable");
    return 0;
}
