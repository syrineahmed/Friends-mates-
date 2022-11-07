ifndef OBSERVATEUR_H_INCLUDED
#define OBSERVATEUR_H_INCLUDED
#include <stdio.h>
#include <string.h>
typedef struct 
{
	int jour ;
	int mois ;
	int annee;
} Date ; 

typedef struct
{
    int Id;
    Date DN ;
    char Nom  [20];
    char Prenom [20];
    char Nationalite[20] ;
    char Profession[20];
    char Genre[20]
    
} observateur;

int ajouter(observateur O, char filename[]);
int modifier( int Id,observateur nouvO, char *filename);
int supprimer(int Id, char *filename);
observateur chercher(int Id, char *filename);

#endif // OBSERVATEUR_H_INCLUDED
