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
char prenom[20];
char nom[20];
char nationalite[20];
char profession [20];
char genre [20];
}observateur;
int ajouter(char * OBSERVATEUR, observateur ob);
int modifier(char * OBSERVATEUR, int identifiant, observateur nouv);
int supprimer(char * OBSERVATEUR, int identifiant);
observateur chercher(char * OBSERVATEUR, int identifiant);
float calcultn( char * OBSERVATEUR);
float calculte( char * OBSERVATEUR);
float agemoyen(char * OBSERVATEUR);
float nobr(char * OBSERVATEUR);
#endif
