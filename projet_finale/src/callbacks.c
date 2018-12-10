#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <glib/gprintf.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "greeting.h"
#include "verifier.h"
#include "seance.h"
#include "function.h"
#include "finals.h"
#include "fonctions.h"

void
logiin                                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char log[50]; char password[50];char hello [50];FILE* f;

GtkWidget *input;
GtkWidget *input2;
GtkWidget *output;

GtkWidget *login;
GtkWidget *window_menu;
GtkWidget   *windowm2;
GtkWidget   *window2s;
GtkWidget *window4;
GtkWidget *window102;
GtkWidget  *listeview;
GtkWidget   *window2m;
login = lookup_widget(objet_graphique,"login");
input=lookup_widget(objet_graphique,"entry1");
input2=lookup_widget(objet_graphique,"entry2");
output=lookup_widget(objet_graphique,"label3");

strcpy(log,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));

int x=id_h(log,password,hello);

		if(x==1)
		{
 	
		window_menu=create_window_menu();
		gtk_widget_show (window_menu);
		gtk_widget_hide(login);



		}
	
                if(x==3)
		{
 	
		window102=create_window102();
		gtk_widget_show (window102);
		gtk_widget_hide(login);
		listeview = lookup_widget(window102,"treeview103");
		afficher_event(listeview);
		}
		if(x==5)
		{
 	
		windowm2=create_windowm2();
		gtk_widget_show (windowm2);
		gtk_widget_hide(login);

		listeview = lookup_widget(windowm2,"treeview6");
		afficher_event(listeview);

		listeview = lookup_widget(windowm2,"treeviewm1");
		perso(listeview);
		}
	if(x==4)
		{
 	
		window2s=create_window2s();
		gtk_widget_show (window2s);
		gtk_widget_hide(login);

listeview = lookup_widget(window2s,"treeview1s");
		afficher2s(listeview);
		
		}
	if(x==6)
		{
 	
		window2m=create_window2m();
		gtk_widget_show (window2m);
		gtk_widget_hide(login);

listeview = lookup_widget(window2m,"treeview1");
		afficher2(listeview);

		}

gtk_label_set_text(GTK_LABEL(output),hello);

}




void
Gestion_salle                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *window_menu;
	GtkWidget *Gestion_Calendrier;
	GtkWidget  *listeview;

window_menu = lookup_widget(objet_graphique,"window_menu");
Gestion_Calendrier = lookup_widget(objet_graphique,"Gestion_Calendrier");
Gestion_Calendrier=create_Gestion_Calendrier();

gtk_widget_show (Gestion_Calendrier);
gtk_widget_hide(window_menu);

listeview = lookup_widget(Gestion_Calendrier,"treeview16");
afficher_event(listeview);



}


void
gestion_comptes                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *window_menu;
	GtkWidget *gestion_compte;
	GtkWidget  *listeview;
	GtkWidget  *listeview1;

window_menu = lookup_widget(objet_graphique,"window_menu");
gestion_compte = lookup_widget(objet_graphique,"gestion_compte");
gestion_compte=create_gestion_compte();

gtk_widget_show (gestion_compte);
gtk_widget_hide(window_menu);


listeview = lookup_widget(gestion_compte,"treeview15");
afficher_h(listeview,2);

listeview1 = lookup_widget(gestion_compte,"treeview17");
afficher_profile_h(listeview1);

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
quitter_page1                          (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}

	



void
on_combobox_admin_changed              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *combobox1;
GtkWidget *gestion_compte;
GtkWidget *listeview;
char role[50];


combobox1=lookup_widget(objet_graphique, "combobox1");
gestion_compte=lookup_widget(objet_graphique, "gestion_compte");
strcpy(role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
listeview = lookup_widget(gestion_compte,"treeview15");

GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(listeview));
gtk_list_store_clear(model);
if (strcmp(role,"Administrateur")==0)
{
//gtk_widget_destroy(listeview);

//listeview = gtk_tree_view_new();
//init_listeview(listeview);
afficher_h(listeview,1);
}
else if(strcmp(role,"Adhérant")==0)
{
afficher_h(listeview,2);
}
else if(strcmp(role,"Coach")==0)
{
afficher_h(listeview,3);
}
else if(strcmp(role,"Diéteticien")==0)
{
afficher_h(listeview,4);
}
else if(strcmp(role,"Medecin")==0)
{
afficher_h(listeview,5);
}
else if(strcmp(role,"Kinésithérapeute")==0)
{
afficher_h(listeview,6);
}
}


void
Ajouter_                               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char logs[50],passwords[50],CIN[50], role[50];int x; 
	GtkWidget *input3;
	GtkWidget *input4;	
	GtkWidget *input5;
	GtkWidget *output;
	GtkWidget *combobox1;
	GtkWidget *gestion_compte;
	GtkWidget *listeview;

input3=lookup_widget(objet_graphique,"entry33");
input4=lookup_widget(objet_graphique,"entry34");
input5=lookup_widget(objet_graphique,"entry35");
combobox1=lookup_widget(objet_graphique,"combobox1");
output=lookup_widget(objet_graphique,"label89");

gestion_compte=lookup_widget(objet_graphique, "gestion_compte");


strcpy(role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(logs,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(passwords,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(input5)));

if (strcmp(role,"Administrateur")==0)
		{
 x=ajouter_h(logs,passwords,1,CIN); 
listeview = lookup_widget(gestion_compte,"treeview15");
 afficher_h(listeview,1);
		}

else if (strcmp(role,"Adhérant")==0)
		{
 x=ajouter_h(logs,passwords,2,CIN);
listeview = lookup_widget(gestion_compte,"treeview15");
 afficher_h(listeview,2); 
		}

else if (strcmp(role,"Coach")==0)
		{
 x=ajouter_h(logs,passwords,3,CIN);
listeview = lookup_widget(gestion_compte,"treeview15"); 
 afficher_h(listeview,3);
		}

else if (strcmp(role,"Diéteticien")==0)
		{
 x=ajouter_h(logs,passwords,4,CIN);
listeview = lookup_widget(gestion_compte,"treeview15");
 afficher_h(listeview,4); 
		}

else if (strcmp(role,"Medecin")==0)
		{
 x=ajouter_h(logs,passwords,5,CIN);
listeview = lookup_widget(gestion_compte,"treeview15");
 afficher_h(listeview,5); 
		}

else if (strcmp(role,"Kinésithérapeute")==0)
		{
 x=ajouter_h(logs,passwords,6,CIN);
listeview = lookup_widget(gestion_compte,"treeview15");
 afficher_h(listeview,6); 
		}

if(x==5)
gtk_label_set_text(GTK_LABEL(output),"CIN Existe");
else if(x==1)
gtk_label_set_text(GTK_LABEL(output),"compte ajouté");
else if(x==3)
gtk_label_set_text(GTK_LABEL(output),"login existe");
else if(x==0)
gtk_label_set_text(GTK_LABEL(output),"format CIN erroné");
else if(x==4)
gtk_label_set_text(GTK_LABEL(output),"format CIN erroné");
else
gtk_label_set_text(GTK_LABEL(output),"champ vide");
}


void
on_treeview15_row_activated_admin      (GtkWidget       *objet_graphique,
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
	GtkWidget *input5;
	GtkWidget *gestion_compte;
	GtkWidget *listeview;
        GtkWidget *supprimer_compte__;
        GtkTreeIter iter;


listeview = lookup_widget(objet_graphique,"treeview15");

GtkTreeModel *model = gtk_tree_view_get_model (GTK_TREE_VIEW(lookup_widget(objet_graphique,"treeview15")));
 

   if (gtk_tree_model_get_iter(model, &iter, path)) {
      gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &login, 1, &password,2,&role,3,&cin, -1);

                                                       }
gestion_compte = lookup_widget(objet_graphique,"gestion_compte");
supprimer_compte__ = lookup_widget(objet_graphique,"supprimer_compte__");
supprimer_compte__=create_supprimer_compte__();
input1 = lookup_widget(gestion_compte,"entry33");
input2=lookup_widget(gestion_compte,"entry34");
input3=lookup_widget(gestion_compte,"entry35");
input5=lookup_widget(supprimer_compte__,"entry36");
input4=lookup_widget(gestion_compte,"combobox1");

