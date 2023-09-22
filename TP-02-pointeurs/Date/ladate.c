#include <stdio.h>
#include "Date.h"
#include <stdlib.h> // Inclure la bibliothèque pour EXIT_FAILURE


void afficheDate(Date *date) {
    printf("Date : %d %d %d\n", date->jour, date->mois, date->annee);
}

// Fonction pour initialiser une date par copie
void initialiseDate(Date *d) {
    d->jour = 1;
    d->mois = JANVIER;
    d->annee = 2000;
}

// Fonction pour créer et initialiser une date en utilisant scanf
Date creerDateParCopie() {
    Date nouvelleDate;

    printf("Entrez le jour (1-31) : ");
    scanf("%d", (int *) &nouvelleDate.jour);

    printf("Entrez le mois (0-11) : ");
    scanf("%d", (int *) &nouvelleDate.mois);

    printf("Entrez l'annee : ");
    scanf("%d", &nouvelleDate.annee);

    return nouvelleDate;
}
// Fonction pour créer une nouvelle Date et retourner son adresse
Date *newDate() {
    Date *nouvelleDate = (Date *)malloc(sizeof(Date)); // Alloue de la mémoire pour la structure Date

    if (nouvelleDate == NULL) {
        // Gestion de l'échec de l'allocation mémoire
        fprintf(stderr, "Erreur d'allocation mémoire pour Date\n");
        exit(EXIT_FAILURE);
    }

    printf("Entrez le jour (1-31) : ");
    scanf("%d", (int *) &(nouvelleDate->jour));

    printf("Entrez le mois (0-11) : ");
    scanf("%d", (int *) &(nouvelleDate->mois));

    printf("Entrez l'annee : ");
    scanf("%d", &(nouvelleDate->annee));

    return nouvelleDate;
}