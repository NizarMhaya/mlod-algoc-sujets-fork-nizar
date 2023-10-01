/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring

 Tests
 diff out.csv turingWinners.csv

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <inttypes.h>  // Pour les types de données scanf (SCNd16)

#include "prixTuring.h"



int numberOfWinners(FILE *file) {
    int count = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            count++;
        }
    }
    rewind(file);
    return count;
}

FILE* ouvrirFichierLecture(const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        // Gérer l'erreur si nécessaire, peut-être quitter le programme
    }
    return fichier;
}

FILE* ouvrirFichierEcriture(const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        // Gérer l'erreur si nécessaire, peut-être quitter le programme
    }
    return fichier;
}

int lireCaractere(FILE *fichier) {
    int caractere = fgetc(fichier);
    if (caractere == EOF) {
        // Fin du fichier ou erreur de lecture
    }
    return caractere;
}


// Fonction pour lire une chaîne de caractères du fichier jusqu'à un caractère de délimitation donné
//La fonction renvoie un pointeur vers la chaîne lue
char *readStringFromFileUntil(FILE *file, char delimiter) {
    int bufferSize = 64; // Taille initiale du tampon
    int bufferLength = 0; // Longueur actuelle de la chaîne lue
    char *buffer = (char *)malloc(bufferSize * sizeof(char));

    if (buffer == NULL) {
        perror("Erreur lors de l'allocation de mémoire pour la chaîne");
        exit(EXIT_FAILURE);
    }

    int c;
    while ((c = fgetc(file)) != EOF && c != delimiter) {
        if (bufferLength + 1 >= bufferSize) {
            bufferSize *= 2; // Doublez la taille du tampon si nécessaire
            buffer = realloc(buffer, bufferSize * sizeof(char)); //realloc pour redimensionner le tampon au besoin.
            if (buffer == NULL) {
                perror("Erreur lors du redimensionnement de la mémoire tampon");
                exit(EXIT_FAILURE);
            }
        }
        buffer[bufferLength++] = (char)c;
    }
    buffer[bufferLength] = '\0'; // Ajoutez le caractère de fin de chaîne
    return buffer;
}

void readWinners(TuringWinner *winner, FILE *file) {
    int scanResult = fscanf(file, "%" SCNu32 ";", &winner->year);
    if (scanResult != 1) {
        perror("Erreur lors de la lecture de l'année");
        exit(EXIT_FAILURE);
    }

    winner->name = readStringFromFileUntil(file, ';');
    winner->description = readStringFromFileUntil(file, '\n');
}

//Pour écrire une fonction printWinners qui prend une structure de données TuringWinner en paramètre ainsi qu'un
//fichier de sortie (type FILE *) et y écrit les gagnants dans le même format que le fichier d'entrée
void printWinners(const TuringWinner *winner, FILE *file) {
    fprintf(file, "%" PRIu32 ";%s;%s\n", winner->year, winner->name, winner->description);
}

void freeWinner(TuringWinner *winner) {
    free(winner->name);
    free(winner->description);
}

//Cette fonction prend l'année recherchée, un tableau de TuringWinner contenant les données des lauréats et le nombre total de lauréats.
//Elle parcourt ensuite le tableau pour trouver un match avec l'année recherchée.
void infosAnnee(unsigned int anneeRecherchee, TuringWinner *turingWinners, int nombreGagnants) {
    int i;
    int trouve = 0;

    for (i = 0; i < nombreGagnants; ++i) {
        if (turingWinners[i].year == anneeRecherchee) {
            trouve = 1;
            printf("L'annee %u, le(s) gagnant(s) ont été : %s\n", turingWinners[i].year, turingWinners[i].name);
            printf("Nature des travaux : %s\n", turingWinners[i].description);
            break;
        }
    }

    if (!trouve) {
        printf("Aucun gagnant trouvé pour l'année %u.\n", anneeRecherchee);
    }
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char** argv)
{
    system("chcp 65001");  // Changer l'encodage de la console à UTF-8 (pour Windows)
    unsigned int anneeRecherchee;
    TuringWinner *turingWinners; // Tableau pour stocker les lauréats
    int nombreDeGagnants; // Variable pour stocker le nombre total de lauréats

    
    char *inputFileName = "turingWinners.csv"; // Nom par défaut du fichier d'entrée
    char *outputFileName = "out.csv"; // Nom par défaut du fichier de sortie

// Analyse des arguments en ligne de commande
for (int i = 1; i < argc; i++) {
    printf("Argument %d : %s\n", i, argv[i]); // Ajoutez cette ligne pour déboguer

    if (strcmp(argv[i], "--info") == 0 && i + 1 < argc) {
        anneeRecherchee = atoi(argv[i + 1]);
        i += 2; // Passer à l'argument suivant
        printf("Option --info détectée. Année recherchée : %d\n", anneeRecherchee); // Ajoutez cette ligne pour déboguer
    } else if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) {
        inputFileName = argv[i + 1];
        i += 2; // Passer à l'argument suivant
        printf("Option -i détectée. Nom du fichier d'entrée : %s\n", inputFileName); // Ajoutez cette ligne pour déboguer
    } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
        outputFileName = argv[i + 1];
        i += 2; // Passer à l'argument suivant
        printf("Option -o détectée. Nom du fichier de sortie : %s\n", outputFileName); // Ajoutez cette ligne pour déboguer
    } else {
        printf("Usage: %s [--info <année>] [-i input_file -o output_file]\n", argv[0]);
        return EXIT_FAILURE;
    }
}

//Le programme prend en charge deux options en ligne de commande : -i pour spécifier le fichier d'entrée et -o pour spécifier le fichier de sortie.
//La boucle for parcourt les arguments en ligne de commande et met à jour les noms des fichiers d'entrée et de sortie en conséquence.

FILE *inputFile = fopen("turingWinners.csv", "r");
    if (inputFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier turingWinners.csv");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen("out.csv", "w");
    if (outputFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier out.csv");
        fclose(inputFile); // Fermer le fichier d'entrée avant de quitter
        exit(EXIT_FAILURE);
    }

    TuringWinner winner;
    while (!feof(inputFile)) {
        readWinners(&winner, inputFile);
        printWinners(&winner, outputFile);
        freeWinner(&winner);
    }


    fclose(inputFile);
    fclose(outputFile);

    return 0;
    // TODO

	return EXIT_SUCCESS;
}