gtk_entry_set_text(GTK_ENTRY(input1),login);
gtk_entry_set_text(GTK_ENTRY(input2),password);
gtk_entry_set_text(GTK_ENTRY(input3),cin);
gtk_entry_set_text(GTK_ENTRY(input5),cin);

}






void
modifierr_adminn                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *input1;
	GtkWidget *input2;	
	GtkWidget *input3;
	GtkWidget *combobox1;

	GtkWidget *listeview;
	GtkWidget *gestion_compte;

	char login[50],password[50],cin[50],role[50];

	gestion_compte = lookup_widget(objet_graphique,"gestion_compte");



input1 = lookup_widget(objet_graphique,"entry33");
input2=lookup_widget(objet_graphique,"entry34");
input3=lookup_widget(objet_graphique,"entry35");
//input4=lookup_widget(objet_graphique,"entry15");
combobox1=lookup_widget(objet_graphique,"combobox1");

strcpy(role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(login,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input3)));
modifier_comptes(login,password,cin);

if (strcmp(role,"Administrateur")==0)
{
listeview = lookup_widget(gestion_compte,"treeview15");
afficher_h(listeview,1);
}
else if(strcmp(role,"Adhérant")==0)
{
listeview = lookup_widget(gestion_compte,"treeview15");
afficher_h(listeview,2);
}
else if(strcmp(role,"Coach")==0)
{
listeview = lookup_widget(gestion_compte,"treeview15");
afficher_h(listeview,3);
}
else if(strcmp(role,"Diéteticien")==0)
{
listeview = lookup_widget(gestion_compte,"treeview15");
afficher_h(listeview,4);
}
else if(strcmp(role,"Medecin")==0)
{
listeview = lookup_widget(gestion_compte,"treeview15");
afficher_h(listeview,5);
}

}





void
on_oui__supprimer_comptes_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *supprimer_compte__;

char cin[50];

supprimer_compte__ = lookup_widget(objet_graphique,"supprimer_compte__");

input1 = lookup_widget(objet_graphique,"entry36");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer_h(cin);
}


void
on_non_supprimer_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_supprimer__compte_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	/*GtkWidget *supprimer_compte__;
		GtkWidget *gestion_compte;

gestion_compte = lookup_widget(objet_graphique,"gestion_compte");
supprimer_compte__=create_supprimer_compte__();
gtk_widget_show (supprimer_compte__);
//gtk_widget_hide(gestion_compte);
*/

GtkWidget *input1;
GtkWidget *gestion_compte;
GtkWidget *combobox1;
GtkWidget *listeview;
	
char cin[50],role[50];

gestion_compte = lookup_widget(objet_graphique,"gestion_compte");

input1 = lookup_widget(objet_graphique,"entry35");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1)));
//supprimer(cin);

combobox1=lookup_widget(objet_graphique,"combobox1");
strcpy(role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
supprimer_h(cin);
if (strcmp(role,"Administrateur")==0)
{

listeview = lookup_widget(gestion_compte,"treeview15");
afficher_h(listeview,1);
}
else if(strcmp(role,"Adhérant")==0)
{

listeview = lookup_widget(gestion_compte,"treeview15");
afficher_h(listeview,2);
}
else if(strcmp(role,"Coach")==0)
{
listeview = lookup_widget(gestion_compte,"treeview15");
afficher_h(listeview,3);
}
else if(strcmp(role,"Diéteticien")==0)
{
listeview = lookup_widget(gestion_compte,"treeview15");
afficher_h(listeview,4);
}
else if(strcmp(role,"Medecin")==0)
{
listeview = lookup_widget(gestion_compte,"treeview15");
afficher_h(listeview,5);
}


}


void
on_confirmer_calendrier_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *combobox2; //comobox pour le choix de la salle
GtkWidget *jour; //spinbuttun pour le choix du jour
GtkWidget *mois; //spinbuttun pour le choix du mois
GtkWidget *annee; //spinbuttun pour le choix de l’année
GtkWidget *input;
GtkWidget *combobox3;
GtkWidget *listeview;
GtkWidget *output;

 //comobox pour le choix du bloc //label pour confirmer la reservation
// associer les objets avec des variables
combobox2=lookup_widget(objet_graphique, "combobox2");
calendrier s;
jour=lookup_widget(objet_graphique, "spinbutton1");
mois=lookup_widget(objet_graphique, "spinbutton3");
annee=lookup_widget(objet_graphique, "spinbutton2");
combobox3=lookup_widget(objet_graphique, "combobox3");
input=lookup_widget(objet_graphique, "entry37");
output=lookup_widget(objet_graphique,"label116");
//récupérer les valeurs
s.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
s.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
s.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
strcpy(s.heure_m,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
strcpy(s.heure_s,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));
strcpy(s.evenement,gtk_entry_get_text(GTK_ENTRY(input)));

int x= reserver_calendrier(s);

listeview = lookup_widget(objet_graphique,"treeview16");
afficher_event(listeview);

if(x==2)
gtk_label_set_text(GTK_LABEL(output),"date repeté");
else
gtk_label_set_text(GTK_LABEL(output),"reservation completé");
}


void
on_treeview16_row_activated            (GtkWidget       *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

	gchar *date;
  	gchar *heure_m;
	gchar *heure_s;
	gchar *event;
   
	GtkWidget *input1;
	GtkWidget *input2;	
	GtkWidget *input3;
	GtkWidget *input4;	
	
	GtkWidget *Gestion_Calendrier;
	GtkWidget *listeview;
        GtkTreeIter iter;


listeview = lookup_widget(objet_graphique,"treeview16");

GtkTreeModel *model = gtk_tree_view_get_model (GTK_TREE_VIEW(lookup_widget(objet_graphique,"treeview16")));
 

   if (gtk_tree_model_get_iter(model, &iter, path)) {
      gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &date, 1, &heure_m,2,&heure_s,3,&event, -1);

                                                       }
Gestion_Calendrier = lookup_widget(objet_graphique,"Gestion_Calendrier");
input1 = lookup_widget(Gestion_Calendrier,"entry38");
gtk_entry_set_text(GTK_ENTRY(input1),date);
input2 = lookup_widget(Gestion_Calendrier,"entry39");
gtk_entry_set_text(GTK_ENTRY(input2),heure_m);
input3 = lookup_widget(Gestion_Calendrier,"entry40");
gtk_entry_set_text(GTK_ENTRY(input3),heure_s);
input4 = lookup_widget(Gestion_Calendrier,"entry41");
gtk_entry_set_text(GTK_ENTRY(input4),event);


}


void
on_modifier_cal104_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *input1;
	GtkWidget *input2;	
	GtkWidget *input3;
	GtkWidget *input4;

	GtkWidget *listeview;
	GtkWidget *Gestion_Calendrier;

	char date[50],heure_m[50],heure_s[50],event[50];

	Gestion_Calendrier = lookup_widget(objet_graphique,"Gestion_Calendrier");



input1 = lookup_widget(objet_graphique,"entry38");
input2=lookup_widget(objet_graphique,"entry39");
input3=lookup_widget(objet_graphique,"entry40");
input4=lookup_widget(objet_graphique,"entry41");

