#include "election.h"
int nb_conseillers (election e)
{
	if ((e.population)<5000)
   		 e.nb_conseillers=10;
	else if (((e.population)>5000)&&((e.population)<10000))
    		e.co=12;
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
	

int ajouter(char * ELECTION, election e )
{ 
    FILE * f=fopen(ELECTION, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %d %d %d %d %s %s %s \n",e.y.jour,e.y.mois,e.y.annee,e.identifiant,e.population,e.nb_conseillers,e.municipalite,e.ville,e.gouvernorat,e.uneelection);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * ELECTION, int identifiant , election nouv )
{
    int tr=0;
    election e;
    FILE * f=fopen(ELECTION, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %d %d %d %s %s %s \n",&e.y.jour,&e.y.mois,&e.y.annee,&e.identifiant,&e.population,&e.nb_conseillers,&e.municipalite,e.ville,e.gouvernorat,e.uneelection)!=EOF)
        {
            if(e.identifiant== identifiant)
            {
                fprintf(f2,"%d %d %d %d %d %d %d %s %s %s \n",e.y.jour,e.y.mois,e.y.annee,e.identifiant,e.population,e.nb_conseillers,e.municipalite,e.ville,e.gouvernorat,e.uneelection);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %d %d %d %d %d %s %s %s \n",e.y.jour,e.y.mois,e.y.annee,e.identifiant,e.population,e.nb_conseillers,e.municipalite,e.ville,e.gouvernorat,e.uneelection);

        }
    }
    fclose(f);
    fclose(f2);
    remove(ELECTION);
    rename("nouv.txt", ELECTION);
    return tr;

}
int supprimer(char * ELECTION, int identifiant)
{
    int tr=0;
    election e;
    FILE * f=fopen(ELECTION, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %d %d %d %s %s %s \n",&e.y.jour,&e.y.mois,&e.y.annee,&e.identifiant,&e.population,&e.nb_conseillers,&e.municipalite,e.ville,e.gouvernorat,e.uneelection)!=EOF)
        {
            if(e.identifiant== identifiant)
                tr=1;
            else
                fprintf(f2,"%d %d %d %d %d %d %d %s %s %s \n",e.y.jour,e.y.mois,e.y.annee,e.identifiant,e.population,e.nb_conseillers,e.municipalite,e.ville,e.gouvernorat,e.uneelection);
        }
    }
    fclose(f);
    fclose(f2);
    remove(ELECTION);
    rename("nouv.txt", ELECTION);
    return tr;
}
election chercher(char * ELECTION, int munic)
{
    election e;
    int tr=0;
    FILE * f=fopen(ELECTION, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d %d %d %d %d %d %s %s %s \n",&e.y.jour,&e.y.mois,&e.y.annee,&e.identifiant,&e.population,&e.nb_conseillers,&e.municipalite,e.ville,e.gouvernorat,e.uneelection)!=EOF)
        {
            if(e.municipalite== munic)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        e.identifiant=-1;
    return e;

}
