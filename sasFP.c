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
void recherche_nom();
void supprimer_tache();
void modifier_tache ();
void recherche();
void ajouter_tache();
void ajouter_tache2();
void alfa();
void modifier_tache ();
void dead_tri();
void rechercher_id();
void recherche_nom();
void afficher_tache();

int main() {
    int numero_doperation;
    int i, j, ndestatut, d;
    int nombre;

    printf("Bienvenue à l'application TO DO\n");
    while (1) {
        printf("1. Ajouter une ou plusieurs nouvelles tâches\n");
        printf("2. Afficher la liste de toutes les tâches\n");
        printf("3. Modifier une tâche\n");
        printf("4. Supprimer une tâche\n");
        printf("5. Rechercher les tâches\n");
        printf("6. Statistique\n");
        printf("7. Quitter\n");

        printf("Choisissez le numéro d'opération : ");
        scanf("%d", &numero_doperation);

        switch (numero_doperation) {
           case 1:
                 ajouter_tache2(); // Plusieurs nouvelles tâches avec affichage
                break;
            case 2:
                afficher_tache();
                break;
            case 3:
                modifier_tache ();// Modifier la tâche
                break;
            case 4:
                supprimer_tache(); // Supprimer la tâche
                break;
            case 5:
                recherche();
                break;
            case 6:
                printf("bv choix 7\n"); // Statistique
                break;
            case 7:
                printf("Au revoir !\n"); // Quitter
                return 0;
            default:
                printf("Erreur\n");
                break;
        }

    }


}
void ajouter_tache2(){
    int nombre;
    printf("Veuillez choisir le nombre de tâches à ajouter :\n");
    scanf("%d", &nombre);
    if(nombre + nombredetache > 100 ){
        printf("Erreur : vous avez depasser les nombres autorises");

    }

    for (int i = nombredetache; i < nombredetache + nombre; i++) {
        tab[i].id = numId ;
        printf("Id : %d:\n",tab[i].id);
        printf("Entrer le titre de la tâche :\n");
        scanf(" %[^\n]", tab[i].titre);
        printf("Entrer la description :\n");
        scanf(" %[^\n]", tab[i].description);
        printf("Entrer une deadline (format JJ/MM/AAAA) :\n");
        scanf(" %s", tab[i].deadline);

        int validChoix = 0;
        // while (1) { //valider le choix
            int ndestatut;
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
        // }


        numId++;
    }
    nombredetache += nombre;

}

void afficher_tache(){
    int choix;
                printf("\n Afficher en :\n 1-tri par ordre alphabetique \n 2-tri par deadline\n");
                scanf ("%d",&choix);
                switch(choix){
                    case 1 :
                        alfa();
                     break;
                     case 2 :
                         dead_tri();
                        break;
                }

}
void alfa() { //classement alphabetique
    tache temp;

    for (i = 0; i < nombredetache; i++) {
        for (j = i + 1; j < nombredetache; j++) {
            // strcmp compare entre 2 cases et retourn le plus grand
            if (strcmp(tab[i].titre, tab[j].titre) < 0) {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
    for(int i=0;i<nombredetache;i++){
        printf("Id : %d:\n",tab[i].id);
        printf("Entrer le titre de la tâche : %s\n", tab[i].titre);

        printf("Entrer la description : %s\n",tab[i].description);

        printf("Entrer une deadline %s :\n",tab[i].deadline);

    }
}
void dead_tri(){ //deadline en general parceque c'est pas defini si vous voulez deadline par time ou par date
    tache temp;

    for (i = 0; i < nombredetache; i++) {
        for (j = i + 1; j < nombredetache; j++) {
            if (strcmp(tab[j].deadline, tab[j-1].deadline) < 0) {
                temp = tab[j];
                tab[j] = tab[j-1];
                tab[j-1] = temp;
            }
        }
    }
    for(int i=0;i<nombredetache;i++){
        printf("Id : %d:\n",tab[i].id);
        printf("titre de la tâche : %s\n", tab[i].titre);

        printf("la description : %s\n",tab[i].description);

        printf("deadline %s :\n",tab[i].deadline);

    }

}
void modifier_tache (){ //modifier la tache description, statut et deadline
        int codeid;//pour acceder au id

        printf("veuillez entrer l'id de tache: \n");
        scanf("%d",&codeid);
        int test = 0;//variable pour valider la modif comparaison

        for(i=0; i<nombredetache; i++){
            if(tab[i].id == codeid){

		 printf("\n modifier la titre: \n");//modif titre
                scanf(" %[^\n]", tab[i].titre);

                printf("\n modifier la description: \n"); //modif des
                scanf(" %[^\n]", tab[i].description);

                printf("\n modifier le statut: \n"); //modif statut
                scanf(" %[^\n]", tab[i].statut);

                printf("\n modifier deadline (jj-mm-aaaa) : \n"); //modif deadline
                scanf(" %[^\n]", tab[i].deadline);

                printf("Modification reussite \n");
                test = 1;
                break;
            }
        }
    if(!test)
    {
      printf("%d introuvable \n ", codeid);//ila kan id nafsso li dakhalnah f lawel s7i7 taydawz la boucle ila makanch s7i7 taykhroj b introuvable
    }
}
void supprimer_tache()
{
    int code_id;
    printf("Entrez l'ID à supprimer:\n");
    scanf("%d", &code_id);
    int found=0;//pour la comparaison vrai ou faux
    for (int i = 0; i < nombredetache; i++)
    {
        if (tab[i].id == code_id)
        {   found=1;// vrai
            for (int j = i; j < nombredetache - 1; j++)
            {
                tab[j] = tab[j + 1];
            }
            nombredetache--;//tayrja3 b 1 ya3ni mataykhalich casier khawi  (nombre de tache = nombre de tache -1)
            printf("Tâche %d supprimée avec succès\n", code_id);
            break;
        }
    }

    if(!found)
    {
        printf("%d non trouvé\n", code_id);
    }
}
void recherche(){// fonction global dakhel fiha recherche par id w nom
    int choice;//variable pour switch condition
    printf("Recherche \n ");
    printf("1 :Chercher par id \n");
    printf("2 : Recherche par nom \n ");
    scanf("%d",&choice);

    switch(choice){
        case 1 :
            rechercher_id();
            break;
        case 2 :
        recherche_nom();
         break;
        default:
	printf(" veuillez choisir 1 ou 2");
        break;


    }
}

void rechercher_id(){
    int ent_id;// hia code id li saminaha f modif o supp
            printf("\nEntrer l'id\n");
            scanf("%d",&ent_id);
            for(i=0;i<nombredetache;i++){
                if( tab[i].id==ent_id){
                printf("\n %s", tab[i].titre);
                printf("\n %s", tab[i].description);
                printf("\n%s", tab[i].deadline);
                printf("\n%s",tab[i].statut);

                }
                else{
                printf("\n numero id introuvable");
                }
            }
}
void recherche_nom(){
    char tit[100];
    printf("\n Entrer le titre");
    scanf(" %[^\n]", tit);
    for(int i=0; i<nombredetache; i++){
        if(strcmp(tit, tab[i].titre)==0){// fonction predefinit pour comparer les chaine de caracteres(pluriel  string char kbira) si est egal a 0 alors lkaha titre
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
void stq_aff_total_tache() {
	int tot = 0;
	for( i=0;i<nombredetache;i++){
	tot = tot+1;
}
	printf("le nombre total de tache est : %d ", tot);

}

void situtation_statut(){


}
