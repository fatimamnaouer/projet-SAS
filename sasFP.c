#include <string.h>
#include<stdlib.h>
#include<stdio.h>
//declaration struction nomee par tache (typedef contient plusieur variable)

typedef struct {
    int id;
    char titre[100];
    char description[500];
    char statut[30];
    char deadline[11];

} tache;
//declaration des variables globale
void ajouter_tache();
void afficher_tache();
void alfa();
void dead_tri();
void modifier_tache();
void supprimer_tache();
void recherche();//contient recherche par id et par nom
void rechercher_id();
void recherche_nom();
void statistique();
void situation_statut();

//declaration des variable globale
int nombredetache = 0;//nombre de tache initialise par 0
int numId =1;//id initialise par 1
int i,j;
tache tab[100];//tableau maximum 100 casiers


int main() {
    int numero_doperation;//
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
                 ajouter_tache(); // ajouter une ou Plusieurs nouvelles tâches avec id
                break;
            case 2:
                afficher_tache();//affichage des taches (par ordre alphabetique ou par date)
                break;
            case 3:
                modifier_tache ();// Modifier la tâche avec id
                break;
            case 4:
                supprimer_tache(); // Supprimer la tâche avec id
                break;
            case 5:
                recherche();//chercher une tache avec id ou nom
                break;
            case 6:
                statistique(); // Statistique (totate des taches =nombre de tache) et (tache complete et incomplete)
                break;
            case 7 :
                return 0;
            default:
                printf("erreur !");//quitter
                break;
        }

    }


}
void ajouter_tache(){
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


            int ndestatut;
            printf("Entrer le numéro 1 pour tâche à réaliser, numéro 2 pour tâche en cours, 3 pour tâche finalisée : ");
            scanf("%d", &ndestatut);
	    if (ndestatut == 1) { //1 statut a realiser
                strcpy(tab[i].statut, "à réaliser");//strcpy pour affecter  une valeur a un variable deja declarer au structure
            } else if (ndestatut == 2) {
                strcpy(tab[i].statut, "en cours");
            } else if (ndestatut == 3) {
                strcpy(tab[i].statut, "finalisée");
            } else {

		printf("Choix invalide, Veuillez entrer un statut entre les trois \n ");
                scanf("%d",&ndestatut);
            }

        numId++;// apres la boucle il s'incremente l'id +
    }
    nombredetache += nombre; //il s'incremente le nombre de tache

}

