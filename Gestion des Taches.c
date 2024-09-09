#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
        printf("6. Afficher Tous les Tâches.\n");
        printf("*Tapper autre chiffre pour quitter*\n");
        scanf("%d", &choix);
        switch(choix) {

            // Ajout d'une tâche
            case 1: {
                Tache T;
                printf("ID ===> ");
                scanf("%d", &taches[count].id);
                printf("Titre ===> ");
                scanf(" %[^\n]s", &taches[count].titre);
                printf("Description ===> ");
                scanf(" %[^\n]s", &taches[count].description);
                printf("Deadline (DD/MM/YYYY) ===> ");
                scanf(" %[^\n]s", &taches[count].deadline);
                printf("Statut ===> ");
                scanf(" %[^\n]s", &taches[count].statut);
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

            // Suppression d'une tâche
            case 3: {
                if(!count) printf("Il n'y a aucune tâche à supprimer.\n");
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

            // Recherche d'une tâche
            case 4: {
                if(!count) printf("Il n'y a aucune tâche actuellement.\n");
                else {
                    int choix;
                    printf("Vous voulez rechercher par ID ou par Titre ?\n1. Par ID\n2.Par Titre\n==>");
                    scanf("%d", &choix);
                    if(choix == 1) {
                        int id;
                        printf("Saisir l'ID ==> ");
                        scanf("%d", &id);
                        if(id > count || id<0) printf("ID invalide!\n");
                        else {
                            printf("ID | Titre | Description | Deadline | Statut\n");
                            printf("%d | %s | %s | %s | %s\n", taches[id].id, taches[id].titre, taches[id].description, taches[id].deadline, taches[id].statut);
                        }
                    } else if(choix == 2) {
                        char titre[100];
                        printf("Saisir le Titre ==> ");
                        scanf(" %[^\n]s", titre);
                        bool exists = false;
                        int indiceTacheTrouvee;
                        for(int i=0; i<count; i++) {
                            if(strcmp(taches[i].titre, titre) == 0) {
                                exists = true;
                                indiceTacheTrouvee = i;
                                break;
                            }
                        }
                        if(!exists) printf("Ce titre n'existe pas!\n");
                        else {
                            printf("ID | Titre | Description | Deadline | Statut\n");
                            printf("%d | %s | %s | %s | %s\n", taches[indiceTacheTrouvee].id, taches[indiceTacheTrouvee].titre, taches[indiceTacheTrouvee].description, taches[indiceTacheTrouvee].deadline, taches[indiceTacheTrouvee].statut);
                        }
                    }
                }
            }; break;

            // Statistiques
            case 5: {
                if(!count) printf("Il n'y a aucune tâche actuellement.\n");
                else {
                    printf("************** Statistiques **************\n");
                    printf("Le nombre total des tâches est: %d\n", count);
                    int countTCompletes = 0, countTInCompletes = 0;
                    for(int i=0; i<count; i++) {
                        if(strcmp(taches[i].statut, "terminée") == 0) countTCompletes++;
                        else countTInCompletes++;
                    }
                    printf("Le nombre total des tâches complètes est: %d\n", countTCompletes);
                    printf("Le nombre total des tâches incomplètes est: %d\n", countTInCompletes);
                }
            }; break;

        }
    } while(choix >= 1 && choix <= 6);

    return 0;
}