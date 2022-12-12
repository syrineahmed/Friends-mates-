#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "liste_electorale.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"


char b[150];
char b1[150];
char c[150];
char c1[150];

liste_electorale R;
liste_electorale V;
void
on_comboboxentry1_changed              (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

}


void
on_radiobutton1homme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{strcpy(b,"homme");}
}


void
on_radiobutton2femme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{strcpy(b,"femme");}
}


void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
liste_electorale R;
int a=0;
date date_ajout;



GtkWidget *label12,*label13;
GtkWidget *input1, *input2,  *orientation;
GtkWidget *window2aj;
GtkWidget *jour, *mois, *annee;
window2aj=lookup_widget(objet,"window2aj");
/////////
jour=lookup_widget(GTK_WIDGET(objet),"spinbutton1jour");
mois=lookup_widget(GTK_WIDGET(objet),"spinbutton2mois");
annee=lookup_widget(GTK_WIDGET(objet),"spinbutton3annee");
//////////
R.date_ajout.j=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
R.date_ajout.m=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
R.date_ajout.a=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
///////

input1=lookup_widget(objet,"entry1");
input2=lookup_widget(objet,"entry2");

orientation=lookup_widget(objet, "comboboxentry1");
strcpy(R.id_liste,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(R.id_tete_liste,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(R.sexe,b);
strcpy(R.orientation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(orientation)));




label12=lookup_widget(window2aj,"label12");
label13=lookup_widget(window2aj,"label13");


if (strcmp(R.id_liste,"")==0)
{a=1;
gtk_widget_show(label12);
}
else
{gtk_widget_hide(label12);
}
if (strcmp(R.id_tete_liste,"")==0)
{a=1;
gtk_widget_show(label13);
}
else
{gtk_widget_hide(label13);
}
if (a==0)
{ajouter(R);}
}


void
on_button2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window2aj;
GtkWidget *window4af;
GtkWidget *treeview1;
gchar*Date;
char date[30];
sprintf(date,"%d %d %d",R.date_ajout.j,R.date_ajout.m,R.date_ajout.a);
window2aj=lookup_widget(objet,"window2aj");

gtk_widget_destroy(window2aj);
window4af=lookup_widget(objet,"window4af");
window4af=create_window4af();

gtk_widget_show(window4af);


treeview1=lookup_widget(window4af,"treeview1");

afficher(treeview1);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
        GtkTreeIter iter;
	gchar* id_liste;
	gchar* id_tete_liste;
	gchar* date_ajout;
        
        gchar* sexe;
	gchar* orientation;
	 char var1[50];
        sprintf(var1,"%d",R.date_ajout);
//GtkTreeModel *model = gtk_tree_view_get_model(treeview);		
	
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model, &iter ,path))
	{
		
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&id_liste,1,&id_tete_liste,2,&date_ajout,3,&sexe,4,&orientation,-1);
		strcpy(R.id_liste,id_liste);
		strcpy(R.id_tete_liste,id_tete_liste);
		strcpy(var1,date_ajout);
		strcpy(R.sexe,sexe);
		strcpy(R.orientation,orientation);
		
		
	}

}


void
on_button4modifier_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *window4af;
 GtkWidget *window5modif;
 window5modif=lookup_widget(objet,"window5modif");
 gtk_widget_destroy(window4af);
 window5modif=create_window5modif();
 gtk_widget_show(window5modif);
}


void
on_button5supprim_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window7supp;
GtkWidget *treeview1;
GtkWidget *window2af;
window2af=lookup_widget(objet,"window2af");
gtk_widget_destroy(window2af);
window7supp=create_window7supp();
gtk_widget_show(window7supp);
}


void
on_button3ajout_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *window4af;
 GtkWidget *window2aj;
 window2aj=lookup_widget(objet,"window2aj");
 gtk_widget_destroy(window4af);
 window2aj=create_window2aj();
 gtk_widget_show(window2aj);
}


void
on_radiobutton4femme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{strcpy(b1,"femme");}
}


void
on_radiobutton2homme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{strcpy(b1,"homme");}
}


void
on_comboboxentry2_changed              (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

}


