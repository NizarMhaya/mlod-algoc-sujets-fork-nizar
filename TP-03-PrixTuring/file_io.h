#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>

// Fonction pour ouvrir un fichier en mode lecture
FILE* ouvrirFichierLecture(const char* nomFichier);

// Fonction pour ouvrir un fichier en mode écriture
FILE* ouvrirFichierEcriture(const char* nomFichier);

// Fonction pour lire un caractère du fichier
int lireCaractere(FILE* fichier);

// Fonction pour écrire un caractère dans le fichier
void ecrireCaractere(FILE* fichier, char caractere);

// Fonction pour fermer un fichier
void fermerFichier(FILE* fichier);

// Fonction pour retourner le nombre de gagnants en comptant les lignes que le fichier contient
int numberOfWinners(FILE* fichier);

#endif /* FILE_IO_H */
