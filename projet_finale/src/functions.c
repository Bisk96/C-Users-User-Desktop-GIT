
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <gtk/gtk.h>
#include "function.h"
void ajouter_medi (char Nom [50], char Prenom [50], char Poids [50], char Taille [50], char Maladie[50], char conseils [50])
{
FILE *f;
f=fopen("src/fiches.txt","a+");
fprintf(f,"%s %s %s %s %s %s\n",Nom,Prenom,Poids,Taille,Maladie,conseils);
fclose(f);	

}
void afficherm(GtkWidget *pListView)
{
enum {
Nom,
Prenom,
Poids,
Taille, 
Maladis,
conseils,
N_COLUMN
};

GtkWidget *window3;

GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore = gtk_list_store_new(N_COLUMN, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

FILE *f; char var0[50],var10[50],var20[50],var30[50],var40[50], var50[40];
f=fopen("src/fiches.txt","r");
while(fscanf(f,"%s %s %s %s %s %s",var0,var10,var20,var30,var40,var50)!=EOF)
	{
GtkTreeIter pIter;
gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,
Nom,var0,
Prenom,var10,
Poids,var20,
Taille,var30,
Maladis,var40,
conseils,var50,
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
pColumn = gtk_tree_view_column_new_with_attributes("Maladis",
pCellRenderer,
"text", Maladis,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("conseils",
pCellRenderer,
"text", conseils,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

	

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 


fclose(f);
	
}






void perso(GtkWidget *pListView)
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

GtkWidget *window2;

GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore = gtk_list_store_new(N_COLUMN, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING);

FILE *f;char var[50],var1[50],var2[50],var3[50],var4[50];
char var5 [50];
f=fopen("src/profile.txt","r");
 while(fscanf(f,"%s %s %s %s %s %s",var,var1,var2,var3,var4,var5)!=EOF)
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

void horrairem(GtkWidget *pListView)
{
enum {
Jour,
Heure,
N_COLUMN
};

GtkWidget *Horraire;

GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore = gtk_list_store_new(N_COLUMN, G_TYPE_STRING, G_TYPE_STRING);

FILE *f; char var[50],var1[50];
f=fopen("src/horairem.txt","a+");
while(fscanf(f,"%s %s ",var,var1)!=EOF)
	{
GtkTreeIter pIter;
gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,
Jour,var,
Heure,var1,

-1);
	}

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("Jour",
pCellRenderer,
"text", Jour,
NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("Heure",
pCellRenderer,
"text", Heure,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 
	




fclose(f);
	
}
void modifier_fiches (char Nom [50], char Prenom [50], char Poids [50], char Taille [50], char Maladie[50], char conseils [50])
{
FILE *f,*f1;
char var10[50];char var11[50];char var22[50] ;char var33[50]; char var44[50]; char var55[50];
f=fopen("src/fiches.txt","r");
f1=fopen("src/tampo.txt","w");
if (f == NULL || f1 == NULL)
  {
    return;
  }
  else
  {
    while(fscanf(f,"%s %s %s %s %s %s ",var10,var11,var22,var33,var44,var55) != EOF)
    {
      if  (strcmp(var10,Nom)==0 && strcmp(var11,Prenom)==0 )
          fprintf(f1,"%s %s %s %s %s %s \n",Nom,Prenom,Poids,Taille,Maladie,conseils);
      else
          fprintf(f1,"%s %s %s %s %s %s \n ",var10,var11,var22,var33,var44,var55);
    }
  }

  fclose(f);
  fclose(f1);
fclose(f1);
fclose(f);
remove("src/fiches.txt");
rename("src/tampo.txt","src/fiches.txt");	
}

void supprimerf(char Nom [50], char Prenom [50], char Poids [50], char Taille [50], char Maladie[50], char conseils [50])
{
  FILE *f;
  FILE *f1;

  char var10[50];char var11[50];char var22[50] ;char var33[50]; char var44[50]; char var55[50];

  f = fopen("src/fiches.txt","r");
  f1 = fopen("src/tampo.txt","w+");
  
   if (f == NULL || f1 == NULL)
  {
    return;
  }
  else
  {
    while(fscanf(f,"%s %s %s %s %s %s ",var10,var11,var22,var33,var44,var55) != EOF)
    {
      if  (strcmp(var10,Nom)!=0 && strcmp(var11,Prenom)!=0)
        
          fprintf(f1,"%s %s %s %s %s %s ",var10,var11,var22,var33,var44,var55);
    }
  }



  fclose(f);
  fclose(f1);
remove("src/fiches.txt");
  rename("src/tampo.txt","src/fiches.txt");
}
void modifier_M (char SEXE [50], char NOM [50], char PRENOM [50], char EMAIL [50], char ADRESSE[50], char TELEPHONE [50])
{
FILE *f,*f1;
char var10[50];char var11[50];char var22[50] ;char var33[50]; char var44[50]; char var55[50];
f=fopen("src/profile.txt","r");
f1=fopen("src/tampor.txt","w");
if (f == NULL || f1 == NULL)
  {
    return;
  }
  else
  {
    while(fscanf(f,"%s %s %s %s %s %s ",var10,var11,var22,var33,var44,var55) != EOF)
    {
      if  (strcmp(var11,NOM)==0 && strcmp(var22,PRENOM)==0 )
          fprintf(f1,"%s %s %s %s %s %s \n",SEXE, NOM, PRENOM , EMAIL ,  ADRESSE,TELEPHONE);
      else
          fprintf(f1,"%s %s %s %s %s %s \n ",var10,var11,var22,var33,var44,var55);
    }
  }

  fclose(f);
  fclose(f1);
fclose(f1);
fclose(f);
remove("src/profile.txt");
rename("src/tampor.txt","src/profile.txt");	
}
void ajouter_date (char Jour[50], char Heure [50])
{
FILE *f;
f=fopen("src/horairem.txt","a+");
fprintf(f,"%s %s \n",Jour,Heure);
fclose(f);	

}


void modifier_HM (char Jour [50], char Heure [50])
{
FILE *f,*f1;
char var10[50];char var11[50];
f=fopen("src/horairem.txt","r");
f1=fopen("src/tamporr.txt","w");
if (f == NULL || f1 == NULL)
  {
    return;
  }
  else
  {
    while(fscanf(f,"%s %s \n ",var10,var11) != EOF)
    {
      if  (strcmp(var10,Jour)==0)
          fprintf(f1,"%s %s \n",Jour,Heure);
      else
          fprintf(f1,"%s %s  \n ",var10,var11);
    }
  }

  fclose(f);
  fclose(f1);
fclose(f1);
fclose(f);
remove("src/horairem.txt");
rename("src/tamporr.txt","src/horairem.txt");	
}



