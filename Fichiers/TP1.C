//Fatima Mahamat ; BTS ciel1
//TP1 d’application : Les fichiers en C

//////////Question n° 1//////////
//Avec une application écrite en C, vous allez ouvrir le fichier « source.txt » en lecture, et
//afficher son contenu caractère par caractère à l’écran à l’aide de la fonction getc.
//Refermez ensuite le fichier.


#include <stdio.h>

int main() {
    FILE *fichier;
    char caractere;

    // Ouvrir le fichier en lecture
    fichier = fopen("source.txt", "r");

    // Vérifier si le fichier est ouvert avec succès
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier source.txt.\n");
        return 1;
    }

    // Lire et afficher chaque caractère du fichier
    while ((caractere = getc(fichier)) != EOF) {
        printf("%c", caractere);
    }

    // Fermer le fichier
    fclose(fichier);

    return 0;
}

//////////Question n° 2//////////
//Ouvrir le fichier « source.txt » en lecture, et un fichier que vous nommerez « dest1.txt » en
//écriture, puis copier chaque caractère du fichier source dans le fichier de destination.
//Refermez le fichier.