void
on_button7cherch_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
/*char id[20];
GtkWidget *input1;
GtkWidget *window4af;
GtkWidget *treeview1;
input1=lookup_widget(objet,"entry5");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
window4af=lookup_widget(objet,"window4af");

//gtk_widget_destroy(gestion);

//gtk_widget_show(fenetre_rechercher);


treeview1=lookup_widget(objet,"treeview1");
chercher_liste(id, treeview1 );
*/

}


void
on_button4chercher_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
 
 //GtkWidget *window2aj;
/* GtkWidget *window6rech;
 GtkWidget *windowresultrech;
 GtkWidget *treeview2;*/
 //window6rech=lookup_widget(objet,"window6rech");
 //GtkWidget *resultat01;
 /*GtkWidget *label29;
 GtkWidget *input1;*/
//gtk_widget_destroy(window4af);
/*window6rech=lookup_widget(objet,"window6rech");
window6rech=create_window6rech();

gtk_widget_show(window6rech);*/
 


/*int tr;
liste_electorale R;
char id[20];
//char code_postal[20];
input1=lookup_widget(objet, "entry6");
//input2=lookup_widget(button, "entrycodech");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
label29=lookup_widget(window6rech,"label29");
//strcpy(code_postal,gtk_entry_get_text(GTK_ENTRY(input2)));
chercher_liste("tunisie.txt",id);
 FILE * f = fopen("tunisie.txt", "r");
if (tr=0)
{


gtk_widget_show(label29);
//resultat01=create_dialogcherchernon();
//gtk_widget_show(resultat01);

}


else if  (tr=1)
{
  //gtk_widget_hide(label29);
  window6rech=lookup_widget(objet,"window6rech");
  gtk_widget_destroy(window6rech);

  windowresultrech=lookup_widget(objet, "windowresultrech");
  windowresultrech=create_windowresultrech();
  gtk_widget_show(windowresultrech); 
  treeview2=lookup_widget(windowresultrech,"treeview2");
  
  affiche_cherch(treeview2);*/
/*char id[20];
GtkWidget *input1;
GtkWidget *window4af;
GtkWidget *treeview1;
input1=lookup_widget(objet,"entry6");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
window4af=lookup_widget(objet,"window4af");

//gtk_widget_destroy(gestion);

//gtk_widget_show(fenetre_rechercher);


treeview1=lookup_widget(objet,"treeview1");
chercher_liste(id, treeview1 );*/
//}
}

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button5cherch_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
 /*GtkWidget *window4af;
 GtkWidget *window6rech;
 window6rech=lookup_widget(objet,"window6rech");
 gtk_widget_destroy(window4af);
 window6rech=create_window6rech();
 gtk_widget_show(window6rech);*/
 



}

void
on_button6modifier_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window5modif;
GtkWidget *input1, *input2,  *orientation;
GtkWidget *jour, *mois, *annee;
window5modif=lookup_widget(objet,"window5modif");
date date_ajout;

                   
jour=lookup_widget(GTK_WIDGET(objet),"spinbutton4");
mois=lookup_widget(GTK_WIDGET(objet),"spinbutton5");
annee=lookup_widget(GTK_WIDGET(objet),"spinbutton6");
//////////
R.date_ajout.j=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
R.date_ajout.m=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
R.date_ajout.a=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
///////

input1=lookup_widget(objet,"entry3");
input2=lookup_widget(objet,"entry4");

orientation=lookup_widget(objet, "comboboxentry2");
strcpy(R.id_liste,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(R.id_tete_liste,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(R.sexe,b1);
strcpy(R.orientation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(orientation)));
		 
modifier(R);
}


/*void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}*/


void
on_button3supprimer_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
/*char idsupp[20];

GtkWidget *window4af;
GtkWidget *treeview1;
GtkWidget *window7supp;
GtkWidget *input1;
input1=lookup_widget(objet,"entry7");
strcpy(idsupp,gtk_entry_get_text(GTK_ENTRY(input1)));

csupprimer(idsupp, treeview1 );

window7supp=lookup_widget(objet,"window7supp");
gtk_widget_destroy(window7supp);

window4af=create_window4af();
gtk_widget_show(window4af);
treeview1=lookup_widget(window4af,"treeview1");
  
  afficher(treeview1);*/
}


void
on_button3retour_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *window4af;
 GtkWidget *window5modif;
 GtkWidget *treeview1;
 window4af=lookup_widget(objet,"window4af");
 gtk_widget_destroy(window5modif);
 window4af=create_window4af();
 gtk_widget_show(window4af);
