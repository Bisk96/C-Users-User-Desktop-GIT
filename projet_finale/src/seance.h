#include<gtk/gtk.h>
typedef struct
{
int jour;
int mois;
int annee;
}Date_a;

/*typedef struct
char j[30];
char m[30];
char a[30];
char h[];
char sal[];
}Sea;*/
typedef struct
{
char num[5];
Date_a dt_res;
char hr_res[20];
}ReservationSalle;

typedef struct
{
int jour;
int mois;
int annee;
char heure[30];
char salle[30];
}Seance;

enum
{
JOUR=0,
MOIS,
ANNEE,
HEURE,
SALLE,
COL
};
int tableau_salle_reserver(ReservationSalle tab[50]);
int verifier_reserver(ReservationSalle sa);
int tableau_salle_disponible(char nom_salle[100][5],Date_a dt_res,char hr_res[20]);
void reserver_salle(ReservationSalle s);
void afficher_seance(GtkWidget *treeview102);
//void supprimer_seance(char jr[],char mo[],char an[],char he[]);
void ajoutermm(char nom[],char prenom[],char gsm[],char adresse[],char specialite[]);

