#include <stdio.h>
#include <string.h>
typedef struct Sdate{
    int jour;
    int mois;
    int annee;
}Sdate;
typedef struct Svoyage {
    char DesD[100];
    char DesA[100];
    struct Sdate DateA;
    struct Sdate DateR;
    int code_voy;

}Svoyage;
Svoyage tab_voy[1000];
int switchm(int m){
    int jmax;
    switch (m){
     case 1:
     jmax=31;
     break;
     case 3:
     jmax=31;
     break;
     case 5:
     jmax=31;
     break;
     case 7:
     jmax=31;
     break;
     case 8:
     jmax=31;
     break;
     case 10:
     jmax=31;
     break;
     case 12:
     jmax=31;
     break;
     case 2:
     jmax=28;
     break;case 4:
     jmax=30;
     break;
     case 6:
     jmax=30;
     break;
    case 9:
     jmax=30;
     break;
     case 11:
     jmax=30;
     break;
 }
 return jmax;

}
void testan (int a) {
    int p;
    do {
    printf("Annee: ");
    scanf("%d",&a);
    if((a<2060)&&(a>2022)){
        p=1;}

    else p=0;
    }
    while (p==0);

}
void testm(int m){
    int p;
   do{
       printf("Mois:  ");
       scanf("%d",&m);
       if((m<13)&&(m>0)){
           p=1;
       }
       else p=0;
   }
    while(p==0);

}
void testj(int j, int m){
    int p,i;
    i=switchm(m);
    do{
            printf("Jour:  ");
            scanf("%d",&j);
            if((j<i+1)&&(j>0)){
                p=1;
            }
            else p=0;
    }
    while(p==0);

}


void AJOUTER_VOYAGE(){
    struct Svoyage voyage;
    FILE *file ;
   int k,i,j;

    printf("Depart de: ");
    scanf("%s",voyage.DesD);
    printf("Arrivee a: ");
   scanf("%s",voyage.DesA);
    printf("Date d'aller:\n");
    testan(voyage.DateA.annee);
    testm(voyage.DateA.mois);
    testj(voyage.DateA.jour,voyage.DateA.mois);
    printf("Date de retour:\n");
    testan(voyage.DateR.annee);
    testm(voyage.DateR.mois);
    testj(voyage.DateR.jour,voyage.DateR.mois);
    printf("Code du voyage:");
    scanf("%i",&voyage.code_voy);
    file = fopen("voyage.txt","ab");
    fwrite(&voyage, sizeof(voyage) , 1, file);
    if (fwrite != 0){
     printf("\nVoyage ajoute avec succes");
    }
    else{
     printf("Erreur");
    }
    fclose(file);
    printf("\nretour a la page principal:\n");
    printf("1- Oui\n");
    printf("2- Non\n");
    scanf("%d",&k);
    if(k==1){
        main();
    }


}
void MODIFIER_VOYAGE(){
     struct Svoyage voyage;
     struct Svoyage nvvoyage;
     FILE *file;
     FILE *nvfile;
     int k,i,nb_voy;

    printf("Code Voyage a modifier:");
    scanf("%i",&nvvoyage.code_voy);
    printf("NvDepart de: ");
    scanf("%s",nvvoyage.DesD);
    printf("NvArrivee a: ");
    scanf("%s",nvvoyage.DesA);
    printf("NvDate d'aller:\n");
    testan(nvvoyage.DateA.annee);
    testm(nvvoyage.DateA.mois);
    testj(nvvoyage.DateA.jour,nvvoyage.DateA.mois);
    printf("NvDate de retour:\n");
    testan(nvvoyage.DateR.annee);
    testm(nvvoyage.DateR.mois);
    testj(nvvoyage.DateR.jour,nvvoyage.DateR.mois);
    file = fopen("voyage.txt","rb");
    nb_voy=0;
    while(fread(&voyage,sizeof(struct Svoyage),1,file)){
        tab_voy[nb_voy]=voyage;
        nb_voy++;
    }
    fclose(file);
    remove("voyage.txt");
    nvfile=fopen("nvvoy.txt","ab");
    for(i=0;i<nb_voy;i++){
       if(nvvoyage.code_voy==tab_voy[i].code_voy) {
           fwrite(&nvvoyage,sizeof(tab_voy[i]),1,nvfile);

       }
       else fwrite(&tab_voy[i],sizeof(tab_voy[i]),1,nvfile);
       fclose(nvfile);
       rename("nvvoy.txt","voyage.txt");
    }

     printf("\nVoyage modifie avec succes");


    printf("\nretour a la page principal:\n");
    printf("1- Oui\n");
    printf("2- Non\n");
    scanf("%d",&k);
    if(k==1){
        main();
    }
}
    void AFFICHER(){
FILE *file;
int t, i,c,nb_voy,k;
struct Svoyage voyage;
 printf("\n code voyage:");
 scanf("%d",&c);
file=fopen("voyage.txt","rb");
nb_voy=0;
    while(fread(&voyage,sizeof(struct Svoyage),1,file)){
        tab_voy[nb_voy]=voyage;
        nb_voy++;
    }
fclose(file);
i=0;
do {
    if(c==tab_voy[i].code_voy){

   printf("\n destination de depart:%s",tab_voy[i].DesD);
   printf("\n destination d arrivee:%s",tab_voy[i].DesA);
   printf("\n date d'aller:%d / %d / %d",tab_voy[i].DateA.jour,voyage.DateA.mois,voyage.DateA.annee);
  printf("\n date de retour:%d / %d / %d",tab_voy[i].DateR.jour,voyage.DateA.mois,voyage.DateA.annee);
  t=1;
    }
    else {
        i++;
        t=0;
    }
}
while(t==0);
printf("\nretour a la page principal:\n");
    printf("1- Oui\n");
    printf("2- Non\n");
    scanf("%d",&k);
    if(k==1){
        main();
    }

}
void SUPPRIMER(){
struct Svoyage voyage;
        int k,code;
        FILE *file;


        printf("Code de voyage a supprimer : ");
        scanf("%d", &code);

        file = fopen("voyage.txt", "r");

        int nbvoyage = 0;

        while(fread(&voyage, sizeof(struct Svoyage), 1, file)) {
            tab_voy[nbvoyage] = voyage;
            nbvoyage++;
        }
        fclose(file);
        remove("voyage.txt");
                FILE *nvfile;
        nvfile = fopen("nvvoyage.txt", "a");
        for ( int i=0 ; i<nbvoyage ; i++)
        {
            if (tab_voy[i].code_voy != code)
                fwrite(&tab_voy[i], sizeof(tab_voy[i]), 1, nvfile);
        }
        fclose(nvfile);
        rename("nvvoyage.txt", "voyage.txt");
        printf("----------------------------------------------");
        printf("\nretour a la page principal:\n");
    printf("1- Oui\n");
    printf("2- Non\n");
    scanf("%d",&k);
    if(k==1){
        main();
    }
    }

