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
char prenom[20];//not nul
char nom[20];//not nul
char nationalite[20];
char profession [20];
char genre [20];
}observateur;
int ajouter(char * OBSERVATEUR, observateur ob);
int modifier(char * OBSERVATEUR, int identifiant, observateur nouv);
int supprimer(char * OBSERVATEUR, int identifiant);
observateur chercher(char * OBSERVATEUR, int identifiant);

int tableau_observateur(ageobser tabl[80]);

void enregistrer_observateur(ageobser dn)
#endif