strcpy(date,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(heure_m,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(heure_s,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(event,gtk_entry_get_text(GTK_ENTRY(input4)));
modifier_calendrier_aa(date,heure_m,heure_s,event);


listeview = lookup_widget(objet_graphique,"treeview16");
afficher_event(listeview);

}


void
on_supprimer_boutton105_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
	GtkWidget *input2;	
	GtkWidget *input3;
	GtkWidget *input4;

	GtkWidget *listeview;
	GtkWidget *Gestion_Calendrier;

	char date[50],heure_m[50],heure_s[50],event[50];

	Gestion_Calendrier = lookup_widget(objet_graphique,"Gestion_Calendrier");



input1 = lookup_widget(objet_graphique,"entry38");
input2=lookup_widget(objet_graphique,"entry39");
input3=lookup_widget(objet_graphique,"entry40");
input4=lookup_widget(objet_graphique,"entry41");

strcpy(date,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(heure_m,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(heure_s,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(event,gtk_entry_get_text(GTK_ENTRY(input4)));
supprimer_calendrier_aa(date);


listeview = lookup_widget(objet_graphique,"treeview16");
afficher_event(listeview);

}


void
on_quitterg_l106_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
gestion_compte____login                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *gestion_compte;
	GtkWidget *login;


gestion_compte= lookup_widget(objet_graphique,"gestion_compte");
login=create_login();
gtk_widget_show (login);
gtk_widget_hide(gestion_compte);
supprimer_id();
}


void
gestion_compte____window_menu          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *gestion_compte;
	GtkWidget *window_menu;


gestion_compte= lookup_widget(objet_graphique,"gestion_compte");
window_menu=create_window_menu();
gtk_widget_show (window_menu);
gtk_widget_hide(gestion_compte);

}


void
quitter_gestion_calendrier             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
Gestion_Calendrier_______login         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *Gestion_Calendrier;
	GtkWidget *login;


Gestion_Calendrier= lookup_widget(objet_graphique,"Gestion_Calendrier");
login=create_login();
gtk_widget_show (login);
gtk_widget_hide(Gestion_Calendrier);
supprimer_id();
}


void
Gestion_Calendrier______window_menu    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *Gestion_Calendrier;
	GtkWidget *window_menu;


Gestion_Calendrier= lookup_widget(objet_graphique,"Gestion_Calendrier");
window_menu=create_window_menu();
gtk_widget_show (window_menu);
gtk_widget_hide(Gestion_Calendrier);

}

GtkWidget *window102;
GtkWidget *window103;
GtkWidget *treeview102;
GtkWidget *window104;
GtkWidget *window105;
void on_button105_clicked  (GtkWidget *objet_graphique,gpointer  user_data)
{
char nom[50];
char prenom[50];
char gsm[50];
char adresse[50];
char specialite[50];
GtkWidget *input103;
GtkWidget *input104;
GtkWidget *input105;
GtkWidget *input106;
GtkWidget *combobox107;
window102=lookup_widget(objet_graphique,"window102");
input103=lookup_widget(objet_graphique,"entry103");
input104=lookup_widget(objet_graphique,"entry104");
input105=lookup_widget(objet_graphique,"entry105");
input106=lookup_widget(objet_graphique,"entry106");
combobox107=lookup_widget(objet_graphique,"combobox107");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input103)));
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input104)));
strcpy(gsm,gtk_entry_get_text(GTK_ENTRY(input105)));
strcpy(adresse,gtk_entry_get_text(GTK_ENTRY(input106)));
strcpy(specialite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox107)));
ajoutermm(nom,prenom,gsm,adresse,specialite);
}


void on_button102_clicked  (GtkWidget  *objet_graphique, gpointer  user_data)
{
GtkWidget *combobox102;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *combobox101;
char nom_salle[100][5];
Date_a dt_res;
int i,n;
char hr_res[20];
char stringNum[20];
int num=100;
combobox102=lookup_widget(objet_graphique,"combobox102");
jour=lookup_widget(objet_graphique,"spinbutton101");
mois=lookup_widget(objet_graphique,"spinbutton102");
annee=lookup_widget(objet_graphique,"spinbutton103");
combobox101=lookup_widget(objet_graphique,"combobox101");
dt_res.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
dt_res.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
dt_res.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
if(strcmp("8h==>10h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox101)))==0)
strcpy(hr_res,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox101)));
else
if(strcmp("10h==>12h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox101)))==0)
strcpy(hr_res,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox101)));
else
if(strcmp("14h==>16h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox101)))==0)
strcpy(hr_res,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox101)));
else
if(strcmp("16h==>18h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox101)))==0)
strcpy(hr_res,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox101)));
else
strcpy(hr_res,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox101)));
n=tableau_salle_disponible(nom_salle,dt_res,hr_res);
for(i=0;i<n;i++)
{
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox102),_(nom_salle[i]));
}
}


void on_button104_clicked  (GtkWidget *objet_graphique,gpointer  user_data)
{
GtkWidget *combobox102;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *combobox101;
GtkWidget *label115;
ReservationSalle s;
combobox102=lookup_widget(objet_graphique,"combobox102");
jour=lookup_widget(objet_graphique,"spinbutton101");
mois=lookup_widget(objet_graphique,"spinbutton102");
annee=lookup_widget(objet_graphique,"spinbutton103");
label115=lookup_widget(objet_graphique,"label115");
combobox101=lookup_widget(objet_graphique,"combobox101");
s.dt_res.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
s.dt_res.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
s.dt_res.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
if(strcmp("8h==>10h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox101)))==0)
strcpy(s.hr_res,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox101)));
else
if(strcmp("10h==>12h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox101)))==0)
strcpy(s.hr_res,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox101)));
else
if(strcmp("14h==>16h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox101)))==0)
strcpy(s.hr_res,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox101)));
else
if(strcmp("16h==>18h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox101)))==0)
strcpy(s.hr_res,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox101)));
else
strcpy(s.hr_res,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox101)));
strcpy(s.num,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox102)));
reserver_salle(s);
gtk_label_set_text(GTK_LABEL(label115),"Réservation réussite");
}



void on_button103_clicked  (GtkWidget  *objet_graphique, gpointer   user_data)
{
window103=create_window103();
gtk_widget_show(window103);
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"window102")));
}


void on_button106_clicked   (GtkWidget *objet_graphique,gpointer user_data)
{
window102=create_window102();
gtk_widget_show(window102);
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"window103")));
treeview102=lookup_widget(window102,"treeview102");
afficher_seance(treeview102);
}


void on_button107_clicked (GtkWidget  *objet_graphique,gpointer user_data)
{

}


void on_button109_clicked (GtkWidget *objet_graphique, gpointer  user_data)
{
window102=create_window102();
gtk_widget_show(window102);
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"window104")));
treeview102=lookup_widget(window102,"treeview102");
afficher_seance(treeview102);
}



void on_button110_clicked  (GtkWidget  *objet_graphique, gpointer  user_data)
{
window104=create_window104();
gtk_widget_show(window104);
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"window102")));
}


void on_button111_clicked (GtkWidget  *objet_graphique, gpointer user_data)
{

window105=create_window105();
gtk_widget_show(window105);
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"window102")));

}


void on_button112_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
GtkWidget *combobox104;
GtkWidget *combobox105;
GtkWidget *combobox106;
GtkWidget *combobox103;
GtkWidget *label123;
combobox104=lookup_widget(objet_graphique,"combobox104");
combobox105=lookup_widget(objet_graphique,"combobox105");
combobox106=lookup_widget(objet_graphique,"combobox106");
combobox103=lookup_widget(objet_graphique,"combobox103");
label123=lookup_widget(objet_graphique,"label123");
char ch[50];
char ch1[50];
char ch2[50];
char ch3[50];
char ch4[50];
FILE *f1, *f2;
f1=fopen("src/salleReserve.txt","r+");
f2=fopen("src/tmp.txt","w+");
if(f1!=NULL && f2!=NULL)
{
while(fscanf(f1,"%s %s %s %s %s",ch,ch1,ch2,ch3,ch4)!=EOF)
{
if(strcmp(ch,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox104)))==0 && strcmp(ch1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox105)))==0 && strcmp(ch2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox106)))==0 && strcmp(ch3,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox103)))==0)
fprintf(f2,NULL);
else
fprintf(f2,"%s %s %s %s %s\n",ch,ch1,ch2,ch3,ch4);
}
}
fclose(f1);
fclose(f2);
remove("src/salleReserve.txt");
rename("src/tmp.txt","src/salleReserve.txt");
GtkWidget *treeview102;
treeview102=lookup_widget(window102,"treeview102");
afficher_seance(treeview102);
}


