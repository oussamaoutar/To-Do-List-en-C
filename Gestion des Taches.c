#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char titre[100];
    char description[1000];
    char deadline[10];
    char statut[25];
} Tache;

Tache taches[1000];
int count = 0;

int main() {
    int choix;

    do {
        printf("Veuillez choisir une option:\n");
        printf("1. Ajouter une tâche.\n");
        printf("2. Modifier une tâche.\n");
        printf("3. Supprimer une tâche.\n");
        printf("4. Rechercher une tâche.\n");
        printf("5. Afficher des Statistiques.\n");
        printf("*Tapper autre chiffre pour quitter*\n");
        scanf("%d", &choix);
        switch(choix) {
            case 1: {
                int id;
                char titre[100];
                char description[1000];
                char deadline[10];
                char statut[25];
                printf("ID ===> ");
                scanf(" %[^\n]s", &id);
                printf("Titre ===> ");
                scanf(" %[^\n]s", titre);
                printf("Description ===> ");
                scanf(" %[^\n]s", description);
                printf("Deadline ===> ");
                scanf(" %[^\n]s", deadline);
                printf("Statut ===> ");
                scanf(" %[^\n]s", statut);
                Tache T = {
                    id,
                    titre,
                    description,
                    deadline,
                    statut
                };
                taches[count] = T;
                count++;
                printf("Tâche Ajoutée avec Succès!\n");
            } break;
            case 2: {
                
            }; break;
        }
    } while(choix >= 1 && choix <= 5);

    return 0;
}