#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <glib/gprintf.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "greeting.h"
#include "fonctions.h"
#include "string.h"
void
logiin                                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char log[50]; char password[50];char hello [50];FILE* f;

GtkWidget *input;
GtkWidget *input2;
GtkWidget *output;
GtkWidget *window2;
GtkWidget *login;
GtkWidget *window_menu;
GtkWidget *espace_kine;
GtkWidget *window4;
GtkWidget *Gestions_comptes;

login = lookup_widget(objet_graphique,"login");
input=lookup_widget(objet_graphique,"entry1");
input2=lookup_widget(objet_graphique,"entry2");
output=lookup_widget(objet_graphique,"label3");

strcpy(log,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));

int x =id(log,password,hello);

		if(x==1)
		{
 	
		window_menu=create_window_menu();
		gtk_widget_show (window_menu);
		gtk_widget_hide(login);



		}
	if(x==2)
	{
		window2=create_window2();
		gtk_widget_show (window2);
		gtk_widget_hide(login);

	}
gtk_label_set_text(GTK_LABEL(output),hello);

}




void
Gestion_salle                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
gestion_comptes                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window_menu;
	GtkWidget *Gestions_comptes;

window_menu = lookup_widget(objet_graphique,"window_menu");
Gestions_comptes = lookup_widget(objet_graphique,"Gestions_comptes");
Gestions_comptes=create_Gestions_comptes();

gtk_widget_show (Gestions_comptes);
gtk_widget_hide(window_menu);


GtkWidget  *listeview;
GtkWidget  *listeview1;

listeview = lookup_widget(Gestions_comptes,"treeview8");
afficher(listeview,1);

listeview1 = lookup_widget(Gestions_comptes,"treeview9");
afficher(listeview1,3);
}

void
menu_quitter                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
deconnexion_6                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window_menu;
	GtkWidget *login;

window_menu = lookup_widget(objet_graphique,"window_menu");
login=create_login();

gtk_widget_show (login);
gtk_widget_hide(window_menu);
}


void
password                               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
GtkWidget *entry2;

  entry2= lookup_widget(GTK_WIDGET(togglebutton),"entry2");
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
  gtk_entry_set_visibility(GTK_ENTRY (entry2), TRUE);
  else
  gtk_entry_set_visibility (GTK_ENTRY (entry2), FALSE);
}


void
on_treeview6_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gint int_data;
   gchar *str_data;

   GtkTreeIter iter;
   GtkTreeModel *model = gtk_tree_view_get_model(treeview);

   if (gtk_tree_model_get_iter(model, &iter, path)) {
      gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &int_data, 1, &str_data, -1);
						    }

}




void
ajouter_ADMIN                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *ajouter_ADMIN;
	GtkWidget *Gestions_comptes;


Gestions_comptes = lookup_widget(objet_graphique,"Gestions_comptes");
ajouter_ADMIN=create_ajouter_ADMIN();
gtk_widget_show (ajouter_ADMIN);
gtk_widget_hide(Gestions_comptes);

}


void
valider_ajouter_ADMIN                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char logs[50],passwords[50],CIN[50]; 
	GtkWidget *input3;
	GtkWidget *input4;	
	GtkWidget *input5;
	GtkWidget *output;


input3=lookup_widget(objet_graphique,"entry9");
input4=lookup_widget(objet_graphique,"entry10");
input5=lookup_widget(objet_graphique,"entry11");
output=lookup_widget(objet_graphique,"label53");

strcpy(logs,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(passwords,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(input5)));
int x=ajouter_a(logs,passwords,1,CIN); 
if(x==1)
{
	GtkWidget *ajouter_ADMIN;
	GtkWidget *Gestions_comptes;
	ajouter_ADMIN = lookup_widget(objet_graphique,"ajouter_ADMIN");
	Gestions_comptes = lookup_widget(objet_graphique,"Gestions_comptes");
gtk_widget_hide(Gestions_comptes);
Gestions_comptes=create_Gestions_comptes();

gtk_widget_show (Gestions_comptes);

gtk_widget_hide(ajouter_ADMIN);


GtkWidget  *listeview;

listeview = lookup_widget(Gestions_comptes,"treeview8");
afficher(listeview,1);
}
gtk_label_set_text(GTK_LABEL(output),"erreur information");
}


