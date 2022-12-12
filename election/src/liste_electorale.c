#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "liste_electorale.h"
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<gtk/gtk.h>

enum
{ 
	EID_LISTE,
	DATE_AJOUT,
	EID_TETE_LISTE,
	ESEXE,
	EORIENTATION,
        COLUMNS,	
};


void ajouter (liste_electorale R )
{ 
    FILE *f;
f=fopen("tunisie.txt", "a+");
    if(f!=NULL)
    {
if  ((R.id_liste !="") && ((!strcmp(R.orientation,"gauche")) || (!strcmp(R.orientation,"centre")) || (!strcmp(R.orientation,"droite"))))
{

fprintf(f,"%s %d %d %d %s %s %s \n",R.id_liste,R.date_ajout.j,R.date_ajout.m,R.date_ajout.a,R.id_tete_liste,R.sexe,R.orientation);
                                            
        fclose(f);
    }
}
}

void ajout_vote(liste_electorale V )
{ 
    FILE *f;
f=fopen("electeur.txt", "a+");
    if(f!=NULL)
    {

fprintf(f,"%s %s \n",V.idvote,V.type_vote);
                                            
        fclose(f);
    }
}

/*void affiche_vote( liste_electorale V)
{ 
liste_electorale V;
    FILE *f;
f=fopen("projet.txt", "r");
    if(f!=NULL)
    {

while 
(fscanf(f,"%s %s \n",V.idvote,V.type_vote) !=EOF);
   {
printf ("%s %s \n",V.idvote,V.type_vote);
}                                         
        fclose(f);
    }
  //return V;
}*/
void afficher(GtkWidget *pListView)
{

 


GtkListStore *pListStore;

GtkTreeViewColumn *pColumn;

GtkCellRenderer *pCellRenderer;

GtkTreeIter pIter;


liste_electorale R;
char id_liste[20];
char id_tete_liste[20];
date date_ajout;
char sexe[20];
char orientation [20];

char var1[50],var2[50],var3[50],var4[50],var5[50];

pListStore=NULL;


FILE *f;

pListStore=gtk_tree_view_get_model(pListView);

if (pListStore== NULL) {

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("id_liste",pCellRenderer,"text", EID_LISTE,NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("date_ajout",pCellRenderer,"text",DATE_AJOUT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("id_tete_liste",pCellRenderer,"text",EID_TETE_LISTE,NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);



pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("sexe",pCellRenderer,"text", ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);


pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("orientation",pCellRenderer,"text",EORIENTATION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pListStore = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("tunisie.txt","r");
if (f==NULL){return;}
else{f=fopen("tunisie.txt","a+");
while(fscanf(f,"%s %d %d %d %s %s %s \n",R.id_liste,&R.date_ajout.j,&R.date_ajout.m,&R.date_ajout.a,R.id_tete_liste,R.sexe,R.orientation)!=EOF)
	{
/*sprintf(var1,"%d",l.id_liste);
sprintf(var2,"%d",l.id_election);
sprintf(var3,"%d",l.id_electeur2);
sprintf(var4,"%d",l.id_electeur3);*/
sprintf(var5,"%d/%d/%d",R.date_ajout.j,R.date_ajout.m,R.date_ajout.a);

///

gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,EID_LISTE,R.id_liste,DATE_AJOUT,var5,ESEXE,R.sexe,EID_TETE_LISTE,R.id_tete_liste,EORIENTATION,R.orientation,-1);


}
fclose(f);

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 
g_object_unref(pListStore);
       }
}

}
void chercher(char idchercher[20],GtkWidget *liste)

{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
        
	char id_liste [20];
        char id_tete_liste [20];
        
        date date_ajout;
        
        char orientation[100];
        char sexe[100];
        char var[20];
        
        int tr=0;
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id_liste",renderer,"text",EID_LISTE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("date_ajout", renderer, "text",DATE_AJOUT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id_tete_liste", renderer, "text",EID_TETE_LISTE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("sexe", renderer,"text",ESEXE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	column = gtk_tree_view_column_new_with_attributes("orientation", renderer,   "text",EORIENTATION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,	 G_TYPE_STRING,	 G_TYPE_STRING, G_TYPE_STRING  );
	f=fopen("tunisie.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("tunisie.txt","a+");
		while((fscanf(f,"%s %d %d %d %s %s %s \n ",id_liste,&date_ajout.j,&date_ajout.m,&date_ajout.a,id_tete_liste,sexe,orientation)!=EOF)&&(tr==0))
                      {
                        sprintf(var,"%d %d %d",date_ajout.j,date_ajout.m,date_ajout.a);
                     
                        if (strcmp(id_liste,idchercher)==0)
                        {tr=1;
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EID_LISTE,id_liste, DATE_AJOUT,var, EID_TETE_LISTE, id_tete_liste, ESEXE ,sexe, EORIENTATION, orientation, -1);
		}
                }
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}

}
/*liste_electorale chercher_liste(char *liste, int id)
{
    liste_electorale R;
    int tr=0;
    FILE * f=fopen(liste, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %d %d %d %s %s %s \n",R.id_liste,&R.date_ajout.j,&R.date_ajout.m,&R.date_ajout.a,R.id_tete_liste,R.sexe,R.orientation)!=EOF)
        {
            if(R.id_liste== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        R.id_liste==-1;
    return R;

}*/
/*liste_electorale chercher_liste(int id, GtkWidget *liste)
{
    liste_electorale R;
    int tr=0;
    FILE *f=fopen("tunisie.txt", "r");
    if(f!=NULL)
    {
        while(tr==0&&fscanf(f,"%s %d %d %d %s %s %s \n",R.id_liste,&R.date_ajout.j,&R.date_ajout.m,&R.date_ajout.a,R.id_tete_liste,R.sexe,R.orientation)!=EOF)
            { if(R.id_liste==id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        R.id_liste==-1;
    return R;
}*/
void modifier(liste_electorale R1)
{
liste_electorale R;
int trouve=0;
FILE *f,*f1;
f=NULL;
f1=NULL;
f=fopen("tunisie.txt","r");
f1=fopen("liste.txt","w+");
if(f!=NULL)
{while((fscanf(f,"%s %d %d %d %s %s %s \n",R.id_liste,&R.date_ajout.j,&R.date_ajout.m,&R.date_ajout.a,R.id_tete_liste,R.sexe,R.orientation)!=EOF))
{
if(strcmp(R.id_liste,R1.id_liste)==0)
{trouve=1;

fprintf(f1,"%s %d %d %d %s %s %s \n",R1.id_liste,R1.date_ajout.j,R1.date_ajout.m,R1.date_ajout.a,R1.id_tete_liste,R1.sexe,R1.orientation);
}
else
{fprintf(f1,"%s %d %d %d %s %s %s \n",R.id_liste,R.date_ajout.j,R.date_ajout.m,R.date_ajout.a,R.id_tete_liste,R.sexe,R.orientation);
}
}
}

fclose(f);
fclose(f1);
remove("tunisie.txt");
rename("liste.txt","tunisie.txt");
}
int supprimer(char id[50])
{
    int tr=0;
    
    liste_electorale R;
    FILE *f=fopen("tunisie.txt","r");
    FILE *f2=fopen("nouv.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %d %d %d %s %s %s \n",R.id_liste,&R.date_ajout.j,&R.date_ajout.m,&R.date_ajout.a,R.id_tete_liste,R.sexe,R.orientation)!=EOF)
        {
            if(strcmp(R.id_liste,id)==0)
                tr=1;
            else
                
                fprintf(f2,"%s %d %d %d %s %s %s \n",R.id_liste,R.date_ajout.j,R.date_ajout.m,R.date_ajout.a,R.id_tete_liste,R.sexe,R.orientation);
        }
    }
    fclose(f);
    fclose(f2);
    remove("tunisie.txt");
    rename("nouv.txt","tunisie.txt");
    return tr;
}
/*void supprimer(liste_electorale R)
{	liste_electorale R2;
	FILE *f,*f2; 
	f=fopen("tunisie.txt", "r");
	f2=fopen("nouv.txt", "w");
	if(f==NULL && f2==NULL)
          	return;
        else 
        {
        while(fscanf(f,"%s %d %d %d %s %s %s \n",R.id_liste,&R.date_ajout.j,&R.date_ajout.m,&R.date_ajout.a,R.id_tete_liste,R.sexe,R.orientation)!=EOF)
        {    
             //if (strcmp(R.sexe,R2.sexe)!=0)
            if (strcmp(R.id_liste,R2.id_liste)!=0)  
            fprintf(f2,"%s %d %d %d %s %s %s \n",R.id_liste,R.date_ajout.j,R.date_ajout.m,R.date_ajout.a,R.id_tete_liste,R.sexe,R.orientation);
        }
        
	fclose(f);
	fclose(f2);
remove("tunisie.txt");
rename("nouv.txt", "tunisie.txt");
 
}
}*/
/*void affiche_cherch(GtkWidget *pListView)
{
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
GtkTreeIter pIter;

liste_electorale R;
char id_liste[20];
char id_tete_liste[20];
date date_ajout;
char sexe[20];
char orientation [20];

char var1[50],var2[50],var3[50],var4[50],var5[50];

pListStore=NULL;


FILE *f;

pListStore=gtk_tree_view_get_model(pListView);

if (pListStore== NULL) {

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("id_liste",pCellRenderer,"text", EID_LISTE,NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("date_ajout",pCellRenderer,"text",DATE_AJOUT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("id_tete_liste",pCellRenderer,"text",EID_TETE_LISTE,NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);



pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("sexe",pCellRenderer,"text", ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);


pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("orientation",pCellRenderer,"text",EORIENTATION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pListStore = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("tunisie.txt","r");
if (f==NULL){return;}
else{f=fopen("tunisie.txt","a+");
while(fscanf(f,"%s %d %d %d %s %s %s \n",R.id_liste,&R.date_ajout.j,&R.date_ajout.m,&R.date_ajout.a,R.id_tete_liste,R.sexe,R.orientation)!=EOF)
	{*/
