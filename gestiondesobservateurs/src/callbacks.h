#include <gtk/gtk.h>


void
on_treeview_ob_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_page_ajouter_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_modifier_page_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supp_page_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercherob_clicked                  (GtkButton       *button,
 
                                      gpointer         user_data);
/*
void
on_button_affiche_dec_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ajouter_dec_clicked          (GtkButton       *button,
                                        gpointer         user_data);
*/
void
on_button_afficher_treeview_ajout_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_valider_ob_ajouter_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_prece_ajouter_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_homme_ob_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_nonetranger_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_femme_ob_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_etranger_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_butto_cherch_id_mod_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_valider_modifier_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_afficher_mod_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_prece_modifier_clicked       (GtkButton       *button,
                                        gpointer         user_data);
/*
void
on_button_modifier_dec_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supp_dec_clicked             (GtkButton       *button,
                                        gpointer         user_data);
*/
void
on_button_cherch_supp_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_prece_supp_clicked           (GtkButton       *button,
                                        gpointer         user_data);