void afficher_tache(){
    int choix;// variable pour donner a l'utilisateur l'acces a choisir 1 ordre alfa ou 2 ordre deadline
                printf("\n Afficher en :\n 1-tri par ordre alphabetique \n 2-tri par deadline\n");
                scanf ("%d",&choix);
                switch(choix){
                    case 1 :
                        alfa();
                     break;
                     case 2 :
                         dead_tri();//le tri compare 2 casiers par 2 casiers du tableau
                        break;
                }

}
void alfa() { //classement alphabetique
    tache temp;//pour changer l'ordre du tableau on a besoin de variable temporaire pour stocker

    for (i = 0; i < nombredetache; i++) {
        for (j = i + 1; j < nombredetache; j++) {
            // strcmp compare entre 2 cases et retourn le plus grand
            if (strcmp(tab[i].titre, tab[j].titre) > 0) {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }


    for(i=0; i<nombredetache; i++){ //affichage du tache apres classement par titre
        printf("Id : %d:\n",tab[i].id);

        printf("Entrer le titre de la tâche : %s\n", tab[i].titre);

        printf("La description : %s\n",tab[i].description);

        printf(" deadline :%s \n",tab[i].deadline);

	printf("statut: %s \n",tab[i].statut);


    }
}
void dead_tri(){ //classement par date
    tache temp;//variable temporaire pour changer l'ordre du tache

    for (i = 0; i < nombredetache; i++) {
        for (j = i + 1; j < nombredetache; j++) {
            if (strcmp(tab[j].deadline, tab[j-1].deadline) < 0) {
                temp = tab[j-1];
                tab[j-1] = tab[j];
                tab[j] = temp;
            }
        }
    }
    for(int i=0;i<nombredetache;i++){
        printf("Id : %d:\n",tab[i].id);

        printf("titre de la tâche : %s\n", tab[i].titre);// l'affichage du tache apres son classement par date

        printf("statut de la tâche : %s\n", tab[i].statut);

        printf("la description : %s\n",tab[i].description);

        printf("deadline %s :\n",tab[i].deadline);

    }

}
void modifier_tache (){ //modifier la tache description, statut, titre et deadline
        int codeid;//id du tache a modifier

        printf("veuillez entrer l'id de tache: \n");
        scanf("%d",&codeid);
       int test = 0;//variable pour valider la modif comparaison

        for(i=0; i<nombredetache; i++){
            if(tab[i].id == codeid){

		 printf("\n modifier la titre: \n");//modif titre
                scanf(" %[^\n]", tab[i].titre);

		printf("\n modifier la description \n");
                scanf(" %[^\n]", tab[i].description);

                int ndestatut;
                printf("\n modifier le statut: \n"); //modif statut
		printf("Entrer le numéro 1 pour tâche à réaliser, numéro 2 pour tâche en cours, 3 pour tâche finalisée : ");
                scanf("%d",&ndestatut);

                 if (ndestatut == 1) {
                    strcpy(tab[i].statut, "à réaliser");//strcpy pour importer toute les donnees de structure tache
                } else if (ndestatut == 2) {
                    strcpy(tab[i].statut, "en cours");
                } else if (ndestatut == 3) {
                    strcpy(tab[i].statut, "finalisée");
                } else {
                    printf("CHOIX INVALIDE, veuillez entrer un statut entre les trois \n");
                    scanf("%d",&ndestatut);

                }

                printf("\n modifier deadline (jj-mm-aaaa) : \n"); //modif deadline
                scanf(" %[^\n]", tab[i].deadline);

                printf("Modification reussite \n");
                test = 1;//code id correcte
                break;
            }
        }
    if(!test)//code id incorrecte
    {
      printf("%d introuvable \n ", codeid);//afficher introuvable
    }
}
void supprimer_tache()
{
    int code_id;//variable pour acceder au tache recherche
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
            nombredetache--;//retourn a la place de tache supprimer pour ne pas avoir un decalage (nombre de tache = nombre de tache -1)
            printf("Tâche %d supprimée avec succès\n", code_id);
            break;
        }
    }

    if(!found)
    {
        printf("%d non trouvé\n", code_id);
    }
}
void recherche(){// fonction globale contient recherche par id et par nom
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

void rechercher_id(){//rechercher la tache par son id
    int ent_id;//variable pour valider le numero d'id
            printf("\nEntrer l'id\n");
            scanf("%d",&ent_id);
            for(i=0;i<nombredetache;i++){
                if( tab[i].id==ent_id){//confirme le numeri de l'id
                printf("\n %s", tab[i].titre);//il s'affiche les information de la tache
                printf("\n %s", tab[i].description);
                printf("\n%s", tab[i].deadline);
                printf("\n%s",tab[i].statut);
                }
                else{
                printf("\n numero id introuvable");
                }
            }
}
void recherche_nom(){//rechercher la tache par son nom
    char tit[100];
    printf("\n Entrer le titre ");
    scanf(" %[^\n]", tit);
    for(int i=0; i<nombredetache; i++){
        if(strcmp(tit, tab[i].titre)==0){// fonction predefinit pour comparer les chaine de caracteres //sont egaux
        printf("\n %s", tab[i].titre);
        printf("\n %s", tab[i].description);
        printf("\n%s", tab[i].deadline);
        printf("\n%s",tab[i].statut);
        } else {
            printf("introuvable");
        }
    }
}


void situation_statut(){//tache complete et incomplete
	int complete=0;//initialiser la tache complete par 0
	int incomplete=0;//initialiser la tache incomplete par 0
      for(i=0 ; i<nombredetache; i++){
        if(strcmp(tab[i].statut, "finalisée")==0)complete++;//sont egaux
        else  incomplete++;
    }
	printf("le nombre de tache complete et incomplete est: \n");
	printf("tache complete: %d\n", complete);
	printf("tache incomplete: %d\n", incomplete);
}

void statistique(){// fonction global statistique total des taches et total tache complete et incomplete
    int choix;//variable pour switch condition
    printf("total des taches \n ");
    printf("1 :Nombre des taches \n");
    printf("2 :tache incomplete et complete \n ");
    scanf("%d",&choix);

    switch(choix){
        case 1 :
            printf("Le nombre de tache est : %d \n",nombredetache);//total des tache = nombre de tache
            break;
        case 2 :
        situation_statut();
         break;
        default:
        printf("nombre de jrs pour completer la tache");
        break;

    }
}

