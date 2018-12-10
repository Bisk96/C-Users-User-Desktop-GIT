#include"fonctions.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <gtk/gtk.h>
int modifierm(char SEXE[50],char NOM[50],char PRENOM[50],char EMAIL[50],char ADRESSE[50],char TELEPHONE[50] )
{
FILE *f,*f1;
char var11[50];char var12[50];char var13[50] ;char var14[50]; char var15[50]; char var16[50];
f=fopen("src/profile.txt","r");
f1=fopen("src/tampo1.txt","w");

    while(fscanf(f,"%s %s %s %s %s %s ",var11,var12,var13,var14,var15,var16) != EOF)
    {
      if  (strcmp(var12,NOM)==0 && strcmp(var13,PRENOM)==0 )
    
          fprintf(f1,"%s %s %s %s %s %s \n ",SEXE,var12,var13,EMAIL,ADRESSE,TELEPHONE);
    }
  

  fclose(f);
  fclose(f1);

remove("/home/manel/Projects/project4/src/profile.txt");
rename("/home/manel/Projects/project4/src/tampo1.txt","/home/manel/Projects/project4/src/profile.txt");	
}


void ajouter2( int jour , int  mois , int annes ,char Horaires[50])
{
FILE*f ;
f=fopen("src/profile3.txt","a");

fprintf(f," %d %d %d %s\n",jour,mois,annes,Horaires);
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







void afficher(GtkWidget *pListView)
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

GtkWidget *window5m;

GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore = gtk_list_store_new(N_COLUMN, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

FILE *f;char var[50],var4[50],var5[50],var1[50],var3[50], var2[40];
f=fopen("src/fiches.txt","r");
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

GtkWidget *window5m;

GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore = gtk_list_store_new(N_COLUMN, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING);

FILE *f;char var[50],var1[50],var2[50],var3[50],var4[50];
char var5 [50];
f=fopen("src/profile7.txt","r");
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
void afficher3(GtkWidget *pListView)
{
enum {
JOUR,
MOIS,
ANNES,
HORAIRES, 

N_COLUMN
};

GtkWidget *window5m;

GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore = gtk_list_store_new(N_COLUMN,G_TYPE_UINT,G_TYPE_UINT,G_TYPE_UINT,G_TYPE_STRING);

FILE *f; int var2 ; int var3; int var4 ;char var5[50];
f=fopen("src/profile3.txt","r");
while(fscanf(f,"%d %d %d %s",&var2,&var3,&var4,var5)!=EOF)
	{
GtkTreeIter pIter;

gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,

JOUR,var2,
MOIS,var3,
ANNES,var4,
HORAIRES,var5,

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
	
	

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 


fclose(f);
	
}





