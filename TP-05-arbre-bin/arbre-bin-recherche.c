#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return (a==NULL);
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	*a = NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	// Alloue un nouvel élément de la liste
    ArbreBinaire nouvelArbre = (ArbreBinaire*)malloc(sizeof(Noeud));
    // Vérifie si l'allocation de mémoire a réussi
    if (nouvelArbre == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        exit(EXIT_FAILURE);
    }
    
    // Initialise le nouvel arbre avec la valeur e
    nouvelArbre->val = e;
	nouvelArbre->filsGauche = NULL;
	nouvelArbre->filsDroit = NULL;
    
	return nouvelArbre;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas inséré afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	ArbreBinaire pere_p = NULL, p = a, res = a;
	while (!estVide(p)&& p->val!=e){
		pere_p = p;
		if (p->val==e){
			//p = 
		}

	}
	
	

	return NULL;
}	

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
	if (estVide(a)){
		return creer(e);
	}
	if(a->val <= e){
		a->filsDroit=insere_r(a->filsDroit, e);
	}
	if(a->val > e){
		a->filsGauche=insere_r(a->filsGauche, e);
	}
	return NULL;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){
	if (estVide(a)){
		return 0;
	}
	return ( 1 + nombreDeNoeud(a->filsGauche)+ nombreDeNoeud(a->filsDroit));
}

int maximum(a,b);
    if (a > b) {
        maximum = a;
    } else {
        maximum = b;
    }

// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){
if (estVide(a)){
		return 0;
	}
	return (1 + maximum(profondeur(a->filsGauche), profondeur(a->filsDroit))); // je ne sais pas comment utiliser la fonction maximun
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	return 0;
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem){

	return NULL;
}


void afficheRGD_r(ArbreBinaire a){
}

void afficheGRD_r(ArbreBinaire a){
}

void afficheGDR_r(ArbreBinaire a){
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	return NULL;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	return NULL;
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem){

	return NULL;
}


// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x)
{

	return NULL;
}

void detruire_r(ArbreBinaire a){

}

