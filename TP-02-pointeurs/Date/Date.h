#pragma once

// TODO: definir echangeContenu

#include <stdio.h>


// Définition de l'énumération Mois
typedef enum  {
    JANVIER,
    FEVRIER,
    MARS,
    AVRIL,
    MAI,
    JUIN,
    JUILLET,
    AOUT,
    SEPTEMBRE,
    OCTOBRE,
    NOVEMBRE,
    DECEMBRE
} Mois;

// Définition de la structure Date
typedef struct  {
    unsigned short jour;
    Mois mois;
    int annee;
} Date;

void initialiseDate(Date *date) ;
void afficheDate(Date *date) ;
Date creerDateParCopie() ;
Date *newDate() ;
