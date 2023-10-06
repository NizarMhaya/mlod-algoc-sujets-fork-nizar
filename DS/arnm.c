#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "vaccins_covid.h"
#include "arnm.h"

// =========
// = Types =
// =========

const char NUCLEOTIDES[] = "ATCG";

// =============
// = Fonctions =
// =============


bool isNucleotide(char c) {
    return (c==NUCLEOTIDES[0] || c==NUCLEOTIDES[1] || c==NUCLEOTIDES[2] || c==NUCLEOTIDES[3]);
}

int indexOf(char nucleotide) {
	switch(nucleotide) {
		case 'A': return 0;
		case 'T': return 1;
		case 'C': return 2;
		case 'G': return 3;
		default:
			return -1;
	}
}

int distanceBetweenNucleotides(char n1, char n2) {
    return indexOf(n1)-indexOf(n2);
}

int * statistics (const char* chaineNucleotides){
	int tab_entiers[4];
	int longueur = longueurChaine (chaineNucleotides);
	tab_entiers[0] = 100* compteurLettre (chaineNucleotides, 'A') / longueur;
	tab_entiers[1] = 100* compteurLettre (chaineNucleotides, 'T') / longueur;
	tab_entiers[2] = 100* compteurLettre (chaineNucleotides, 'C') / longueur;
	tab_entiers[3] = 100* compteurLettre (chaineNucleotides, 'G') / longueur;

}

int longueurChaine (const char* chaine){ // donne la longueur d'une chaine de caractères
	int nombreCaractere = 0;
	int caractere;
	while ((caractere = chaine[nombreCaractere]) != '\0') {
        nombreCaractere++;
        }
	return nombreCaractere;
    }

int compteurLettre (const char * chaine, char Lettre){
	int indice = 0;
	int comptageLettre = 0;
	int caractere;
	while ((caractere = chaine[indice]) != '\0') {
		if(caractere == Lettre){
			comptageLettre++;
		}
        
        }
	return comptageLettre;
    }

// Fonction pour afficher un tableau d'entiers'
void afficherTableau(int *tableauStat) {
    for (int i = 0; i < 5; i++) {
        printf("%i\t", tableauStat[i]);
        printf("\n");
    }
}
Difference* computeDifferenceBeetween (const char* sequence1, const char* sequence2){
	tabDiff diff = (Difference *)malloc(sizeof(Difference));
	int indice = 0;
	while (sequence1[indice]==sequence2[indice]){
		indice++;
	}

}


	


// ========
// = Main =
// ========

int main(void){

	char sequenceDeNucleotides[]="ATGCATCCATCATGCATGTA";

    //printf("%s\n",code_proteine_spike_moderna);

	//printf (statistics(sequenceDeNucleotides));

	// afficherTableau(statistics(sequenceDeNucleotides));

	// J'ai perdu du temmps à essayer de faire fonctionner le print pour tester au fur et à mesure
	// La loi du point final m'a fait bloquer sur cela pendant 1h30

	return EXIT_SUCCESS;
}