void
quitter_page1                          (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
modifier_ADMIN                         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
supprimer_ADMIN                        (GtkButton       *button,
                                        gpointer         user_data)
{

}

GtkWidget *objet_graphique;


void
on_treeview8_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

	gint *role;
  	gchar *login;
	gchar *password;
	gchar *cin;
   
	GtkWidget *input1;
	GtkWidget *input2;	
	GtkWidget *input3;
	GtkWidget *input4;

	GtkWidget *modifier;
	GtkWidget *Gestions_comptes;


   GtkTreeIter iter;
   GtkTreeModel *model = gtk_tree_view_get_model(treeview);

   if (gtk_tree_model_get_iter(model, &iter, path)) {
      gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &login, 1, &password,2,&role,3,&cin, -1);

						    }

	
modifier=create_modifier();



input1 = lookup_widget(modifier,"entry12");
input2=lookup_widget(modifier,"entry13");
input3=lookup_widget(modifier,"entry14");
input4=lookup_widget(modifier,"entry15");

gtk_entry_set_text(GTK_ENTRY(input1),login);
gtk_entry_set_text(GTK_ENTRY(input2),password);
gtk_entry_set_text(GTK_ENTRY(input4),cin);

gtk_widget_show (modifier);
}


void
valider_modifier_ADMIN                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *input1;
	GtkWidget *input2;	
	GtkWidget *input3;
	GtkWidget *input4;

	GtkWidget *modifier;
	GtkWidget *Gestions_comptes;

char login[50],password[50],cin[50];

	modifier = lookup_widget(objet_graphique,"ajouter_ADMIN");



input1 = lookup_widget(objet_graphique,"entry12");
input2=lookup_widget(objet_graphique,"entry13");
input3=lookup_widget(objet_graphique,"entry14");
input4=lookup_widget(objet_graphique,"entry15");

strcpy(login,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input4)));
modifier_comptes(login,password,cin);



Gestions_comptes=create_Gestions_comptes();
gtk_widget_show (Gestions_comptes);

gtk_widget_hide(modifier);


GtkWidget  *listeview;

listeview = lookup_widget(Gestions_comptes,"treeview8");
afficher(listeview,1);



}


void
ajouter_KIN__                          (GtkButton       *button,
                                        gpointer         user_data)
{

}


//manel

void
consulter_les_fiches_medicales         (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{ 
GtkWidget *window2;
GtkWidget *window3;
GtkWidget *listeview ;

window2=lookup_widget(objet_graphique,"window2");
window3=create_window3() ;
listeview=lookup_widget(window3,"treeview2");
afficher_(listeview);
gtk_widget_show (window3);
gtk_widget_hide(window2) ;



}


void
horaires_et_rendez_vous                (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window2;
GtkWidget *window5;
GtkWidget *listeview ;
window2=lookup_widget(objet_graphique,"window2") ;
window5=create_window5();
listeview=lookup_widget(window5,"treeview3");
afficher3(listeview);
gtk_widget_show(window5);
gtk_widget_hide(window2);

}


void
calendrier                 
            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window2;
GtkWidget *window6;
window2=lookup_widget(objet_graphique,"window2") ;
window6=create_window6() ;

gtk_widget_show(window6) ;
gtk_widget_hide(window2);



}



void
ajouter                                (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window5;
GtkWidget *window7;


window5=lookup_widget(objet_graphique,"window5");
window7=create_window7() ;
gtk_widget_show (window7);
gtk_widget_hide(window5) ;

}




void
modifier                               (GtkButton       *button,
                                        gpointer         user_data)
{ 


}


void
supprimer                              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
confirmer_                             (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{ char nom [50] ; char prenom[50] ; char heures_de_rendezvous[50] ;int jour ; int mois ; int annee  ;
GtkWidget *combobox1 ;
GtkWidget *jour1 ;
GtkWidget *mois1 ;
GtkWidget *annee1;
GtkWidget *label17 ;
GtkWidget *window7 ;
GtkWidget *input2 ;
GtkWidget *input3 ;

combobox1=lookup_widget(objet_graphique,"combobox1");
jour1=lookup_widget(objet_graphique,"spinbutton1");
mois1=lookup_widget(objet_graphique,"spinbutton2");
annee1=lookup_widget(objet_graphique,"spinbutton3");
window7=lookup_widget(objet_graphique,"window7") ;
input2=lookup_widget(objet_graphique,"entry3") ;
input3=lookup_widget(objet_graphique,"entry4") ;

strcpy(heures_de_rendezvous,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));
mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee1));
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input3)));

ajouter2(nom,prenom,heures_de_rendezvous,jour,mois,annee);

}

