#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seance.h"
#include<gtk/gtk.h>

int tableau_salle_reserver(ReservationSalle tab[50])
{
int n=0;
FILE* f=fopen("src/salleReserve.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%d %d %d %s %s",&tab[n].dt_res.jour,&tab[n].dt_res.mois,&tab[n].dt_res.annee,tab[n].hr_res,tab[n].num)!=EOF)
{
n++;
}
fclose(f);
}
return n;
}

int verifier_reserver(ReservationSalle sa)
{
ReservationSalle s;
int v=0;
FILE* f=fopen("src/salleReserve.txt","r");
if(f!=NULL)
{
while(!v && fscanf(f,"%d %d %d %s %s",&s.dt_res.jour,&s.dt_res.mois,&s.dt_res.annee,s.hr_res,s.num)!=EOF)
{
if(strcmp(s.num,sa.num)==0)
{
if((s.dt_res.jour==sa.dt_res.jour) && (s.dt_res.mois==sa.dt_res.mois) && (s.dt_res.annee==sa.dt_res.annee) && strcmp(s.hr_res,sa.hr_res)==0)
{v=1;}
}
}
fclose(f);
}
return v;
}

int tableau_salle_disponible(char salle[100][5],Date_a dt_res,char hr_res[20])
{
int i,nS=0;
FILE* f=fopen("src/salle.txt","r");
ReservationSalle s;
s.dt_res=dt_res;
strcpy(s.hr_res,hr_res);
if(f!=NULL)
{
while(fscanf(f,"%s",s.num)!=EOF)
{
if(!verifier_reserver(s))
{
strcpy(salle[nS],s.num);
nS++;
}
}
fclose(f);
}
return nS;
}

void reserver_salle(ReservationSalle s)
{
FILE* f=fopen("src/salleReserve.txt","a");
if(f!=NULL)
{
fprintf(f,"%d %d %d %s %s\n",s.dt_res.jour,s.dt_res.mois,s.dt_res.annee,s.hr_res,s.num);
fclose(f);
}
}

void afficher_seance(GtkWidget *treeview102)
{
GtkCellRenderer *renderer; //afficheur de cellule
GtkTreeViewColumn *column; //visualisation des colonnes
GtkTreeIter iter; //création d'une nouvelle ligne 
GtkListStore *store; //création du modèle de type liste
char jour[50];
char mois[50];
char annee[50];
char heure[30];
char salle[30];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(treeview102);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new(); //cellule contenant du texte
column=gtk_tree_view_column_new_with_attributes("JOUR",renderer,"text",JOUR, NULL); //création d'une colonne avec du texte
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview102), column); //associer la colonne à l'afficheur(GtkTreeView);

renderer=gtk_cell_renderer_text_new(); 
column=gtk_tree_view_column_new_with_attributes("MOIS",renderer,"text",MOIS,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview102), column); 

renderer=gtk_cell_renderer_text_new(); 
column=gtk_tree_view_column_new_with_attributes("ANNEE",renderer,"text",ANNEE,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview102), column); 
}
renderer=gtk_cell_renderer_text_new(); 
column=gtk_tree_view_column_new_with_attributes("HEURE",renderer,"text",HEURE,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview102), column); 

renderer=gtk_cell_renderer_text_new(); 
column=gtk_tree_view_column_new_with_attributes("SALLE",renderer,"text",SALLE,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview102), column); 

store=gtk_list_store_new(COL,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("src/salleReserve.txt","r");
if(f==NULL)
{
return;
}
else
{
while(fscanf(f," %s %s %s %s %s\n",jour,mois,annee,heure,salle)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,JOUR,jour,MOIS,mois,ANNEE,annee,HEURE,heure,SALLE,salle,-1);
}
fclose(f);
}
gtk_tree_view_set_model(GTK_TREE_VIEW(treeview102),GTK_TREE_MODEL(store));
g_object_unref(store);
}

/*void supprimer_seance(char jr[],char mo[],char an[],char he[])
{
char jour[50];
char mois[50];
char annee[50];
char heure[30];
char salle[30];
FILE *F;
FILE *F1;
F=fopen("/home/hnana/Projects/monespace/src/salleReserve.txt","a+");
F1=fopen("/home/hnana/Projects/monespace/src/tmp.txt","w+");
if(F!=NULL)
{
while(fscanf(F,"%s %s %s %s %s\n",jour,mois,annee,heure,salle)!=EOF)
{
if(strcmp(jr,jour)==0 && strcmp(mo,mois)==0 && strcmp(an,annee)==0 && strcmp(he,heure)==0)
printf(F1,"%s %s %s %s %s\n",jour,mois,annee,heure,salle);
}
}
fclose(F1);
fclose(F);
remove("/home/hnana/Projects/monespace/src/salleReserve.txt");
rename("/home/hnana/Projects/monespace/src/tmp.txt","/home/hnana/Projects/monespace/src/salleReserve.txt");
}*/

/*void modifier_seance(char jou[],char moi[],char anne[],char heu[],char sall[],Sea c);
Sea cc;
FILE *f;
FILE *f_temp;
f=fopen("/home/hnana/Projects/monespace/src/salleReserve.txt","a+");
if(f!=NULL && f1!=NULL)
while(fscanf(f,"%s %s %s %s %s",cc.j,cc.m,cc.a,cc.h,cc.sal)!=EOF)
{
if(strcmp(jou,cc.j)==0 && strcmp(jou,cc.m)==0 && strcmp(jou,cc.a)==0 && strcmp(jou,cc.)==0*/

void ajoutermm(char nom[],char prenom[],char gsm[],char adresse[],char specialite[])
{
FILE *f;
f=fopen("src/profil.txt","w");
fprintf(f,"%s %s %s %s %s",nom,prenom,gsm,adresse,specialite);
fclose(f);
}





