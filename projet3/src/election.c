
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include <gtk/gtk.h>
#include "callbacks.h"
#include "election.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*int nb_conseillers (election e)
{
	if ((e.population)<5000)
   		 e.nb_conseillers=10;
	else if (((e.population)>5000)&&((e.population)<10000))
    		e.nb_conseillers=12;
	else if ((e.population>10000)&&(e.population<25000))
   		 e.nb_conseillers=16;
	else if ((e.population>25000)&& (e.population<50000))
   		 e.nb_conseillers=22;
	else if ((e.population>50000)&& (e.population<100000))
    		e.nb_conseillers=30;
	else if ((e.population>100000)&& (e.population<500000))
   		 e.nb_conseillers=40;
	else
   		 e.nb_conseillers=60;

	return 0;
}
	*/
enum{
Date,
identifiant,
code_postal, 
population,
nb_conseillers,
uneelection,
ville,
municipalite,
COLUMNS
};


void ajouter(election e )
{    
   
    FILE * f=fopen("ELECTION.txt", "a+");
    if(f!=NULL) 
    {
        fprintf(f,"%s %d %d %d %s %s %s %s %s %s \n",e.uneelection,e.y.jour,e.y.mois,e.y.annee,e.identifiant,e.ville,e.municipalite,e.code_postal,e.population,e.nb_conseillers);
        printf("%s",e.uneelection);
	fclose(f);
        
    }
}
 //////////////////////////////////////////////////////////////////

