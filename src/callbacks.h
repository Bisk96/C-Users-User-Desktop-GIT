#include <gtk/gtk.h>



void
Gestion_salle                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
gestion_comptes                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
menu_quitter                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
deconnexion_6                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
password                               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview6_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);


void
ajouter_ADMIN                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
valider_ajouter_ADMIN                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
quitter_page1                          (GtkButton       *button,
                                        gpointer         user_data);

void
modifier_ADMIN                         (GtkButton       *button,
                                        gpointer         user_data);

void
supprimer_ADMIN                        (GtkButton       *button,
                                        gpointer         user_data);

void
logiin                                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview8_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
valider_modifier_ADMIN                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
ajouter_KIN__                          (GtkButton       *button,
                                        gpointer         user_data);
//manel
void
consulter_les_fiches_medicales         (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
horaires_et_rendez_vous                (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
calendrier                             (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
ajouter                                (GtkWidget      *objet_graphique,
                                        gpointer         user_data);


void
modifier                               (GtkButton       *button,
                                        gpointer         user_data);

void
supprimer                              (GtkButton       *button,
                                        gpointer         user_data);

void
confirmer_                             (GtkWidget     *objet_graphiques,
                                        gpointer         user_data);
