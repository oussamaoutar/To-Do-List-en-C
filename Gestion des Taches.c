#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int DD;
    int MM;
    int YYYY;
} Date;

typedef struct {
    int id;
    char titre[100];
    char description[1000];
    Date deadline;
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
        printf("*Tapper autre chiffre pour quitter*\n===> ");
        scanf("%d", &choix);
        switch(choix) {
            // Ajout d'une tâche
            case 1: {
                Tache T;
                Date D;
                bool IDExiste = false, titreExiste = false;
                printf("ID ===> ");
                scanf("%d", &T.id);
                for(int i=0; i<count; i++) {
                    if(taches[i].id == T.id) { IDExiste = true; break; }
                }
                while(IDExiste) {
                    printf("Cet ID existe déjà, veuillez taper un autre ID ===> ");
                    scanf("%d", &T.id);
                    for(int i=0; i<count; i++) {
                        if(taches[i].id == T.id) { IDExiste = true; break; }
                        else IDExiste = false;
                    }
                }
                printf("Titre ===> ");
                scanf(" %[^\n]s", T.titre);
                for(int i=0; i<count; i++) {
                    if(strcmp(taches[i].titre, T.titre) == 0) { titreExiste = true; break; }
                }
                while(titreExiste) {
                    printf("Ce titre existe déjà, veuillez saisir un autre titre ===> ");
                    scanf(" %[^\n]s", T.titre);
                    for(int i=0; i<count; i++) {
                        if(strcmp(taches[i].titre, T.titre) == 0) { titreExiste = true; break; }
                        else titreExiste = false;
                    }
                }
                printf("Description ===> ");
                scanf(" %[^\n]s", T.description);
                printf("Deadline (YYYY-MM-DD):\n");
                // la validation de la date coming soon...
                printf("YYYY ===> ");
                scanf("%d", &D.YYYY);
                printf("MM ===> ");
                scanf("%d", &D.MM);
                printf("DD ===> ");
                scanf("%d", &D.DD);
                printf("Statut ===> ");
                scanf(" %[^\n]s", T.statut);
                T.deadline = D;
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
                        printf("%d | %s | %s | %d-%d-%d | %s\n", taches[i].id, taches[i].titre, taches[i].description, taches[i].deadline.DD, taches[i].deadline.MM, taches[i].deadline.YYYY, taches[i].statut);
                    }
                    printf("===> ");
                    scanf("%d", &choix);
                    bool IDExiste = false;
                    for(int i=0; i<count; i++) {
                        if(taches[i].id == choix) { IDExiste = true; break; }
                    }
                    while(!IDExiste) {
                        printf("Cet ID n'existe pas, veuillez taper un ID valide ===> ");
                        scanf("%d", &choix);
                        for(int i=0; i<count; i++) {
                            if(taches[i].id == choix) { IDExiste = true; break; }
                            else IDExiste = false;
                        }
                    }
                    char c;
                    printf("Voulez-vous modifier la description? (O/N) ===> ");
                    scanf(" %c", &c);
                    int x = 0;
                    if(c=='O') {
                        printf("Nouvelle Description ===> ");
                        scanf(" %[^\n]s", taches[choix-1].description);
                        x++;
                    }
                    printf("Voulez-vous modifier le deadline? (O/N) ===> ");
                    scanf(" %c", &c);
                    if(c=='O') {
                        printf("Nouveau Deadline:\n");
                        printf("YYYY ===> ");
                        scanf("%d", taches[choix-1].deadline.YYYY);
                        printf("MM ===> ");
                        scanf("%d", taches[choix-1].deadline.MM);
                        printf("DD ===> ");
                        scanf("%d", taches[choix-1].deadline.DD);
                        x++;
                    }
                    printf("Voulez-vous modifier le statut? (O/N) ===> ");
                    scanf(" %c", &c);
                    if(c=='O') {
                        // printf("Nouveau Statut(1. à réaliser || 2. en cours de réalisation || Autre. finalisée):\n");
                        printf("Nouveau Statut ===> ");
                        scanf(" %[^\n]s", taches[choix-1].statut);
                        x++;
                    }
                    if(x >= 1) printf("Tâche Modifiée avec succès!\n");
                    else printf("Modification annulée.\n");
                }
            }; break;

            // Suppression d'une tâche
            case 3: {
                if(!count) printf("Il n'y a aucune tâche à supprimer.\n");
                else {
                    int choix;
                    printf("Veuillez choisir l'ID du tâche à supprimer:\nID | Titre | Description | Deadline | Statut\n");
                    for(int i=0; i<count; i++) {
                        printf("%d | %s | %s | %d-%d-%d | %s\n", taches[i].id, taches[i].titre, taches[i].description, taches[i].deadline.DD, taches[i].deadline.MM, taches[i].deadline.YYYY, taches[i].statut);
                    }
                    printf("===> ");
                    scanf("%d", &choix);
                    bool IDExiste = false;
                    for(int i=0; i<count; i++) {
                        if(taches[i].id == choix) { IDExiste = true; break; }
                    }
                    while(!IDExiste) {
                        printf("Cet ID n'existe pas, veuillez taper un ID valide ===> ");
                        scanf("%d", &choix);
                        for(int i=0; i<count; i++) {
                            if(taches[i].id == choix) { IDExiste = true; break; }
                            else IDExiste = false;
                        }
                    }
                    char confirmation;
                    printf("Voulez-vous vraiement supprimer cette tâche? (O/N) ===> ");
                    scanf(" %c", &confirmation);
                    if(confirmation == 'O') {
                        for(int i=choix-1; i<count-1; i++)
                            taches[i] = taches[i+1];
                        count--;
                        printf("Tâche Supprimée avec succès!\n");
                    } else printf("Suppression annulée.\n");
                }
            }; break;

            // Recherche d'une tâche
            case 4: {
                if(!count) printf("Il n'y a aucune tâche actuellement.\n");
                else {
                    int choix;
                    printf("Vous voulez rechercher par ID ou par Titre ?\n1. Par ID\nAutre Chiffre. Par Titre\n==>");
                    scanf("%d", &choix);
                    if(choix == 1) {
                        int id, i;
                        bool IDExiste = false;
                        printf("ID ===> ");
                        scanf("%d", &id);
                        for(i=0; i<count; i++) {
                            if (taches[i].id == id) { 
                                IDExiste = true; 
                                break; 
                            }
                        }
                        while(!IDExiste) {
                            printf("Cet ID n'existe pas, veuillez taper un ID valide ===> ");
                            scanf("%d", &id);
                            for(i=0; i<count; i++) {
                                if(taches[i].id == id) { 
                                    IDExiste = true; 
                                    break; 
                                }
                            }
                        }
                        printf("ID | Titre | Description | Deadline | Statut\n");
                        printf("%d | %s | %s | %d-%d-%d | %s\n", taches[i].id, taches[i].titre, taches[i].description, taches[i].deadline.DD, taches[i].deadline.MM, taches[i].deadline.YYYY, taches[i].statut);

                    } else {
                        char titre[100];
                        bool titreExiste = false;
                        int i;
                        printf("Saisir le titre ==> ");
                        scanf(" %[^\n]s", titre);
                        for(i=0; i<count; i++) {
                            if (strcmp(taches[i].titre, titre) == 0) { 
                                titreExiste = true; 
                                break; 
                            }
                        }
                        while(!titreExiste) {
                            printf("Ce titre n'existe pas, veuillez saisir un titre existant ===> ");
                            scanf(" %[^\n]s", titre);
                            for(i=0; i<count; i++) {
                                if(strcmp(taches[i].titre, titre) == 0) { 
                                    titreExiste = true; 
                                    break; 
                                }
                            }
                        }
                        printf("ID | Titre | Description | Deadline | Statut\n");
                        printf("%d | %s | %s | %d-%d-%d | %s\n", taches[i].id, taches[i].titre, taches[i].description, taches[i].deadline.DD, taches[i].deadline.MM, taches[i].deadline.YYYY, taches[i].statut);
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

            // Affichage
            case 6: {
                int choix;
                printf("Choisissez une option:\n");
                printf("1. Trier les tâches par ordre alphabétique\n");
                printf("2. Trier les tâches par deadline\n");
                printf("Autre. Afficher les tâches dont le deadline est dans 3 jours ou moins\n");
                switch(choix) {
                    case 1: {
                        // Application du tri à bulles sur le tableau des tâches     
                        for(int i=0; i<count-1; i++) {
                            for(int j=0; j<count-i-1; j++) {
                                if(strcmp(taches[j].titre, taches[j+1].titre) > 0) {
                                    Tache temp = taches[j];
                                    taches[j] = taches[j+1];
                                    taches[j+1] = temp;
                                }
                            }
                        }
                    }; break;

                    case 2: {

                    }; break;

                    default: {

                    }
                }
            }; break;

            default: exit(0);
        }
    } while(choix >= 1 && choix <= 6);

    return 0;
}