void afficher(GtkWidget *liste)
{
    GtkCellRenderer *renderer;                            
    GtkTreeViewColumn *column;   
    GtkTreeIter iter;  
    GtkListStore *store;
    election e;                    
    char date[30];
    store=NULL;
    FILE *f;

    store= gtk_tree_view_get_model(liste);
    if (store==NULL)
    {
        renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("uneelection", renderer, "text" ,uneelection, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("Date", renderer, "text",Date, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("identifiant", renderer, "text",identifiant, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("ville", renderer, "text",ville, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("municipalite", renderer, "text",municipalite, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("code_postal", renderer, "text",code_postal, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("population", renderer, "text",population, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nb_conseillers", renderer, "text",nb_conseillers, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	
      }	

        store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	f = fopen("ELECTION.txt","r");
	if(f==NULL)
	{
     		return;
	}
	else 
	{
  		 f = fopen("ELECTION.txt", "a+");
        		while(fscanf(f,"%s %d %d %d %s %s %s %s %s %s \n",e.uneelection,&e.y.jour,&e.y.mois,&e.y.annee,e.identifiant,e.ville,e.municipalite,e.code_postal,e.population,e.nb_conseillers)!=EOF)
    		{ 	
	
		sprintf(date, "%d/%d/%d", e.y.jour,e.y.mois,e.y.annee);

		gtk_list_store_append (store, &iter); 
		gtk_list_store_set (store, &iter,uneelection , e.uneelection, Date, date,identifiant,e.identifiant, ville, e.ville, municipalite, e.municipalite,code_postal,e.code_postal, population,e.population, nb_conseillers, e.nb_conseillers,-1);
    		}
    		 fclose (f);
 		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
       }
}    


//////////////////////////////////////////////////////////////
void modifier(election r)

{
    
    election e;
    FILE *f;
    FILE *f2;
    f=fopen("ELECTION.txt","r");
    f2=fopen("ELECTION3.txt","a+");
   

      fprintf(f2,"%s %d %d %d %s %s %s %s %s %s \n",r.uneelection,r.y.jour,r.y.mois,r.y.annee,r.identifiant,r.ville,r.municipalite,r.code_postal,r.population,r.nb_conseillers);
    fscanf(f2,"%s %d %d %d %s %s %s %s %s %s \n",r.uneelection,&r.y.jour,&r.y.mois,&r.y.annee,r.identifiant,r.ville,r.municipalite,r.code_postal,r.population,r.nb_conseillers);
    if (f!=NULL) 
    { 
        
        
      
        while(fscanf(f,"%s %d %d %d %s %s %s %s %s %s \n",e.uneelection,&e.y.jour,&e.y.mois,&e.y.annee,e.identifiant,e.ville,e.municipalite,e.code_postal,e.population,e.nb_conseillers)!=EOF)

            if(strcmp(e.identifiant,r.identifiant)!=0)
            
                fprintf(f2,"%s %d %d %d %s %s %s %s %s %s \n",e.uneelection,e.y.jour,e.y.mois,e.y.annee,e.identifiant,e.ville,e.municipalite,e.code_postal,e.population,e.nb_conseillers);
                
            
            
    }
    fclose(f);
    fclose(f2);
    remove("ELECTION.txt");
    rename("ELECTION3.txt", "ELECTION.txt");
    
}

void supprimer(election r)
{
   
    election e;
    FILE * f=fopen("ELECTION.txt", "r");
    FILE * f2=fopen("nouv.txt", "a+");
    FILE * f3=fopen("ELECTION2.txt", "r");
    if(f!=NULL && f3!=NULL)
    {
       fscanf(f3,"%s %d %d %d %s %s %s %s %s %s \n",r.uneelection,&r.y.jour,&r.y.mois,&r.y.annee,r.identifiant,r.ville,r.municipalite,r.code_postal,r.population,r.nb_conseillers);
        while(fscanf(f,"%s %d %d %d %s %s %s %s %s %s \n",e.uneelection,&e.y.jour,&e.y.mois,&e.y.annee,e.identifiant,e.ville,e.municipalite,e.code_postal,e.population,e.nb_conseillers)!=EOF)
        {
            if(strcmp(e.identifiant,r.identifiant)!=0)
               
            
                fprintf(f2,"%s %d %d %d %s %s %s %s %s %s \n",e.uneelection,e.y.jour,e.y.mois,e.y.annee,e.identifiant,e.ville,e.municipalite,e.code_postal,e.population,e.nb_conseillers);
        }
    }
    fclose(f);
    fclose(f2);
    fclose(f3);
    remove("ELECTION.txt");
    rename("nouv.txt","ELECTION.txt");
    
}


void chercher(election e, char identifiant[20], char code_postal[20])
{
    
    int ok=0;
    FILE * f=fopen("ELECTION.txt", "r");
    FILE * f1 = fopen("ELECTION2.txt", "w");
    if(f==NULL)
    {
	return;
    }
    else
    {	
        while(fscanf(f,"%s %d %d %d %s %s %s %s %s %s \n",e.uneelection,&e.y.jour,&e.y.mois,&e.y.annee,e.identifiant,e.ville,e.municipalite,e.code_postal,e.population,e.nb_conseillers)!=EOF)
        {
            if ((strcmp(identifiant,e.identifiant)==0) && (strcmp(code_postal,e.code_postal)==0))
            {
		fprintf(f1,"%s %d %d %d %s %s %s %s %s %s \n",e.uneelection,e.y.jour,e.y.mois,e.y.annee,e.identifiant,e.ville,e.municipalite,e.code_postal,e.population,e.nb_conseillers);
                ok=1;
			
            }
    }
    }
    fclose(f);
    fclose(f1);
}
void afficher_rech(GtkWidget *liste)
{
    GtkCellRenderer *renderer;                            
    GtkTreeViewColumn *column;   
    GtkTreeIter iter;  
    GtkListStore *store;
    election e;                    
    char date[30];
    store=NULL;
    FILE *f;

    store = gtk_tree_view_get_model(liste);
    if (store==NULL)
    {
        renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("uneelection", renderer, "text" ,uneelection, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("Date", renderer, "text",Date, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("identifiant", renderer, "text",identifiant, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("ville", renderer, "text",ville, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("municipalite", renderer, "text",municipalite, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("code_postal", renderer, "text",code_postal, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("population", renderer, "text",population, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nb_conseillers", renderer, "text",nb_conseillers, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
      }	

        store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	f = fopen("ELECTION2.txt","r");
	if(f==NULL)
	{
     		return;
	}
	else 
	{
  		 f = fopen("ELECTION2.txt", "a+");
        		while(fscanf(f,"%s %d %d %d %s %s %s %s %s %s \n",e.uneelection,&e.y.jour,&e.y.mois,&e.y.annee,e.identifiant,e.ville,e.municipalite,e.code_postal,e.population,e.nb_conseillers)!=EOF)
    		{ 	
	
		sprintf(date, "%d/%d/%d", e.y.jour,e.y.mois,e.y.annee);

		gtk_list_store_append (store, &iter); 
		gtk_list_store_set (store, &iter, uneelection , e.uneelection, Date, date,identifiant,e.identifiant,ville, e.ville, municipalite, e.municipalite,code_postal,e.code_postal, population,e.population, nb_conseillers, e.nb_conseillers,-1);
    		}
    		 fclose (f);
 		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
       }
}    


