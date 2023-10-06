int * statistics (const char* chaineNucleotides);

int longueurChaine (const char* chaine);

int compteurLettre (const char * chaine, char Lettre);

void afficherTableau(int *tableauStat);

struct difference{
   int index; //indice où les deux séquences diffèrent
   int distance;
};

typedef struct difference Difference;

typedef Difference* tabDiff; //Question 2 

