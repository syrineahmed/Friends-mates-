#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "election.h"

#include<string.h>
#include<stdio.h>

 /////////
//condition sur les conseillers autotmatique
//design

void //affichage
on_treeviewafficher_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter;
gchar* identifiant;
gchar* Date;
gchar* population;
gchar* nb_conseillers;
gchar* code_postal;
gchar* ville ;
gchar* municipalite;
gchar* uneelection;
election e;
char date[30]; 
GtkWidget *treeview1 ;


GtkTreeModel *model = gtk_tree_view_get_model(treeview);

 if (gtk_tree_model_get_iter(model, &iter, path)) 
{
sprintf(date, "%d/%d/%d", e.y.jour,e.y.mois,e.y.annee);

gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &Date,1,&uneelection,2,&identifiant,3,&ville,4,&municipalite,5,&code_postal,6,
&population,7,&nb_conseillers,8, -1);

strcpy(date,Date);
strcpy(e.uneelection,uneelection);
strcpy(e.identifiant,identifiant);
strcpy(e.ville,ville);
strcpy(e.municipalite,municipalite);
strcpy(e.code_postal,code_postal);
strcpy(e.population,population);
strcpy(e.nb_conseillers,nb_conseillers);

treeview=lookup_widget("windowaffiche","treeviewafficher");

afficher(treeview);
}

}
//////

void
on_buttondeconnexion_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
//pas encore
}

      /////button modif///
void
on_buttonModifier__clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowModifier;
GtkWidget *windowAffich;
windowAffich = lookup_widget(button,"windowaffiche");
gtk_widget_destroy(windowAffich);

windowModifier = lookup_widget(button,"windowchercher01");
windowModifier = create_windowchercher01();
gtk_widget_show(windowModifier);
}

          ///////////////affficheverschercher///////////////////
void
on_buttonchercher_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowrecherche;
GtkWidget *windowMenu;
windowMenu = lookup_widget(button,"windowaffiche");
gtk_widget_destroy(windowMenu);

windowrecherche = lookup_widget(button,"windowchercher01");
windowrecherche = create_windowchercher01();
gtk_widget_show(windowrecherche);

}
//afficheversajout////
void
on_buttonajouter_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAjout;
GtkWidget *windowaffiche;
windowaffiche = lookup_widget(button,"windowaffiche");
gtk_widget_destroy(windowaffiche);

windowAjout = lookup_widget(button,"windowajout");
windowAjout = create_windowajout();
gtk_widget_show(windowAjout);
}
///////////////////////
void
on_buttonsupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowafficheee;
windowafficheee = lookup_widget(button,"windowaffiche");
gtk_widget_destroy(windowafficheee);

windowSupprimer = lookup_widget(button,"windowchercher01");
windowSupprimer = create_windowchercher01();
gtk_widget_show(windowSupprimer);
}



////////annulerajout/////

void
on_buttonannuler_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAjjout;
GtkWidget *windowaffiiche;
windowAjjout = lookup_widget(button,"windowajout");
gtk_widget_destroy(windowAjjout);

windowaffiiche = lookup_widget(button,"windowaffiche");
windowaffiiche = create_windowaffiche();
gtk_widget_show(windowaffiiche);
}

               //////////////////windowajout/////////////////////
int choix ;
void on_buttonvalider_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

election e ; 
GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9;

GtkWidget *fenetre_ajout; 
GtkWidget *validation; 
GtkWidget *fenetre_affiche;
GtkWidget *treeviewafficher;
fenetre_ajout=lookup_widget (button, "windowajout");

input1=lookup_widget(button, "spinbuttonjour");
input2=lookup_widget(button, "spinbuttonmois");
input3=lookup_widget(button, "spinbuttonannee");
input4=lookup_widget(button, "entryid");
input5=lookup_widget(button, "combobox1");
input6=lookup_widget(button, "entrycode");
input7=lookup_widget(button, "entrypopulation01");
input8=lookup_widget(button, "entryconseilleres");
input9=lookup_widget(button, "entrymunicipalite");

strcpy(e.ville,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
strcpy(e.identifiant,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(e.code_postal,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(e.population,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(e.nb_conseillers,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(e.municipalite,gtk_entry_get_text(GTK_ENTRY(input9)));


e.y.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input1));
e.y.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
e.y.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));

if(choix==1) 
strcpy(e.uneelection,"Municipalles");	
else if(choix==2)
strcpy(e.uneelection,"Présidentielles"); 
ajouter(e);
validation=create_dialogconfirmer();
gtk_widget_show(validation); 




 gtk_widget_destroy(fenetre_ajout);
 fenetre_affiche=lookup_widget (button, "windowaffiche");
 fenetre_affiche=create_windowaffiche();

 gtk_widget_show(fenetre_affiche); 

 treeviewafficher=lookup_widget(fenetre_affiche,"treeviewafficher");
 afficher(treeviewafficher);
}