void RECHERCHE (){
    struct Svoyage voyage;
    FILE *file;
    int k,AA,MA,JA,AR,MR,JR,nb_voy,nb_voy_dispo,i,t;
    int tab_voy_dispo[100];

    printf("donner la date d aller de voyage : ");
    printf("donner l anneé :");
    scanf("%i",&AA);
    printf("donner le mois : ");
    scanf("%i",&MA);
    printf("donner le jour : ");
    scanf("%i",&JA);
    printf("donner la date de retour du voyage : ");
    printf("donner l anneé :");
    scanf("%i",&AR);
    printf("donner le mois : ");
    scanf("%i",&MR);
    printf("donner le jour : ");
    scanf("%i",&JR);
    file=fopen("voyage.txt","r");
     nb_voy=0;
    while(fread(&voyage,sizeof(struct Svoyage),1,file)){
        tab_voy[nb_voy]=voyage;
        nb_voy++;
    }
    fclose(file);
    nb_voy_dispo=0;
    i=0;
    do{
       if((AA==tab_voy[i].DateA.annee) && (MA==tab_voy[i].DateA.mois) && (JA==tab_voy[i].DateA.jour)&& (AR==tab_voy[i].DateR.annee) && (MR==tab_voy[i].DateR.mois) && (JR==tab_voy[i].DateR.jour)){
           tab_voy_dispo[nb_voy_dispo]=tab_voy[i].code_voy;
           nb_voy_dispo ++ ;
           i++;



       }
       else{
        i++;
        nb_voy_dispo ++ ;

       }
    }
    while(i>=nb_voy);
    if (nb_voy_dispo ==0){
        printf("il n existe pas de voyage pour ces dates precises ");
    }else {
        for(i=0;i<nb_voy_dispo;i++){

            printf ("le code de  %i eme voyage disponible pour ces dates precises est : " ,i);
 printf("%d",tab_voy_dispo[i]);
        }

     }
     printf("\nretour a la page principal:\n");
    printf("1- Oui\n");
    printf("2- Non\n");
    scanf("%d",&k);
    if(k==1){
        main();
    }

}



void main(){
    int a;
    printf("1- Ajouter un voyage.\n");
    printf("2- Afficher la description du voyage.\n");
    printf("3- Supprimer un voyage.\n");
    printf("4- Modifier un voyage.\n");
    printf("5- Recherche des voyages disponibles selon des dates pr�cises.\n");
    printf("Que voulez-vous faire ?\n");
    scanf("%d",&a);
    switch(a){
        case 1:AJOUTER_VOYAGE();
        break;
        case 2:AFFICHER();
        break;
        case 4:MODIFIER_VOYAGE();
        break;
        case 3:SUPPRIMER();
        break;
        case 5:RECHERCHE ();
    }

}



