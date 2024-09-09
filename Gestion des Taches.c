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

            // Ajout d'une tâche
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

            // Modification d'une tâche
            case 2: {
                if(!count) printf("Il n'y a aucune tâche à modifier.\n");
                else {
                    int choix;
                    printf("Veuillez choisir l'ID du tâche à modifier:\nID | Titre | Description | Deadline | Statut\n");
                    for(int i=0; i<count; i++) {
                        printf("%d | %s | %s | %s | %s\n", taches[i].id, taches[i].titre, taches[i].description, taches[i].deadline, taches[i].statut);
                    }
                    scanf("%d", &choix);
                    if(choix>count || choix<0) printf("Choix invalide!");
                    else {
                        printf("Nouveau Description ===> ");
                        scanf(" %[^\n]s", taches[choix].description);
                        printf("Nouveau Deadline ===> ");
                        scanf(" %[^\n]s", taches[choix].deadline);
                        printf("Nouveau Statut ===> ");
                        scanf(" %[^\n]s", taches[choix].statut);
                        printf("Tâche Modifiée avec succès!\n");
                    }
                }
            }; break;

            case 3: {
                if(!count) printf("Il n'y a aucune tâche à modifier.\n");
                else {
                    int choix;
                    printf("Veuillez choisir l'ID du tâche à supprimer:\nID | Titre | Description | Deadline | Statut\n");
                    for(int i=0; i<count; i++) {
                        printf("%d | %s | %s | %s | %s\n", taches[i].id, taches[i].titre, taches[i].description, taches[i].deadline, taches[i].statut);
                    }
                    scanf("%d", &choix);
                    if(choix>count || choix<0) printf("Choix invalide!");
                    else {
                        for(int i=choix; i<count-1; i++)
                            taches[i] = taches[i+1];
                        count--;
                        printf("Tâche Supprimée avec succès!\n");
                    }
                }
            }; break;

        }
    } while(choix >= 1 && choix <= 5);

    return 0;
}