void on_button113_clicked  (GtkWidget *objet_graphique,gpointer  user_data)
{
GtkWidget *input120;
GtkWidget *input121;
GtkWidget *input122;
GtkWidget *input123;
GtkWidget *input124;
GtkWidget *combobox107;
char nom[50];
char prenom[50];
char gsm[50];
char adresse[50];
char specialite[50];
FILE *f1;
int test=0;
window102=lookup_widget(objet_graphique,"window102");
input120=lookup_widget(objet_graphique,"entry103");
input121=lookup_widget(objet_graphique,"entry104");
input122=lookup_widget(objet_graphique,"entry105");
input123=lookup_widget(objet_graphique,"entry106");
input124=lookup_widget(objet_graphique,"entry107");
combobox107=lookup_widget(objet_graphique,"combobox107");
f1=fopen("src/profil.txt","r");
while((fscanf(f1,"%s %s %s %s %s",nom,prenom,gsm,adresse,specialite)!=EOF) && (test==0))
{
test=1;
}
if(test==1)
{
gtk_entry_set_text(GTK_ENTRY(input120),nom);
gtk_entry_set_text(GTK_ENTRY(input121),prenom);
gtk_entry_set_text(GTK_ENTRY(input122),gsm);
gtk_entry_set_text(GTK_ENTRY(input123),adresse);
gtk_entry_set_text(GTK_ENTRY(input124),specialite);
}
fclose(f1);
}

void
on_m8c_clicked                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *input;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *window102;
char nom[50];char prenom[50];char GSM[50];char adresse[50];char specialites[50];
window102=lookup_widget(objet_graphique,"window102");
input=lookup_widget(objet_graphique, "entry103");
input1=lookup_widget(objet_graphique, "entry104");
input2=lookup_widget(objet_graphique, "entry105");
input3=lookup_widget(objet_graphique, "entry106");
input4=lookup_widget(objet_graphique, "entry107");

strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(GSM,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(adresse,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(specialites,gtk_entry_get_text(GTK_ENTRY(input4)));

modifier_profil(nom,prenom,GSM,adresse,specialites);
}



void
on_button115_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *combobox108;
GtkWidget *combobox109;
GtkWidget *combobox110;
GtkWidget *combobox111;
GtkWidget *label140;
combobox108=lookup_widget(objet_graphique,"combobox108");
combobox109=lookup_widget(objet_graphique,"combobox109");
combobox110=lookup_widget(objet_graphique,"combobox110");
combobox111=lookup_widget(objet_graphique,"combobox111");
label140=lookup_widget(objet_graphique,"label140");
char ch[50];
char ch1[50];
char ch2[50];
char ch3[50];
char ch4[50];
FILE *f1, *f2;
f1=fopen("src/salleReserve.txt","r+");
f2=fopen("src/tmp.txt","w+");
if(f1!=NULL && f2!=NULL)
{
while(fscanf(f1,"%s %s %s %s %s",ch,ch1,ch2,ch3,ch4)!=EOF)
{
if(strcmp(ch3,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox111)))==0)
fprintf(f2,NULL);
else
fprintf(f2,"%s %s %s %s %s\n",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox108)),gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox109)),gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox110)),ch3,ch4);
}
}
fclose(f1);
fclose(f2);
rename("src/tmp.txt","src/salleReserve.txt");
GtkWidget *treeview102;
treeview102=lookup_widget(window102,"treeview102");
afficher_seance(treeview102);

}


void
on_button116_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
window102=create_window102();
gtk_widget_show(window102);
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"window105")));
GtkWidget *treeview102;
treeview102=lookup_widget(window102,"treeview102");
afficher_seance(treeview102);

}


void
on_Button407_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowm2;
GtkWidget *windowm4;
windowm2=lookup_widget(objet_graphique,"windowm2");
windowm4=create_windowm4() ;


gtk_widget_show (windowm4);
gtk_widget_hide(windowm2);
}


void
on_button406_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowm2;
GtkWidget *windowm3;
GtkWidget *listeview2 ;
windowm2=lookup_widget(objet_graphique,"windowm2");

windowm3=create_windowm3() ;

listeview2=lookup_widget(windowm3,"treeviewm2");
afficherm(listeview2);
gtk_widget_hide(windowm2);

gtk_widget_show (windowm3);



}


void
on_button408_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowm2;
GtkWidget *login;

windowm2=lookup_widget(objet_graphique,"windowm2");
login=create_login() ;


gtk_widget_show (login);
gtk_widget_hide(windowm2);


}


void
on_button409_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowm5;
GtkWidget *windowm3;
GtkWidget *listeview ;
windowm3=lookup_widget(objet_graphique,"windowm3");
windowm5=create_windowm5() ;


gtk_widget_show (windowm5);
gtk_widget_hide(windowm3);

}



void
on_button415_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char Nom [50], prenom [50],  Poids [50],  Taille [50],  Maladie[50],  conseils [50];
	GtkWidget *input3;
	GtkWidget *input4;	
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *input7;	
	GtkWidget *input8;
        GtkWidget *windowm3;	
	GtkWidget *windowm5;
        GtkWidget *listeview2 ;


input3=lookup_widget(objet_graphique,"entry3");
input4=lookup_widget(objet_graphique,"entry4");
input5=lookup_widget(objet_graphique,"entry5");
input6=lookup_widget(objet_graphique,"entry6");
input7=lookup_widget(objet_graphique,"entry7");
input8=lookup_widget(objet_graphique,"entry8");
strcpy(Nom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(Poids,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(Taille,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(Maladie,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(conseils,gtk_entry_get_text(GTK_ENTRY(input8)));

ajouter_medi(Nom, prenom,Poids, Taille, Maladie, conseils);
windowm5=lookup_widget(objet_graphique,"windowm5"); 
windowm3=create_windowm3() ;
gtk_widget_show (windowm3);
gtk_widget_hide(windowm5);
listeview2=lookup_widget(windowm3,"treeviewm2");
afficherm(listeview2);

}


void
on_button412_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowm3;
GtkWidget *login;

windowm3=lookup_widget(objet_graphique,"windowm3");
login=create_login() ;


gtk_widget_show (login);
gtk_widget_hide(windowm3);


}

void
on_button417_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowm4;
GtkWidget *login;

windowm4=lookup_widget(objet_graphique,"windowm4");
login=create_login() ;


gtk_widget_show (login);
gtk_widget_hide(windowm4);


}

void
on_button418_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowm5;
GtkWidget *login;

windowm5=lookup_widget(objet_graphique,"windowm5");
login=create_login() ;


gtk_widget_show (login);
gtk_widget_hide(windowm5);


}


void
on_button419_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Horraire;
GtkWidget *login;

Horraire=lookup_widget(objet_graphique,"Horraire");
login=create_login() ;


gtk_widget_show (login);
gtk_widget_hide(Horraire);
}


void
on_button420_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button421_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button422_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Rendez_vousM;
GtkWidget *login;

Rendez_vousM=lookup_widget(objet_graphique,"Rendez_vousM");
login=create_login() ;


gtk_widget_show (login);
gtk_widget_hide(Rendez_vousM);
}

void
on_button413_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowm4;
GtkWidget *Horraire;
GtkWidget *listeview6;

windowm4=lookup_widget(objet_graphique,"windowm4");
Horraire=create_Horraire() ;


gtk_widget_show (Horraire);
gtk_widget_hide(windowm4);

     
        



listeview6=lookup_widget(Horraire,"treeviewm3");
horrairem(listeview6);


}


void
on_button414_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowm4;
GtkWidget *Rendez_vousM;

windowm4=lookup_widget(objet_graphique,"windowm4");
Rendez_vousM=create_Rendez_vousM() ;


gtk_widget_show (Rendez_vousM);
gtk_widget_hide(windowm4);
}

void
on_button423_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowm2;
GtkWidget *login;

windowm2=lookup_widget(objet_graphique,"windowm2");
login=create_login() ;


