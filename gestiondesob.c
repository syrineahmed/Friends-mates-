#include "observateur.h"
#include<stdio.h>
int ajouter(observateur O, char * OBSERVATEUR )
{
    FILE * f=fopen(OBSERVATEUR, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %d %s  %s %s %s %s\n",O.Id,O.DN.jour,O.DN.mois,O.DN.annee,O.Nom,O.Prenom,O.Nationalite,O.Profession,O.Genre);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifier(int Id, observateur nouvO, char * OBSERVATEUR)
{int tr=0;
observateur O;
    FILE * f=fopen(OBSERVATEUR, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f!=NULL &&  f2!=NULL)
    {

while(fscanf(f,"%d %d %d %d %s  %s %s %s %s\n",&O.Id,&O.DN.jour,&O.DN.mois,&O.DN.annee,O.Nom,O.Prenom,O.Nationalite,O.Profession,O.Genre)!=EOF)
{
if(O.Id==Id)
{
       fprintf(f2,"%d %d %d %d %s  %s %s %s %s\n",nouvO.Id,nouvO.DN.jour,nouvO.DN.mois,nouvO.DN.annee,nouvO.Nom,nouvO.Prenom,nouvO.Nationalite,nouvO.Profession,nouvO.Genre);
tr=1 ;
}
    else

        fprintf(f2,"%d %d %d %d %s  %s %s %s %s\n",O.Id,O.DN.jour,O.DN.mois,O.DN.annee,O.Nom,O.Prenom,O.Nationalite,O.Profession,O.Genre);
}
}
        fclose(f);
        fclose(f2);
remove(OBSERVATEUR);
rename("aux.txt", OBSERVATEUR);
        return tr;
    }
  


int supprimer(int Id, char * OBSERVATEUR)
{ int tr=0;
observateur O;
    FILE * f=fopen(OBSERVATEUR, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f!=NULL && f2!=NULL)
    {

while(fscanf(f,"%d %d %d %d %s  %s %s %s %s",&O.Id,&O.DN.jour,&O.DN.mois,&O.DN.annee,O.Nom,O.Prenom,O.Nationalite,O.Profession,O.Genre)!=EOF)
{
if(O.Id==Id)
    tr=1;
    else
        fprintf(f2,"%d %d %d %d %s  %s %s %s %s\n",O.Id,O.DN.jour,O.DN.mois,O.DN.annee,O.Nom,O.Prenom,O.Nationalite,O.Profession,O.Genre);

}
    }
        fclose(f);
        fclose(f2);
remove(OBSERVATEUR);
rename("aux.txt", OBSERVATEUR);
        return tr;
    }


observateur chercher(int Id, char * OBSERVATEUR)
{
observateur O; int tr=0;
    FILE * f=fopen(OBSERVATEUR, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%d %d %d %d %s  %s %s %s %s",&O.Id,&O.DN.jour,&O.DN.mois,&O.DN.annee,O.Nom,O.Prenom,O.Nationalite,O.Profession,O.Genre)!=EOF && tr==0)
{if(O.Id==Id)
tr=1;
}
}
    fclose(f)
if(tr==0)
O.Id=-1;
return O;

}
