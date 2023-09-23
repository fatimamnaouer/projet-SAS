#include <string.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct {
    int id;
    char titre[100];
    char description[500];
    char statut[30];
    char deadline[11];

} tache;

int nombredetache = 0;
int numId =1;
int i,j;
tache tab[100];
void recherche_id();
void recherche_nom();
void supprimer_tache();
void modifier_tache ();
int recherche(){
    int choice;
    printf("Recherche \n ");
    printf("1 :Chercher par id \n");
    printf("2 : Recherche par nom \n ");
    scanf("%d",&choice);

    switch(choice){
        recherche_id();
        break;
        case 2 :
        recherche_nom();
         break;
        case 3:
            return 0;


    }
}
int i, j, ndestatut, d;
//////
void choixN1() { //Ajouter une tache
    printf("tache id: %d\n", numId); //id
    tab[nombredetache].id = numId; //id deja initialiser par 1 
    printf("Entrer le titre de la tâche :\n");
    scanf(" %[^\n]", tab[nombredetache].titre);
    printf("Entrer la description :\n");
    scanf(" %[^\n]", tab[nombredetache].description);
    printf("Entrer une deadline (format JJ/MM/AAAA) :\n");
    scanf(" %s", tab[nombredetache].deadline);


    
        printf("Entrer le numéro 1 pour tâche à réaliser, numéro 2 pour tâche en cours, 3 pour tâche finalisée : ");
        scanf(" %d", &ndestatut);

        if (ndestatut == 1) {
            strcpy(tab[nombredetache].statut, "à réaliser");
            
        } else if (ndestatut == 2) {
            strcpy(tab[nombredetache].statut, "en cours");
            
        } else if (ndestatut == 3) {
            strcpy(tab[nombredetache].statut, "finalisée");
            
        } else {
            printf("Veuillez choisir 1, 2 ou 3.\n");
        
        }
        
    numId++; // id taytincrementa b 1
    nombredetache++;// nombredetache taytdoz l casier suivant
}

int choixN2() { // Affichage des taches
    int nombre;// nombre de tache a ajouter
    printf("Veuillez choisir le nombre de tâches à ajouter :\n");
    scanf("%d", &nombre);
    if(nombre + nombredetache > 100 ){
        printf("Erreur : vous avez depasser les nombres autorises");
        return 0;
    }

    for (int i = nombredetache; i < nombredetache + nombre; i++) { //nombre de tache initial howa 0 + nombre (li howa li andakhloh)
        tab[i].id = numId ; //id 
        printf("Id : %d:\n",tab[i].id);
        printf("Entrer le titre de la tâche :\n");
        scanf(" %[^\n]", tab[i].titre);
        printf("Entrer la description :\n");
        scanf(" %[^\n]", tab[i].description);
        printf("Entrer une deadline (format JJ/MM/AAAA) :\n");
        scanf(" %s", tab[i].deadline);

        int validChoix = 0;
        // while (1) { //valider le choix
            printf("Entrer le numéro 1 pour tâche à réaliser, numéro 2 pour tâche en cours, 3 pour tâche finalisée : ");
            scanf("%d", &ndestatut);

void alfa(tache tab[],int n) { //classement alphabetique
    tache temp;// variable isti3ana b sadi9 bch nbadlo les places

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
}            if (ndestatut == 1) {
                strcpy(tab[i].statut, "à réaliser");//strcpy pour importer toute les donnees de structure tachde
            } else if (ndestatut == 2) {
                strcpy(tab[i].statut, "en cours");
            } else if (ndestatut == 3) {
                strcpy(tab[i].statut, "finalisée");
            } else {
                printf("Veuillez choisir 1, 2 ou 3.\n");
            }
        // }

        // tab[i].id = i + 1;
        
        numId++;
    }
    nombredetache += nombre;
    return nombredetache;
    // nombredetache = nombre de tache + nombre
}


void alfa(tache tab[],int n) { //classement alphabetique
    tache temp;// variable isti3ana b sadi9 bch nbadlo les places

    for (i = 0; i < n; i++) { //n =size de titre
        for (j = i + 1; j < n; j++) {
            // strcmp compare entre 2 cases et retourn le plus petit
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

void modifier_tache (){ //modifier la tache description, statut et deadline
        int codeid;
        printf("veuillez entrer l'id de tache: \n");
        scanf("%d",&codeid);
        int test = 0;
        
        for(i=0; i<nombredetache; i++){
            if(tab[i].id == codeid){
        
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
                int na = choixN2();
                choixN3(); // Plusieurs nouvelles tâches avec affichage
                break;
            case 3:
                alfa(tab, nombredetache); // Tri alphabétique
                choixN3(); // Affichage des listes triées
                break;
            case 4:
                modifier_tache ();// Modifier la tâche
                break;
            case 5:
                supprimer_tache(); // Supprimer la tâche
                break;
            case 6:
                recherche();
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

    
}
void recherche_id(){
         int ent_id;
            printf("\nEntrer l'id\n");
            scanf("%d",&ent_id);
            for(i=0;i<nombredetache;i++){
                if( tab[i].id==ent_id){
                printf("\n %s", tab[i].titre);   
                printf("\n %s", tab[i].description);
                printf("\n%s", tab[i].deadline);
                printf("\n%s",tab[i].statut);
                    
                }
                else
                printf("\n numero id introuvable");
            }
}
void recherche_nom(){
    char tit[100];
    printf("\n Entrer le titre");
    scanf(" %[^\n]", tit);
    for(int i=0; i<nombredetache; i++){
        if(strcmp(tit, tab[i].titre)==0){
        printf("\n %s", tab[i].titre);   
                printf("\n %s", tab[i].description);
                printf("\n%s", tab[i].deadline);
                printf("\n%s",tab[i].statut);
        }
        else {
            printf("introuvable");
        }
    }
}

void supprimer_tache(){
    int ent_id;
    int found;
        printf("\nEntrer l'id\n");
        scanf("%d",&ent_id);
        for(i=0;i<nombredetache;i++){
            if( tab[i].id==ent_id){
        for(j=i;j>nombredetache-1;j++){
            tab[j] = tab[j+1];
            printf("\nTache supprimee\n");


        nombredetache--;
        }    
        }




}
