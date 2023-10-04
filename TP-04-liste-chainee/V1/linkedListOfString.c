#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

void afficheElement(Element e) { // fonction modifiée par rapport à liste-chainee.c Qui sont données en extern dans le .h
    char* chaine = (char*)e;
     printf("%s ", chaine);
}

int main() {
    Liste maListe, p;
    maListe = NULL;
    maListe = ajoutTete("Hello", maListe);
    maListe = ajoutTete("world", maListe);
    maListe = ajoutTete("this", maListe);
    maListe = ajoutTete("is", maListe);
    maListe = ajoutTete("verlan", maListe);
    maListe = ajoutTete("because", maListe);
    maListe = ajoutTete("top to bottom", maListe);
    maListe = ajoutTete("becomes", maListe);
    maListe = ajoutTete("left", maListe);
    maListe = ajoutTete("to", maListe);
    maListe = ajoutTete("right", maListe);
    maListe = ajoutTete("THE END", maListe);
    
     char* texte = "Bonjour, Monde!";
    //afficheElement(texte);
    afficheListe_i(maListe);
}