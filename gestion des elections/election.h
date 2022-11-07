#ifndef ELECTION_H_INCLUDED
#define ELECTION_H_INCLUDED
#include <stdio.h>
#include <string.h>
typedef struct 
{
	int jour ;
	int mois ;
	int annee;
} Datee ; 

typedef struct
{
    int Identifiant;
    Datee Date ;
    char Ville   [20];
    char Gouvernorat [20];
    int Population ;
    int Conseilleres;
    char Municipalite[20]
    
} election;
//le type de  retour int c'est pour indiquer si la tache a été réalisée avec succés ou non// pour afficher des lsg plus tard exemple erreur d'ouverture de fichier, element introuvable
int ajouter(char *, election );
int modifier( char *, int, election);
int supprimer(char *, int );
election chercher(char *, int);

#endif // ELECTION_H_INCLUDED