//////////confirmajout/////

void
on_buttonok_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ok;
fenetre_ok = lookup_widget(button,"dialogconfirmer");
gtk_widget_destroy(fenetre_ok);

}
////////radiobutton////
void
on_radiobuttonpresidentielle01_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 choix=2;
}
void
on_radiobuttonmunicipales_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 choix=1;
}
/////anuulerlamodif////

void
on_buttonannuler1_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmod;
GtkWidget *windowaccueil;
windowmod = lookup_widget(button,"windowmodifier");
gtk_widget_destroy(windowmod);

windowaccueil = lookup_widget(button,"windowaffiche");
windowaccueil = create_windowaffiche();
gtk_widget_show(windowaccueil);
}

//////////// winodwmodifier////

void
on_buttonvalider1_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
election r ; 
GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9, *input10;

GtkWidget *fenetre_modif; 
GtkWidget *validation; 
GtkWidget *fenetre_affiche;
GtkWidget *treeviewafficher;
fenetre_modif=lookup_widget (button, "windowmodifier");

input1=lookup_widget(button, "spinbuttonjour1");
input2=lookup_widget(button, "spinbuttonmois1");
input3=lookup_widget(button, "spinbuttonannee1");
input4=lookup_widget(button, "labelid044");
input5=lookup_widget(button, "comboboxville1");
input6=lookup_widget(button, "entrycode1");
input7=lookup_widget(button, "entrypop1");
input8=lookup_widget(button, "entryconseill1");
input9=lookup_widget(button, "entry8");
input10=lookup_widget(button,"labeltype045");
strcpy(r.ville,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));

strcpy(r.code_postal,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(r.population,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(r.nb_conseillers,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(r.municipalite,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(r.identifiant,gtk_label_get_text(GTK_LABEL(input4)));
strcpy(r.uneelection,gtk_label_get_text(GTK_LABEL(input10)));



r.y.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input1));
r.y.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
r.y.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));

modifier(r);
fenetre_modif=lookup_widget (button,"windowmodifier");
gtk_widget_destroy(fenetre_modif);
fenetre_affiche=lookup_widget (button,"windowaffiche");
fenetre_affiche=create_windowaffiche();

gtk_widget_show(fenetre_affiche); 

treeviewafficher=lookup_widget(fenetre_affiche,"treeviewafficher");

afficher(treeviewafficher);
validation=create_dialogconfirmermodif();
gtk_widget_show(validation); 

}



/////////////// affichermodif/////
void
on_buttonaffiche1_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *diagsuccee;
//GtkWidget *windowaccueil;
diagsuccee = lookup_widget(button,"dialogconfirmermodif");
gtk_widget_destroy(diagsuccee);

//windowaccueil = lookup_widget(button,"windowaffiche");
//windowaccueil = create_windowaffiche();
//gtk_widget_show(windowaccueil);
}
///////////////

void
on_buttonaccueil__clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowdiag;
GtkWidget *windowaccueil;
windowdiag = lookup_widget(button,"dialogcherchernon");
gtk_widget_destroy(windowdiag);

windowaccueil = lookup_widget(button,"windowaffiche");
windowaccueil = create_windowaffiche();
gtk_widget_show(windowaccueil);
}
//////////////////


void
on_treeviewchercher_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}

                    ///////////////windowrmodif/////////////////
void
on_buttonmodif2_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
election e;
GtkWidget *windowMenu;
GtkWidget *windowModi;
FILE *fp;
fp = fopen("ELECTION2.txt","a+");

windowMenu = lookup_widget(button,"windowresultatrecherche");
gtk_widget_destroy(windowMenu);
windowModi = create_windowmodifier_();
gtk_widget_show(windowModi);

GtkWidget *output1, *output2, *output3, *output4, *output5, *output6, *output7, *output8, *output9, *output10;



if(fp!=NULL)
{
while (fscanf(fp,"%s %d %d %d %s %s %s %s %s %s \n",e.uneelection,&e.y.jour,&e.y.mois,&e.y.annee,e.identifiant,e.ville,e.municipalite,e.code_postal,e.population,e.nb_conseillers)!=EOF)
{
	output1 = lookup_widget(windowModi, "spinbuttonjour1");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output1), e.y.jour);


	output2 = lookup_widget(windowModi, "spinbuttonmois1");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output2), e.y.mois);


	output3 = lookup_widget(windowModi, "spinbuttonannee1");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output3), e.y.annee);	

	output4 = lookup_widget(windowModi, "comboboxville1");
	gtk_combo_box_get_active_text(GTK_COMBO_BOX(output4));

	output5 = lookup_widget(windowModi, "entrycode1");
	gtk_entry_set_text(GTK_ENTRY(output5), e.code_postal);

	output6 = lookup_widget(windowModi, "entry8");
	gtk_entry_set_text(GTK_ENTRY(output6), e.municipalite);

	output7 = lookup_widget(windowModi, "entrypop1");
	gtk_entry_set_text(GTK_ENTRY(output7), e.population);

	output8 = lookup_widget(windowModi, "entryconseill1");
	gtk_entry_set_text(GTK_ENTRY(output8), e.nb_conseillers);
	
	
	output9 = lookup_widget(windowModi, "labelid044");
	gtk_label_set_text(GTK_LABEL(output9), e.identifiant);


	output10 = lookup_widget(windowModi, "labeltype045");
	gtk_label_set_text(GTK_LABEL(output10), e.uneelection);	


	

}
}

