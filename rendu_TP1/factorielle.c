#include <stdio.h>
#include <stdlib.h>
typedef short TypeEntier;

TypeEntier factorielle (TypeEntier n) {
    if (n==0){
        return 1;
    } else {
        return n * factorielle(n-1);
    }
}

int main(){
    for(int i = 1; i<=15; i++){
        TypeEntier resultat = factorielle(i);
        printf("Factorielle de %d : %llu\n", i, resultat);
    }return 0;
}