/*sprintf(var1,"%d",l.id_liste);
sprintf(var2,"%d",l.id_election);
sprintf(var3,"%d",l.id_electeur2);
sprintf(var4,"%d",l.id_electeur3);*/
/*sprintf(var5,"%d/%d/%d",R.date_ajout.j,R.date_ajout.m,R.date_ajout.a);

///

gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,EID_LISTE,R.id_liste,DATE_AJOUT,var5,ESEXE,R.sexe,EID_TETE_LISTE,R.id_tete_liste,EORIENTATION,R.orientation,-1);


}
fclose(f);

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 
g_object_unref(pListStore);
       }
}

}*/



/*int ajout_vote (char  *liste, liste_electorale R)
{int n=0;
 int id_liste;
    FILE * f=fopen(liste, "a");
    if(f!=NULL)
    {
R=chercher(liste, id_liste);
n=0;
//printf("\n Tapper 1 si vote non valide");
n=1;
if(n==1){
strcpy(R.typevote,"blanc");
R.vote_blanc++;
}
else       
 {
n=2;
printf("\n vote valide");
R.vote_valide++;
strcpy(R.typevote,"valide");}

          fclose(f);
        return 1;
    }
    else return 0;
}

int ajout_particip (char * liste, liste_electorale R )
{
FILE * f=fopen(liste, "a");
    if(f!=NULL)
     {
      fprintf(f,"%d %d\n",R.id_particip,R.numero_bv);
         fclose(f);
        return 1;
    }
   else return 0;
}

*/
/*int nbrP (char *filename)
{   
int nb=0;
    liste_electorale V;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s \n",V.idvote,V.type_vote)!=EOF)
       {
           nb=nb+1;
       }
fclose(f);
    }
    
    return nb;
}*/
int nombre(char *filename)
{
FILE *f=fopen(filename,"r");
liste_electorale V;
int nb=0;
if(f!=0){ 
             
while(fscanf(f,"%s %s \n",V.idvote,V.type_vote)!=EOF)
{
     if(strcmp(V.type_vote,"voteblanc")==0)
      nb=nb+1;

}
fclose(f);
 }
return nb;
}
float taux(int x,int y)
{
float T;
/*x=nombretotal("tunisie.txt");
y=nombrevote_total("electeur.txt");*/
T=(y/x)*100;
return T;
}
int nombretotal(char *filename)
{
FILE *f=fopen("tunisie.txt","r");
liste_electorale R;
int nbt=0;
if(f!=NULL){ 
             
while(fscanf(f,"%s %d %d %d %s %s %s \n",R.id_liste,&R.date_ajout.j,&R.date_ajout.m,&R.date_ajout.a,R.id_tete_liste,R.sexe,R.orientation)!=EOF)
{
     
      nbt=nbt+1;

}
fclose(f);
 }
return nbt;
}

