#include <stdio.h>
#include <stdlib.h>

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
    printf("*Tapper autre chiffre pour quitter*\n");

    ligneEtoiles();
}

void ligneEtoiles() {
    printf("***********************************************\n");
}

int main() {
    int choix;

    do {
        menuPrincipal();
        scanf("%d", &choix);
    } while(choix >= 1 && choix <= 5);

    return 0;
}