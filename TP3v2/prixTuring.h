// prixTuring.h

#ifndef PRIX_TURING_H
#define PRIX_TURING_H
#ifndef _IO_STDIO_H
#endif

#define FICHIER_TURING_WINNERS "turingWinners.csv"

// Structure pour stocker les données d'un lauréat Turing
typedef struct {
    unsigned year;
    char *name;
    char *description;
}TuringWinner;

// Déclaration du prototype de la fonction numberOfWinners
int numberOfWinners(FILE *file);

FILE* ouvrirFichierLecture(const char *nomFichier);

FILE* ouvrirFichierEcriture(const char *nomFichier);

int lireCaractere(FILE *fichier);

char *readStringFromFileUntil(FILE *file, char delimiter);
void readWinners(TuringWinner *winner, FILE *file);
void printWinners(const TuringWinner *winner, FILE *file);
void freeWinner(TuringWinner *winner);


#endif // PRIX_TURING_H