int nombrevote_total(char *filename)
{
FILE *f=fopen("electeur.txt","r");
liste_electorale V;
int nbvt=0;
if(f!=NULL){ 
             
while(fscanf(f,"%s %s \n",V.idvote,V.type_vote)!=EOF)
{
     
      nbvt=nbvt+1;

}
fclose(f);
 }
return nbvt;
}

/*int NBV (char * liste,int id)
{   
int nbrbv=0;

    liste_electorale R;
    FILE * f=fopen(liste, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%d%d\n",&R.id_particip,&R.numero_bv)!=EOF)
       {
        if (R.numero_bv == id)
           nbrbv++;
       }
    }

    fclose(f);
    return nbrbv;
}


int modifier( char *liste, int id, liste_electorale nouv )
{
    int tr=0;
    liste_electorale R;
    FILE * f=fopen(liste, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s\n",R.date_ajout.j,R.date_ajout.m,R.date_ajout.a,R.id_liste,R.id_tete_liste,R.sexe,R.orientation)!=EOF)
        {
            if(R.id_liste== id)
            {
                fprintf(f,"%s %s %s %s %s %s %s\n",R.date_ajout.j,R.date_ajout.m,R.date_ajout.a,R.id_liste,R.id_tete_liste,R.sexe,R.orientation);
        
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %s %s %s %s\n",R.date_ajout.j,R.date_ajout.m,R.date_ajout.a,R.id_liste,R.id_tete_liste,R.sexe,R.orientation);

        }
    }
    fclose(f);
    fclose(f2);
    remove(liste);
    rename("nouv.txt", liste);
    return tr;

}

void supprimer(char *liste, int id)
{
    int tr=0;
    liste_electorale R;
    FILE * f=fopen(liste, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %d %d %d %s %s %s \n",R.id_liste,&R.date_ajout.j,&R.date_ajout.m,&R.date_ajout.a,R.id_tete_liste,R.sexe,R.orientation)!=EOF)
        {
            if(R.id_liste== id)
                tr=1;
            else
                fprintf(f2,"%s %d %d %d %s %s %s \n",R.id_liste,R.date_ajout.j,R.date_ajout.m,R.date_ajout.a,R.id_tete_liste,R.sexe,R.orientation);

        }
    }
    fclose(f);
    fclose(f2);
    remove(liste);
    rename("nouv.txt", liste);
   // return tr;
}*/
/*void supprimer_liste(int id)
{
    int tr=0;
    liste_electorale R;
    FILE *f=fopen("tunisie.txt","r");
    FILE *f2=fopen("nouv.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %d %d %d %s %s %s \n",R.id_liste,&R.date_ajout.j,&R.date_ajout.m,&R.date_ajout.a,R.id_tete_liste,R.sexe,R.orientation)!=EOF)
        {
            if(R.id_liste==id)
                tr=1;
            else
                fprintf(f2,"%s %d %d %d %s %s %s \n",R.id_liste,R.date_ajout.j,R.date_ajout.m,R.date_ajout.a,R.id_tete_liste,R.sexe,R.orientation);
        }
    }
    fclose(f);
    fclose(f2);
    remove("tunisie.txt");
    rename("nouv.txt","tunisie.txt");
    //return tr;
}*/
/*void supprimer(char id[30],liste_electorale R)
///////////////////////////////////////////////

{	liste_electorale R2;
	FILE *f,*f2; 
	f=fopen("tunisie.txt", "r");
	f2=fopen("nouv.txt", "w");
	if(f==NULL && f2==NULL)
          	return;
        else 
        {
        while(fscanf(f,"%s %d %d %d %s %s %s \n",R2.id_liste,&R2.date_ajout.j,&R2.date_ajout.m,&R2.date_ajout.a,R.id_liste,R2.sexe,R2.orientation)!=EOF)
        {    
             
            if (strcmp(R.id_liste,id)!=0)  
            fprintf(f2,"%s %d %d %d %s %s %s \n",R2.id_liste,R2.date_ajout.j,R2.date_ajout.m,R2.date_ajout.a,R.id_liste,R2.sexe,R2.orientation);
        }
        
	fclose(f);
	fclose(f2);
remove("tunisie.txt");
rename("nouv.txt", "tunisie.txt");

}
}*/
/*void supprimer(char *liste , char id[50])
{
    int tr=0;
    liste_electorale R;
    FILE * f=fopen(liste, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %d %d %d %s %s %s \n",R.id_liste,&R.date_ajout.j,&R.date_ajout.m,&R.date_ajout.a,R.id_tete_liste,R.sexe,R.orientation)!=EOF)
        {
            if(strcmp(R.id_liste,id)==0)
                tr=1;
            else
                fprintf(f2,"%s %d %d %d %s %s %s \n",R.id_liste,R.date_ajout.j,R.date_ajout.m,R.date_ajout.a,R.id_tete_liste,R.sexe,R.orientation);

        }
    }
    fclose(f);
    fclose(f2);
    remove(liste);
    rename("nouv.txt", liste);
    //return tr;
}*/
/*void supprimer(char idsupp[20],GtkWidget *liste)

{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
        
	char id_liste [20];
        char id_tete_liste [20];
        
        date date_ajout;
        
        char orientation[100];
        char sexe[100];
        char var[20];
        
        int tr=0;
	store=NULL;
	FILE *f,*f2;
	store=gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id_liste",renderer,"text",EID_LISTE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("date_ajout", renderer, "text",DATE_AJOUT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id_tete_liste", renderer, "text",EID_TETE_LISTE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("sexe", renderer,"text",ESEXE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	column = gtk_tree_view_column_new_with_attributes("orientation", renderer,   "text",EORIENTATION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,	 G_TYPE_STRING,	 G_TYPE_STRING, G_TYPE_STRING  );
	f=fopen("tunisie.txt","r");
	if(f!=NULL && f2!=NULL)
	{
		return;
	}
	else
	{
		f= fopen("tunisie.txt","a+");
		while((fscanf(f,"%s %d %d %d %s %s %s \n ",id_liste,&date_ajout.j,&date_ajout.m,&date_ajout.a,id_tete_liste,sexe,orientation)!=EOF)&&(tr==0))
                      {
                        sprintf(var,"%d %d %d",date_ajout.j,date_ajout.m,date_ajout.a);
                     
                        if (strcmp(id_liste,idsupp)==0)
                        {tr=1;
else{
                fprintf(f2,"%s %d %d %d %s %s %s \n",id_liste,&date_ajout.j,&date_ajout.m,&date_ajout.a,id_tete_liste,sexe,orientation);

        if (strcmp(id_liste,idsupp)==0)}}*/
    
    /*fclose(f);
    fclose(f2);
    remove(liste);
    rename("nouv.txt", liste);*/

			/*gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EID_LISTE,id_liste, DATE_AJOUT,var, EID_TETE_LISTE, id_tete_liste, ESEXE ,sexe, EORIENTATION, orientation, -1);
		}
                }
		fclose(f);
                fclose(f2);
                remove(liste);
                rename("nouv.txt", liste);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}

}*/
/*liste_electorale chercher(char *liste, int id)
{
    liste_electorale R;
    int tr=0;
    FILE * f=fopen(liste, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d %d %d %d %s %s\n",&R.date_ajout.j,&R.date_ajout.m,&R.date_ajout.a,&R.id_liste,&R.id_tete_liste,R.sexe,R.orientation)!=EOF)
        {
            if(R.id_liste== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        R.id_liste=-1;
    return R;

}
int calculfemmehomme(char * liste)
{
liste_electorale R;
 int nbrf=0;
    FILE * f=fopen(liste, "r");
    if(f!=NULL)
    {
while(fscanf(f,"%d %d %d %d %d %s %s\n",&R.date_ajout.j,&R.date_ajout.m,&R.date_ajout.a,&R.id_liste,&R.id_tete_liste,R.sexe,R.orientation)!=EOF)
{
      // if (strcmp(R.sexe,"femme"))
	nbrf++;
}
}
    fclose(f);
    return nbrf;
  

}
int nbrV (char * liste)
{   
int nbrtv=0;
    liste_electorale R;
    FILE * f=fopen(liste, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %d %s %s\n",&R.date_ajout.j,&R.date_ajout.m,&R.date_ajout.a,&R.id_liste,&R.id_tete_liste,R.sexe,R.orientation)!=EOF)
       {
        if (R.vote_valide !=0  && R.vote_blanc !=0)
           nbrtv++;
       }
    }

    
    fclose(f);
    return nbrtv;
}
liste_electorale critere (char * liste)
{
liste_electorale R;
int tr=0;
char sexe[20];
char orientation[20];
FILE * f=fopen(liste, "r");
    if(f!=NULL)
      {
       while(tr==0 && fscanf(f,"%s %s %s %s %s %s %s\n",R.date_ajout.j,R.date_ajout.m,R.date_ajout.a,R.id_liste,R.id_tete_liste,R.sexe,R.orientation)!=EOF)
      {
        if(strcmp(R.sexe,sexe) && strcmp(R.orientation,orientation))
           tr=1;
      }
   }
fclose(f);
if (tr==0)
    R.sexe==NULL;
    R.orientation==NULL;
    return R;
}
 */


/*float TPE (int A,int B)
{
float TPE;
TP=(A/B);
return TP;
}*/



