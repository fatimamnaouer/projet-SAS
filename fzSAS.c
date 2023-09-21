#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



typedef struct // ajouter nouvelle taches
{ 

     char titre [100];
     char description [500];
     char statut [30];
     char deadline[11];
     int id;
}tache;
	int nombredetache = 0;
	tache tab[100];

// declaration des fonctions:

void choixN1 (){
	int ndestatut;

    printf("entrer le titre de la tache ");
    scanf("%s",tab[nombredetache].titre);
    printf("entrer la description ");
    scanf("%s", tab[nombredetache].description);
    printf("entrer un deadline ");
    scanf("%s", tab[nombredetache].deadline);
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
       
        tab[nombredetache].id=nombredetache+1;
        nombredetache++;
}

void choixN3(){



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
                    choixN1();            //  nouvel tache 
		 break ;
	       case 2:
                     printf("bv choix 2");          // plusieur nouvelle tâches
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

