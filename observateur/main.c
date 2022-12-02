#include <stdio.h>
#include <string.h>
#include"observateur.h"

int main()
{   
    observateur ob1= {{1,1,2012},1,"foen","trab","nonetranger","prof","homme"};
    observateur ob2= {{1,3,2002},4,"somaya","rekik","etranger","doctor","femme"};
    observateur ob3= {{1,5,2022},3,"qbderrqwek","feki","nonetranger","prof","homme"};
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
    X=modifier("OBSERVATEUR.txt",4,ob2 );
    if(X==1)
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
printf("\n ecrire 1 pour nombres des hommes non etrangers");
printf("\n ecrire 2 pour nombres des hommes etrangers");
printf("\n ecrire 3 pour nombres des femmes non etrangers");
printf("\n ecrire 4 pour nombres des femmes etrangers");
printf("\n le nombre est %d",RechCritere("OBSERVATEUR.txt",1));

    return 0;
}
