#include"finals.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <gtk/gtk.h>

void ajouter2s( int jour , int  mois , int annes ,char Horaires [50])
{
FILE*f ;
f=fopen("src/profile3s.txt","a+");

fprintf(f," %d %d %d %s\n",jour,mois,annes,Horaires);
fclose(f) ;
}

void ajouter_reg (char Nom [50], char Prenom [50], char Poids [50], char Taille [50], char regime[50], char imc [50])
{
FILE *f;
f=fopen("src/regimes.txt","a+");
fprintf(f,"%s %s %s %s %s %s\n",Nom,Prenom,Poids,Taille,regime,imc);
fclose(f);	

}

void afficher2s(GtkWidget *pListView)
{
enum {
SEXE,
NOM,
PRENOM,
EMAIL, 
ADRESSE,
TELEPHONE,
TOGGLE_COLUMN,
N_COLUMN
};

GtkWidget *window2s;

GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore = gtk_list_store_new(N_COLUMN, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_UINT,G_TYPE_BOOLEAN);

FILE *f;char var[50],var1[50],var2[50],var3[50],var4[50];
int var5;
f=fopen("src/profiles.txt","r");
while(fscanf(f,"%s %s %s %s %s %d",var,var1,var2,var3,var4,&var5)!=EOF)
	{
GtkTreeIter pIter;
gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,
SEXE,var,
NOM,var1,
PRENOM,var2,
EMAIL,var3,
ADRESSE,var4,
TELEPHONE,var5,
TOGGLE_COLUMN,FALSE,

-1);
	}
void toggled_func(GtkCellRendererToggle *cell_renderer, gchar *path, gpointer user_data)
{
 
    GtkTreeIter iter;
    GtkTreePath *ppath;
    gboolean boolean;
 
 
// convertir la chaine path en GtkTreePath 
 
     ppath = gtk_tree_path_new_from_string (path);
 
// convertir la valeure recuperée en GtkTreeIter  
     gtk_tree_model_get_iter (GTK_TREE_MODEL (user_data),
                           &iter,
                           ppath);
//  utiliser la variable GtkTreeIter pour acceder la valeure booleaine                           
     gtk_tree_model_get (GTK_TREE_MODEL (user_data),
                           &iter,
                           TOGGLE_COLUMN,&boolean,
                           -1);
// changer cette valeure booleaine (! boolean )                          
     gtk_list_store_set (user_data, &iter,
                      TOGGLE_COLUMN, !boolean,
                      -1);
 
 
}


pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("sexe",
pCellRenderer,
"text", SEXE,
NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("nom",
pCellRenderer,
"text", NOM,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("prenom",
pCellRenderer,
"text", PRENOM,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("email",
pCellRenderer,
"text", EMAIL,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("adresse",
pCellRenderer,
"text", ADRESSE,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("telephone",
pCellRenderer,
"text", TELEPHONE,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);


g_signal_connect(G_OBJECT(pCellRenderer), "toggled", (GCallback)toggled_func, pListStore);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);	

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 


fclose(f);
	
}
void afficher3s(GtkWidget *pListView)
{
enum {
JOUR,
MOIS,
ANNES,
HORAIRES, 
TOGGLE_COLUMN,
N_COLUMN
};

GtkWidget *window5s;

GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore = gtk_list_store_new(N_COLUMN,G_TYPE_UINT,G_TYPE_UINT,G_TYPE_UINT,G_TYPE_STRING,G_TYPE_BOOLEAN);

FILE *f; int var2 ; int var3 ; int var4 ;char var5[50] ;
f=fopen("src/profile3s.txt","r");
while(fscanf(f,"%d %d %d %s",&var2,&var3,&var4,var5)!=EOF)
	{
GtkTreeIter pIter;

gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,

JOUR,var2,
MOIS,var3,
ANNES,var4,
HORAIRES,var5,
TOGGLE_COLUMN,FALSE,
-1);
	}
void toggled_func(GtkCellRendererToggle *cell_renderer, gchar *path, gpointer user_data)
{
 
    GtkTreeIter iter;
    GtkTreePath *ppath;
    gboolean boolean;
 
 
// convertir la chaine path en GtkTreePath 
 
     ppath = gtk_tree_path_new_from_string (path);
 
// convertir la valeure recuperée en GtkTreeIter  
     gtk_tree_model_get_iter (GTK_TREE_MODEL (user_data),
                           &iter,
                           ppath);
//  utiliser la variable GtkTreeIter pour acceder la valeure booleaine                           
     gtk_tree_model_get (GTK_TREE_MODEL (user_data),
                           &iter,
                           TOGGLE_COLUMN,&boolean,
                           -1);
// changer cette valeure booleaine (! boolean )                          
     gtk_list_store_set (user_data, &iter,
                      TOGGLE_COLUMN, !boolean,
                      -1);
 
 
}

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("jour",
pCellRenderer,
"text", JOUR,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("mois",
pCellRenderer,
"text", MOIS,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("annes", 
pCellRenderer,
"text", ANNES,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("Horaires",
pCellRenderer,
"text", HORAIRES,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

g_signal_connect(G_OBJECT(pCellRenderer), "toggled", (GCallback)toggled_func, pListStore);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);	
	

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 


fclose(f);
	
}




void afficher_fich_regime(GtkWidget *pListView)
{
enum {
Nom,
Prenom,
Poids,
Taille, 
regime,
imc,
N_COLUMN1
};

GtkWidget *window7s;

GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore = gtk_list_store_new(N_COLUMN1, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

FILE *f; char var300[50],var310[50],var320[50],var330[50],var340[50], var350[40];
f=fopen("src/regimes.txt","r");
while(fscanf(f,"%s %s %s %s %s %s",var300,var310,var320,var330,var340,var350)!=EOF)
	{
GtkTreeIter pIter;
gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,
Nom,var300,
Prenom,var310,
Poids,var320,
Taille,var330,
regime,var340,
imc,var350,
-1);
	}

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("Nom",
pCellRenderer,
"text", Nom,
NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("Prenom",
pCellRenderer,
"text", Prenom,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("Poids",
pCellRenderer,
"text", Poids,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("Taille",
pCellRenderer,
"text", Taille,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("Regime",
pCellRenderer,
"text", regime,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("IMC",
pCellRenderer,
"text", imc,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

	

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 


fclose(f);
	
}



