#include <stdio.h>
#include <string.h>

typedef struct {
    char titre[100];
    char description[500];
    char statut[30];
    char deadline[11];
    int id;
} tache;

int nombredetache = 0;
tache tab[100];
int i, j, ndestatut;

void choixN1() {
    printf("Entrer le titre de la tâche :\n");
    scanf(" %[^\n]", tab[nombredetache].titre);
    printf("Entrer la description :\n");
    scanf(" %[^\n]", tab[nombredetache].description);
    printf("Entrer une deadline (format JJ/MM/AAAA) :\n");
    scanf(" %s", tab[nombredetache].deadline);


    while (1) {
        printf("Entrer le numéro 1 pour tâche à réaliser, numéro 2 pour tâche en cours, 3 pour tâche finalisée : ");
        scanf("%d", &ndestatut);

        if (ndestatut == 1) {
            strcpy(tab[nombredetache].statut, "à réaliser");
    
        } else if (ndestatut == 2) {
            strcpy(tab[nombredetache].statut, "en cours");
     
        } else if (ndestatut == 3) {
            strcpy(tab[nombredetache].statut, "finalisée");

        } else {
            printf("Veuillez choisir 1, 2 ou 3.\n");
        }
    }

    tab[nombredetache].id = nombredetache + 1;
    nombredetache++;
}

void choixN2() {
    int nombre;
    printf("Veuillez choisir le nombre de tâches à ajouter :\n");
    scanf("%d", &nombre);

    for (i = nombredetache; i < nombre + nombredetache && i < 100; i++) {
        printf("Entrer le titre de la tâche :\n");
        scanf(" %[^\n]", tab[i].titre);
        printf("Entrer la description :\n");
        scanf(" %[^\n]", tab[i].description);
        printf("Entrer une deadline (format JJ/MM/AAAA) :\n");
        scanf(" %s", tab[i].deadline);

        int validChoix = 0;
        while (1) { //valider le choix
            printf("Entrer le numéro 1 pour tâche à réaliser, numéro 2 pour tâche en cours, 3 pour tâche finalisée : ");
            scanf("%d", &ndestatut);

            if (ndestatut == 1) {
                strcpy(tab[i].statut, "à réaliser");

            } else if (ndestatut == 2) {
                strcpy(tab[i].statut, "en cours");
             
            } else if (ndestatut == 3) {
                strcpy(tab[i].statut, "finalisée");
              
            } else {
                printf("Veuillez choisir 1, 2 ou 3.\n");
            }
        }

        tab[i].id = i + 1;
    }

    nombredetache += nombre;
}

void alfa(tache tab[], int n) {
    tache temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(tab[j].titre, tab[j + 1].titre) > 0) {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

void choixN3() {
    printf("\nListe des tâches :\n");
    printf("----------------------------------------------\n");
    for (i = 0; i < nombredetache; i++) {
        printf("Id: %d\t | Titre: %s\t | Description: %s\t | Deadline: %s\t | Statut: %s\n",
               tab[i].id, tab[i].titre, tab[i].description, tab[i].deadline, tab[i].statut);
    }
    printf("----------------------------------------------\n");
}

int main() {
    int numero_doperation;

    printf("Bienvenue à l'application TO DO\n");
    while (1) {
        printf("1. Ajouter une nouvelle tâche\n");
        printf("2. Ajouter plusieurs nouvelles tâches\n");
        printf("3. Afficher la liste de toutes les tâches\n");
        printf("4. Modifier une tâche\n");
        printf("5. Supprimer une tâche\n");
        printf("6. Rechercher les tâches\n");
        printf("7. Statistique\n");
        printf("8. Quitter\n");

        printf("Choisissez le numéro d'opération : ");
        scanf("%d", &numero_doperation);

        switch (numero_doperation) {
            case 1:
                choixN1();
                choixN3(); // Nouvelle tâche avec affichage
                break;
            case 2:
                choixN2();
                choixN3(); // Plusieurs nouvelles tâches avec affichage
                break;
            case 3:
                alfa(tab, nombredetache); // Tri alphabétique
                choixN3(); // Affichage des listes triées
                break;
            case 4:
                printf("bv choix 4\n"); // Modifier la tâche
                break;
            case 5:
                printf("bv choix 5\n"); // Supprimer la tâche
                break;
            case 6:
                printf("bv choix 6\n"); // Rechercher les tâches
                break;
            case 7:
                printf("bv choix 7\n"); // Statistique
                break;
            case 8:
                printf("Au revoir !\n"); // Quitter
                return 0;
            default:
                printf("Erreur\n");
                break;
        }
    }

    return 0;
}

