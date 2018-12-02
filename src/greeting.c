#include <gtk/gtk.h>
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include "greeting.h"

int id(char log[],char password[], char hello[])
{
	FILE *f;
	char var[50];char var1[50];int var2;
	f=fopen("src/admin.txt","r");
	
	
		while(fscanf(f,"%s %s %d",var,var1,&var2)!=EOF)
		{
			if(!strcmp(log,var) && !strcmp(password,var1) )
			{
				strcpy(hello , "yes");
				strcat(hello," ");
				strcat(hello,log);
				fclose(f);
				return var2;
			}

			
		}

				strcpy(hello , "info invalid");
				fclose(f);
				return 0;
		
}





int ajouter(char log[50],char password[50],int role,char cin[50])
{
FILE *f;

f=fopen("src/admin.txt","a+");
		for(int i=0;i<strlen(cin);i++)
		{
if((cin[i] < '0') || (cin[i] > '9') )
	{
fclose(f);
return 0;	
	}
		}
	
fprintf(f,"%s %s %d %s\n",log,password,role,cin);
fclose(f);	
return 1;
}

void supprimer(char login[])
{
FILE *f,*f2;char var[50];char var1[50];int var2;
f=fopen("src/admin.txt","r");
f2=fopen("src/tomp.txt","a+");
while(fscanf(f,"%s %s %d",var,var1,&var2)!=EOF)
	{


		if (strcmp(login,var)!=0)
		{
		fprintf(f2,"%s %s %d\n",var,var1,var2);
		fclose(f2);
		}

	}	

fclose(f);
}

void afficher(GtkWidget *pListView,int role)
{
enum {
LOGIN,
PASSWORD,
ROLE,
CIN,
TOGGLE_COLUMN,
N_COLUMN
};



GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore = gtk_list_store_new(N_COLUMN, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_UINT,G_TYPE_STRING,G_TYPE_BOOLEAN);

FILE *f;char var[50],var1[50],var3[50];int var2;
f=fopen("src/admin.txt","r");
while(fscanf(f,"%s %s %d %s",var,var1,&var2,var3)!=EOF)
	{

if (role!=var2)
continue;

GtkTreeIter pIter;

gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,
LOGIN,var,
PASSWORD,var1,
ROLE,var2,
CIN,var3,
TOGGLE_COLUMN, FALSE,
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
pColumn = gtk_tree_view_column_new_with_attributes("login",
pCellRenderer,
"text", LOGIN,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("password",
pCellRenderer,
"text", PASSWORD,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("role",
pCellRenderer,
"text", ROLE,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("cin",
pCellRenderer,
"text", CIN,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);


pCellRenderer = gtk_cell_renderer_toggle_new();
pColumn=gtk_tree_view_column_new_with_attributes("select",pCellRenderer,"active", TOGGLE_COLUMN,
NULL);

g_signal_connect(G_OBJECT(pCellRenderer), "toggled", (GCallback)toggled_func, pListStore);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);	

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 


fclose(f);
	
}
void modifier_comptes(char login[],char password[],char cin[])
{
FILE *f,*f1;
char var[50];char var1[50];int var2;char var3[50];
f=fopen("src/admin.txt","r");
f1=fopen("src/tampo.txt","a+");
while(fscanf(f,"%s %s %d %s",var,var1,&var2,var3)!=EOF)
	{
if (strcmp(var3,cin)==0)
		{
fprintf(f1,"%s %s %d %s\n",login,password,var2,cin);

	
		}
else
fprintf(f1,"%s %s %d %s\n",var,var1,var2,var3);
	}
fclose(f1);
fclose(f);
rename("src/tampo.txt","src/admin.txt");	
}
