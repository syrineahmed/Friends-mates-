#ifndef ELECTION_H_INCLUDED
#define ELECTION_H_INCLUDED
#include <stdio.h>
#include <string.h>
typedef struct 
{
	int jour ;
	int mois ;
	int année;
} Date ; 

typedef struct
{
    char  Prénom [20];
    char Nom [20];
    char Sexe [20];
    char Type [20];
    int identifiant, numero de bureau de vote;
    Date Date
} election;
//le type de  retour int c'est pour indiquer si la tache a été réalisée avec succés ou non// pour afficher des lsg plus tard exemple erreur d'ouverture de fichier, element introuvable
int ajouter(char *, election );
int modifier( char *, int, election);
int supprimer(char *, int );
point chercher(char *, int);

#endif // ELECTION_H_INCLUDED
