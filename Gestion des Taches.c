#include <stdio.h>

typedef struct {
    int id;
    char titre[100];
    char description[1000];
    char deadline[10];
    char statut[25];
} Tache;

void menuPrincipal() {
    ligneEtoiles();

    printf("Veuillez choisir une option:\n");
    printf("1. Ajouter une tâche.\n");
    printf("2. Modifier une tâche.\n");
    printf("3. Supprimer une tâche.\n");
    printf("4. Rechercher une tâche.\n");
    printf("5. Afficher des Statistiques.\n");

    ligneEtoiles();
}

void ligneEtoiles() {
    printf("***********************************************\n");
}

int main() {
        

    return 0;
}