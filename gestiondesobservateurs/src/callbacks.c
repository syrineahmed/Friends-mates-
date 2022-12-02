#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "ob.h"
int X,Y;
int t[2]={0,0};

void
on_treeview_ob_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* date;
gchar* identifiant;
gchar* prenom;
gchar* nom;
gchar* nationalite;
gchar* profession;
gchar* genre;
observateur ob;
char identifiant[20];
char date[20];

GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{
sprintf(date,"%d/%d/%d",ob.y.jour,ob.y.mois,ob.y.annee);
sprintf(identifiant,"%d",ob.identifiant);
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&DATE,1,&IDENTIFIANT,2,&prenom,3,&nom,4,&nationalite,5,&profession,6,&genre,7,-1);
strcpy(date,DATE);
strcpy(identifiant,IDENTIFIANT);
strcpy(ob.prenom,prenom);
strcpy(ob.nom,nom);
strcpy(ob.nationalite,nationalite);
strcpy(ob.profession,profession);
strcpy(ob.genre,genre);
afficherObservateur(treeview);
}
}


void
on_button_page_ajouter_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AjouterObservateur, *AfficherObservateur;
AfficherObservateur=lookup_widget(objet,"AfficherObservateur");
gtk_widget_destroy(AfficherObservateur);
AjouterObservateur=create_AjouterObservateur();
gtk_widget_show(AjouterObservateur);
}


void
on_button_modifier_page_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ModifierObservateur, *AfficherObservateur;
AfficherObservateur=lookup_widget(objet,"AfficherObservateur");
gtk_widget_destroy(AfficherObservateur);
ModifierObservateur=create_ModifierObservateur();
gtk_widget_show(ModifierObservateur);
}


void
on_button_supp_page_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *SupprimerObservateur, *AfficherObservateur;
AfficherObservateur=lookup_widget(objet,"AfficherObservateur");
gtk_widget_destroy(AfficherObservateur);
SupprimerObservateur=create_SupprimerObservateur();
gtk_widget_show(SupprimerObservateur);
}


void
on_chercherob_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}
/*

void
on_button_affiche_dec_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_ajouter_dec_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}

*/
void
on_button_afficher_treeview_ajout_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_valider_ob_ajouter_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
observateur ob;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7;
GtkWidget *AjouterObservateur;
AjouterObservateur=lookup_widget(objet,"AjouterObservateur");
input1=lookup_widget(objet,"date");
input2=lookup_widget(objet,"identifiant");
input3=lookup_widget(objet,"prenom");
input4=lookup_widget(objet,"nom");
input5=lookup_widget(objet,"nationalite");
input6=lookup_widget(objet,"profession");
input7=lookup_widget(objet,"genre");
strcpy(date,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(identifiant,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(ob.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(ob.nom,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(ob.nationalite,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(ob.profession,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(ob.genre,gtk_entry_get_text(GTK_ENTRY(input7)));
char text1="homme";
char text2="";
char text3="";
if(Y==1)
strcpy(text1,"homme");
if(X==1)
strcpy(text1,"femme");
if(t[0]==1)
strcat(text2,"non etranger");
if(t[1]==1)
strcat(text2,"etranger");
sprintf(text3,"votre observateur est %s et %s ",text1,text2);
output=lookup_widget(button,"label46");
gtk_label_set_text(GTK_LABEL(output),text3);
GtkWidget *spinbutton_jour;
GtkWidget *spinbutton_mois;
GtkWidget *spinbutton_annee;
GtkWidget *combobox_profession;
spinbutton_jour=lookup_widget(objet_graphique,"spinbutton_jour");
spinbutton_mois=lookup_widget(objet_graphique,"spinbutton_mois");
spinbutton_annee=lookup_widget(objet_graphique,"spinbutton_annee");
combobox_profession=lookup_widget(objet_graphique,"combobox_profession");
ob.y.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_jour));
ob.y.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_mois));
ob.y.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_annee));
strcpy(ob.profession,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_profession)));
ob.profession=ob.profession[0];
ajouterObservateur(ob)
}


void
on_button_prece_ajouter_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AjouterObservateur, *AfficherObservateur;
AjouterObservateur=lookup_widget(objet,"AjouterObservateur");
gtk_widget_destroy(AjouterObservateur);
AfficherObservateur=create_AfficherObservateur();
gtk_widget_show(AfficherObservateur);}


void
on_radiobutton_homme_ob_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{Y=1;}

}


void
on_checkbutton_nonetranger_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{t[0]=1;}
}


void
on_radiobutton_femme_ob_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{X=1;}
}


void
on_checkbutton_etranger_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{t[1]=1;}
}


void
on_butto_cherch_id_mod_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_valider_modifier_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_afficher_mod_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}

void
on_button_prece_modifier_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ModifierObservateur, *AfficherObservateur;
ModifierObservateur=lookup_widget(objet,"ModifierObservateur");
gtk_widget_destroy(ModifierObservateur);
AfficherObservateur=create_AfficherObservateur();
gtk_widget_show(AfficherObservateur);
}

/*
void
on_button_modifier_dec_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_supp_dec_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}

*/
void
on_button_cherch_supp_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_prece_supp_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *SupprimerObservateur, *AfficherObservateur;
SupprimerObservateur=lookup_widget(objet,"SupprimerObservateur");
gtk_widget_destroy(SupprimerObservateur);
AfficherObservateur=create_AfficherObservateur();
gtk_widget_show(AfficherObservateur);
}

