#ifndef ELECTION_H_INCLUDED
#define ELECTION_H_INCLUDED
#include <stdio.h>
#include <string.h>
typedef struct
{
int jour;
int mois;
int annee;
}DateE;
typedef struct
{
DateE y;
char identifiant[20];
char code_postal[20];  
char population[20];
char nb_conseillers[20];
char uneelection[20];
char ville [20];
char municipalite [20];
}election;

//int nb_conseillers( election e);
void ajouter( election e);
void modifier(election r);
void supprimer(election r);
void chercher(election e, char identifiant[20] , char code_postal[20]); 
void afficher_rech(GtkWidget *liste);
void afficher(GtkWidget *liste);

#endif
