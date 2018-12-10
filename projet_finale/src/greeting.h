int id_h(char log[],char password[], char hello[]);
int ajouter_h(char log[],char password[],int role,char cin[]);

void afficher_h(GtkWidget *pListView,int role);
void modifier_comptes(char login[],char password[],char cin[]);
void afficherx(GtkWidget *pListView,int role);
void supprimer_h(char cin[50]);
void supprimer_id();
typedef struct Date
{
int jour;
int mois;
int annee;
}Date;

typedef struct calendrier
{

Date date;//-1/-1/-1 si nn reserver
char heure_m[50];
char heure_s[50];
char evenement[50];//1 si matin 2 si apret midi -1 si non 
}calendrier;


int reserver_calendrier(calendrier s);

void afficher_event(GtkWidget *pListView);
void modifier_calendrier_aa(char date[50],char heure_m[50],char heure_s[50],char event[50]);
void supprimer_calendrier_aa(char date[50]);
void afficher_profile_h(GtkWidget *pListView);
