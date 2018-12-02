#include"fonctions.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <gtk/gtk.h>

void ajouter2(char nom[50] , char prenom[50], char heure_de_rendezvous[50] , int jour , int  mois , int annes )
{
FILE*f ;
f=fopen("src/profile3.txt","a");

fprintf(f,"%s %s %s %d %d %d\n",nom ,prenom,heure_de_rendezvous,jour,mois,annes);
fclose(f) ;
}


int verifier(char login[],char password[])
{
int role ;
char ch1[50] , ch2[50] ;
FILE*f ;
f=fopen("src/users.txt","r");
while((fscanf(f,"%s %s %d",ch1,ch2,&role)!=EOF))
 { if((strcmp(ch1,login) == 0 ) && (strcmp(ch2,password)==0))
      {
        fclose(f) ;
return role ;

}
}
fclose(f) ;
return 0 ;}







void afficher_(GtkWidget *pListView)
{
enum {
NOM,
PRENOM,
POIDS,
TAILLE, 
MALADIS,
CONSEILS,
N_COLUMN
};

GtkWidget *window5;

GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore = gtk_list_store_new(N_COLUMN, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

FILE *f;char var[50],var4[50],var5[50],var1[50],var3[50], var2[40];
f=fopen("src/profile2.txt","r");
while(fscanf(f,"%s %s %s %s %s %s",var,var1,var2,var3,var4,var5)!=EOF)
	{
GtkTreeIter pIter;
gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,
NOM,var,
PRENOM,var1,
POIDS,var2,
TAILLE,var3,
MALADIS,var4,
CONSEILS,var5,
-1);
	}

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
pColumn = gtk_tree_view_column_new_with_attributes("poids",
pCellRenderer,
"text", POIDS,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("taille",
pCellRenderer,
"text", TAILLE,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("maladis",
pCellRenderer,
"text", MALADIS,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("conseils",
pCellRenderer,
"text", CONSEILS,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

	

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 


fclose(f);
	
}




void afficher2(GtkWidget *pListView)
{
enum {
SEXE,
NOM,
PRENOM,
EMAIL, 
ADRESSE,
TELEPHONE,
N_COLUMN
};

GtkWidget *window5;

GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore = gtk_list_store_new(N_COLUMN, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_UINT);

FILE *f;char var[50],var1[50],var2[50],var3[50],var4[50];
int var5;
f=fopen("src/profile.txt","r");
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

	

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 


fclose(f);
	
}
void afficher3(GtkWidget *pListView)
{
enum {
NOM,
PRENOM,
DATE_DE_RENDEZVOUS,
HEURES_DE_RENDEZVOUS, 
N_COLUMN
};

GtkWidget *window5;

GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore = gtk_list_store_new(N_COLUMN, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

FILE *f;char var[50],var1[50],var2[50],var3[50];
f=fopen("src/profile3.txt","r");
while(fscanf(f,"%s %s %s %s",var,var1,var2,var3)!=EOF)
	{
GtkTreeIter pIter;

gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,
NOM,var,
PRENOM,var1,
DATE_DE_RENDEZVOUS,var2,
HEURES_DE_RENDEZVOUS,var3,
-1);
	}

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
pColumn = gtk_tree_view_column_new_with_attributes("date_de_rendezvous",
pCellRenderer,
"text", DATE_DE_RENDEZVOUS,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("heures_de_rendezvous",
pCellRenderer,
"text", HEURES_DE_RENDEZVOUS,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

	

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 


fclose(f);
	
}
