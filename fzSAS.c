#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main() {
    int numero_doperation;

printf("Bienvenue à l'application TO DO\n");
     printf("1. Ajouter une nouvelle tâche\n");
     printf("2. Ajouter plusieur nouvelle tâches\n");
     printf("3. Afficher la liste de toutes les tâche\n");
     printf("4. Modifier une tâche\n");
     printf("5. Suprimer une tâche\n");
     printf("6.Rechercher les tâches\n");
     printf("7.Statistique\n");
     printf("8.Sortir");
     

    return 0;
}

struct taches
{
     char titre [100];
     char description [500];
     char statut [30];
     char deadline;
     int id;
};
//declaration des fonctions
