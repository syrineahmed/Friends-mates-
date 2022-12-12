#ifndef LISTE_ELECTORALE_H_INCLUDED
#define LISTE_ELECTORALE_H_INCLUDED
#include <stdio.h>
#include<gtk/gtk.h>
#include "liste_electorale.h"
typedef struct
{
    int j;
    int m;
    int a;
} date;
typedef struct
{
    date date_ajout;
    char idvote[30];
    //char date_ajout[30];
    char id_liste[30];
    char id_tete_liste[30];//not null
    char sexe[20];
    char orientation[20];// condtion 3
    /*int id_particip;
    int numero_bv;
    int id;
    int vote_valide;
    int vote_blanc;*/
    char type_vote[20];
 
} liste_electorale;
//le type de  retour int c'est pour indiquer si la tache a été réalisée avec succés ou non// pour afficher des lsg plus tard exemple erreur d'ouverture de fichier, element introuvable
//int ajouter(char * liste, liste_electorale R);
void ajouter(liste_electorale R );
void ajout_vote(liste_electorale V );
float taux(int x,int y);
//void affiche_vote( liste_electorale V)
//void afficher(GtkWidget *liste);
void afficher(GtkWidget *pListView);
void chercher(char idchercher[20],GtkWidget *liste);
void modifier(liste_electorale R1);
int nombre(char *filename);
int nombrevote_total(char *filename);
int nombretotal(char *filename);
//void supprimer_liste(int id);
//void supprimer(liste_electorale R);
int supprimer(char id[50]);
//int nbrP (char *filename);

//void supprimer(char idsupp[20],GtkWidget *liste);
//void supprimer(char *liste , char id[50]);
//void supprimer(char *liste, int id);
//liste_electorale chercher_liste(char *liste, int id);
//liste_electorale chercher_liste(int id, GtkWidget *liste);
//void affiche_cherch(GtkWidget *pListView);
/*int ajout_vote (char  *liste, liste_electorale R );
int ajout_particip (char * liste, liste_electorale R );
int NBV (char * liste,int numero_bv);
int nbrP (char * liste);
int nbrV (char * liste);
liste_electorale critere (char * liste);
int modifier( char *liste, int id, liste_electorale nouv );
int supprimer(char *, int id);
liste_electorale chercher(char *liste, int id);*/
//int calculfemmehomme(char*liste);
//recherche  multicritere id des tetes de liste femme dont l orientation gauche

//float TPE (char *liste);

#endif // RECLAMATION_H_INCLUDED
