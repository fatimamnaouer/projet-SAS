#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct {
    char titre[100];
    char description[500];
    char statut[30];
    char deadline[11];
    int id;
} tache;

int nombredetache = 0;
//tache tab[100] = {
  //{"bar", "My first desc", "en cours de réalisation", "23/09/2023", 1},
 // {"foo", "My second desc", "à réaliser", "25/09/2023", 1},
 // {"deamon", "My third desc", "finalisé", "24/09/2023", 1}
//};

int i, j, ndestatut, n, d;

void choixN1() { //Ajouter une ou plusieur tache 
    printf("Entrer le titre de la tâche :\n");
    printf("tache id : %d", tab[i].id); //id
    scanf(" %[^\n]", tab[nombredetache].titre);
    printf("Entrer la description :\n");
    scanf(" %[^\n]", tab[nombredetache].description);
    printf("Entrer une deadline (format JJ/MM/AAAA) :\n");
    scanf(" %s", tab[nombredetache].deadline);


    while (1) { // la boucle pour arreter le statut de tache et passer a autre operation
        printf("Entrer le numéro 1 pour tâche à réaliser, numéro 2 pour tâche en cours, 3 pour tâche finalisée : ");
        scanf(" %d", &ndestatut);

        if (ndestatut == 1) {
            strcpy(tab[nombredetache].statut, "à réaliser");
	    break;
        } else if (ndestatut == 2) {
            strcpy(tab[nombredetache].statut, "en cours");
	    break;
        } else if (ndestatut == 3) {
            strcpy(tab[nombredetache].statut, "finalisée");
	    break;
        } else {
            printf("Veuillez choisir 1, 2 ou 3.\n");
	    break;
        }
    }

    tab[nombredetache].id = nombredetache + 1;
    nombredetache++;
}

void choixN2() { // Affichage
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
                strcpy(tab[i].statut, "à réaliser");//strcpy pour importer toute les donnees de structure tache
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

//void fakeData() {
//}

void alfa(tache tab[],n) { //classement alphabetique
    tache temp;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            // strcmp compare entre 2 cases et retourn le plus grand
            if (strcmp(tab[i].titre, tab[j].titre) > 0) {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}

void choixN3() { // classement des titres en utilisant tri de bulle pour un classement alphabetique (le tri a bulle compare 2 cases de tableau)
    printf("\nListe des tâches :\n");
    printf("----------------------------------------------\n");
    for (i = 0; i < nombredetache; i++) {
        printf("Id: %d\t | Titre: %s\t | Description: %s\t | Deadline: %s\t | Statut: %s\n",
               tab[i].id, tab[i].titre, tab[i].description, tab[i].deadline, tab[i].statut);
    }
    printf("----------------------------------------------\n");
}

void choixN4 (){ //modifier la tache description, statut et deadline
 	int codeid;
	printf("veuillez entrer l'id de tache: \n");
	scanf("%d",&codeid);
	int test = 0;

	for(i=0; i<nombredetache; i++){
	  if(tab[i].id == codeid)
	{
	printf("\n modifier la description: \n");
	scanf(" %[^\n]", tab[i].description);

	printf("\n modifier le statut: \n");
	scanf(" %[^\n]", tab[i].statut);

	printf("\n modifier deadline (jj-mm-aaaa) : \n");
	scanf(" %[^\n]", tab[i].deadline);

	printf("Modification reussite \n");
	test = 1;
	break;
    }
    if(!test)
{
      printf("%d introuvable \n ", codeid);
}
}

//void choixN5() { // suprimer une tache
//int supprimer(tache tab[],












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

