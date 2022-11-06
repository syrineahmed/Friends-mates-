#include "election.h"

int ajouter(char * filename, election E )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %s %s %s %d %d \n",E.identifiant, E.Date,E.Types d'élèctions,E.Ville,E.Gouvernorat,E.population,E.conseillères);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * filename, int id, election nouv )
{
    int tr=0;
    election E;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %s %s %s %d %d \n",E.identifiant, E.Date,E.Types d'élèctions,E.Ville,E.Gouvernorat,E.population,E.conseillères)!=EOF)
        {
            if(E.identifiant == identifiant)
            {
                fprintf(f2,"%d %d %s %s %s %d %d \n",E.identifiant, E.Date,E.Types d'élèctions,E.Ville,E.Gouvernorat,E.population,E.conseillères);
                tr=1;
            }
            else"%d %d %s %s %s %d %d \n",E.identifiant, E.Date,E.Types d'élèctions,E.Ville,E.Gouvernorat,E.population,E.conseillères);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int supprimer(char * filename, int identifiant)
{
    int tr=0;
    election E;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %s %s %s %d %d \n",&E.identifiant, &E.Date,E.Types d'élèctions,E.Ville,E.Gouvernorat,&E.population,&E.conseillères)!=EOF)
        {
            if(E.identifiant== identifiant)
                tr=1;
            else
                fprintf(f2,"%d %d %s %s %s %d %d \n",E.identifiant, E.Date,E.Types d'élèctions,E.Ville,E.Gouvernorat,E.population,E.conseillères);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
election chercher(char * filename, int identifiant)
{
    identifiant E;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %s %s %d %s %s  %d\n",&E.identifiant, &E.Date,E.Types d'élèctions,E.Ville,E.Gouvernorat,&E.population,&E.conseillères)!=EOF)
        {
            if(E.identifiant== identifiant)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        E.identifiant=-1;
    return E;

