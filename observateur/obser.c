#include "observateur.h"


int ajouter(char * OBSERVATEUR, observateur ob )
{ 
    FILE * f=fopen(OBSERVATEUR, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %d  %s %s %s %s %s  \n",ob.y.jour,ob.y.mois,ob.y.annee,ob.identifiant,ob.prenom,ob.nom,ob.nationalite,ob.profession,ob.genre);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * OBSERVATEUR, int identifiant , observateur nouv )
{
    int tr=0;
    observateur ob;
    FILE * f=fopen(OBSERVATEUR, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d  %s %s %s %s %s \n",&ob.y.jour,&ob.y.mois,&ob.y.annee,&ob.identifiant,ob.prenom,ob.nom,ob.nationalite,ob.profession,ob.genre)!=EOF)
        {
            if(ob.identifiant== identifiant)
            {
                fprintf(f2,"%d %d %d %d  %s %s %s %s %s \n",nouv.y.jour,nouv.y.mois,nouv.y.annee,nouv.identifiant,nouv.prenom,nouv.nom,nouv.nationalite,nouv.profession,nouv.genre);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %d %d  %s %s %s %s %s\n",ob.y.jour,ob.y.mois,ob.y.annee,ob.identifiant,ob.prenom,ob.nom,ob.nationalite,ob.profession,ob.genre);

        }
    }
    fclose(f);
    fclose(f2);
    remove(OBSERVATEUR);
    rename("nouv.txt", OBSERVATEUR);
    return tr;

}
int supprimer(char * OBSERVATEUR, int identifiant)
{
    int tr=0;
    observateur ob;
    FILE * f=fopen(OBSERVATEUR, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d  %s %s %s %s %s\n",&ob.y.jour,&ob.y.mois,&ob.y.annee,&ob.identifiant,ob.prenom,ob.nom,ob.nationalite,ob.profession,ob.genre)!=EOF)
        {
            if(ob.identifiant== identifiant)
                tr=1;
            else
                fprintf(f2,"%d %d %d %d  %s %s %s %s %s\n",ob.y.jour,ob.y.mois,ob.y.annee,ob.identifiant,ob.prenom,ob.nom,ob.nationalite,ob.profession,ob.genre);
        }
    }
    fclose(f);
    fclose(f2);
    remove(OBSERVATEUR);
    rename("nouv.txt", OBSERVATEUR);
    return tr;
}
observateur chercher(char * OBSERVATEUR, int identifiant)
{
    observateur ob;
    int tr=0;
    FILE * f=fopen(OBSERVATEUR, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d %d %d  %s %s %s %s %s\n",&ob.y.jour,&ob.y.mois,&ob.y.annee,&ob.identifiant,ob.prenom,ob.nom,ob.nationalite,ob.profession,ob.genre)!=EOF)
        {
            if(ob.identifiant== identifiant)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        ob.identifiant=-1;
    return ob;

}
float calcultn(char * OBSERVATEUR)
{
observateur ob;
int tn=0;
int inon=0;
    FILE * f=fopen(OBSERVATEUR, "r");
    if(f!=NULL)
{
    while(fscanf(f,"%d %d %d %d  %s %s %s %s %s \n",&ob.y.jour,&ob.y.mois,&ob.y.annee,&ob.identifiant,ob.prenom,ob.nom,ob.nationalite,ob.profession,ob.genre)!=EOF)
   
       if (strcmp(ob.nationalite,"nonetranger"))
	tn++;}

    fclose(f);
    return tn;
 }
float calculte(char * OBSERVATEUR)
{
observateur ob;
int te=0;
int inon=0;
    FILE * f=fopen(OBSERVATEUR, "r");
    if(f!=NULL)
    { while(fscanf(f,"%d %d %d %d  %s %s %s %s %s \n",&ob.y.jour,&ob.y.mois,&ob.y.annee,&ob.identifiant,ob.prenom,ob.nom,ob.nationalite,ob.profession,ob.genre)!=EOF)
       
if (strcmp(ob.nationalite,"etranger"))
	te++;}
    fclose(f);
    return te;
 }
float agemoyen(char * OBSERVATEUR)
{observateur ob;
int nob=0;
int b=0;
    FILE * f=fopen(OBSERVATEUR, "r");
    if(f!=NULL)
    { while(fscanf(f,"%d %d %d %d  %s %s %s %s %s \n",&ob.y.jour,&ob.y.mois,&ob.y.annee,&ob.identifiant,ob.prenom,ob.nom,ob.nationalite,ob.profession,ob.genre)!=EOF)
{nob++;
b=b+(2022-ob.y.annee);

}
}
fclose(f);
    return b;
}
float nobr(char * OBSERVATEUR)
{observateur ob;
int nbb=0;
    FILE * f=fopen(OBSERVATEUR, "r");
    if(f!=NULL)
    { while(fscanf(f,"%d %d %d %d  %s %s %s %s %s \n",&ob.y.jour,&ob.y.mois,&ob.y.annee,&ob.identifiant,ob.prenom,ob.nom,ob.nationalite,ob.profession,ob.genre)!=EOF)
nbb++;
}
fclose(f);
    return nbb;

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
}