gtk_widget_show (login);
gtk_widget_hide(windowm2);


}


void
on_button424_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowm2;
GtkWidget *windowm3;
GtkWidget *listeview ;
windowm3=lookup_widget(objet_graphique,"windowm3");
windowm2=create_windowm2() ;
listeview=lookup_widget(windowm2,"treeviewm1");
perso(listeview);

gtk_widget_show (windowm2);
gtk_widget_hide(windowm3);


}


void
on_button425_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowm2;
GtkWidget *windowm4;
GtkWidget *listeview ;
windowm4=lookup_widget(objet_graphique,"windowm4");
windowm2=create_windowm2() ;
listeview=lookup_widget(windowm2,"treeviewm1");
perso(listeview);
gtk_widget_show (windowm2);
gtk_widget_hide(windowm4);

}


void
on_button426_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowm4;
GtkWidget *Horraire;

Horraire=lookup_widget(objet_graphique,"Horraire");
windowm4=create_windowm4() ;


gtk_widget_show (windowm4);
gtk_widget_hide(Horraire);


}


void
on_button427_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowm4;
GtkWidget *Rendez_vousM;

Rendez_vousM=lookup_widget(objet_graphique,"Rendez_vousM");
windowm4=create_windowm4() ;


gtk_widget_show (windowm4);
gtk_widget_hide(Rendez_vousM);

}


void
on_button416_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
        GtkWidget *windowm3;	
	GtkWidget *windowm5;
        GtkWidget *listeview2 ;
windowm5=lookup_widget(objet_graphique,"windowm5"); 
windowm3=create_windowm3() ;
gtk_widget_show (windowm3);
gtk_widget_hide(windowm5);
listeview2=lookup_widget(windowm3,"treeviewm2");
afficherm(listeview2);

}


void
on_button434_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button435_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button436_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button438_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

		
   char Jour [50], Heure [50];
	GtkWidget *input20;
	GtkWidget *input30;	
         GtkWidget *Horraire;	
	GtkWidget *ajouter_horaire;
        GtkWidget *listeview6 ;


input20=lookup_widget(objet_graphique,"entry23");
input30=lookup_widget(objet_graphique,"entry24");

strcpy(Jour,gtk_entry_get_text(GTK_ENTRY(input20)));
strcpy(Heure,gtk_entry_get_text(GTK_ENTRY(input30)));


ajouter_date(Jour,Heure);
ajouter_horaire=lookup_widget(objet_graphique,"ajouter_horaire"); 
Horraire=create_Horraire() ;
gtk_widget_show (Horraire);
gtk_widget_hide(ajouter_horaire);
listeview6=lookup_widget(Horraire,"treeviewm3");
horrairem(listeview6);

}


void
on_button437_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
        GtkWidget *Horraire;	
	GtkWidget *ajouter_horaire;
        GtkWidget *listeview6;
Horraire=lookup_widget(objet_graphique,"Horraire"); 
ajouter_horaire=create_ajouter_horaire() ;
gtk_widget_show (ajouter_horaire);
gtk_widget_hide(Horraire);
listeview6=lookup_widget(Horraire,"treeviewm3");
horrairem(listeview6);


}



void
on_button411_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

 }






void
on_button439_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Horraire;	
	GtkWidget *ajouter_horaire;
        GtkWidget *listeview6 ;



ajouter_horaire=lookup_widget(objet_graphique,"ajouter_horaire"); 
Horraire=create_Horraire() ;
gtk_widget_show (Horraire);
gtk_widget_hide(ajouter_horaire);
listeview6=lookup_widget(Horraire,"treeviewm3");
horrairem(listeview6);


}





void
on_button441_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char Nom [50], prenom [50],  Poids [50],  Taille [50],  Maladie[50],  conseils [50];
	GtkWidget *input2;
	GtkWidget *input4;	
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *input7;	
	GtkWidget *input8;
        GtkWidget *windowm3;	
	GtkWidget *modifier_fiche;
        GtkWidget *listeview7 ;


