#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include "verifier.h"


void modifier_profil(char nom[50],char prenom[50],char GSM[50],char adresse[50],char specialites[50])
{
FILE *f,*f1;
char var[50];char var1[50];char var2[50];char var3[50],var4[50];
f=fopen("src/profil.txt","r");
f1=fopen("src/tampo.txt","a+");
while(fscanf(f,"%s %s %s %s %s",var,var1,var2,var3,var4)!=EOF)
	{
if (strcmp(var,nom)==0)
		{
fprintf(f1,"%s %s %s %s %s \n",var,prenom,GSM,adresse,specialites);

	
		}
else
fprintf(f1,"%s %s %s %s %s \n",var,var1,var2,var3,var4);
	}
fclose(f1);
fclose(f);
rename("src/tampo.txt","src/profil.txt");	
}
