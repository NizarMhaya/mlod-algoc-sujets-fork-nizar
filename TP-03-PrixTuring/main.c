#include <stdio.h>
#include <stdlib.h>
#include "file_io.h" // Inclure le fichier d'en-tête

int main(int argc, char**, argv) {
    FILE* inputFile = ouvrirFichierLecture("turingWinners.csv");

    int nbGagnants = scanLineAsInt();
	printf("nbGagnants = %i\n",nbGagnants);

    FILE* outputFile = ouvrirFichierEcriture("out.csv");

    int caractere;
    while ((caractere = lireCaractere(inputFile)) != EOF) {
        // Traitement du caractère si nécessaire
        ecrireCaractere(outputFile, caractere);
    }

    int nombreDeGagnants = numberOfWinners(inputFile);
    printf("Le fichier contient %d lignes de données.\n", nombreDeGagnants);

    fermerFichier(inputFile);
    fermerFichier(outputFile);

    printf("Opération terminée avec succès.\n");

    return EXIT_SUCCESS;
}