input2=lookup_widget(objet_graphique,"entry11");
input4=lookup_widget(objet_graphique,"entry12");
input5=lookup_widget(objet_graphique,"entry13");
input6=lookup_widget(objet_graphique,"entry14");
input7=lookup_widget(objet_graphique,"entry15");
input8=lookup_widget(objet_graphique,"entry16");
strcpy(Nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(Poids,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(Taille,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(Maladie,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(conseils,gtk_entry_get_text(GTK_ENTRY(input8)));
modifier_fiche=lookup_widget(objet_graphique,"modifier_fiche"); 
supprimerf(Nom, prenom,Poids, Taille, Maladie, conseils);
windowm3=create_windowm3() ;
gtk_widget_show (windowm3);
gtk_widget_hide(modifier_fiche);
listeview7=lookup_widget(windowm3,"treeviewm2");
afficherm(listeview7);

}


void
on_button440_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
               {  char Nom [50], prenom [50],  Poids [50],  Taille [50],  Maladie[50],  conseils [50];
	GtkWidget *input2;
	GtkWidget *input4;	
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *input7;	
	GtkWidget *input8;
        GtkWidget *windowm3;	
	GtkWidget *modifier_fiche;
        GtkWidget *listeview5 ;


input2=lookup_widget(objet_graphique,"entry11");
input4=lookup_widget(objet_graphique,"entry12");
input5=lookup_widget(objet_graphique,"entry13");
input6=lookup_widget(objet_graphique,"entry14");
input7=lookup_widget(objet_graphique,"entry15");
input8=lookup_widget(objet_graphique,"entry16");
strcpy(Nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(Poids,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(Taille,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(Maladie,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(conseils,gtk_entry_get_text(GTK_ENTRY(input8)));
modifier_fiche=lookup_widget(objet_graphique,"modifier_fiche"); 
modifier_fiches(Nom, prenom,Poids, Taille, Maladie, conseils);
windowm3=create_windowm3() ;
gtk_widget_show (windowm3);
gtk_widget_hide(modifier_fiche);
listeview5=lookup_widget(windowm3,"treeviewm2");
afficherm(listeview5);
}


void
on_button442_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modifier_fiche;
GtkWidget *login;

modifier_fiche=lookup_widget(objet_graphique,"modifier_fiche");

login=create_login() ;



gtk_widget_hide(modifier_fiche);

gtk_widget_show (login);

}


void
on_treeviewm2_row_activated             (GtkWidget       *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

  	gchar *Nom;
	gchar *Prenom;
	gchar *Poids;
        gchar *Taille;
	gchar *Maladie;
	gchar *conseils;
   
	GtkWidget *input1;
	GtkWidget *input2;	
	GtkWidget *input3;
        GtkWidget *input4;
	GtkWidget *input5;	
	GtkWidget *input6;
	GtkWidget *modifier_fiche;
	GtkWidget *listeview;
        GtkTreeIter iter;

GtkWidget *windowm3;

         



GtkTreeModel *model = gtk_tree_view_get_model (GTK_TREE_VIEW(lookup_widget(objet_graphique,"treeviewm2")));
 

   if (gtk_tree_model_get_iter(model, &iter, path)) {
      gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &Nom, 1, &Prenom,2,&Poids,3,&Taille,4,&Maladie,5,&conseils, -1); 
windowm3=lookup_widget(objet_graphique,"windowm3"); 
     modifier_fiche=create_modifier_fiche();                                                  }
input1=lookup_widget(modifier_fiche,"entry11");
input2=lookup_widget(modifier_fiche,"entry12");
input3=lookup_widget(modifier_fiche,"entry13");
input4=lookup_widget(modifier_fiche,"entry14");
input5=lookup_widget(modifier_fiche,"entry15");
input6=lookup_widget(modifier_fiche,"entry16");

gtk_entry_set_text(GTK_ENTRY(input1),Nom);
gtk_entry_set_text(GTK_ENTRY(input2),Prenom);
gtk_entry_set_text(GTK_ENTRY(input3),Poids);
gtk_entry_set_text(GTK_ENTRY(input4),Taille);
gtk_entry_set_text(GTK_ENTRY(input5),Maladie);
gtk_entry_set_text(GTK_ENTRY(input6),conseils);
gtk_widget_hide (windowm3);
gtk_widget_show (modifier_fiche);
}




void
on_button443_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modifier_fiche;
GtkWidget *windowm3;
GtkWidget *listeview2 ;
modifier_fiche=lookup_widget(objet_graphique,"modifier_fiche");

windowm3=create_windowm3() ;

listeview2=lookup_widget(windowm3,"treeviewm2");
afficherm(listeview2);
gtk_widget_hide(modifier_fiche);

gtk_widget_show (windowm3);

}


void
on_treeviewm1_row_activated             (GtkWidget       *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

  	gchar *SEXE;
	gchar *NOMm;
	gchar *PRENOMm;
        gchar *EMAIL;
	gchar *ADRESSE;
	gchar *TELEPHONE;
   
	GtkWidget *input1;
	GtkWidget *input2;	
	GtkWidget *input3;
        GtkWidget *input4;
	GtkWidget *input5;	
	GtkWidget *input6;
	GtkWidget *modif_m;
	GtkWidget *listeview;
        GtkTreeIter iter;

GtkWidget *windowm2;

         



GtkTreeModel *model = gtk_tree_view_get_model (GTK_TREE_VIEW(lookup_widget(objet_graphique,"treeviewm1")));
 

   if (gtk_tree_model_get_iter(model, &iter, path)) {
      gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &SEXE, 1, &NOMm,2,&PRENOMm,3,&EMAIL,4,&ADRESSE,5,&TELEPHONE, -1); 
windowm2=lookup_widget(objet_graphique,"windowm2"); 
     modif_m=create_modif_m();                                                  }
input1=lookup_widget(modif_m,"entry17");
input2=lookup_widget(modif_m,"entry18");
input3=lookup_widget(modif_m,"entry19");
input4=lookup_widget(modif_m,"entry20");
input5=lookup_widget(modif_m,"entry21");
input6=lookup_widget(modif_m,"entry22");

gtk_entry_set_text(GTK_ENTRY(input1),SEXE);
gtk_entry_set_text(GTK_ENTRY(input2),NOMm);
gtk_entry_set_text(GTK_ENTRY(input3),PRENOMm);
gtk_entry_set_text(GTK_ENTRY(input4),EMAIL);
gtk_entry_set_text(GTK_ENTRY(input5),ADRESSE);
gtk_entry_set_text(GTK_ENTRY(input6),TELEPHONE);
gtk_widget_hide (windowm2);
gtk_widget_show (modif_m);
}



void
on_button445_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
               {  
GtkWidget *windowm2;	
	GtkWidget *modif_m;
 GtkWidget *listeview5;
modif_m=lookup_widget(objet_graphique,"modif_m"); 
windowm2=create_windowm2() ;
gtk_widget_show (windowm2);
gtk_widget_hide(modif_m);
listeview5=lookup_widget(windowm2,"treeviewm1");
perso(listeview5);


}

void
on_button446_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *login;	
	GtkWidget *modif_m;
 
modif_m=lookup_widget(objet_graphique,"modif_m"); 
login=create_login() ;
gtk_widget_show (login);
gtk_widget_hide(modif_m);


}


void
on_button444_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char SEXE [50], NOM [50],  PRENOM [50],  EMAIL[50],  ADRESSE[50],  TELEPHONE [50];
	GtkWidget *input2;
	GtkWidget *input4;	
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *input7;	
	GtkWidget *input8;
        GtkWidget *windowm2;	
	GtkWidget *modif_m;
        GtkWidget *listeview5 ;


input2=lookup_widget(objet_graphique,"entry17");
input4=lookup_widget(objet_graphique,"entry18");
input5=lookup_widget(objet_graphique,"entry19");
input6=lookup_widget(objet_graphique,"entry20");
input7=lookup_widget(objet_graphique,"entry21");
input8=lookup_widget(objet_graphique,"entry22");
strcpy(SEXE,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(NOM,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(PRENOM,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(EMAIL,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(ADRESSE,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(TELEPHONE,gtk_entry_get_text(GTK_ENTRY(input8)));
modif_m=lookup_widget(objet_graphique,"modif_m"); 
modifier_M ( SEXE, NOM, PRENOM , EMAIL ,  ADRESSE,TELEPHONE);
windowm2=create_windowm2() ;
gtk_widget_show (windowm2);
gtk_widget_hide(modif_m);
listeview5=lookup_widget(windowm2,"treeviewm1");
perso(listeview5);

}










void
on_treeviewm3_row_activated            (GtkWidget       *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

	gchar *Jour;
	gchar *Heure;
      
   
	GtkWidget *input1;
	GtkWidget *input2;	
	
	GtkWidget *mod_hm;
	GtkWidget *listeview;
        GtkTreeIter iter;

GtkWidget *Horraire;

         



GtkTreeModel *model = gtk_tree_view_get_model (GTK_TREE_VIEW(lookup_widget(objet_graphique,"treeviewm3")));
 

   if (gtk_tree_model_get_iter(model, &iter, path)) {
      gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &Jour, 1, &Heure, -1); 
Horraire=lookup_widget(objet_graphique,"Horraire"); 
     mod_hm=create_mod_hm();                                                  }
input1=lookup_widget(mod_hm,"entry25");
input2=lookup_widget(mod_hm,"entry26");


gtk_entry_set_text(GTK_ENTRY(input2),Heure);
gtk_entry_set_text(GTK_ENTRY(input1),Jour);

gtk_widget_hide (Horraire);
gtk_widget_show (mod_hm);


}


void
on_button447_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char Jour [50], Heure [50];
	GtkWidget *input2;
	GtkWidget *input4;	
        GtkWidget *Horraire;	
	GtkWidget *mod_hm;
        GtkWidget *listeview5 ;


input2=lookup_widget(objet_graphique,"entry25");
input4=lookup_widget(objet_graphique,"entry26");

strcpy(Jour,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(Heure,gtk_entry_get_text(GTK_ENTRY(input4)));
mod_hm=lookup_widget(objet_graphique,"mod_hm"); 
modifier_HM (Jour,Heure);
Horraire=create_Horraire() ;
gtk_widget_show (Horraire);
gtk_widget_hide(mod_hm);
listeview5=lookup_widget(Horraire,"treeviewm3");
horrairem(listeview5);

}


void
on_button448_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Horraire;	
	GtkWidget *mod_hm;
        GtkWidget *listeview6 ;



mod_hm=lookup_widget(objet_graphique,"mod_hm"); 
Horraire=create_Horraire() ;
gtk_widget_show (Horraire);
gtk_widget_hide(mod_hm);
listeview6=lookup_widget(Horraire,"treeviewm3");
horrairem(listeview6);


}



void
on_button333s_clicked (GtkWidget     *objet_graphique, gpointer  user_data)
{
GtkWidget *window2s;
GtkWidget *window3s;
GtkWidget *listeview ;
window3s=lookup_widget(objet_graphique,"window3s") ;
window3s=create_window3s();
listeview=lookup_widget(window3s,"treeview6s");
afficherm(listeview);
gtk_widget_show(window3s);
gtk_widget_hide(window2s);
}


void
on_button2s_clicked                   (GtkWidget     *objet_graphique, gpointer  user_data)
{

}


void
on_button3s_clicked  (GtkWidget     *objet_graphique, gpointer  user_data)
{
GtkWidget *window2s ;
GtkWidget *window9s ;
window2s=lookup_widget(objet_graphique,"window2s") ;
window9s=create_window9s();
gtk_widget_show (window9s);
gtk_widget_hide(window2s) ;
}

void
on_button5s_clicked (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window2s;
GtkWidget *window7s;
GtkWidget *listeview ;
window2s=lookup_widget(objet_graphique,"window2s");
window7s=create_window7s() ;
listeview=lookup_widget(window7s,"treeview4s");
afficher_fich_regime(listeview);
gtk_widget_show (window7s);
gtk_widget_hide(window2s);

}


void
on_button4s_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window2s;
GtkWidget *window5s;
GtkWidget *listeview ;
window2s=lookup_widget(objet_graphique,"window2s") ;
window5s=create_window5s();
listeview=lookup_widget(window5s,"treeview3s");
afficher3s(listeview);
gtk_widget_show(window5s);
gtk_widget_hide(window2s);
}

void
on_button11s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button10s_clicked                      (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window5s;
GtkWidget *window6s;


window5s=lookup_widget(objet_graphique,"window5s");
window6s=create_window6s() ;

gtk_widget_show (window6s);
gtk_widget_hide(window5s) ;

}



void
on_button13s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button14s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button15s_clicked (GtkWidget     *objet_graphique,
                                        gpointer         user_data)

{ int jour ; int mois ; int annee  ;char Horaires [50] ;
GtkWidget *combobox1s ;
GtkWidget *jour1s ;
GtkWidget *mois1s ;
GtkWidget *annee1s;
GtkWidget *listeview ;
GtkWidget *window6s ;
GtkWidget *window5s;

combobox1s=lookup_widget(objet_graphique,"combobox1s");
jour1s=lookup_widget(objet_graphique,"spinbutton1s");
mois1s=lookup_widget(objet_graphique,"spinbutton2s");
annee1s=lookup_widget(objet_graphique,"spinbutton3s");
window6s=lookup_widget(objet_graphique,"window6s") ;


strcpy(Horaires,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1s)));
jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1s));
mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1s));
annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee1s));


