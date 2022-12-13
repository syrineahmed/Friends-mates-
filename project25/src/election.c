#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "election.h"
#include "callbacks.h"
#include <gtk/gtk.h>

enum
{
	ID,
	NOM,
	NAT,
	SEXE,
	DATE,
	APP,
	COLUMNS
};


void ajouter(obs u, char *fname){
GtkWidget *pQuestion;
FILE *f;
int b=0;
gpointer user_data;
obs p;
f=fopen(fname,"a+");
if(f!=NULL)
{	
	while(fscanf(f,"%d %s %s %s %d %d %d %d %s\n",&(p.id),p.nom,p.prenom,p.nat,&(p.sexe),&(p.d.j),&(p.d.m),&(p.d.a),p.app)!=EOF)
	{	
		if(u.id==p.id)
		b=1;
	}
	if(b==0){
	fprintf(f,"%d %s %s %s %d %d %d %d %s\n",u.id,u.nom,u.prenom,u.nat,u.sexe,u.d.j,u.d.m,u.d.a,u.app);
	}
	pQuestion=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,b==0?GTK_MESSAGE_INFO:GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,b==0?"Observateur ajouté avec succès !":"Observateur déja existant !");
	switch(gtk_dialog_run(GTK_DIALOG(pQuestion)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pQuestion);
	break;
	}
	fclose(f);
}
}

void modifier(obs u, char *fname){
obs p;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen(fname,"r");
g=fopen("dump.txt","w");
if(f==NULL||g==NULL)
{
	return;
}
else{
	while(fscanf(f,"%d %s %s %s %d %d %d %d %s\n",&(p.id),p.nom,p.prenom,p.nat,&(p.sexe),&(p.d.j),&(p.d.m),&(p.d.a),p.app)!=EOF)
	{
		if(p.id!=u.id)
			fprintf(g,"%d %s %s %s %d %d %d %d %s\n",p.id,p.nom,p.prenom,p.nat,p.sexe,p.d.j,p.d.m,p.d.a,p.app);
		else
			fprintf(g,"%d %s %s %s %d %d %d %d %s\n",u.id,u.nom,u.prenom,u.nat,u.sexe,u.d.j,u.d.m,u.d.a,u.app);
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Observateur modifié avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove(fname);
rename("dump.txt",fname);
}
}

void afficher(GtkWidget *liste, char *fname, char *id, char *nat, char *genre)
{
obs p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
gchar date[50], sexe[10], nom[50];
FILE *f;

store=gtk_tree_view_get_model(liste);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" ID", renderer,"text",ID, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_expand(column,TRUE);

store=gtk_tree_view_get_model(liste);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Nom et prénom", renderer,"text",NOM, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_expand(column,TRUE);

store=gtk_tree_view_get_model(liste);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Nationalité", renderer,"text",NAT, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_expand(column,TRUE);

store=gtk_tree_view_get_model(liste);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Sexe", renderer,"text",SEXE, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_expand(column,TRUE);

store=gtk_tree_view_get_model(liste);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Date", renderer,"text",DATE, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_expand(column,TRUE);

store=gtk_tree_view_get_model(liste);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Appartenance", renderer,"text",APP, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_expand(column,TRUE);


store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
if (strcmp(id,"")==0&&strcmp(genre,"")==0&&strcmp(nat,"")==0){
f=fopen(fname,"a+");
if(f!=NULL)
{
		while(fscanf(f,"%d %s %s %s %d %d %d %d %s\n",&(p.id),p.nom,p.prenom,p.nat,&(p.sexe),&(p.d.j),&(p.d.m),&(p.d.a),p.app)!=EOF)
	{
sprintf(date,"%d/%d/%d",p.d.j,p.d.m,p.d.a);
sprintf(sexe,p.sexe==0?"Homme":"Femme");
sprintf(nom,"%s %s", p.nom, p.prenom);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,p.id,NOM,nom,NAT,p.nat,SEXE,sexe,DATE,date,APP,p.app,-1);
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
else{
f = fopen(fname,"a+");
if(f!=NULL){
		while(fscanf(f,"%d %s %s %s %d %d %d %d %s\n",&(p.id),p.nom,p.prenom,p.nat,&(p.sexe),&(p.d.j),&(p.d.m),&(p.d.a),p.app)!=EOF)
	{
sprintf(sexe,p.sexe==0?"Homme":"Femme");
if(p.id==atoi(id)||strcmp(p.nat,nat)==0||strcmp(sexe,genre)==0){
sprintf(date,"%d/%d/%d",p.d.j,p.d.m,p.d.a);
sprintf(nom,"%s %s", p.nom, p.prenom);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,p.id,NOM,nom,NAT,p.nat,SEXE,sexe,DATE,date,APP,p.app,-1);
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
gtk_tree_view_set_reorderable(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_rules_hint(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_search_column(GTK_TREE_VIEW(liste),0);
gtk_tree_view_set_enable_tree_lines(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_grid_lines(GTK_TREE_VIEW(liste),GTK_TREE_VIEW_GRID_LINES_BOTH);
}

void supprimer(int id, char *fname)
{
obs p;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen(fname,"r");
g=fopen("dump.txt","w");
if(f!=NULL&&g!=NULL){
	while(fscanf(f,"%d %s %s %s %d %d %d %d %s\n",&(p.id),p.nom,p.prenom,p.nat,&(p.sexe),&(p.d.j),&(p.d.m),&(p.d.a),p.app)!=EOF)
	{
		if(p.id!=id)
			fprintf(g,"%d %s %s %s %d %d %d %d %s\n",p.id,p.nom,p.prenom,p.nat,p.sexe,p.d.j,p.d.m,p.d.a,p.app);
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Observateur supprimée avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove(fname);
rename("dump.txt",fname);
}
}

obs chercher(int id, char *fname){
FILE *f;
obs p, e={id:-1};
f=fopen(fname,"r");
if(f!=NULL)
{
	while(fscanf(f,"%d %s %s %s %d %d %d %d %s\n",&(p.id),p.nom,p.prenom,p.nat,&(p.sexe),&(p.d.j),&(p.d.m),&(p.d.a),p.app)!=EOF)
	{
	if(p.id==id)
            return p;
	}
	fclose(f);
}
    return e;

}

char* taux_obs(char *fname){
FILE *f=fopen(fname,"r");
obs p;
int c=0, n=0;
if(f!=NULL){ 
while(fscanf(f,"%d %s %s %s %d %d %d %d %s\n",&(p.id),p.nom,p.prenom,p.nat,&(p.sexe),&(p.d.j),&(p.d.m),&(p.d.a),p.app)!=EOF)
   {
	c++;
   if(strcmp(p.nat,"Tunisienne")==0)
     n++;
  }
fclose(f);
}
float x = (float)n/c, y = (float)(c-n)/c;
char *ch = malloc(500);
sprintf(ch, "Tunisiens : %.2f\nEtrangers : %.2f", x*100, y*100);
return ch; 
} 

char* nb_obs(char *fname){
FILE *f=fopen(fname,"r");
obs p;
int c=0;
if(f!=NULL){ 
while(fscanf(f,"%d %s %s %s %d %d %d %d %s\n",&(p.id),p.nom,p.prenom,p.nat,&(p.sexe),&(p.d.j),&(p.d.m),&(p.d.a),p.app)!=EOF)
   {
	c++;
  }
fclose(f);
}
char *ch = malloc(500);
sprintf(ch, "Nombre total d'observateurs : %d", c);
return ch; 
} 
