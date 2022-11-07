#include "obsevateur.h"
#include<stdio.h>
int ajouter(observateur O, char filename [])
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %d %s  %s %s %s       %s\n",O.Id,O.DN.jour,O.DN.mois,O.DN.annee,O.Nom,O.Prenom,O.Nationalite,O.Profession,O.Genre);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifier(int id, observateur nouvO, char * filename)
{
observateur O;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%d %d %d %d %s  %s %s %s %s",&O.Id,&O.DN.jour,&O.DN.mois,&O.DN.annee,O.Nom,O.Prenom,O.Nationalite,O.Profession,O.Genre)!=EOF)
{
if(O.Id!=Id)
        fprintf(f2,"%d %d %d %d %s  %s %s %s %s\n",O.Id,O.DN.jour,O.DN.mois,O.DN.annee,O.Nom,O.Prenom,O.Nationalite,O.Profession,O.Genre);
else

  fprintf(f2,"%d %d %d %d %s  %s %s %s %s\n",nouvO.Id,nouvO.DN.jour,nouvO.DN.mois,nouvO.DN.annee,nouvO.Nom,nouvO.Prenom,nouvO.Nationalite,nouvO.Profession,nouvO.Genre);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }
  
}

int supprimer(int Id, char * filename)
{
observateur O;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%d %d %d %d %s  %s %s %s %s",&O.Id,&O.DN.jour,&O.DN.mois,&O.DN.annee,O.Nom,O.Prenom,O.Nationalite,O.Profession,O.Genre)!=EOF)
{
if(O.id!=Id)
        fprintf(f2,"%d %d %d %d %s  %s %s %s %s\n",O.Id,O.DN.jour,O.DN.mois,O.DN.annee,O.Nom,O.Prenom,O.Nationalite,O.Profession,O.Genre);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }
}

observateur chercher(int Id, char * filename)
{
observateur O; int tr=0;
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%d %d %d %d %s  %s %s %s %s",&O.Id,&O.DN.jour,&O.DN.mois,&O.DN.annee,O.Nom,O.Prenom,O.Nationalite,O.Profession,O.Genre)!=EOF && tr==0)
{if(Id==O.Id)
tr=1;
}
}
if(tr==0)
O.Id=-1;
return O;

}
