#include <stdio.h>
#include <string.h>
#include"election.h"

int main()
{   
    election e1= {1,1,1999,1,9000,90,9,"tunis","ariana","municipale"};
    election e2= {1,1,1888,2,8000,80,8,"tunis","ariana","municipale"},e3;
    election e4= {1,1,1777,4,7000,70,7,"tunis","ariana","municipales"};
    
    int X=ajouter("ELECTION.txt", e1);
    int Y=ajouter("ELECTION.txt", e2);
    int Z=ajouter("ELECTION.txt", e4);
    if (X==1)
        printf("\najout de election avec succés");
    else printf("\nechec ajout");
    
    if(Y==1)
        printf("\najout de election avec succés");
    else printf("\nechec ajout");

    if(Z==1)
        printf("\najout de election avec succés");
    else printf("\nechec ajout");
    

    X=modifier("ELECTION.txt",4,e2 );
    if(X==1)
        printf("\nModification de election avec succés");
    else printf("\nechec Modification");
    X=supprimer("ELECTION.txt",4 );
    if(X==1)
        printf("\nSuppression de election avec succés");
    else printf("\nechec Suppression");
    e3=chercher("ELECTION.txt",1 );
    if(e3.identifiant==-1)
        printf("introuvable");
    return 0;
}
