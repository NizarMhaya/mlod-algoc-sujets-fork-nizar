#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v) {
    // Alloue un nouvel élément de la liste
    Cellule* nouvelleCellule = (Cellule*)malloc(sizeof(Cellule)); //Au lien de Cellule* on aurait pu mettre Liste
    
    // Vérifie si l'allocation de mémoire a réussi
    if (nouvelleCellule == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        exit(EXIT_FAILURE);
    }
    
    // Initialise la nouvelle cellule avec la valeur v
    nouvelleCellule->val = v;
    
    // La cellule suivante est NULL car c'est le seul élément dans la liste
    nouvelleCellule->suiv = NULL;
    
    // Retourne la nouvelle liste contenant un seul élément
    return nouvelleCellule;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	 Cellule* nouvelleCellule = creer(v);
	 nouvelleCellule->val = v;
	 nouvelleCellule->suiv = l;
	 // l = nouvelleCellule; // l est une variable local donc ça ne sert à rien de la modifier. Son espace mémoire est libéré à la fin.
	return nouvelleCellule; // avant il y avait ici return l // Par contre la valeur de nouvelleCellule est retournée dans la fonction main
}


void afficheElement(Element e) {
	printf("%i ",e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative

void afficheListe_i(Liste l) {
    Cellule* courant = l; // Initialise un pointeur courant à la tête de la liste

    // Parcourt la liste et affiche les éléments
    while (!estVide(courant)) {
        afficheElement(courant->val); // Appelle la fonction d'affichage pour afficher le champs val du pointeur courant (donc ce qu'on voulait)
        courant = courant->suiv; // Déplace le pointeur courant vers l'élément suivant
    }

    printf("\n"); // Ajoute un saut de ligne à la fin pour une meilleure lisibilité
}

// version recursive
void afficheListe_r(Liste l) {
	// Cas de base : si la liste est vide (NULL), terminer la récursion
    if (estVide(l)) {
        printf("\n"); // Ajouter un saut de ligne pour une meilleure lisibilité
        return;
    }

    // Affiche l'élément actuel
    afficheElement(l->val);

    // Appelle récursivement la fonction pour afficher le reste de la liste
    afficheListe_r(l->suiv);
	TODO;
}

void detruireElement(Element e) {}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste suivant, courant = l;

	while (!estVide(courant)){
		suivant = courant -> suiv;
		detruireElement(courant->val);
		free(l);
	}
	TODO;
}

// version récursive
void detruire_r(Liste l) {
	TODO;
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative


Liste ajoutFin_i(Element v, Liste l) {
	// Initialise la nouvelle cellule avec la valeur v
	Cellule* nouvelleCellule = creer(v);
    nouvelleCellule->val = v;
    nouvelleCellule->suiv = NULL; // La nouvelle cellule est en fin de liste

	// Si la liste est vide, la nouvelle cellule devient la tête de liste
    if (l == NULL) {
        return nouvelleCellule;
    }

    // Sinon, parcourt la liste jusqu'à la dernière cellule
    Cellule* courant = l;
    while (courant->suiv != NULL) {
        courant = courant->suiv;
    }

    // Ajoute la nouvelle cellule en fin de liste
    courant->suiv = nouvelleCellule;
	// nb : cela change qui le suivant de l'ancienne queue de liste qui contenant NULL
	//maintenant elle pointe vers nouvelleCellule, nouvelle queue.

    // Retourne la tête de liste inchangée
    return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	// Cas de base : si la liste est vide, crée une nouvelle cellule
    if (!estVide(l)) {
		l->suiv = ajoutFin_r (v, l->suiv);
		return l;
	}
	l =creer(v);
	return l;
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	Liste p=l;
	while (!estVide(p)){
		if (equalsElement(p->val,v)){
			return p;
		}
		p=p->suiv;

	}
	return p;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if (!estVide(l)&&!equalsElement(l->val,v)){
		return cherche_r(v, l->suiv);
	}
	return l;
}
bool estPresent (Element v,Liste l){
	return cherche_i(v,l) != NULL;
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	return TODO;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	return TODO;
}


void afficheEnvers_r(Liste l) {
	TODO;
}



