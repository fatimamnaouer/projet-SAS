#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



typedef struct // structure pour representer une tache
{ 
     char titre [100];
     char description [500];
     char statut [30];
     char deadline[11];
     int id;
}tache;
	int nombredetache = 0;
	tache tab[100];
        int i, j,  ndestatut;
// declaration des fonctions:

void choixN1 (){


    printf("entrer le titre de la tache \n");
    scanf(" %[^\n]",tab[nombredetache].titre);
    printf("entrer la description \n ");
    scanf(" %[^\n]", tab[nombredetache].description);
    printf("entrer un deadline (format JJ/MM/AAAA): \n ");
    scanf(" %s", tab[nombredetache].deadline);
    printf("entrer le numero 1 pour tache à realiser , numero 2 pour tache en cours , 3 pour tache finalisée "); 
    scanf("%d", &ndestatut);
  	        
		if(ndestatut==1)
	           strcpy(tab[nombredetache].statut , "à realiser");
                 else if (ndestatut ==2)
                    strcpy(tab[nombredetache].statut , "en cours");
                 else if (ndestatut ==3)
                    strcpy(tab[nombredetache].statut , "finalisee");
                 else
                     printf("veuillez choisir 1 ou 2 ou 3");
                     scanf("%d", &ndestatut);//pour donner a l'utilisateur d'entrer un autre numero

        tab[nombredetache].id=nombredetache+1;
        nombredetache++;
}
void choixN2 (){
int nombre;
printf("veuillez choisir le nombre de tache  \n");
scanf("%d", &nombre);

for (i=nombredetache; i< nombre + nombredetache && i<10; i++){

 printf("entrer le titre de la tache ");
    scanf(" %[^\n]",tab[i].titre);
    printf("entrer la description ");
    scanf("  %[^\n]", tab[i].description);// "%[^\n] pour avoir un espace entre la phrase de description
    printf(" entrer un deadline (format JJ/MM/AAAA)\n ");
    scanf(" %[^\n]", tab[i].deadline);
while(1){
    printf("entrer le numero 1 pour tache à realiser , numero 2 pour tache en cours , 3 pour tache finalisée "); 
    scanf(" %d", &ndestatut);
  	        
		if(ndestatut==1){
	           strcpy(tab[i].statut , "à realiser");break;
                } else if (ndestatut ==2){
                    strcpy(tab[i].statut , "en cours");break;
                 }else if (ndestatut ==3){
                    strcpy(tab[i].statut , "finalisee");break;
                } else
                     continue;// njarabha bch nchof wch ay3ti utilisateur idir autre numero
       }
        tab[i].id=i+1;
}
        nombredetache += nombre;// nombredetache=nombredetache + nombre  

}


void alfa(tache tab[], int n){  //classement alphabetique
	

	for(i=0 ; i<n-1 ; i++){
	  for(j=0 ; j<n-1; j++){
           if(strcmp(tab[j].titre, tab[j+1].titre)>0){
	      tache x = tab[j];
	      tab[j] = tab[j+1];
	      tab[j+1] = x;
        }
      }
   }
}

void choixN3(){

printf("\n la liste des taches\n");
printf("\n ----------------------------------------------\n");
for(i=0; i < nombredetache; i++){
printf("Id: %d\t | Titre: %s\t| Description: %s\t | Deadline: %s\t | Statut: %s\n", tab[i].id, tab[i].titre, tab[i].description, tab[i].deadline, tab[i].statut);
 
}

printf("\n --------------------------------------------------------------------\n");

}



int main() {
    int numero_doperation;


printf("Bienvenue à l'application TO DO\n");
while(1){
     printf("1. Ajouter une nouvelle tâche\n");
     printf("2. Ajouter plusieur nouvelle tâches\n");
     printf("3. Afficher la liste de toutes les tâche\n");
     printf("4. Modifier une tâche\n");
     printf("5. Suprimer une tâche\n");
     printf("6.Rechercher les tâches\n");
     printf("7.Statistique\n");
     printf("8.Sortir\n");

     printf("Choisissez le numero d'operation: ");
     scanf("%d", &numero_doperation);
       switch(numero_doperation){ 
               case 1: 
                    choixN1();
                    choixN3();            //  nouvel tache avec affichage 
		 break ;
	       case 2:
                     choixN2();
                     choixN3();          // plusieur nouvelle tâches avec affichage
 	         break;
	       case 3:
                     printf("bv choix 3");         // Affichage des listes
	         break;
	       case 4:
                     printf("bv choix 4");         // Modifier la tache
	         break;
	       case 5:
                     printf("bv choix 5");        // Suprimer la tache
	         break;
	       case 6:
                     printf("bv choix 6");       // Rchercher la taches
	         break;
	       case 7:
                      printf("bv choix 7");     // Statistique
	         break;
	       case 8:
                      printf("bv choix 8");     // Quitter
	         break;
	default:
	       printf("Erreur");
                 break;

           }
}

    return 0;
}

