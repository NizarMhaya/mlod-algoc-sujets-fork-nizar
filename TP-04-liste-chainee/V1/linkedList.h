#pragma once

#include <stdbool.h>

typedef void* Element;

struct cellule_s {
	Element val;
	struct cellule_s* suiv;
};

typedef struct cellule_s Cellule;

typedef Cellule* Liste;

// Déclarations des fonctions
bool estVide(Liste l);
Liste creer(Element v);
Liste ajoutTete(Element v, Liste l);
Liste ajoutFin_i(Element v, Liste l);
Liste ajoutFin_r(Element v, Liste l);
Liste retirePremier(Element v, Liste l);
extern void afficheElement(Element e);
extern void afficheListe_i(Liste l);
extern void afficheListe_r(Liste l);
Liste cherche_i(Element v, Liste l);
Liste cherche_r(Element v, Liste l);
bool estPresent(Element v, Liste l);
bool equalsElement(Element e1, Element e2);