ajouter2s(jour,mois,annee,Horaires);

window6s=lookup_widget(objet_graphique,"window6s"); 
window5s=create_window5s() ;
gtk_widget_show (window5s);
gtk_widget_hide(window6s);
listeview=lookup_widget(window5s,"treeview3s");
afficher3s(listeview);




}


void
on_button16s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button17s_clicked  (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window7s;
GtkWidget *window8s;
window7s=lookup_widget(objet_graphique,"window7s") ;
window8s=create_window8s();
gtk_widget_show(window8s);
gtk_widget_hide(window7s); 
}




void
on_button18s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button19s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button20s_clicked                  (GtkWidget     *objet_graphique, gpointer  user_data)
{
GtkWidget *window7s;
GtkWidget *window2s;
window7s=lookup_widget(objet_graphique,"window7s") ;
window2s=create_window2s();
gtk_widget_show(window2s);
gtk_widget_hide(window7s);
GtkWidget *listeview ;


listeview=lookup_widget(window2s,"treeview1s");
afficher2s(listeview);

}


void
on_button21s_clicked   (GtkWidget     *objet_graphique, gpointer  user_data)

{
char Nom [50];char prenom [50];char Poids [50];char Taille [50];char regime [50];char imc [50];
	GtkWidget *input30;
	GtkWidget *input40;	
	GtkWidget *input50;
	GtkWidget *input60;
	GtkWidget *input70;	
	GtkWidget *input80;
        GtkWidget *window7s;	
	GtkWidget *window8s;
        GtkWidget *listeview ;
input30=lookup_widget(objet_graphique,"entry6s");
input40=lookup_widget(objet_graphique,"entry7s");
input50=lookup_widget(objet_graphique,"entry301s");
input60=lookup_widget(objet_graphique,"entry302s");
input70=lookup_widget(objet_graphique,"entry10s");
input80=lookup_widget(objet_graphique,"entry303s");
strcpy(Nom,gtk_entry_get_text(GTK_ENTRY(input30)));
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input40)));
strcpy(Poids,gtk_entry_get_text(GTK_ENTRY(input50)));
strcpy(Taille,gtk_entry_get_text(GTK_ENTRY(input60)));
strcpy(imc,gtk_entry_get_text(GTK_ENTRY(input70)));
strcpy(regime,gtk_entry_get_text(GTK_ENTRY(input80)));

ajouter_reg(Nom, prenom,Poids, Taille, regime, imc);
window8s=lookup_widget(objet_graphique,"window8s"); 
window7s=create_window7s() ;
gtk_widget_show (window7s);
gtk_widget_hide(window8s);
listeview=lookup_widget(window7s,"treeview4s");
afficher_fich_regime(listeview);
}



void
on_button22s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button7s_clicked (GtkWidget     *objet_graphique, gpointer  user_data)
{
GtkWidget *window2s ;
GtkWidget *login ;
window2s=lookup_widget(objet_graphique,"window2s") ;
login=create_login();
gtk_widget_show (login);
gtk_widget_hide(window2s) ;
}


void
on_button303s_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button302s_clicked (GtkWidget     *objet_graphique, gpointer  user_data)
{
GtkWidget *window3s;GtkWidget *window2s;
GtkWidget *listeview ;
window3s=lookup_widget(objet_graphique,"window3s") ;
window2s=create_window2s();
listeview=lookup_widget(window2s,"treeview1s");
afficher2s(listeview);
gtk_widget_show(window2s);
gtk_widget_hide(window3s);
}


void
on_button8s_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
ajouter                                (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window5m;
GtkWidget *window7m;


window5m=lookup_widget(objet_graphique,"window5m");
window7m=create_window7m() ;

gtk_widget_show (window7m);
gtk_widget_hide(window5m) ;

}



void
supprimer                              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window5m;
GtkWidget *window12m;


window5m=lookup_widget(objet_graphique,"window5m");
window12m=create_window12m() ;
gtk_widget_show (window12m);
gtk_widget_hide(window5m) ;

}
void
modifier                               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{}

void
confirmer_                             (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{ int jour ; int mois ; int annes  ;char Horaires [50] ;
GtkWidget *combobox1m ;
GtkWidget *jour1 ;
GtkWidget *mois1 ;
GtkWidget *annes1;

GtkWidget *window7m ;


combobox1m=lookup_widget(objet_graphique,"combobox1m");
jour1=lookup_widget(objet_graphique,"spinbutton1m");
mois1=lookup_widget(objet_graphique,"spinbutton2m");
annes1=lookup_widget(objet_graphique,"spinbutton3m");
window7m=lookup_widget(objet_graphique,"window7m") ;


strcpy(Horaires,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1m)));
jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));
mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
annes=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annes1));


ajouter2(jour,mois,annes,Horaires);

}



void
confirmer1                             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char SEXE [50], NOM[50],  PRENOM[50],  EMAIL [50],  ADRESSE[50],  TELEPHONE[50];
	GtkWidget *input2;
	GtkWidget *input4;	
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *input7;	
	GtkWidget *input8;
        GtkWidget *window10m;	
	GtkWidget *window2m;
        GtkWidget *listeview5 ;


input2=lookup_widget(objet_graphique,"entry5");
input4=lookup_widget(objet_graphique,"entry6");
input5=lookup_widget(objet_graphique,"entry7");
input6=lookup_widget(objet_graphique,"entry8");
input7=lookup_widget(objet_graphique,"entry9");
input8=lookup_widget(objet_graphique,"entry10");
strcpy(SEXE,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(NOM,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(PRENOM,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(EMAIL,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(ADRESSE,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(TELEPHONE,gtk_entry_get_text(GTK_ENTRY(input8)));
window10m=lookup_widget(objet_graphique,"window10m"); 
modifierm(SEXE,NOM,PRENOM,EMAIL,ADRESSE,TELEPHONE);

window2m=create_window2m() ;
gtk_widget_show (window2m);
gtk_widget_hide(window10m);

listeview5=lookup_widget(window2m,"treeview1");
afficher2(listeview5);
}


void
on_button21_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window2m;
GtkWidget *login;


window2m=lookup_widget(objet_graphique,"window2m");
login=create_login() ;
gtk_widget_show (login);
gtk_widget_hide(window2m) ;


}


void
confirmer3                             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{



}


void
on_button23_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window3m;
GtkWidget *window2m;
GtkWidget *listview;


window3m=lookup_widget(objet_graphique,"window3m");
window2m=create_window2m() ;
listview=lookup_widget(window2m,"treeview1");
afficher2(listview);
gtk_widget_show (window2m);
gtk_widget_hide(window3m) ;

}


void
on_button24_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window5m;
GtkWidget *window2m;
GtkWidget *listview;

window5m=lookup_widget(objet_graphique,"window5m");
window2m=create_window2m() ;
listview=lookup_widget(window2m,"treeview1");
afficher2(listview);
gtk_widget_show (window2m);
gtk_widget_hide(window5m) ;


}


void
on_button25_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window7m;
GtkWidget *window5m;
GtkWidget *listview;

window7m=lookup_widget(objet_graphique,"window7m");
window5m=create_window5m() ;
listview=lookup_widget(window5m,"treeview3");
afficher3(listview);
gtk_widget_show (window5m);
gtk_widget_hide(window7m) ;

}


