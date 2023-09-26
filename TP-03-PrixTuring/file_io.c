//Ces fichiers contiendront des fonctions pour gérer l'ouverture, la lecture et l'écriture de fichiers. 
// Vous pouvez y mettre les fonctions telles que ouvrirFichierLecture, ouvrirFichierEcriture, lireLigne, ecrireLigne, etc.

#include <stdio.h>
#include <stdlib.h>

// Fonction pour ouvrir un fichier en mode lecture
FILE* ouvrirFichierLecture(const char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier en lecture");
        exit(EXIT_FAILURE);
    }
    return fichier;
}

// Fonction pour ouvrir un fichier en mode écriture
FILE* ouvrirFichierEcriture(const char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier en écriture");
        exit(EXIT_FAILURE);
    }
    return fichier;
}

// Fonction pour lire un caractère du fichier
int lireCaractere(FILE* fichier) {
    int caractere = fgetc(fichier);
    if (caractere == EOF) {
        // Fin de fichier ou erreur de lecture
        return EOF;
    }
    return caractere;
}

// Fonction pour écrire un caractère dans le fichier
void ecrireCaractere(FILE* fichier, char caractere) {
    if (fputc(caractere, fichier) == EOF) {
        perror("Erreur lors de l'écriture dans le fichier");
        exit(EXIT_FAILURE);
    }
}

// Fonction pour fermer un fichier
void fermerFichier(FILE* fichier) {
    fclose(fichier);
}

//Question 3

int numberOfWinners(FILE* fichier) {
    int nombreLignes = 0;
    int caractere;

    while ((caractere = fgetc(fichier)) != EOF) {
        if (caractere == '\n') {
            nombreLignes++;
        }
    }

    // Si le fichier ne se termine pas par une nouvelle ligne, nous ajoutons une ligne au compteur
    if (nombreLignes > 0) {
        nombreLignes++;
    }

    // Retourne le nombre de lignes comptées
    return nombreLignes;
}


void readWinner (TuringWinner *winner, FILE *f) {
    fscanf(f, "%" , SCNd16 ";", &winner->year);
    winner->names = readStringFromFileUntil (f, ';'); //fonction qui va lire dans le fichier n'importe quoi jusqu'à arriver à un point virgule et renvoyé ce qu'il a lu jusque là
    winner->description = readStringFromFileUntil (f, '\n');
}

// Fonction pour lire une chaîne de caractères du fichier jusqu'à un caractère de délimitation donné
char* readStringFromFileUntil(FILE* fichier, char delim) {
    int bufferSize = 64; // Taille initiale du tampon
    int bufferLength = 0; // Longueur actuelle de la chaîne lue
    char* buffer = (char*)malloc(bufferSize * sizeof(char));

    if (buffer == NULL) {
        perror("Erreur lors de l'allocation de mémoire pour la chaîne");
        exit(EXIT_FAILURE);
    }

    int caractere;

    while ((caractere = fgetc(fichier)) != EOF && caractere != delim) {
        // Vérifier si nous avons suffisamment d'espace dans le tampon
        if (bufferLength == bufferSize - 1) {
            bufferSize *= 2; // Double la taille du tampon
            buffer = (char*)realloc(buffer, bufferSize * sizeof(char));
            if (buffer == NULL) {
                perror("Erreur lors de la réallocation de mémoire pour la chaîne");
                exit(EXIT_FAILURE);
            }
        }

        // Ajouter le caractère lu au tampon
        buffer[bufferLength++] = caractere;
    }

    // Ajouter un caractère nul de fin de chaîne
    buffer[bufferLength] = '\0';

    return buffer;
}