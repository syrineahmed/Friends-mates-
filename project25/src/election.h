#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct date
{
    int j;
    int m;
    int a;
}date;

typedef struct obs
  {
     int id;
     char nom[50];
     char prenom[50];
     char nat[40];
     int sexe;
     date d;
     char app[50];
  }obs;



void ajouter(obs u, char *fname);
void supprimer(int id, char *fname);
void modifier(obs u, char *fname);
void afficher(GtkWidget *liste, char *fname, char *id, char *nat, char *genre);
obs chercher(int id, char *fname);
char* taux_obs(char *fname);
char* nb_obs(char *fname);

