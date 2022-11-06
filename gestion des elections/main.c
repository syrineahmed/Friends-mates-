include <stdio.h>
#include <string.h>
#include"election.h"

int main()
{
    election identifiant , Date , Types d'élèctions,Ville,Gouvernorat,Population,Conseillères;
    int x=ajouter("election.txt", identifiant, Date , Types      				     d'élèctions,Ville,Gouvernorat,Population,Conseillères);
    
    if(x==1)
        printf("\najout de point avec succés");
    else printf("\nechec ajout");
        */
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
        printf("introuvable");
    return 0;
}