void
on_button26_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window11m;
GtkWidget *window5m;
GtkWidget *listview;

window11m=lookup_widget(objet_graphique,"window11m");
window5m=create_window5m() ;
listview=lookup_widget(window5m,"treeview3");
afficher3(listview);
gtk_widget_show (window5m);
gtk_widget_hide(window11m) ;
}


void
on_button27_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window10m;
GtkWidget *window2m;
GtkWidget *listview;

window10m=lookup_widget(objet_graphique,"window10m");
window2m=create_window2m() ;
listview=lookup_widget(window2m,"treeview1");
afficher2(listview);
gtk_widget_show (window2m);
gtk_widget_hide(window10m) ;

}


void
on_button6_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window2m;
GtkWidget *login;


window2m=lookup_widget(objet_graphique,"window2m");
login=create_login() ;
gtk_widget_show (login);
gtk_widget_hide(window2m) ;
}


void
on_button28_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window3m;
GtkWidget *login;


window3m=lookup_widget(objet_graphique,"window3m");
login=create_login() ;
gtk_widget_show (login);
gtk_widget_hide(window3m) ;
}


void
on_button29_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window5m;
GtkWidget *login;


window5m=lookup_widget(objet_graphique,"window5m");
login=create_login() ;
gtk_widget_show (login);
gtk_widget_hide(window5m) ;
}


void
on_button30_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window7m;
GtkWidget *login;


window7m=lookup_widget(objet_graphique,"window7m");
login=create_login() ;
gtk_widget_show (login);
gtk_widget_hide(window7m) ;
}




void
on_button31_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window10m;
GtkWidget *login;


window10m=lookup_widget(objet_graphique,"window10m");
login=create_login() ;
gtk_widget_show (login);
gtk_widget_hide(window10m) ;
}


void
on_button32_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window11m;
GtkWidget *login;


window11m=lookup_widget(objet_graphique,"window11m");
login=create_login() ;
gtk_widget_show (login);
gtk_widget_hide(window11m) ;
}


void
on_button33_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window12m;
GtkWidget *window5m;
GtkWidget *listview;

window12m=lookup_widget(objet_graphique,"window12m");
window5m=create_window5m() ;
listview=lookup_widget(window5m,"treeview3");
afficher3(listview);
gtk_widget_show (window5m);
gtk_widget_hide(window12m);
}


void
confirmer4                             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window12m;
GtkWidget *window5m ;

GtkWidget *combobox12m;
GtkWidget *combobox22m;
GtkWidget *combobox33m;
GtkWidget *combobox7m ;
GtkWidget *label60m;
combobox12m=lookup_widget(objet_graphique,"combobox12m");
combobox22m=lookup_widget(objet_graphique,"combobox22m");
combobox33m=lookup_widget(objet_graphique,"combobox33m");
combobox7m=lookup_widget(objet_graphique,"combobox7m");
label60m=lookup_widget(objet_graphique,"label60m");

char ch[50];
char ch1[50];
char ch2[50];
char ch3[50];

FILE *f1, *f2;
f1=fopen("/home/manel/Projects/project4/src/profile3.txt","r");
f2=fopen("/home/manel/Projects/project4/src/tmp.txt","w+");


while(fscanf(f1,"%s %s %s %s",ch,ch1,ch2,ch3)!=EOF)
{
if(strcmp(ch,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox12m)))!=0 && strcmp(ch1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox22m)))!=0 && strcmp(ch2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox33m)))!=0 && strcmp(ch3,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox7m)))!=0)
fprintf(f2,"%s %s %s %s \n",ch,ch1,ch2,ch3);
}

fclose(f1);
fclose(f2);

rename("/home/manel/projects/project4/src/tmp.txt","/home/Projects/project4/src/profile3.txt");
//GtkWidget *treeview3;
//treeview3=lookup_widget(window5m,"treeview3");
//afficher3(treeview3);

}


void
on_button35_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window12m;
GtkWidget *login;


window12m=lookup_widget(objet_graphique,"window12m");
login=create_login() ;
gtk_widget_show (login);
gtk_widget_hide(window12m) ;
}


void
Disponibilit__                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window2m;
GtkWidget *window5m;
GtkWidget *listeview ;
window2m=lookup_widget(objet_graphique,"window2m") ;
window5m=create_window5m();
listeview=lookup_widget(window5m,"treeview3");
afficher3(listeview);
gtk_widget_show(window5m);
gtk_widget_hide(window2m);
}





void
on_button38_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button39_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
modifier_fiche_personellem             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window2m;
GtkWidget *window10m;


window2m=lookup_widget(objet_graphique,"window2m");
window10m=create_window10m() ;
gtk_widget_show (window10m);
gtk_widget_hide(window2m) ;
}


void
consulter_fiches_medicalem             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window2m;
GtkWidget *window3m;
GtkWidget *listeview ;

window2m=lookup_widget(objet_graphique,"window2m");
window3m=create_window3m() ;
listeview=lookup_widget(window3m,"treeview2");
afficher(listeview);
gtk_widget_show (window3m);
gtk_widget_hide(window2m) ;
}


void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
 
}


void
on_treeview1_row_activated              (GtkWidget       *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

  	gchar *SEXE;
	gchar *NOM;
	gchar *PRENOM;
   
         gchar *EMAIL;
	gchar *ADRESSE;
        gchar *TELEPHONE;
   
	GtkWidget *input1;
	GtkWidget *input2;	
	GtkWidget *input3;
        GtkWidget *input4;
	GtkWidget *input5;	
	GtkWidget *input6;

	GtkWidget *window10m;
        GtkWidget   *window2m;
	GtkWidget *listeview;
        GtkTreeIter iter;



         



GtkTreeModel *model = gtk_tree_view_get_model (GTK_TREE_VIEW(lookup_widget(objet_graphique,"treeview1")));
 

   if (gtk_tree_model_get_iter(model, &iter, path)) {
      gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &SEXE, 1, &NOM,2,&PRENOM,3,&EMAIL,4,&ADRESSE,5,&TELEPHONE, -1); 
window2m=lookup_widget(objet_graphique,"window2m"); 
window10m=create_window10m();                                                  }
input1=lookup_widget(window10m,"entry5");
input2=lookup_widget(window10m,"entry6");
input3=lookup_widget(window10m,"entry7");
input4=lookup_widget(window10m,"entry8");
input5=lookup_widget(window10m,"entry9");
input6=lookup_widget(window10m,"entry10");


gtk_entry_set_text(GTK_ENTRY(input1),SEXE);
gtk_entry_set_text(GTK_ENTRY(input2),NOM);
gtk_entry_set_text(GTK_ENTRY(input3),PRENOM);
gtk_entry_set_text(GTK_ENTRY(input4),EMAIL);
gtk_entry_set_text(GTK_ENTRY(input5),ADRESSE);
gtk_entry_set_text(GTK_ENTRY(input6),TELEPHONE);

gtk_widget_hide(window2m);
gtk_widget_show (window10m);
}


void
on_button36_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window2m;
GtkWidget *window1111m;


window2m=lookup_widget(objet_graphique,"window2m");
window1111m=create_window1111m() ;
gtk_widget_show (window1111m);
gtk_widget_hide(window2m) ;

}


