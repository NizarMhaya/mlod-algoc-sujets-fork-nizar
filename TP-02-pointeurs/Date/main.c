#include "Date.h"

int main() {
    // Exemple d'utilisation des types Mois et Date
    Mois moisActuel = SEPTEMBRE;
    Date maDate;
    maDate.jour = 18;
    maDate.mois = moisActuel;
    maDate.annee = 2023;
    
    Date d;
    initialiseDate(&d); //Pourquoi a t-on ajouté un &?
    afficheDate(&d);

    printf("La date est : %d %d %d\n", maDate.jour, maDate.mois, maDate.annee);

    Date *date;
    date = newDate();
    afficheDate(date);

    // Libère la mémoire allouée pour la date
    free(date);

    return 0;
}
