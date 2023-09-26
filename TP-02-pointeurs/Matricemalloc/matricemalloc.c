#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Structure de matrice
typedef struct {
    int **donnees; // Tableau 2D pour stocker les données de la matrice
    int lignes;    // Nombre de lignes
    int colonnes;  // Nombre de colonnes
} Matrice;

// Fonction pour créer une matrice avec des valeurs initiales
Matrice *creer(int valeurInitiale, int nbreLignes, int nbreColonnes) {
    Matrice *matrice = (Matrice *)malloc(sizeof(Matrice));
    if (matrice == NULL) {
        perror("Erreur d'allocation mémoire pour la matrice");
        exit(EXIT_FAILURE);
    }

    matrice->lignes = nbreLignes;
    matrice->colonnes = nbreColonnes;
    matrice->donnees = (int **)malloc(nbreLignes * sizeof(int *));
    if (matrice->donnees == NULL) {
        perror("Erreur d'allocation mémoire pour les lignes de la matrice");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < nbreLignes; i++) {
        matrice->donnees[i] = (int *)malloc(nbreColonnes * sizeof(int));
        if (matrice->donnees[i] == NULL) {
            perror("Erreur d'allocation mémoire pour les colonnes de la matrice");
            exit(EXIT_FAILURE);
        }

        for (int j = 0; j < nbreColonnes; j++) {
            matrice->donnees[i][j] = valeurInitiale;
        }
    }

    return matrice;
}

// Fonction pour initialiser une ligne de la matrice avec des valeurs
void initialiserLigne(int ligne, int *valeurs, Matrice *matrice) {
    if (ligne < 1 || ligne > matrice->lignes) {
        fprintf(stderr, "Ligne invalide\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < matrice->colonnes; i++) {
        matrice->donnees[ligne - 1][i] = valeurs[i];
    }
}

// Fonction pour multiplier deux matrices
Matrice *multiplier(const Matrice *matrice1, const Matrice *matrice2) {
    if (matrice1->colonnes != matrice2->lignes) {
        fprintf(stderr, "Impossible de multiplier les matrices : dimensions incorrectes\n");
        exit(EXIT_FAILURE);
    }

    Matrice *resultat = creer(0, matrice1->lignes, matrice2->colonnes);

    for (int i = 0; i < matrice1->lignes; i++) {
        for (int j = 0; j < matrice2->colonnes; j++) {
            for (int k = 0; k < matrice1->colonnes; k++) {
                resultat->donnees[i][j] += matrice1->donnees[i][k] * matrice2->donnees[k][j];
            }
        }
    }

    return resultat;
}

// Fonction pour afficher une matrice
void afficherMatrice(const Matrice *matrice) {
    for (int i = 0; i < matrice->lignes; i++) {
        for (int j = 0; j < matrice->colonnes; j++) {
            printf("%d\t", matrice->donnees[i][j]);
        }
        printf("\n");
    }
}

// Fonction pour libérer la mémoire allouée pour une matrice
void libererMatrice(Matrice *matrice) {
    for (int i = 0; i < matrice->lignes; i++) {
        free(matrice->donnees[i]);
    }
    free(matrice->donnees);
    free(matrice);
}

int main() {
    Matrice *A, *B, *C;

    A = creer(1, 2, 3);
    B = creer(1, 3, 3);

    int valeursA[] = {2, 4, 6};
    int valeursB[] = {1, 2, 3};

    initialiserLigne(2, valeursA, A);
    initialiserLigne(2, valeursB, B);

    C = multiplier(A, B);

    printf("Matrice A :\n");
    afficherMatrice(A);

    printf("Matrice B :\n");
    afficherMatrice(B);

    printf("Resultat de la multiplication (A * B) :\n");
    afficherMatrice(C);

    libererMatrice(A);
    libererMatrice(B);
    libererMatrice(C);
}
