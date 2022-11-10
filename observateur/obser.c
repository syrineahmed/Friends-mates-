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
