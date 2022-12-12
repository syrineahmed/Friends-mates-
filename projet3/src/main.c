/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *windowaffiche;
  GtkWidget *windowajout;
  GtkWidget *dialogconfirmer;
  GtkWidget *windowmodifier_;
  GtkWidget *dialogconfirmermodif;
  GtkWidget *windowchercher01;
  GtkWidget *dialogcherchernon;
  GtkWidget *windowresultatrecherche;
  GtkWidget *windowsupprimer;
  GtkWidget *dialogconfsuppr;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory ("../pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  windowaffiche = create_windowaffiche ();
  gtk_widget_show (windowaffiche);
  windowajout = create_windowajout ();
  gtk_widget_show (windowajout);
  dialogconfirmer = create_dialogconfirmer ();
 /* gtk_widget_show (dialogconfirmer);
  windowmodifier_ = create_windowmodifier_ ();
  gtk_widget_show (windowmodifier_);
  dialogconfirmermodif = create_dialogconfirmermodif ();
  gtk_widget_show (dialogconfirmermodif);
  windowchercher01 = create_windowchercher01 ();
  gtk_widget_show (windowchercher01);
  dialogcherchernon = create_dialogcherchernon ();
  gtk_widget_show (dialogcherchernon);
  windowresultatrecherche = create_windowresultatrecherche ();
  gtk_widget_show (windowresultatrecherche);
  windowsupprimer = create_windowsupprimer ();
  gtk_widget_show (windowsupprimer);
  dialogconfsuppr = create_dialogconfsuppr ();
  gtk_widget_show (dialogconfsuppr);*/

  gtk_main ();
  return 0;
}

