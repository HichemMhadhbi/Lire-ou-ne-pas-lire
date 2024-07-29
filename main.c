#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, nbLivres;

    printf("Veuillez saisir le nombre total de livres : ");
    scanf("%d", &nbLivres);

    char Ttitre[1001];
    int max_length = 0; // Longueur du dernier livre lu
    char Tlus[nbLivres][1001]; // Tableau à deux dimensions pour stocker les titres des livres lus
    int lus_count = 0; // Compteur pour le nombre de livres lus

    printf("Veuillez saisir les titres des livres : \n");
    for (i = 0 ; i < nbLivres ; i++){
        fgets(Ttitre, sizeof(Ttitre), stdin);

        // Enlever le caractère de nouvelle ligne si présent
        Ttitre[strcspn(Ttitre, "\n")] = 0;

        int length = strlen(Ttitre);

        // Si la longueur du titre est supérieure à max_length, ajouter le titre au tableau lus et mettre à jour max_length.
        if(length > max_length) {
            strcpy(Tlus[lus_count], Ttitre);
            lus_count++;
            max_length = length;
        }
    }
    printf("Les titres des livres lus sont :\n")
    for (i = 0 ; i < lus_count ; i++){
        printf("%s\n", Tlus[i]);
    }

    return 0;
}