fclose(fp);


}

/////dechercherverssupp/////
void
on_buttonsupp2_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *windowdiag;
GtkWidget *windowaccueil;
windowdiag = lookup_widget(button,"windowresultatrecherche");
gtk_widget_destroy(windowdiag);

//windowaccueil = lookup_widget(button,"windowaffiche");
windowaccueil = create_dialogconfsuppr();
gtk_widget_show(windowaccueil);

}

////////////checkbutton///////////////
int CHOIX[] = {0,0} ;
void
on_checkbuttonoui_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{CHOIX[0] = 1;}
else
{CHOIX[0] = 0;}
}


void
on_checkbuttonnon_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{CHOIX[1] = 1;}
else
{CHOIX[1] = 0;}
}









             ///////////////////windowchercher01////////////////////
void
on_buttonchercher01_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

 GtkWidget *fenetre_menu01;
 GtkWidget *fenetre_ajout01;
 GtkWidget *fenetre_ajout02;
 GtkWidget *treeviewchercher;
 GtkWidget *input1;
 GtkWidget *input2;
 election r;
 char identifiant[20];
 char code_postal[20];
 int ok ;

 input1=lookup_widget (button, "entrychercher");
 input2=lookup_widget (button, "entrycodech");
 strcpy(identifiant,gtk_entry_get_text(GTK_ENTRY(input1)));
 strcpy(code_postal,gtk_entry_get_text(GTK_ENTRY(input2)));
 chercher(r,identifiant, code_postal);


 fenetre_menu01=lookup_widget (button,"windowchercher01");
 gtk_widget_destroy(fenetre_menu01);
 
 fenetre_ajout01=create_windowresultatrecherche();
 gtk_widget_show(fenetre_ajout01); 

 treeviewchercher=lookup_widget(fenetre_ajout01,"treeviewchercher");

   
 afficher_rech(treeviewchercher);
}

///affichersupp///
//int CHOIX[] = {0,0};
void
on_okbutton1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modif; 
GtkWidget *fenetre_affiche;
GtkWidget *treeviewafficher;
election r ; 
fenetre_modif=lookup_widget (button,"dialogconfsuppr");
gtk_widget_destroy(fenetre_modif);
fenetre_affiche=lookup_widget (button,"windowaffiche");
if ((CHOIX[0]==1) && (CHOIX[1]==0))
{
 supprimer(r);

fenetre_affiche=create_windowaffiche();

gtk_widget_show(fenetre_affiche); 

treeviewafficher=lookup_widget(fenetre_affiche,"treeviewafficher");

afficher(treeviewafficher);
} 
else
{

fenetre_affiche=create_windowaffiche();

gtk_widget_show(fenetre_affiche); 

treeviewafficher=lookup_widget(fenetre_affiche,"treeviewafficher");

afficher(treeviewafficher);
}
//il faut que si oui tfaskh sinon tmshy lel affiche ken nzelt alihom zouz me yaml shy 
}

///progcheckbutton///
void
on_OUINON_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
char texte [100]="";
GtkWidget* output;
if(CHOIX[0]==1)  
strcpy(texte,"OUI");	
else if(CHOIX[1]==1)
strcpy(texte,"NON"); 
output=lookup_widget(button,"label64");
gtk_label_set_text (GTK_LABEL(output),texte);

}

//annulerchercher///
void
on_buttonannulerrecherche_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowrecherche;
GtkWidget *windowMenu;
windowrecherche = lookup_widget(button,"windowchercher01");

gtk_widget_destroy(windowrecherche);

windowMenu = lookup_widget(button,"windowaffiche");
windowMenu = create_windowaffiche();
gtk_widget_show(windowMenu);
}


void
on_buttonaccueiil_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowrecherche;
GtkWidget *windowMenu;
windowrecherche = lookup_widget(button,"windowresultatrecherche");

gtk_widget_destroy(windowrecherche);

windowMenu = lookup_widget(button,"windowaffiche");
windowMenu = create_windowaffiche();
gtk_widget_show(windowMenu);
}

