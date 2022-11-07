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
int identifiant;
int population;
int nb_conseillers;
int municipalite;
char ville [20];
char gouvernorat [20];
char uneelection[20];
}election;
int nb_conseillers( election e);
int ajouter(char * ELECTION, election e);
int modifier(char * ELECTION, int identifiant, election nouv);
int supprimer(char * ELECTION, int identifiant);
election chercher(char * ELECTION, int identifiant);
#endif
