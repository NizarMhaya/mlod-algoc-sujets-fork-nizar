#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SIZE 5

// Fonction pour multiplier deux matrices et stocker le résultat dans une troisième matrice
void matrix_mult(int64_t resultat[][SIZE], const int64_t matrice1[][SIZE], const int64_t matrice2[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            resultat[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                resultat[i][j] += matrice1[i][k] * matrice2[k][j];
            }
        }
    }
}

// Fonction pour afficher une matrice
void matrix_print(const int64_t matrice[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%lld\t", matrice[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    // Matrices en ligne * colonne
    int64_t matrice1[][SIZE] = {{1, 2, 3, 4, 5},
                                {1, 2, 3, 4, 5},
                                {1, 2, 3, 4, 5},
                                {1, 2, 3, 4, 5},
                                {1, 2, 3, 4, 5}};

    int64_t matrice2[][SIZE] = {{6, 7, 8, 9, 10},
                                {6, 7, 8, 9, 10},
                                {6, 7, 8, 9, 10},
                                {6, 7, 8, 9, 10},
                                {6, 7, 8, 9, 10}};

    int64_t matriceResultat[SIZE][SIZE];

    matrix_mult(matriceResultat, matrice1, matrice2);
    matrix_print(matriceResultat);

    return EXIT_SUCCESS;
}
