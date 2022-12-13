#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "election.h"

void
on_check_id_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *mod4, *mod5, *mod6, *mod7, *mod8, *pInfo;
GtkCalendar *c;
int id;
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
mod4=lookup_widget(objet,"mod4");
mod5=lookup_widget(objet,"mod5");
mod6=lookup_widget(objet,"mod6");
mod7=lookup_widget(objet,"mod7");
c=lookup_widget(objet,"modc");
id = gtk_spin_button_get_value(GTK_SPIN_BUTTON(mod1));
obs p = chercher(id, "election.txt");
if(p.id!=-1){
gtk_entry_set_text(GTK_ENTRY(mod2),p.nom);
gtk_entry_set_text(GTK_ENTRY(mod3),p.prenom);
gtk_entry_set_text(GTK_ENTRY(mod4),p.nat);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(mod5),p.sexe==0?TRUE:FALSE);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(mod6),p.sexe==1?TRUE:FALSE);
gtk_entry_set_text(GTK_ENTRY(mod7),p.app);
gtk_calendar_select_month(GTK_CALENDAR(c),p.d.m,p.d.a);
gtk_calendar_select_day(GTK_CALENDAR(c),p.d.j);
}
else{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Observateur introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
}


void
on_button_mod_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *mod4, *mod5, *mod6, *mod7, *mod8, *pInfo;
GtkCalendar *c;
obs u;
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
mod4=lookup_widget(objet,"mod4");
mod5=lookup_widget(objet,"mod5");
mod6=lookup_widget(objet,"mod6");
mod7=lookup_widget(objet,"mod7");
mod8=lookup_widget(objet,"mod8");
c=lookup_widget(objet,"modc");
bool a=gtk_toggle_button_get_active(GTK_CHECK_BUTTON(mod8));
if(a){
u.id=gtk_spin_button_get_value(GTK_SPIN_BUTTON(mod1));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(mod2)));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(mod3)));
strcpy(u.nat,gtk_entry_get_text(GTK_ENTRY(mod4)));
u.sexe=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(mod5))?0:1;
strcpy(u.app,gtk_entry_get_text(GTK_ENTRY(mod7)));
gtk_calendar_get_date(GTK_CALENDAR(c),&(u.d.a),&(u.d.m),&(u.d.j));
modifier(u,"election.txt");
}
else{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,"Veuillez confirmer");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
}


void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	guint id;
	GtkWidget *pInfo, *objet, *af;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,-1);
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer cet observateur?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(pInfo);
	supprimer(id,"election.txt");
	afficher(treeview,"election.txt","","","");
	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pInfo);
	break;
}	
}
}


void
on_button_af_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af;
af=lookup_widget(objet, "af");
treeview=lookup_widget(af,"treeview");
afficher(treeview,"election.txt", "","","");
}


void
on_button_aj_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj1, *aj2, *aj3, *aj4, *aj5, *aj6, *aj7, *aj8, *pInfo;
GtkCalendar *c;
obs u;
aj1=lookup_widget(objet,"aj1");
aj2=lookup_widget(objet,"aj2");
aj3=lookup_widget(objet,"aj3");
aj4=lookup_widget(objet,"aj4");
aj5=lookup_widget(objet,"aj5");
aj6=lookup_widget(objet,"aj6");
aj7=lookup_widget(objet,"aj7");
aj8=lookup_widget(objet,"aj8");
c=lookup_widget(objet,"ajc");
bool a=gtk_toggle_button_get_active(GTK_CHECK_BUTTON(aj8));
if(a){
u.id=gtk_spin_button_get_value(GTK_SPIN_BUTTON(aj1));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(aj2)));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(aj3)));
strcpy(u.nat,gtk_entry_get_text(GTK_ENTRY(aj4)));
u.sexe=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(aj5))?0:1;
strcpy(u.app,gtk_entry_get_text(GTK_ENTRY(aj7)));
gtk_calendar_get_date(GTK_CALENDAR(c),&(u.d.a),&(u.d.m),&(u.d.j));
ajouter(u,"election.txt");
}
else{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,"Veuillez confirmer");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
}


void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj;
aj=lookup_widget(objet,"aj");
aj=create_aj();
gtk_widget_show(aj);
}


void
on_button6_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj;
aj=lookup_widget(objet,"mod");
aj=create_mod();
gtk_widget_show(aj);
}


void
on_button7_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af, *e1, *e2, *e3;
char genre[20], nat[20], id[10];
af=lookup_widget(objet,"af");
treeview=lookup_widget(af,"treeview");
e1=lookup_widget(objet, "entry1");
e2=lookup_widget(objet, "entry2");
e3=lookup_widget(objet, "entry3");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(e1)));
strcpy(nat,gtk_entry_get_text(GTK_ENTRY(e2)));
strcpy(genre,gtk_entry_get_text(GTK_ENTRY(e3)));
afficher(treeview, "election.txt", id, nat, genre);
}


void
on_button8_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *pInfo;
char *ch = taux_obs("election.txt");
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,ch);
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}


void
on_button15_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *pInfo;
char *ch = nb_obs("election.txt");
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,ch);
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}

void
on_button_aff_aj_ah_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Ajouter, *Afficher;
Ajouter=lookup_widget(button,"Ajouter");
gtk_widget_destroy(Ajouter);
Afficher=create_af();
gtk_widget_show(Afficher);
}


void
on_button_aff_mod_ah_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Modifier, *Afficher;
Modifier=lookup_widget(button,"Modifier");
gtk_widget_destroy(Modifier);
Afficher=create_af();
gtk_widget_show(Afficher);
}

