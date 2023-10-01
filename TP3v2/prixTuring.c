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


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char** argv)
{
    
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";
FILE *inputFile = fopen("turingWinners.csv", "r");
    if (inputFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier turingWinners.csv");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen("out.csv", "w");
    if (outputFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier out.csv");
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

    // TODO

	return EXIT_SUCCESS;
}