treeview1=lookup_widget(window4af,"treeview1");
  
  afficher(treeview1);
}


void
on_button3cherche_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
char idchercher[10];
GtkWidget *input1;
GtkWidget *window4af;
GtkWidget *treeview1;
input1=lookup_widget(objet,"entry8");
strcpy(idchercher,gtk_entry_get_text(GTK_ENTRY(input1)));
window4af=lookup_widget(objet,"window4af");
treeview1=lookup_widget(objet,"treeview1");
chercher(idchercher, treeview1 );
}


void
on_button4annuler_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window4af;
GtkWidget *treeview1;
GtkWidget *window7supp;
window7supp=lookup_widget(button,"window7supp");
gtk_widget_destroy(window7supp);

window4af=create_window4af();

gtk_widget_show(window4af);
treeview1=lookup_widget(window4af,"treeview1");
  afficher(treeview1);
}


void
on_button3valider_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
char id[20];
GtkWidget *input1;
GtkWidget *window4af;
GtkWidget *treeview1;
GtkWidget *window7supp;
input1=lookup_widget(objet,"entry10");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer(id);
//window7supp=lookup_widget(objet,"window7supp");
gtk_widget_destroy(window7supp);

window4af=create_window4af();
gtk_widget_show(window4af);
treeview1=lookup_widget(window4af,"treeview1");
  afficher(treeview1);
}


void
on_button3gestion_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window2aj;

GtkWidget *Choix;
Choix=lookup_widget(objet,"Choix");
gtk_widget_destroy(Choix);

window2aj=create_window2aj();

gtk_widget_show(window2aj);
}


void
on_button4voter_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espacevote;
GtkWidget *Choix;
Choix=lookup_widget(objet,"Choix");
gtk_widget_destroy(Choix);

espacevote=create_espacevote();

gtk_widget_show(espacevote);
}


void
on_button5Vvalid_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
liste_electorale V;
GtkWidget *input1;
GtkWidget *espacevote;

espacevote=lookup_widget(objet,"espacevote");

input1=lookup_widget(objet,"entry9");

strcpy(V.idvote,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(V.type_vote,c1);

{ajout_vote(V);}
}


void
on_button7preced_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espacevote;
GtkWidget *Choix;
espacevote=lookup_widget(objet,"espacevote");
gtk_widget_destroy(espacevote);

Choix=create_Choix();

gtk_widget_show(Choix);
}


void
on_button6vblanc_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button8ret_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window2aj;
GtkWidget *Choix;
window2aj=lookup_widget(objet,"window2aj");
gtk_widget_destroy(window2aj);

Choix=create_Choix();

gtk_widget_show(Choix);
}


void
on_treeview2v_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{strcpy(c1,"votevalide");}
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{strcpy(c1,"voteblanc");}
}


void
on_button10voteaff_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window4af;
	GtkWidget *statistique;
	gtk_widget_destroy(window4af);
	statistique=create_statistique();
	gtk_widget_show(statistique);
}


void
on_button3stat_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{	
	/*GtkWidget *window4af;
	GtkWidget *statistique;
	gtk_widget_destroy(window4af);
	statistique=create_statistique();
	gtk_widget_show(statistique);*/
        
}


void
on_button3affstat_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkButton *label57,*label55, *output,*output1;
	int x=nombre("electeur.txt");
	char A[20];
	sprintf (A,"%d",x);
	output = lookup_widget(button, "label57");
	gtk_label_set_text(GTK_LABEL(output),A);

	
	/*int w=nombrevote_total("electeur.txt");
	
	char M[50];
	sprintf (M,"%d",w);
	output1 = lookup_widget(button, "label55");
	gtk_label_set_text(GTK_LABEL(output1),M);*/
	
	double k=nombretotal("tunisie.txt");
        double e=nombrevote_total("electeur.txt");
	float C=(e/k)*100;
	char M[50];
	sprintf (M,"%.2f",C);
	output1 = lookup_widget(button, "label55");
	gtk_label_set_text(GTK_LABEL(output1),M);





}


void
on_button3retourners_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
        GtkWidget *espacevote;
	GtkWidget *statistique;
	gtk_widget_destroy(statistique);
	espacevote=create_espacevote();
	gtk_widget_show(espacevote);
}

