#include <stdio.h>
#include"election.h"

int main()
{
    election E= (12865013,12/15/2022,"Tunis","Ariana",1500,25,"Ariana");
    int x=ajouter("election.txt", E);
    
    if(x==1)
        printf("\najout de point avec succés");
    else printf("\nechec ajout");
        /*
    x=modifier("election.txt",1, identifiant , Date , Types 					   	d'élèctions,Ville,Gouvernorat,Population,Conseillères);

    if(x==1)
        printf("\nModification de point avec succés");
    else printf("\nechec Modification");
    x=supprimer("point.txt",1 );
    if(x==1)
        printf("\nSuppression de point avec succés");
    else printf("\nechec Suppression");
    E =chercher("election.txt",3 );
    if(E.identifiant==-1)
        printf("introuvable");*/
    return 0;
}
