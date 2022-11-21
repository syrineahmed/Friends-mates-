#include <stdio.h>
#include <string.h>
#include"observateur.h"

int main()
{   
    observateur ob1= {{1,1,2012},1,"folen","trab","nonetranger","prof","homme"};
    observateur ob2= {{1,3,2002},2,"folna","rekik","etranger","doctor","femme"};
    observateur ob3= {{1,5,2022},3,"faloun","feki","nonetranger","prof","homme"};
    observateur ob4;
    int X=ajouter("OBSERVATEUR.txt", ob1);
    int Y=ajouter("OBSERVATEUR.txt", ob2);
    int Z=ajouter("OBSERVATEUR.txt", ob3);
int W;
int r;
    if (X==1)
        printf("\najout de observateur avec succés");
    else printf("\nechec ajout");
    
    if(Y==1)
        printf("\najout de observateur avec succés");
    else printf("\nechec ajout");

    if(Z==1)
        printf("\najout de observateur avec succés");
    else printf("\nechec ajout");
    /*

    Y=modifier("OBSERVATEUR.txt",4,ob2 );
    if(Y==1)
        printf("\nModification de observateur avec succés");
    else printf("\nechec Modification");
    W=supprimer("OBSERVATEUR.txt",111 );
    if(W==1)
        printf("\nSuppression de observateur avec succés");
    else printf("\nechec Suppression");*/
    ob4=chercher("OBSERVATEUR.txt",45 );
    if(ob4.identifiant==-1)
        printf("\nintrouvable");
r=nobr("OBSERVATEUR.txt");
printf("\n le L’âge moyen des electeurs est %f ",(float)agemoyen("OBSERVATEUR.txt")/r);

printf("\n le taux des observateurs non etrangers est %f ",(float)calcultn("OBSERVATEUR.txt")/r);
printf("\n le taux des observateurs etrangers est %f ",(float)calculte("OBSERVATEUR.txt")/r);

    return 0;
}
