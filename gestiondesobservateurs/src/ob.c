#include "stdio.h"
#include "gtk/gtk.h"
#include "ob.h"
#include "string.h"
int tableau_observateur(observateur tabl[])
{
int n=0;
FILE* f=fopen("OBSERVATEUR.txt","r");
if(f!=NULL)
{
    while( fscanf(f,"%d %d %d \n",&tabl[n].y.jour,&tabl[n].y.mois,&tabl[n].y.annee)!=EOF)
{n++;}
fclose(f);
}
return n;
}
void enregistrer_observateur(observateur ob)
{
FILE* f=fopen("OBSERVATEUR.txt","a");
if(f!=NULL)
{
fprintf(f,"%d %d %d \n",ob.y.jour,ob.y.mois,ob.y.annee);
fclose(f);
}
}
int ajouter(observateur ob)
{
FILE* f;
f=fopen("OBSERVATEUR.txt","a+");
if(f!=NULL)
{
   fprintf(f,"%s%s%s%s%s%s%s\n",ob.date,ob.identifiant,ob.nom,ob.prenom,ob.nationalite,ob.profession,ob.genre);

fclose(f);
}
}

void afficherObservateur(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char prenom[20];
char nom[20];
char nationalite[20];
char profession [20];
char genre [20];
store=NULL;
renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",prenom,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",prenom,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",prenom,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",prenom,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",prenom,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",prenom,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",prenom,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

